#include "../include/cIGZCOM.h"
#include "../include/cIGZString.h"
#include "../include/cRZCOMDllDirector.h"
#include <assert.h>
#include <Windows.h>

extern "C" __declspec(dllexport) cIGZCOMDirector* GZDllGetGZCOMDirector(void) {
	return static_cast<cIGZCOMDirector*>(RZGetCOMDllDirector());
}

cIGZCOM* GZCOM(void) {
	return RZGetCOMDllDirector()->GZCOM();
}

cRZCOMDllDirector::cRZCOMDllDirector(void)
	: mnRefCount(0),
	  mDirectorID(0),
	  msLibraryPath(),
	  mpCOM(nullptr),
	  mpFrameWork(nullptr),
	  mChildDirectorArray(),
	  mClassObjectMap()
{
	// Empty
}

cRZCOMDllDirector::~cRZCOMDllDirector(void) {
	// Empty
}

bool cRZCOMDllDirector::QueryInterface(uint32_t riid, void** ppvObj) {
	MessageBoxA(NULL, "Director: QueryInterface()", NULL, MB_OK);
	switch (riid) {
		case kGZIID_cIGZCOMDirector:
			*ppvObj = static_cast<cIGZCOMDirector*>(this);
			AddRef();
			return true;

		case GZIID_cIGZFrameWorkHooks:
			*ppvObj = static_cast<cIGZFrameWorkHooks*>(this);
			AddRef();
			return true;

		case GZIID_cIGZUnknown:
			*ppvObj = static_cast<cIGZUnknown*>(static_cast<cIGZCOMDirector*>(this));
			AddRef();
			return true;
	}

	return false;
}

cIGZFrameWork* cRZCOMDllDirector::FrameWork() {
	MessageBoxA(NULL, "Director: FrameWork()", NULL, MB_OK);
	return mpFrameWork;
}

uint32_t cRZCOMDllDirector::AddRef() {
	MessageBoxA(NULL, "Director: AddRef()", NULL, MB_OK);
	return ++mnRefCount;
}

uint32_t cRZCOMDllDirector::Release() {
	MessageBoxA(NULL, "Director: Release()", NULL, MB_OK);
//	return RemoveRef();
	assert(mnRefCount > 0);
	if (mnRefCount > 0) {
		--mnRefCount;
	}

	return mnRefCount;
}

uint32_t cRZCOMDllDirector::RemoveRef() {
	MessageBoxA(NULL, "Director: RemoveRef()", NULL, MB_OK);
	assert(mnRefCount > 0);
	if (mnRefCount > 0) {
		--mnRefCount;
	}

	return mnRefCount;
}

uint32_t cRZCOMDllDirector::RefCount() {
	MessageBoxA(NULL, "Director: RefCount()", NULL, MB_OK);
	return mnRefCount;
}

bool cRZCOMDllDirector::InitializeCOM(cIGZCOM* pCOM, const cIGZString& sLibraryPath) {
	if (pCOM != nullptr) {
		mpCOM = pCOM;
		mpFrameWork = pCOM->FrameWork();
		msLibraryPath = sLibraryPath;

		char test[64];
		sprintf_s(test, "%08X", mpFrameWork);
		//MessageBoxA(NULL, test, NULL, MB_OK);

		for (ChildDirectorArray::iterator it = mChildDirectorArray.begin(); it != mChildDirectorArray.end(); ++it) {
			cRZCOMDllDirector* const pDirector = *it;
			pDirector->InitializeCOM(pCOM, sLibraryPath);
		}

		return true;
	}

	return false;
}

bool cRZCOMDllDirector::OnStart(cIGZCOM* pCOM) {
	return true;
}

bool cRZCOMDllDirector::GetClassObject(uint32_t clsid, uint32_t iid, void** ppvObj) {
	MessageBoxA(NULL, "Director: GetClassObject()", NULL, MB_OK);
	for (ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it) {
		cRZCOMDllDirector* const pDirector = *it;
		if (pDirector->GetClassObject(clsid, iid, ppvObj)) {
			return true;
		}
	}

	ClassObjectMap::iterator it2 = mClassObjectMap.find(clsid);
	if (it2 != mClassObjectMap.end()) {
		FactoryFuncRecord& ffr = (*it2).second;
		switch (ffr.second) {
			case kFactorFunctionType1: {
				FactoryFunctionPtr1 const ffp1 = (FactoryFunctionPtr1)ffr.first;
				cIGZUnknown*        const pObj = ffp1();
				if (pObj->QueryInterface(iid, ppvObj)) {
					return true;
				}

				pObj->AddRef();
				pObj->Release();
				break;
			}

			case kFactorFunctionType2: {
				FactoryFunctionPtr2 ffp2 = (FactoryFunctionPtr2)ffr.first;
				return ffp2(iid, ppvObj);
			}

			default:
				assert(false);
		}
	}

	return false;
}

