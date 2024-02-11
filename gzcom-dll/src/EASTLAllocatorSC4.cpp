#include "EASTLConfigSC4.h"
#include <EASTL/internal/config.h>
#include <EASTL/allocator.h>

#include "cIGZAllocatorService.h"
#include "cRZSysServPtr.h"

// This file implements an EASTL allocator that uses SC4's internal memory pool.

namespace eastl
{
	allocator::allocator(const char* EASTL_NAME(pName))
	{
#if EASTL_NAME_ENABLED
		mpName = pName ? pName : "eastl_allocator_sc4";
#endif
	}


	allocator::allocator(const allocator& EASTL_NAME(alloc))
	{
#if EASTL_NAME_ENABLED
		mpName = alloc.mpName;
#endif
	}


	allocator::allocator(const allocator&, const char* EASTL_NAME(pName))
	{
#if EASTL_NAME_ENABLED
		mpName = pName ? pName : "eastl_allocator_sc4";
#endif
	}


	allocator& allocator::operator=(const allocator& EASTL_NAME(alloc))
	{
#if EASTL_NAME_ENABLED
		mpName = alloc.mpName;
#endif
		return *this;
	}


	const char* allocator::get_name() const
	{
#if EASTL_NAME_ENABLED
		return mpName;
#else
		return "eastl_allocator_sc4";
#endif
	}

	void allocator::set_name(const char* EASTL_NAME(pName))
	{
#if EASTL_NAME_ENABLED
		mpName = pName;
#endif
	}

	void* allocator::allocate(size_t n, int flags)
	{
		cRZSysServPtr<cIGZAllocatorService, 988069547ul, 988069539ul> allocatorService;

		return allocatorService->Allocate(n);
	}

	void* allocator::allocate(size_t n, size_t alignment, size_t offset, int flags)
	{
		EA_UNUSED(offset); EA_UNUSED(flags);

		size_t adjustedAlignment = (alignment > EA_PLATFORM_PTR_SIZE) ? alignment : EA_PLATFORM_PTR_SIZE;

		size_t totalAlignedPointerSize = n + adjustedAlignment + EA_PLATFORM_PTR_SIZE;

		cRZSysServPtr<cIGZAllocatorService, 988069547ul, 988069539ul> allocatorService;

		void* p = allocatorService->Allocate(n);

		if (!p)
		{
			return NULL;
		}

		void* pPlusPointerSize = (void*)((uintptr_t)p + EA_PLATFORM_PTR_SIZE);
		void* pAligned = (void*)(((uintptr_t)pPlusPointerSize + adjustedAlignment - 1) & ~(adjustedAlignment - 1));

		void** pStoredPtr = (void**)pAligned - 1;
		EASTL_ASSERT(pStoredPtr >= p);
		*(pStoredPtr) = p;

		EASTL_ASSERT(((size_t)pAligned & ~(alignment - 1)) == (size_t)pAligned);

		return pAligned;
	}

	void allocator::deallocate(void* p, size_t)
	{
		cRZSysServPtr<cIGZAllocatorService, 988069547ul, 988069539ul> allocatorService;

		allocatorService->Deallocate(p);
	}


	bool operator==(const allocator&, const allocator&)
	{
		return true; // All allocators are considered equal, as they use SC4's internal allocator.
	}

	bool operator!=(const allocator&, const allocator&)
	{
		return false; // All allocators are considered equal, as they SC4's internal allocator.
	}

	/// gDefaultAllocator
	/// Default global allocator instance.
	EASTL_API allocator   gDefaultAllocator;
	EASTL_API allocator* gpDefaultAllocator = &gDefaultAllocator;

	EASTL_API allocator* GetDefaultAllocator()
	{
		return gpDefaultAllocator;
	}

	EASTL_API allocator* SetDefaultAllocator(allocator* pAllocator)
	{
		allocator* const pPrevAllocator = gpDefaultAllocator;
		gpDefaultAllocator = pAllocator;
		return pPrevAllocator;
	}
} // namespace eastl