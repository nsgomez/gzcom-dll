#pragma once
#include "cIGZUnknown.h"

class cGZCOMLibrary;
class cIGZCOMLibrary;
class cIGZFrameWork;
class cIGZString;

// The prototypes here should be fine but the ordering and inclusion of
// methods is again a best-guess effort that probably isn't accurate.
class cIGZCOM : public cIGZUnknown
{
	public:
		// COM is maintained in the system service list; however,
		// it initialized and shutdown separately from the rest.
		/*virtual bool RealInit() = 0;
		virtual void RealShutdown() = 0;*/
		virtual bool OnInstall() = 0;
		virtual cIGZFrameWork* FrameWork() = 0;
		virtual bool UpdateClassRegistry(cGZCOMLibrary& lib) = 0;

		virtual bool GetClassObject(uint32_t clsid, uint32_t iid, void** ppvObj) = 0;
		virtual bool GetLibObject(cGZCOMLibrary& lib, uint32_t clsid, uint32_t iid, void** ppvObj) = 0;

		// FreeUnusedLibraries unloads any DLLs that have been loaded by cGZCOM::LoadLibrary but 
		// are no longer in use. Applications should call this function periodically to free resources, 
		// either at the top of their message loop or in some idle-time task.
		virtual void FreeUnusedLibraries() = 0;
		virtual void FreeAllLibraries() = 0;
		virtual bool CanUnloadLibrary(cGZCOMLibrary& lib) = 0;
		/*virtual bool CreateGuid(uint32_t* pGuid) = 0;
		virtual bool CreateGuids(uint32_t pGuidArray[], uint32_t nCount) = 0;*/
		virtual bool AddLibrary(const cIGZString& sPath) = 0;

		//Library enumeration
		typedef bool(*GZCOMLibraryIterationFunction)(cGZCOMLibrary*, void*);
		virtual uint32_t EnumerateLibraries(cIGZCOMLibrary* pLibraries[], uint32_t& nCount) = 0;
		virtual void EnumerateLibraries(GZCOMLibraryIterationFunction iterationFunction, void* pContext) = 0;

		//cIGZCOM
};