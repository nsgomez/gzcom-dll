#include "stdafx.h"
#include "gzcom-dll.h"
#include "RZCOM.h"

cRZCOMDllDirector::cRZCOMDllDirector()
	: mnRefCount(0),
	  mDirectorID(0),
	  msLibraryPath(),
	  mpCOM(NULL),
	  mpFrameWork(NULL),
	  mChildDirectorArray(),
	  mClassObjectMap()
{
	DebugMessageBox( "cRZCOMDllDirector spawn" );
	// Empty
}

cRZCOMDllDirector::~cRZCOMDllDirector()
{
	DebugMessageBox( "cRZCOMDllDirector destroy" );
	// Empty
}

bool cRZCOMDllDirector::QueryInterface( DWORD riid, void** ppvObj )
{
	DebugMessageBox( "cRZCOMDllDirector::QueryInterface" );
	switch( riid )
	{
		// need to get back to this
		case 0x8675309:
		default:
			break;
	}

	char buf[64];
	sprintf_s( buf, 64, "QueryInterface -- %i", riid );
	DebugMessageBox( buf );

	return false;
}

cIGZFrameWork* cRZCOMDllDirector::FrameWork()
{
	DebugMessageBox( "cRZCOMDllDirector::FrameWork" );
	return mpFrameWork;
}

uint32_t cRZCOMDllDirector::AddRef()
{
	DebugMessageBox( "cRZCOMDllDirector::AddRef" );
	++mnRefCount;

	char buf[64];
	sprintf_s( buf, 64, "mnRefCount = %i", mnRefCount );
	DebugMessageBox( buf );

	return mnRefCount;
}

uint32_t cRZCOMDllDirector::Release()
{
	DebugMessageBox( "cRZCOMDllDirector::Release" );
	return RemoveRef();
}

uint32_t cRZCOMDllDirector::RemoveRef()
{
	DebugMessageBox( "cRZCOMDllDirector::RemoveRef" );
	if( mnRefCount > 0 )
		--mnRefCount;

	char buf[64];
	sprintf_s( buf, 64, "mnRefCount = %i", mnRefCount );
	DebugMessageBox( buf );

	return mnRefCount;
}

uint32_t cRZCOMDllDirector::RefCount()
{
	DebugMessageBox( "cRZCOMDllDirector::RefCount" );

	char buf[64];
	sprintf_s( buf, 64, "mnRefCount = %i", mnRefCount );
	DebugMessageBox( buf );

	return mnRefCount;
}

bool cRZCOMDllDirector::InitializeCOM(cIGZCOM* pCOM, const std::string& sLibraryPath)
{
	DebugMessageBox( "cRZCOMDllDirector::InitializeCOM" );
	if(pCOM)
	{
		DebugMessageBox
		(
			"cRZCOMDllDirector::InitializeCOM\n"
			"\n"
			"pCOM exists."
		);

		mpCOM         = pCOM;
		mpFrameWork	  = pCOM->FrameWork();
		msLibraryPath = sLibraryPath;

		DebugMessageBox
		(
			"cRZCOMDllDirector::InitializeCOM\n"
			"\n"
			"Faked our way out of pCOM->FrameWork()"
		);

		for(ChildDirectorArray::iterator it = mChildDirectorArray.begin(); it != mChildDirectorArray.end(); ++it)
		{
			// Recursively call InitializeCOM for every director that is a child of this director.
			cRZCOMDllDirector* const pDirector = *it;
			pDirector->InitializeCOM(pCOM, sLibraryPath);
		}

		DebugMessageBox( "cRZCOMDllDirector::InitializeCOM had a happy ending." );
		return true;
	}

	DebugMessageBox( "cRZCOMDllDirector::InitializeCOM passed an empty pCom" );
	return false;
}

bool cRZCOMDllDirector::OnStart(cIGZCOM* pCOM)
{
	DebugMessageBox( "cRZCOMDllDirector::OnStart" );
	return true;
}