void cRZCOMDllDirector::EnumClassObjects(ClassObjectEnumerationCallback pCallback, void* pContext) {
	MessageBoxA(NULL, "Director: EnumClassObjects()", NULL, MB_OK);
	for (ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it) {
		cRZCOMDllDirector* const pDirector = *it;
		pDirector->EnumClassObjects(pCallback, pContext);
	}

	for (ClassObjectMap::iterator it2(mClassObjectMap.begin()); it2 != mClassObjectMap.end(); ++it2) {
		const uint32_t classID = (*it2).first;
		pCallback(classID, 0, pContext);
	}
}

bool cRZCOMDllDirector::GetLibraryPath(cIGZString& sLibraryPath) {
	MessageBoxA(NULL, "Director: GetLibraryPath()", NULL, MB_OK);
	sLibraryPath = msLibraryPath;
	return true;
}

void cRZCOMDllDirector::AddDirector(cRZCOMDllDirector* pCOMDirector) {
	MessageBoxA(NULL, "Director: AddDirector()", NULL, MB_OK);
	pCOMDirector->InitializeCOM(GZCOM(), msLibraryPath);
	for (ChildDirectorArray::iterator it(pCOMDirector->mChildDirectorArray.begin()); it != pCOMDirector->mChildDirectorArray.end(); ++it) {
		cRZCOMDllDirector* const pCOMDirectorTemp = *it;
		AddDirector(pCOMDirectorTemp);
	}

	mChildDirectorArray.push_back(pCOMDirector);
}

bool cRZCOMDllDirector::CanUnloadNow() {
	MessageBoxA(NULL, "Director: CanUnloadNow()", NULL, MB_OK);
	if (mnRefCount == 0) {
		for (ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it) {
			cRZCOMDllDirector* const pCOMDirectorTemp = *it;
			if (!pCOMDirectorTemp->CanUnloadNow()) {
				return false;
			}
		}
	}

	return true;
}

uint32_t cRZCOMDllDirector::GetHeapAllocatedSize(void) {
	// TODO
	MessageBoxA(NULL, "Director: GetHeapAllocatedSize()", NULL, MB_OK);
	return 0;
}

void cRZCOMDllDirector::AddCls(uint32_t clsid, cRZCOMDllDirector::FactoryFunctionPtr1 pff1) {
	MessageBoxA(NULL, "Director: AddCls(pff1)", NULL, MB_OK);
	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	assert(it == mClassObjectMap.end());

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff1), kFactorFunctionType1));
	mClassObjectMap.insert(entry);
}

void cRZCOMDllDirector::AddCls(uint32_t clsid, cRZCOMDllDirector::FactoryFunctionPtr2 pff2) {
	MessageBoxA(NULL, "Director: AddCls(pff2)", NULL, MB_OK);
	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	assert(it == mClassObjectMap.end());

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff2), kFactorFunctionType2));
	mClassObjectMap.insert(entry);
}

cIGZCOM* cRZCOMDllDirector::GZCOM() {
	MessageBoxA(NULL, "Director: GZCOM()", NULL, MB_OK);
	return mpCOM;
}

bool cRZCOMDllDirector::PreFrameWorkInit() { return true; }
bool cRZCOMDllDirector::PreAppInit() { return true; }
bool cRZCOMDllDirector::PostAppInit() { return true; }
bool cRZCOMDllDirector::PreAppShutdown() { return true; }
bool cRZCOMDllDirector::PostAppShutdown() { return true; }
bool cRZCOMDllDirector::PostSystemServiceShutdown() { return true; }
bool cRZCOMDllDirector::AbortiveQuit() { return true; }
bool cRZCOMDllDirector::OnInstall() { return true; }