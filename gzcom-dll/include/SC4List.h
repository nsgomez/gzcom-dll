#pragma once
#include "cIGZAllocatorService.h"
#include "GZServPtrs.h"
#include <functional>
#include <type_traits>

template<typename T>
struct SC4ListNode
{
	SC4ListNode<T>* next;
	SC4ListNode<T>* prev;
	T value;
};

template <typename T>
struct SC4ListIterator
{
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T;
	using pointer = T*;
	using reference = T&;

	SC4ListIterator(SC4ListNode<T>* node) : pNode(node)
	{
	}

	~SC4ListIterator()
	{
	}

	reference operator*() const
	{
		return pNode->value;
	}

	pointer operator->()
	{
		if constexpr (std::is_pointer_v<T>)
		{
			return pNode->value;
		}
		else
		{
			return &pNode->value;
		}
	}

	// Prefix increment
	SC4ListIterator& operator++()
	{
		pNode = pNode->next;
		return *this;
	}

	// Postfix increment
	SC4ListIterator operator++(int)
	{
		SC4ListIterator tmp = *this;
		++(*this);
		return tmp;
	}

	friend bool operator== (const SC4ListIterator& a, const SC4ListIterator& b)
	{
		return a.pNode == b.pNode;
	};
	friend bool operator!= (const SC4ListIterator& a, const SC4ListIterator& b)
	{
		return a.pNode != b.pNode;
	};

	SC4ListNode<T>* pNode;
};

template <typename T>
struct SC4ListConstIterator
{
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T;
	using pointer = const T*;
	using reference = const T&;

	SC4ListConstIterator(SC4ListNode<T>* node) : pNode(node)
	{
	}

	~SC4ListConstIterator()
	{
	}

	reference operator*() const
	{
		return pNode->value;
	}

	pointer operator->()
	{
		if constexpr (std::is_pointer_v<T>)
		{
			return pNode->value;
		}
		else
		{
			return &pNode->value;
		}
	}

	// Prefix increment
	SC4ListConstIterator& operator++()
	{
		pNode = pNode->next;
		return *this;
	}

	// Postfix increment
	SC4ListConstIterator operator++(int)
	{
		SC4ListIterator tmp = *this;
		++(*this);
		return tmp;
	}

	friend bool operator== (const SC4ListConstIterator& a, const SC4ListConstIterator& b)
	{
		return a.pNode == b.pNode;
	};
	friend bool operator!= (const SC4ListConstIterator& a, const SC4ListConstIterator& b)
	{
		return a.pNode != b.pNode;
	};

	SC4ListNode<T>* pNode;
};

template <typename T>
class SC4List
{
public:
	using const_iterator = SC4ListConstIterator<T>;
	using iterator = SC4ListIterator<T>;

	SC4List()
	{
		auto internalRoot = internal_root();

		root.next = internalRoot;
		root.prev = internalRoot;
	}

	SC4List(const SC4List<T>& other)
	{
		auto internalRoot = internal_root();

		root.next = internalRoot;
		root.prev = internalRoot;
		operator=(other);
	}

	SC4List(SC4List<T>&& other) = delete;

	~SC4List()
	{
		auto internalRoot = internal_root();
		auto entry = root.next;

		while (entry != internalRoot)
		{
			auto nextEntry = entry->next;

			destroy_node(entry);

			entry = nextEntry;
		}

		root.next = internalRoot;
		root.prev = internalRoot;
	}

	SC4List<T>& operator=(const SC4List<T>& other)
	{
		auto internalRoot = other.internal_root();
		auto entry = other.root.next;

		while (entry != internalRoot)
		{
			auto nextEntry = entry->next;

			push_back(entry->value);

			if constexpr (std::is_base_of_v<cIGZUnknown, std::remove_pointer_t<T>>)
			{
				if constexpr (std::is_pointer_v<T>)
				{
					entry->value->AddRef();
				}
				else
				{
					entry->value.AddRef();
				}
			}

			entry = nextEntry;
		}

		return *this;
	}

	SC4List<T>& operator=(SC4List<T>&& other) = delete;

	iterator begin()
	{
		return iterator(root.next);
	}

	iterator end()
	{
		return iterator(internal_root());
	}

	const_iterator begin() const
	{
		return const_iterator(root.next);
	}

	const_iterator end() const
	{
		return const_iterator(const_cast<SC4ListNode<T>*>(internal_root()));
	}

	const_iterator cbegin() const
	{
		return const_iterator(root.next);
	}

	const_iterator cend() const
	{
		return const_iterator(const_cast<SC4ListNode<T>*>(internal_root()));
	}

	bool empty() const
	{
		return root.next == internal_root();
	}

	iterator erase(iterator position)
	{
		SC4ListNode<T>* pNextNode = position.pNode->next;
		SC4ListNode<T>* pPrevNode = position.pNode->prev;

		pPrevNode->next = pNextNode;
		pNextNode->prev = pPrevNode;

		destroy_node(position.pNode);

		position.pNode = pNextNode;

		return position;
	}

	iterator insert(iterator position, T& value)
	{
		SC4ListNode<T>* newNode = create_node(value);

		SC4ListNode<T>* pNode = position.pNode;
		SC4ListNode<T>* pPrevNode = pNode->prev;

		newNode->next = pNode;
		newNode->prev = pPrevNode;
		pPrevNode->next = newNode;
		pNode->prev = newNode;

		return iterator(newNode);
	}

	void push_back(T& value)
	{
		insert(end(), value);
	}

	void push_front(T& value)
	{
		insert(begin(), value);
	}

	size_t size() const
	{
		size_t size = 0;

		auto internalRoot = internal_root();
		auto entry = root.next;

		while (entry != internalRoot)
		{
			auto nextEntry = entry->next;

			++size;

			entry = nextEntry;
		}

		return size;
	}

private:
	static SC4ListNode<T>* create_node(T& value)
	{
		cIGZAllocatorServicePtr allocator;

		auto ptr = static_cast<SC4ListNode<T>*>(allocator->Allocate(sizeof(SC4ListNode<T>)));

		if (!ptr)
		{
			throw std::bad_alloc();
		}

		ptr->value = value;
		return ptr;
	}

	static void destroy_node(SC4ListNode<T>* node)
	{
		cIGZAllocatorServicePtr allocator;

		destroy_value(node->value);

		allocator->Deallocate(node);
	}

	static void destroy_value(T& item)
	{
		if constexpr (std::is_pointer_v<T>)
		{
			T ptr = item;

			if (ptr)
			{
				if constexpr (std::is_base_of_v<cIGZUnknown, std::remove_pointer_t<T>>)
				{
					ptr->Release();
				}
				else
				{
					ptr->~T();
				}
			}
		}
		else
		{
			if constexpr (std::is_base_of_v<cIGZUnknown, T>)
			{
				item.Release();
			}
			else
			{
				item.~T();
			}
		}
	}

	SC4ListNode<T>* internal_root()
	{
		return &root;
	}

	const SC4ListNode<T>* internal_root() const
	{
		return &root;
	}

	SC4ListNode<T> root;
};
