/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4Tree.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
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
#include "cIGZAllocatorService.h"
#include "GZServPtrs.h"
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <new>
#include <type_traits>
#include <utility>

// Game-layout red-black tree. SimCity 4.exe 1.1.641 uses the STLport 4
// _Rb_tree for std::map and std::set, and this mirrors its memory layout so
// a game function can fill one of these, or hand out a reference to its own.
//
// The container is three words. The first points to a header node on the
// heap, the second is the element count and the third is padding for the
// empty std::less comparator. The header is a full-size node whose value is
// never constructed. Its parent is the root, its left is the leftmost node
// and its right is the rightmost node. An empty tree has a red header, a null
// root, and left and right pointing back at the header.
//
// Nodes and the header live in the game allocator. Freeing goes through
// cIGZAllocatorService, like SC4Vector and SC4List.
//
// Only what out-parameters and read-only access need is here: an empty tree
// the game can insert into, ordered iteration, lookup, clear and destruction.
// There is no insert, so there is no rebalancing.

#pragma pack(push, 4)

struct SC4TreeNodeBase
{
	enum : uint8_t { Red = 0, Black = 1 };

	uint8_t color;              // +0x00, followed by three bytes of padding
	SC4TreeNodeBase* parent;    // +0x04
	SC4TreeNodeBase* left;      // +0x08
	SC4TreeNodeBase* right;     // +0x0C

	static SC4TreeNodeBase* Minimum(SC4TreeNodeBase* x)
	{
		while (x->left)
		{
			x = x->left;
		}
		return x;
	}

	static SC4TreeNodeBase* Maximum(SC4TreeNodeBase* x)
	{
		while (x->right)
		{
			x = x->right;
		}
		return x;
	}

	// Same walk as the game's iterator increment. Stepping past the
	// rightmost node lands on the header.
	static SC4TreeNodeBase* Increment(SC4TreeNodeBase* x)
	{
		if (x->right)
		{
			return Minimum(x->right);
		}

		SC4TreeNodeBase* y = x->parent;
		while (x == y->right)
		{
			x = y;
			y = y->parent;
		}

		// When the tree has a single node, x ends up on the header and
		// y on the root. The header is the right answer then.
		return x->right != y ? y : x;
	}

	// Same walk as the game's iterator decrement. Stepping back from the
	// header lands on the rightmost node. The header is the only red node
	// whose grandparent is itself.
	static SC4TreeNodeBase* Decrement(SC4TreeNodeBase* x)
	{
		if (x->color == Red && x->parent->parent == x)
		{
			return x->right;
		}

		if (x->left)
		{
			return Maximum(x->left);
		}

		SC4TreeNodeBase* y = x->parent;
		while (x == y->left)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
};

static_assert(sizeof(SC4TreeNodeBase) == 0x10);
static_assert(offsetof(SC4TreeNodeBase, color) == 0x00);
static_assert(offsetof(SC4TreeNodeBase, parent) == 0x04);
static_assert(offsetof(SC4TreeNodeBase, left) == 0x08);
static_assert(offsetof(SC4TreeNodeBase, right) == 0x0C);

template<typename Value>
struct SC4TreeNode
{
	SC4TreeNodeBase base;       // +0x00
	Value value;                // +0x10
};

// Allocates through the game's allocator service.
struct SC4TreeGameAllocator
{
	static void* Allocate(size_t size)
	{
		cIGZAllocatorServicePtr allocator;

		void* ptr = allocator->Allocate(static_cast<uint32_t>(size));

		if (!ptr)
		{
			throw std::bad_alloc();
		}

		return ptr;
	}

	static void Deallocate(void* ptr)
	{
		cIGZAllocatorServicePtr allocator;

		allocator->Deallocate(ptr);
	}
};

// Key extractors for sets and maps.
struct SC4TreeIdentity
{
	template<typename T>
	static const T& Get(const T& value) { return value; }
};

struct SC4TreeSelect1st
{
	template<typename Pair>
	static const typename Pair::first_type& Get(const Pair& value) { return value.first; }
};

template<typename Value, bool IsConst>
class SC4TreeIterator
{
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = std::remove_cv_t<Value>;
	using reference = std::conditional_t<IsConst, const Value&, Value&>;
	using pointer = std::conditional_t<IsConst, const Value*, Value*>;

	SC4TreeIterator() : pNode(nullptr)
	{
	}

	explicit SC4TreeIterator(SC4TreeNodeBase* node) : pNode(node)
	{
	}

	// A mutable iterator converts to a const one.
	template<bool OtherConst, typename = std::enable_if_t<IsConst && !OtherConst>>
	SC4TreeIterator(const SC4TreeIterator<Value, OtherConst>& other) : pNode(other.pNode)
	{
	}

	reference operator*() const
	{
		return reinterpret_cast<SC4TreeNode<Value>*>(pNode)->value;
	}

	pointer operator->() const
	{
		return &reinterpret_cast<SC4TreeNode<Value>*>(pNode)->value;
	}

	SC4TreeIterator& operator++()
	{
		pNode = SC4TreeNodeBase::Increment(pNode);
		return *this;
	}

	SC4TreeIterator operator++(int)
	{
		SC4TreeIterator tmp = *this;
		++(*this);
		return tmp;
	}

	SC4TreeIterator& operator--()
	{
		pNode = SC4TreeNodeBase::Decrement(pNode);
		return *this;
	}

