/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4HashSet.h
 *
 * Copyright (C) 2025 Casper Van Gheluwe
 * Copyright (C) 2025 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include <cstdint>
#include "cIGZAllocatorService.h"
#include "GZServPtrs.h"
#include <type_traits>

#pragma pack(push, 4)
template<typename K>
struct SC4HashNode {
    SC4HashNode* next;
    K key;
};
static_assert(sizeof(SC4HashNode<uint32_t>) == 8);
static_assert(sizeof(SC4HashNode<void*>) == 8);

// Binary-compatible hash table
template<typename Key>
class SC4HashSet {
    SC4HashNode<Key>** mpStart;    // +0x04
    SC4HashNode<Key>** mpEnd;      // +0x08
    void* reserved;                // +0x0C (capacity)
    uint32_t mSize;                // +0x10 (element count)

    template <typename T>
    struct IsIGZUnknownPointer
    {
        static constexpr bool value = std::is_pointer_v<T> && std::is_base_of_v<cIGZUnknown, std::remove_pointer_t<T>>;
    };

    static void DeleteBucketNodes(SC4HashNode<Key>** const pStart, size_t bucketCount)
    {
        cIGZAllocatorServicePtr as;

        for (size_t i = 0; i < bucketCount; i++)
        {
            SC4HashNode<Key>* bucket = pStart[i];

            if (bucket != nullptr)
            {
                // Cleanup the key values in each bucket.
                // This can be skipped for types that are trivially destructable.
                if constexpr (IsIGZUnknownPointer<Key>::value || !std::is_trivially_destructible_v<Key>)
                {
                    SC4HashNode<Key>* node = bucket;

                    while (node != nullptr)
                    {
                        SC4HashNode<Key>* next = node->next;

                        if constexpr (IsIGZUnknownPointer<Key>::value)
                        {
                            // Handle the cleanup of cIGZUnknown-derived types in case the user forgets to
                            // call the clear method the game's API provides.
                            if (node->key)
                            {
                                node->key->Release();
                            }
                        }
                        else
                        {
                            node->key.~Key();
                        }

                        node = next;
                    }
                }
                
                as->Deallocate(bucket);
                bucket = nullptr;
            }
        }
    }

public:
    // Iterator type compatible with SC4's traversal pattern
    class iterator {
        SC4HashNode<Key>** pBucket;
        SC4HashNode<Key>** pEnd;
        SC4HashNode<Key>* pNode;

    public:
        iterator(SC4HashNode<Key>** start, SC4HashNode<Key>** end, SC4HashNode<Key>* node = nullptr)
            : pBucket(start), pEnd(end), pNode(node)
        {
            advanceWhileNull();
        }

        iterator& operator++() {
            if (pNode) pNode = pNode->next;
            if (!pNode && pBucket < pEnd) {
                ++pBucket;
                advanceWhileNull();
            }
            return *this;
        }

        bool operator==(const iterator& other) const { return pNode == other.pNode; }
        bool operator!=(const iterator& other) const { return pNode != other.pNode; }
        Key operator*() const { return pNode->key; }
        Key operator->() const { return pNode->key; }

    private:
        void advanceWhileNull() {
            while (!pNode && pBucket < pEnd) {
                pNode = *pBucket;
                if (!pNode) ++pBucket;
            }
        }
    };

    SC4HashSet()
        : mpStart(nullptr), mpEnd(nullptr), reserved(nullptr), mSize(0)
    {
    }

    virtual ~SC4HashSet() {
        if (mpStart) {
            DeleteBucketNodes(mpStart, bucketCount());
            mpStart = mpEnd = nullptr;
            reserved = 0;
            mSize = 0;
        }
    }

    // Compute bucket count
    size_t bucketCount() const {
        if (!mpStart || !mpEnd) return 0;
        return (reinterpret_cast<uintptr_t>(mpEnd) - reinterpret_cast<uintptr_t>(mpStart)) / sizeof(SC4HashNode<Key>*);
    }

    // Hash function: (key >> 2) % bucket_count
    size_t bucketIndex(const Key& key) const {
        return (reinterpret_cast<uintptr_t>(key) >> 2) % bucketCount();
    }

    // Find node by key
   iterator find(const Key& key) const {
        if (!mpStart || mpStart == mpEnd) return nullptr;
        auto idx = bucketIndex(key);
        auto bucket = mpStart[idx];

        for (auto n = bucket; n; n = n->next)
            if (n->key == key) return iterator(bucket, mpEnd, n);

        return end();
    }

    size_t size() const {
        return mSize;
    }

    iterator begin() const {
        if (!mpStart || mpStart == mpEnd) return iterator(mpEnd, mpEnd, nullptr);
        return iterator(mpStart, mpEnd);
    }

    iterator end() const {
        return iterator(mpEnd, mpEnd, nullptr);
    }
};

#pragma pack(pop)
