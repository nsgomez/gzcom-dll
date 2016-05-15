#pragma once
#include "cIGZUnknown.h"

class cIGZCOMDirector;
class cIGZString;

// Mostly guessed as to what this interface includes.
class cIGZCOMLibrary : public cIGZUnknown
{
	public:
		virtual bool Load(void) = 0;
		virtual bool Free(void) = 0;
		virtual bool IsLoaded(void) const = 0;
		virtual void SetLoaded(bool bUse) = 0;
		/*virtual bool GetPath(cIGZString& szCopyTo) = 0;
		virtual cIGZCOMDirector* GetDirector(void) = 0;
		//virtual int operator<(cIGZCOMLibrary const&) = 0;
		virtual bool IsLoaded(void) = 0;
		virtual uintptr_t GetHandle(void) = 0;*/
};