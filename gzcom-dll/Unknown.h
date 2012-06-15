#include "stdafx.h"
#ifndef UNKNOWN_H
	#define UNKNOWN_H

	// Unknown class derived from IGZ classes
	class cIGZUnknown
	{
		public:
			cIGZUnknown();
			~cIGZUnknown();

		public:
			virtual bool     QueryInterface( DWORD riid, void** ppvObj );
			virtual uint32_t AddRef();
			virtual uint32_t Release();
			virtual uint32_t RemoveRef();
			virtual uint32_t RefCount();

		protected:
			uint32_t mnRefCount;
	};

#endif