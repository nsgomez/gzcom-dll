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
	DebugMessageBox( "z0" );
	// Empty
}

cRZCOMDllDirector::~cRZCOMDllDirector()
{
	DebugMessageBox( "z-1" );
	// Empty
}

bool cRZCOMDllDirector::QueryInterface( DWORD riid, void** ppvObj )
{
	DebugMessageBox( "z3" );
	switch( riid )
	{
		// need to get back to this
		case 0x8675309:
		default:
			break;
	}

	char buf[64];
	sprintf( buf, "QueryInterface -- %i", riid );
	DebugMessageBox( buf );

	return false;
}

// unknown: cIGZFrameWork*, replaced with void*
void* cRZCOMDllDirector::FrameWork()
{
	DebugMessageBox( "z1" );
	return mpFrameWork;
}

DWORD cRZCOMDllDirector::AddRef()
{
	DebugMessageBox( "z2a" );
	++mnRefCount;

	char buf[64];
	sprintf( buf, "z2b -- mnRefCount = %i", mnRefCount );
	DebugMessageBox( buf );

	return mnRefCount;
}

DWORD cRZCOMDllDirector::Release()
{
	DebugMessageBox( "z4" );
	return RemoveRef();
}

DWORD cRZCOMDllDirector::RemoveRef()
{
	DebugMessageBox( "z5a" );
	if( mnRefCount > 0 )
		--mnRefCount;

	DebugMessageBox( "z5b" );
	return mnRefCount;
}

DWORD cRZCOMDllDirector::RefCount()
{
	DebugMessageBox( "z6" );
	return mnRefCount;
}

bool cRZCOMDllDirector::InitializeCOM(cIGZCOM* pCOM, const std::string& sLibraryPath)
{
	DebugMessageBox( "CRITICAL HIT." );
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
	DebugMessageBox( "z7" );
	return true;
}

bool cRZCOMDllDirector::GetClassObject(DWORD clsid, DWORD iid, void** ppvObj)
{
	DebugMessageBox( "z8a" );
	 // Check to see if it's in one of our list of directors (recursive / linear)
	for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it)
	{
		cRZCOMDllDirector* const pDirector = *it;

		// Recursively call GetClassObject for every director that
		// is a child of this director
		if(pDirector->GetClassObject(clsid, iid, ppvObj))
			return true; // successfully created the object!
	}
	DebugMessageBox( "z8b" );

	// Check to see if the class is in this director.
	ClassObjectMap::iterator it2 = mClassObjectMap.find(clsid);
	if(it2 != mClassObjectMap.end())
	{
		DebugMessageBox( "z8c, failure anticipated" );
		FactoryFuncRecord& ffr = (*it2).second;

		switch(ffr.second)
		{
			case kFactorFunctionType1:
			{
				FactoryFunctionPtr1 const ffp1 = (FactoryFunctionPtr1)ffr.first;

				// unknown: cIGZUnknown*, replaced with void*
				DebugMessageBox( "z8d1 nulled" );
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
				DebugMessageBox( "z8d2 unknown outcome" );
				FactoryFunctionPtr2 ffp2 = (FactoryFunctionPtr2)ffr.first;
				return ffp2(iid, ppvObj);
			}

			default:
				DebugMessageBox( "z8d3 unknown outcome" );
				assert(false);
		 }
	}
	DebugMessageBox( "z8e" );
	return false;
}

// unknown: ClassObjectEnumerationCallback in pCallback, replaced with void*
void cRZCOMDllDirector::EnumClassObjects(void* pCallback, void* pContext)
{
	DebugMessageBox( "z9" );
	// Register our list of directors
	for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it)
	{
		cRZCOMDllDirector* const pDirector = *it;

		//Recursively call EnumClassObjects for every director that is a child of this director.
		pDirector->EnumClassObjects(pCallback, pContext);
	}
	DebugMessageBox( "z10" );

	// Register classes in this director
	for(ClassObjectMap::iterator it2(mClassObjectMap.begin()); it2 != mClassObjectMap.end(); ++it2)
	{
		const DWORD classID = (*it2).first;
		//pCallback(classID, 0, pContext);
	}

	DebugMessageBox( "z11" );
}

bool cRZCOMDllDirector::GetLibraryPath(std::string& sLibraryPath)
{
	// Well, nothing to do here
	DebugMessageBox( "z12 anticipated failure" );
	return true;
}

void cRZCOMDllDirector::AddDirector(cRZCOMDllDirector* pCOMDirector)
{
	DebugMessageBox( "z13a" );
	// Initialize the New director's COM parameters
	pCOMDirector->InitializeCOM(GZCOM(), msLibraryPath);
	DebugMessageBox( "z13b" );

	// First, add all of the DLL director's directors
	for(ChildDirectorArray::iterator it(pCOMDirector->mChildDirectorArray.begin()); it != pCOMDirector->mChildDirectorArray.end(); ++it){
		cRZCOMDllDirector* const pCOMDirectorTemp = *it;

		//Recursively call AddDirector for every director that is a child of the given director.
		AddDirector(pCOMDirectorTemp);
	}

	DebugMessageBox( "z13c" );
	// Now, add the DLL director
	mChildDirectorArray.push_back(pCOMDirector);
	DebugMessageBox( "z13d" );
}

bool cRZCOMDllDirector::CanUnloadNow()
{
	DebugMessageBox( "z14a" );
	if(mnRefCount == 0){ //If we can unload...
		// Recursively call CanUnloadNow for every director that is
		// a child of this director. As soon as a false result is
		// reported, we cannot unload.
		for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it){
			DebugMessageBox( "z14b-it" );
			cRZCOMDllDirector* const pCOMDirectorTemp = *it;
			if(!pCOMDirectorTemp->CanUnloadNow())
				return false;
		}
	}
	DebugMessageBox( "z14c" );

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

	DebugMessageBox( "z15 anticipated failure" );
	return -1;
}

void cRZCOMDllDirector::AddCls( DWORD clsid, cRZCOMDllDirector::FactoryFunctionPtr1 pff1)
{
	DebugMessageBox( "z16a" );
	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	assert(it == mClassObjectMap.end());
	DebugMessageBox( "z16b" );

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff1), kFactorFunctionType1));
	mClassObjectMap.insert(entry);
	DebugMessageBox( "z16c" );
}

void cRZCOMDllDirector::AddCls( DWORD clsid, cRZCOMDllDirector::FactoryFunctionPtr2 pff2)
{
	DebugMessageBox( "z17a" );
	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	assert(it == mClassObjectMap.end());
	DebugMessageBox( "z17b" );

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff2), kFactorFunctionType2));
	mClassObjectMap.insert(entry);
	DebugMessageBox( "z17c" );
}

cIGZCOM* cRZCOMDllDirector::GZCOM()
{
	DebugMessageBox( "z18 anticipated failure" );
	return mpCOM;
}

bool cRZCOMDllDirector::PreFrameWorkInit()          { return true; }
bool cRZCOMDllDirector::PreAppInit()                { return true; }
bool cRZCOMDllDirector::PostAppInit()               { return true; }
bool cRZCOMDllDirector::PreAppShutdown()            { return true; }
bool cRZCOMDllDirector::PostAppShutdown()           { return true; }
bool cRZCOMDllDirector::PostSystemServiceShutdown() { return true; }
bool cRZCOMDllDirector::AbortiveQuit()              { return true; }
bool cRZCOMDllDirector::OnInstall()	                { return true; }