bool cRZCOMDllDirector::GetClassObject(DWORD clsid, DWORD iid, void** ppvObj)
{
	DebugMessageBox( "cRZCOMDllDirector::GetClassObject (start)" );

	 // Check to see if it's in one of our list of directors (recursive / linear)
	for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it)
	{
		cRZCOMDllDirector* const pDirector = *it;

		// Recursively call GetClassObject for every director that
		// is a child of this director
		if(pDirector->GetClassObject(clsid, iid, ppvObj))
		{
			DebugMessageBox( "cRZCOMDllDirector::GetClassObject found object, done." );
			return true; // successfully created the object!
		}
	}

	DebugMessageBox( "cRZCOMDllDirector::GetClassObject no class object" );

	// Check to see if the class is in this director.
	ClassObjectMap::iterator it2 = mClassObjectMap.find(clsid);
	if(it2 != mClassObjectMap.end())
	{
		DebugMessageBox( "cRZCOMDllDirector::GetClassObject expecting a show, failure anticipated" );
		FactoryFuncRecord& ffr = (*it2).second;

		switch(ffr.second)
		{
			case kFactorFunctionType1:
			{
				FactoryFunctionPtr1 const ffp1 = (FactoryFunctionPtr1)ffr.first;
				DebugMessageBox( "cRZCOMDllDirector::GetClassObject calling for cIGZUnknown" );
				cIGZUnknown * const pObj = ffp1(); // call the create method
				DebugMessageBox( "cRZCOMDllDirector::GetClassObject looked for cIGZUnknown" );

				// obtain the requested interface
				if(pObj->QueryInterface(iid, ppvObj))
				{
					DebugMessageBox( "cRZCOMDllDirector::GetClassObject found interface a" );
					return true;
				}

				DebugMessageBox( "cRZCOMDllDirector::GetClassObject failed pObj->QueryInterface" );

				// Interface not found, release and return
				pObj->AddRef();	  // this ref. Adding a ref, so the release should
				pObj->Release();  // delete the object.

				DebugMessageBox( "cRZCOMDllDirector::GetClassObject released interface a" );
				break;
			}

			case kFactorFunctionType2:
			{
				DebugMessageBox( "cRZCOMDllDirector::GetClassObject calling for FactoryFunctionPtr2" );
				FactoryFunctionPtr2 ffp2 = (FactoryFunctionPtr2)ffr.first;
				return ffp2(iid, ppvObj);
			}

			default:
				DebugMessageBox( "cRZCOMDllDirector::GetClassObject -- wait, where the hell are we?" );
				break;
		 }
	}

	DebugMessageBox( "cRZCOMDllDirector::GetClassObject ending empty-handed" );
	return false;
}

void cRZCOMDllDirector::EnumClassObjects(ClassObjectEnumerationCallback pCallback, void* pContext)
{
	DebugMessageBox( "cRZCOMDllDirector::EnumClassObjects" );

	// Register our list of directors
	for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it)
	{
		cRZCOMDllDirector* const pDirector = *it;

		//Recursively call EnumClassObjects for every director that is a child of this director.
		pDirector->EnumClassObjects(pCallback, pContext);
	}

	DebugMessageBox( "cRZCOMDllDirector::EnumClassObjects done registering." );

	// Register classes in this director
	for(ClassObjectMap::iterator it2(mClassObjectMap.begin()); it2 != mClassObjectMap.end(); ++it2)
	{
		const DWORD classID = (*it2).first;

		DebugMessageBox( "cRZCOMDllDirector::EnumClassObjects attempting ClassObjectEnumerationCallback" );
		pCallback(classID, 0, pContext);
	}

	DebugMessageBox( "cRZCOMDllDirector::EnumClassObjects done" );
}

bool cRZCOMDllDirector::GetLibraryPath(std::string& sLibraryPath)
{
	// Well, nothing to do here
	DebugMessageBox
	(
		"cRZCOMDllDirector::GetLibraryPath expected to fail.\n"
		"No implementation of SC4's string class exists.\n"
		"\n"
		"Returning true without doing anything..."
	);

	return true;
}

