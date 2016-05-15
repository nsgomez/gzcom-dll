#pragma once
#include "cIGZUnknown.h"

class cIGZCOM;
class cIGZFrameWork;
class cIGZString;
class cRZCOMDllDirector;

// This class was guessed from Paul Pedriana's released code. It seems alright
// for the most part, but it's mostly uncertain whether or not to include the
// RemoveRef and RefCount pure methods, and where exactly they should go. Note
// that they definitely do not belong to cIGZUnknown.
class cIGZCOMDirector : public cIGZUnknown
{
	public:
		typedef void(*ClassObjectEnumerationCallback)(uint32_t, int, void*);

		virtual bool InitializeCOM(cIGZCOM* pCOM, const cIGZString& sLibraryPath) = 0;
		virtual bool GetLibraryPath(cIGZString& sLibraryPath) = 0;
		virtual bool OnStart(cIGZCOM* pCOM) = 0;
		virtual bool GetClassObject(uint32_t rclsid, uint32_t riid, void** ppbObj) = 0;
		virtual bool OnUnload(void) = 0;
		virtual cIGZFrameWork* FrameWork(void) = 0;
		virtual cIGZCOM* GZCOM(void) = 0;
		virtual void EnumClassObjects(ClassObjectEnumerationCallback pCallback, void* pContext) = 0;

		virtual bool CanUnloadNow(void) = 0;
		virtual void AddDirector(cRZCOMDllDirector* pCOMDirector) = 0;
		virtual uint32_t GetHeapAllocatedSize(void) = 0;

	public:
		virtual uint32_t RemoveRef(void) = 0;
		virtual uint32_t RefCount(void) = 0;
};