	SC4TreeIterator operator--(int)
	{
		SC4TreeIterator tmp = *this;
		--(*this);
		return tmp;
	}

	friend bool operator==(const SC4TreeIterator& a, const SC4TreeIterator& b)
	{
		return a.pNode == b.pNode;
	}

	friend bool operator!=(const SC4TreeIterator& a, const SC4TreeIterator& b)
	{
		return a.pNode != b.pNode;
	}

	SC4TreeNodeBase* pNode;
};

template<typename Value, typename KeyOfValue, typename Allocator = SC4TreeGameAllocator>
class SC4Tree
{
public:
	using value_type = Value;
	using key_type = std::remove_cv_t<std::remove_reference_t<
		decltype(KeyOfValue::Get(std::declval<const Value&>()))>>;
	using size_type = size_t;
	using node_type = SC4TreeNode<Value>;
	using iterator = SC4TreeIterator<Value, false>;
	using const_iterator = SC4TreeIterator<Value, true>;

	SC4Tree()
		: mpHeader(static_cast<SC4TreeNodeBase*>(Allocator::Allocate(sizeof(node_type)))),
		  mSize(0),
		  mCompare(0)
	{
		ResetHeader();
	}

	~SC4Tree()
	{
		if (mpHeader)
		{
			Erase(mpHeader->parent);
			Allocator::Deallocate(mpHeader);
			mpHeader = nullptr;
		}
	}

	// The nodes belong to exactly one tree, so copying is not allowed.
	SC4Tree(const SC4Tree&) = delete;
	SC4Tree& operator=(const SC4Tree&) = delete;

	size_type size() const
	{
		return mSize;
	}

	bool empty() const
	{
		return mSize == 0;
	}

	iterator begin()
	{
		return iterator(mpHeader->left);
	}

	iterator end()
	{
		return iterator(mpHeader);
	}

	const_iterator begin() const
	{
		return const_iterator(mpHeader->left);
	}

	const_iterator end() const
	{
		return const_iterator(mpHeader);
	}

	const_iterator cbegin() const
	{
		return begin();
	}

	const_iterator cend() const
	{
		return end();
	}

	// Ordered lookup with operator<, the same walk as the game's find.
	iterator find(const key_type& key)
	{
		return iterator(FindNode(key));
	}

	const_iterator find(const key_type& key) const
	{
		return const_iterator(FindNode(key));
	}

	bool contains(const key_type& key) const
	{
		return FindNode(key) != mpHeader;
	}

	// Frees every node and leaves the empty-tree invariants in place.
	void clear()
	{
		Erase(mpHeader->parent);
		ResetHeader();
		mSize = 0;
	}

private:
	void ResetHeader()
	{
		mpHeader->color = SC4TreeNodeBase::Red;
		mpHeader->parent = nullptr;
		mpHeader->left = mpHeader;
		mpHeader->right = mpHeader;
	}

	SC4TreeNodeBase* FindNode(const key_type& key) const
	{
		SC4TreeNodeBase* y = mpHeader;
		SC4TreeNodeBase* x = mpHeader->parent;

		while (x)
		{
			if (!(KeyOf(x) < key))
			{
				y = x;
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}

		if (y == mpHeader || key < KeyOf(y))
		{
			return mpHeader;
		}

		return y;
	}

	static const key_type& KeyOf(SC4TreeNodeBase* node)
	{
		return KeyOfValue::Get(reinterpret_cast<node_type*>(node)->value);
	}

	// Same recursion as the game. Recurse right, then loop left.
	static void Erase(SC4TreeNodeBase* x)
	{
		while (x)
		{
			Erase(x->right);
			SC4TreeNodeBase* left = x->left;

			node_type* node = reinterpret_cast<node_type*>(x);
			if constexpr (!std::is_trivially_destructible_v<Value>)
			{
				node->value.~Value();
			}
			Allocator::Deallocate(node);

			x = left;
		}
	}

	SC4TreeNodeBase* mpHeader;  // +0x00
	uint32_t mSize;             // +0x04
	uint32_t mCompare;          // +0x08, the empty std::less and its padding
};

template<typename Key, typename Allocator = SC4TreeGameAllocator>
using SC4Set = SC4Tree<const Key, SC4TreeIdentity, Allocator>;

template<typename Key, typename T, typename Allocator = SC4TreeGameAllocator>
using SC4Map = SC4Tree<std::pair<const Key, T>, SC4TreeSelect1st, Allocator>;

// Node sizes match the allocations in the game: 0x14 for a std::set of
// uint32_t and 0x18 for a std::map of uint32_t to a 4-byte value.
using SC4TreeSetNodeU32 = SC4TreeNode<const uint32_t>;
using SC4TreeMapNodeU32 = SC4TreeNode<std::pair<const uint32_t, int32_t>>;
static_assert(sizeof(SC4Set<uint32_t>) == 0x0C);
static_assert(sizeof(SC4Map<uint32_t, int32_t>) == 0x0C);
static_assert(sizeof(SC4TreeSetNodeU32) == 0x14);
static_assert(sizeof(SC4TreeMapNodeU32) == 0x18);
static_assert(offsetof(SC4TreeSetNodeU32, value) == 0x10);
static_assert(offsetof(SC4TreeMapNodeU32, value) == 0x10);

#pragma pack(pop)