void cRZCOMDllDirector::AddDirector(cRZCOMDllDirector* pCOMDirector)
{
	DebugMessageBox( "cRZCOMDllDirector::AddDirector" );

	// Initialize the New director's COM parameters
	pCOMDirector->InitializeCOM(GZCOM(), msLibraryPath);
	DebugMessageBox( "cRZCOMDllDirector::AddDirector attempted pCOMDirector->InitializeCOM" );

	// First, add all of the DLL director's directors
	for(ChildDirectorArray::iterator it(pCOMDirector->mChildDirectorArray.begin()); it != pCOMDirector->mChildDirectorArray.end(); ++it)
	{
		cRZCOMDllDirector* const pCOMDirectorTemp = *it;

		// Recursively call AddDirector for every director that is a child of the given director.
		AddDirector(pCOMDirectorTemp);
	}

	DebugMessageBox( "cRZCOMDllDirector::AddDirector done iterating." );

	// Now, add the DLL director
	mChildDirectorArray.push_back(pCOMDirector);
	DebugMessageBox( "cRZCOMDllDirector::AddDirector adding DLL director. Done." );
}

bool cRZCOMDllDirector::CanUnloadNow()
{
	DebugMessageBox( "cRZCOMDllDirector::CanUnloadNow" );

	//If we can unload...
	if(mnRefCount == 0)
	{
		// Recursively call CanUnloadNow for every director that is
		// a child of this director. As soon as a false result is
		// reported, we cannot unload.
		for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it)
		{
			DebugMessageBox( "cRZCOMDllDirector::CanUnloadNow iterator call" );
			cRZCOMDllDirector* const pCOMDirectorTemp = *it;
			if(!pCOMDirectorTemp->CanUnloadNow())
			{
				DebugMessageBox( "cRZCOMDllDirector::CanUnloadNow denying unload" );
				return false;
			}
		}
	}

	DebugMessageBox( "cRZCOMDllDirector::CanUnloadNow permitting unload" );
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

	DebugMessageBox( "cRZCOMDllDirector::GetHeapAllocatedSize not implemented. Returning -1..." );
	return -1;
}

void cRZCOMDllDirector::AddCls( DWORD clsid, cRZCOMDllDirector::FactoryFunctionPtr1 pff1)
{
	DebugMessageBox( "cRZCOMDllDirector::AddCls(1) executed." );
	
	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	DebugMessageBox( "cRZCOMDllDirector::AddCls(1) obtained iterator handle." );

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff1), kFactorFunctionType1));
	mClassObjectMap.insert(entry);
	
	DebugMessageBox( "cRZCOMDllDirector::AddCls(1) added instance." );
}

void cRZCOMDllDirector::AddCls( DWORD clsid, cRZCOMDllDirector::FactoryFunctionPtr2 pff2)
{
	DebugMessageBox( "cRZCOMDllDirector::AddCls(2) executed." );

	ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
	DebugMessageBox( "cRZCOMDllDirector::AddCls(2) obtained iterator handle." );

	const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff2), kFactorFunctionType2));
	mClassObjectMap.insert(entry);

	DebugMessageBox( "cRZCOMDllDirector::AddCls(2) added instance." );
}

cIGZCOM* cRZCOMDllDirector::GZCOM()
{
	DebugMessageBox( "cRZCOMDllDirector::GZCOM has no known implementation. Cross your fingers." );
	return mpCOM;
}

bool cRZCOMDllDirector::PreFrameWorkInit()          { DebugMessageBox( "cRZCOMDllDirector::PreFrameWorkInit" ); return true; }
bool cRZCOMDllDirector::PreAppInit()                { DebugMessageBox( "cRZCOMDllDirector::PreAppInit" ); return true; }
bool cRZCOMDllDirector::PostAppInit()               { DebugMessageBox( "cRZCOMDllDirector::PostAppInit" ); return true; }
bool cRZCOMDllDirector::PreAppShutdown()            { DebugMessageBox( "cRZCOMDllDirector::PreAppShutdown" ); return true; }
bool cRZCOMDllDirector::PostAppShutdown()           { DebugMessageBox( "cRZCOMDllDirector::PostAppShutdown" ); return true; }
bool cRZCOMDllDirector::PostSystemServiceShutdown() { DebugMessageBox( "cRZCOMDllDirector::PostSystemServiceShutdown" ); return true; }
bool cRZCOMDllDirector::AbortiveQuit()              { DebugMessageBox( "cRZCOMDllDirector::AbortiveQuit" ); return true; }
bool cRZCOMDllDirector::OnInstall()	                { DebugMessageBox( "cRZCOMDllDirector::OnInstall" ); return true; }