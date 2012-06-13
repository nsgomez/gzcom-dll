#include "stdafx.h"
#ifndef RZCOM_H
	#include "RZCOM.h"
#endif

cRZCOMDllDirector::cRZCOMDllDirector()
	: mnRefCount(0),
	  mDirectorID(0),
	  msLibraryPath(),
	  mpCOM(NULL),
	  mpFrameWork(NULL),
	  mChildDirectorArray(),
	  mClassObjectMap()
{
	// Empty
}

cRZCOMDllDirector::~cRZCOMDllDirector()
{
	// Empty
}

bool cRZCOMDllDirector::QueryInterface( DWORD riid, void** ppvObj )
{
	switch( riid )
	{
		// need to get back to this
		case 0x8675309:
		default:
			break;
	}

	char buf[64];
	sprintf( buf, "QueryInterface -- %i", riid );
	MessageBoxA( NULL, buf, "GZCOM DLL", MB_OK | MB_ICONINFORMATION );

	return false;
}

// unknown: cIGZFrameWork*, replaced with void*
void* cRZCOMDllDirector::FrameWork()
{
	return mpFrameWork;
}

DWORD cRZCOMDllDirector::AddRef()
{
	return ++mnRefCount;
}

DWORD cRZCOMDllDirector::Release()
{
	return RemoveRef();
}

DWORD cRZCOMDllDirector::RemoveRef()
{
	if( mnRefCount > 0 )
		--mnRefCount;

	return mnRefCount;
}

DWORD cRZCOMDllDirector::RefCount()
{
	return mnRefCount;
}

bool cRZCOMDllDirector::InitializeCOM(cIGZCOM* pCOM, const std::string& sLibraryPath)
{
	if(pCOM)
	{
		mpCOM			= pCOM;
		mpFrameWork	= /*pCOM->FrameWork()*/ NULL;
		msLibraryPath = sLibraryPath;

		for(ChildDirectorArray::iterator it = mChildDirectorArray.begin(); it != mChildDirectorArray.end(); ++it){
			// Recursively call InitializeCOM for every director that is a child of this director.
			cRZCOMDllDirector* const pDirector = *it;
			pDirector->InitializeCOM(pCOM, sLibraryPath);
		}

		return true;
	}

	return false;
}

bool cRZCOMDllDirector::OnStart(cIGZCOM* pCOM)
{
	return true;
}

bool cRZCOMDllDirector::GetClassObject(DWORD clsid, DWORD iid, void** ppvObj)
{
	 // Check to see if it's in one of our list of directors (recursive / linear)
	for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it)
	{
		cRZCOMDllDirector* const pDirector = *it;

		// Recursively call GetClassObject for every director that
		// is a child of this director
		if(pDirector->GetClassObject(clsid, iid, ppvObj))
			return true; // successfully created the object!
	}

	// Check to see if the class is in this director.
	ClassObjectMap::iterator it2 = mClassObjectMap.find(clsid);
	if(it2 != mClassObjectMap.end())
	{
		FactoryFuncRecord& ffr = (*it2).second;

		switch(ffr.second)
		{
			case kFactorFunctionType1:
			{
				FactoryFunctionPtr1 const ffp1 = (FactoryFunctionPtr1)ffr.first;

				// unknown: cIGZUnknown*, replaced with void*
				void* const pObj = ffp1(); // call the create method

				// obtain the requested interface
				/*if(pObj->QueryInterface(iid, ppvObj))
					return true;

				// Interface not found, release and return
				pObj->AddRef();	// this ref. Adding a ref, so the release should
				pObj->Release();  // delete the object.*/
				break;
			}

			case kFactorFunctionType2:
			{
				FactoryFunctionPtr2 ffp2 = (FactoryFunctionPtr2)ffr.first;
				return ffp2(iid, ppvObj);
			}

			default:
				assert(false);
		 }
	}
	return false;
}

