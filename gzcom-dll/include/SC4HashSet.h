/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4HashSet.h
 *
 * Copyright (C) 2025 Casper Van Gheluwe
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
#include <cstdlib>

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
struct SC4HashSet {
    void* vftable;
    SC4HashNode<Key>** mpStart;    // +0x04
    SC4HashNode<Key>** mpEnd;      // +0x08
    uint32_t reserved;             // +0x0C (capacity)
    uint32_t mSize;                // +0x10 (element count)

    static void Init(SC4HashSet<Key>* table, size_t bucketCount = 8) {
        table->mpStart = static_cast<SC4HashNode<Key> **>(std::malloc(bucketCount * sizeof(SC4HashNode<Key> *)));
        std::memset(table->mpStart, 0, bucketCount * sizeof(SC4HashNode<Key>*));
        table->mpEnd = table->mpStart + bucketCount;
        table->reserved = bucketCount;
        table->mSize = 0;
    }

    void Init(size_t bucketCount = 8) {
        mpStart = static_cast<SC4HashNode<Key> **>(std::malloc(bucketCount * sizeof(SC4HashNode<Key> *)));
        std::memset(mpStart, 0, bucketCount * sizeof(SC4HashNode<Key>*));
        mpEnd = mpStart + bucketCount;
        reserved = bucketCount;
        mSize = 0;
    }

    void Clear() {
        if (mpStart) {
            std::free(mpStart);
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
    SC4HashNode<Key>* find(const Key& key) const {
        if (!mpStart || mpStart == mpEnd) return nullptr;
        auto idx = bucketIndex(key);
        for (auto n = mpStart[idx]; n; n = n->next)
            if (n->key == key) return n;
        return nullptr;
    }

    // Insert new node
    SC4HashNode<Key>* insert(const Key& key, SC4HashNode<Key>* (*alloc)(size_t) = nullptr) {
        if (!mpStart || mpStart == mpEnd) return nullptr;
        auto idx = bucketIndex(key);
        auto head = mpStart[idx];

        for (auto n = head; n; n = n->next)
            if (n->key == key) return n; // already exists

        auto node = alloc ? alloc(sizeof(SC4HashNode<Key>))
                          : reinterpret_cast<SC4HashNode<Key>*>(malloc(sizeof(SC4HashNode<Key>)));
        node->next = head;
        node->key = key;
        mpStart[idx] = node;
        mSize++;
        return node;
    }

    // Iterator type compatible with SC4's traversal pattern
    struct iterator {
        SC4HashNode<Key>** pBucket;
        SC4HashNode<Key>** pEnd;
        SC4HashNode<Key>* pNode;

        iterator(SC4HashNode<Key>** start, SC4HashNode<Key>** end, SC4HashNode<Key>* node = nullptr)
            : pBucket(start), pEnd(end), pNode(node)
        {
            advanceWhileNull();
        }

        void advanceWhileNull() {
            while (!pNode && pBucket < pEnd) {
                pNode = *pBucket;
                if (!pNode) ++pBucket;
            }
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
        SC4HashNode<Key>* operator*() const { return pNode; }
        SC4HashNode<Key>* operator->() const { return pNode; }
    };

    iterator begin() const {
        if (!mpStart || mpStart == mpEnd) return iterator(mpEnd, mpEnd, nullptr);
        return iterator(mpStart, mpEnd);
    }

    iterator end() const {
        return iterator(mpEnd, mpEnd, nullptr);
    }
};

#pragma pack(pop)
