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

// Frees through the game's allocator service.
struct SC4HashSetGameAllocator
{
    static void Deallocate(void* ptr)
    {
        cIGZAllocatorServicePtr allocator;

        allocator->Deallocate(ptr);
    }
};

// Binary-compatible view of the game's STLport hash_set.
//
// The game owns the bucket array and the nodes and fills them in. This class
// only reads them and frees them when it goes away. The game hashes integral
// keys as key % buckets and pointer keys as (key >> 2) % buckets, and bucketIndex
// does the same. The allocator is a parameter so the self-check can count blocks.
template<typename Key, typename Allocator>
class SC4HashSetImpl {
    static_assert(std::is_integral_v<Key> || std::is_pointer_v<Key>,
                  "the game's hash is only known for integral and pointer keys");

    SC4HashNode<Key>** mpStart;    // +0x04
    SC4HashNode<Key>** mpEnd;      // +0x08
    void* reserved;                // +0x0C (capacity)
    uint32_t mSize;                // +0x10 (element count)

    template <typename T>
    struct IsIGZUnknownPointer
    {
        static constexpr bool value = std::is_pointer_v<T> && std::is_base_of_v<cIGZUnknown, std::remove_pointer_t<T>>;
    };

    // Same order as the game's hashtable clear and destructor: every node of
    // every bucket first, then the bucket array.
    static void DeleteBuckets(SC4HashNode<Key>** const pStart, size_t bucketCount)
    {
        for (size_t i = 0; i < bucketCount; i++)
        {
            SC4HashNode<Key>* node = pStart[i];

            while (node != nullptr)
            {
                SC4HashNode<Key>* next = node->next;

                if constexpr (IsIGZUnknownPointer<Key>::value)
                {
                    // The game hands these out with a reference held, in case
                    // the user forgets to call the clear method its API provides.
                    if (node->key)
                    {
                        node->key->Release();
                    }
                }

                Allocator::Deallocate(node);
                node = next;
            }

            pStart[i] = nullptr;
        }

        Allocator::Deallocate(pStart);
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

    SC4HashSetImpl()
        : mpStart(nullptr), mpEnd(nullptr), reserved(nullptr), mSize(0)
    {
    }

    // The nodes belong to this set, so a copy would free them twice.
    SC4HashSetImpl(const SC4HashSetImpl&) = delete;
    SC4HashSetImpl& operator=(const SC4HashSetImpl&) = delete;

    virtual ~SC4HashSetImpl() {
        if (mpStart) {
            DeleteBuckets(mpStart, bucketCount());
            mpStart = mpEnd = nullptr;
            reserved = nullptr;
            mSize = 0;
        }
    }

    // Compute bucket count
    size_t bucketCount() const {
        if (!mpStart || !mpEnd) return 0;
        return static_cast<size_t>(mpEnd - mpStart);
    }

    // The bucket the game puts a key in
    size_t bucketIndex(const Key& key) const {
        if constexpr (std::is_pointer_v<Key>) {
            return (reinterpret_cast<uintptr_t>(key) >> 2) % bucketCount();
        }
        else {
            return static_cast<uint32_t>(key) % bucketCount();
        }
    }

    // Find node by key
    iterator find(const Key& key) const {
        if (!mpStart || mpStart == mpEnd) return end();

        SC4HashNode<Key>** bucket = mpStart + bucketIndex(key);

        for (auto n = *bucket; n; n = n->next)
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

// The hash set the game's interfaces take, freed through the allocator service.
template<typename Key>
class SC4HashSet : public SC4HashSetImpl<Key, SC4HashSetGameAllocator> {
};

static_assert(sizeof(SC4HashSet<uint32_t>) == 0x14);

#pragma pack(pop)