// unknown: ClassObjectEnumerationCallback in pCallback, replaced with void*
void cRZCOMDllDirector::EnumClassObjects(void* pCallback, void* pContext)
{
	// Register our list of directors
	for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it)
	{
		cRZCOMDllDirector* const pDirector = *it;

		//Recursively call EnumClassObjects for every director that is a child of this director.
		pDirector->EnumClassObjects(pCallback, pContext);
	}

	// Register classes in this director
	for(ClassObjectMap::iterator it2(mClassObjectMap.begin()); it2 != mClassObjectMap.end(); ++it2)
	{
		const DWORD classID = (*it2).first;
		//pCallback(classID, 0, pContext);
	}
}

bool cRZCOMDllDirector::GetLibraryPath(std::string& sLibraryPath)
{
	// Well, nothing to do here
	return true;
}

void cRZCOMDllDirector::AddDirector(cRZCOMDllDirector* pCOMDirector)
{
	// Initialize the New director's COM parameters
	pCOMDirector->InitializeCOM(GZCOM(), msLibraryPath);

	// First, add all of the DLL director's directors
	for(ChildDirectorArray::iterator it(pCOMDirector->mChildDirectorArray.begin()); it != pCOMDirector->mChildDirectorArray.end(); ++it){
		cRZCOMDllDirector* const pCOMDirectorTemp = *it;

		//Recursively call AddDirector for every director that is a child of the given director.
		AddDirector(pCOMDirectorTemp);
	}

	// Now, add the DLL director
	mChildDirectorArray.push_back(pCOMDirector);
}

bool cRZCOMDllDirector::CanUnloadNow()
{
	if(mnRefCount == 0){ //If we can unload...
		// Recursively call CanUnloadNow for every director that is
		// a child of this director. As soon as a false result is
		// reported, we cannot unload.
		for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it){
			cRZCOMDllDirector* const pCOMDirectorTemp = *it;
			if(!pCOMDirectorTemp->CanUnloadNow())
				return false;
		}
	}

	return true;
}

DWORD cRZCOMDllDirector::GetHeapAllocatedSize()
{
	// No idea what the hell I'm doing. This line alone will
	//	  probably cause millions of adverse side effects, which
	//	  may include:
	//			- Nausea
	//			- Dizziness
	//			- Drowsiness
	//			- Upset stomach
	//			- Fatigue
	//			- Suicidal thoughts
	//			- Numbness of face
	//			- Increased blood pressure
	//			- Increased risk of heart attack or stroke
	//			- Projectile vomit
	//			- Explosive diarhhea
	//
	//	  Please consult your doctor before using GetHeapAllocatedSize()
	return -1;
}

void cRZCOMDllDirector::AddCls( DWORD clsid, cRZCOMDllDirector::FactoryFunctionPtr1 pff1)
{
	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	assert(it == mClassObjectMap.end());

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff1), kFactorFunctionType1));
	mClassObjectMap.insert(entry);
}

void cRZCOMDllDirector::AddCls( DWORD clsid, cRZCOMDllDirector::FactoryFunctionPtr2 pff2)
{
	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	assert(it == mClassObjectMap.end());

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff2), kFactorFunctionType2));
	mClassObjectMap.insert(entry);
}

cIGZCOM* cRZCOMDllDirector::GZCOM()
{
	return mpCOM;
}

bool cRZCOMDllDirector::PreFrameWorkInit()			 { return true; }
bool cRZCOMDllDirector::PreAppInit()					 { return true; }
bool cRZCOMDllDirector::PostAppInit()					{ return true; }
bool cRZCOMDllDirector::PreAppShutdown()				{ return true; }
bool cRZCOMDllDirector::PostAppShutdown()			  { return true; }
bool cRZCOMDllDirector::PostSystemServiceShutdown() { return true; }
bool cRZCOMDllDirector::AbortiveQuit()				  { return true; }
bool cRZCOMDllDirector::OnInstall()					  { return true; }