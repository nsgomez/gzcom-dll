///////////////////////////////////////////////////////////////////////////////
// RZCOMDirector.cpp
//
// Maintained by Paul Pedriana and Greg Kearney.
//
// Copyright (c) 1996 Maxis, Inc. -- All Rights Reserved World Wide.
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// Include files
//
#include <Rizzo.h>
#ifndef IGZCOM_H
   #include <IGZCOM.h>
#endif
#ifndef RZCOMDIRECTOR_H
   #include <RZCOMDirector.h>
#endif
#ifndef RZDEBUGHELP_H
   #include <RZDebugHelp.h>
#endif
#ifndef AUTHOR_H
   #include <author.h>
#endif



///////////////////////////////////////////////////////////////////////////////
// Debug Stuff
//
#if defined(MASTER_DEBUG) && defined(DEBUG_RZCOMDIRECTOR) //You can define this in your author file or your environment variables.
   #define DEBUG_LOCAL
#endif
#ifdef DEBUG_LOCAL
   #define DEBUG_OUTPUT_LOCAL RZ_DEBUG_OUTPUT
   #define ASSERT_LOCAL       RZ_ASSERT
#else
   #define DEBUG_OUTPUT_LOCAL RZ_SWALLOW_ARGS
   #define ASSERT_LOCAL(x)
#endif
///////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////
// GZDllGetGZCOMDirector
//
// The method returns a pointer to the controling or main GZCOM director 
// within this link module.
//
extern "C" RZ_DLLEXPORT cIGZCOMDirector* GZDllGetGZCOMDirector();


///////////////////////////////////////////////////////////////////////////////
// GZCOM
//
cIGZCOM* GZCOM(){
   return RZGetCOMDllDirector()->GZCOM();
}


///////////////////////////////////////////////////////////////////////////////
// GZDllGetGZCOMDirector
//
RZ_DLLEXPORT cIGZCOMDirector* GZDllGetGZCOMDirector(){
   return RZGetCOMDllDirector();
}



///////////////////////////////////////////////////////////////////////////////
// cRZCOMDllDirector
//
cRZCOMDllDirector::cRZCOMDllDirector()
   :  mnRefCount(0),
      mDirectorID(0),
      msLibraryPath(),
      mpCOM(NULL),
      mpFrameWork(NULL),
      mChildDirectorArray(),
      mClassObjectMap()
{
   //Empty
}


///////////////////////////////////////////////////////////////////////////////
// ~cRZCOMDllDirector
//
cRZCOMDllDirector::~cRZCOMDllDirector() 
{
   //Empty
}


///////////////////////////////////////////////////////////////////////////////
// QueryInterface
//
bool cRZCOMDllDirector::QueryInterface( GZREFIID riid, void** ppvObj)
{
   switch (riid) {
      case kGZIID_cIGZCOMDirector:
         *ppvObj = static_cast<cIGZCOMDirector*>(this); 
         AddRef(); 
         return true; 
      case GZIID_cIGZFrameWorkHooks:
         (*ppvObj) = static_cast<cIGZFrameWorkHooks*>(this);
         AddRef();
         return true;
      case GZIID_cIGZUnknown:
         *ppvObj = static_cast<cIGZUnknown*>(static_cast<cIGZCOMDirector*>(this));
         AddRef();
         return true;
   } 
   return false;
}


///////////////////////////////////////////////////////////////////////////////
// FrameWork
//
// Return a pointer to the framework.  This pointer is set up during
// InitializeFramework through COM.
//
cIGZFrameWork* cRZCOMDllDirector::FrameWork()
{
   return mpFrameWork;
}


///////////////////////////////////////////////////////////////////////////////
// AddRef
//
// Increment the global reference count
//
Uint32 cRZCOMDllDirector::AddRef()
{
   return ++mnRefCount;
}


///////////////////////////////////////////////////////////////////////////////
// Release
//
// The default for release is to NOT delete the director at any time.
// Directors are NOT stack objects but are usually statically defined.
//
Uint32 cRZCOMDllDirector::Release()
{
   return RemoveRef();
}


///////////////////////////////////////////////////////////////////////////////
// RemoveRef
//
// Decrement the global reference count
//
Uint32 cRZCOMDllDirector::RemoveRef()
{
   RZ_ASSERT(mnRefCount > 0);
   if(mnRefCount > 0)
      --mnRefCount;
   return mnRefCount;
}


///////////////////////////////////////////////////////////////////////////////
// RefCount
//
// Return the global reference count
//
Uint32 cRZCOMDllDirector::RefCount()
{
   return mnRefCount;
}


///////////////////////////////////////////////////////////////////////////////
// InitializeCOM
//
// Provides the initializtion of the cIGZCOMDirector for use by cGZCOM.
//
bool cRZCOMDllDirector::InitializeCOM(cIGZCOM* pCOM, const cIGZString& sLibraryPath)
{
   if(pCOM){
      mpCOM         = pCOM;
      mpFrameWork   = pCOM->FrameWork();
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


///////////////////////////////////////////////////////////////////////////////
// OnStart
//
bool cRZCOMDllDirector::OnStart(cIGZCOM* pCOM)
{
   return true;
}


///////////////////////////////////////////////////////////////////////////////
// OnStart
//
// Gets an instance of a class ID that is defined in your dll.
//
bool cRZCOMDllDirector::GetClassObject(GZCLSID clsid, GZREFIID iid, void** ppvObj)
{
    // Check to see if it's in one of our list of directors (recursive / linear)
   for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it){
      cRZCOMDllDirector* const pDirector = *it;

      // Recursively call GetClassObject for every director that
      // is a child of this director
      if(pDirector->GetClassObject(clsid, iid, ppvObj))
         return true; // successfully created the object!
   }

   // Check to see if the class is in this director.
   ClassObjectMap::iterator it2 = mClassObjectMap.find(clsid);
   if(it2 != mClassObjectMap.end()){
      FactoryFuncRecord& ffr = (*it2).second;

      switch(ffr.second){
         case kFactorFunctionType1:{
            FactoryFunctionPtr1 const ffp1 = (FactoryFunctionPtr1)ffr.first;
            cIGZUnknown*        const pObj = ffp1(); // call the create method

            // obtain the requested interface
            if(pObj->QueryInterface(iid, ppvObj))
               return true;

            // Interface not found, release and return
            pObj->AddRef();   // this ref. Adding a ref, so the release should
            pObj->Release();  // delete the object.
            break;
         }

         case kFactorFunctionType2:{
            FactoryFunctionPtr2 ffp2 = (FactoryFunctionPtr2)ffr.first;
            return ffp2(iid, ppvObj);
         }

         default:
            RZ_ASSERT(false);
       }
   }
   return false;
}


///////////////////////////////////////////////////////////////////////////////
// EnumClassObjects
//
// Enumerate all CLSIDs
//
void cRZCOMDllDirector::EnumClassObjects(ClassObjectEnumerationCallback pCallback, void* pContext)
{
   // Register our list of directors
   for(ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it){
      cRZCOMDllDirector* const pDirector = *it;

      //Recursively call EnumClassObjects for every director that is a child of this director.
      pDirector->EnumClassObjects(pCallback, pContext);
   }

   // Register classes in this director
   for(ClassObjectMap::iterator it2(mClassObjectMap.begin()); it2 != mClassObjectMap.end(); ++it2){
      const GZCLSID classID = (*it2).first;
      pCallback(classID, 0, pContext);
   }
}


///////////////////////////////////////////////////////////////////////////////
// GetLibraryPath
//
// Return the name of this module.
//
bool cRZCOMDllDirector::GetLibraryPath(cIGZString& sLibraryPath)
{
   sLibraryPath.FromChar(msLibraryPath.data(), msLibraryPath.length()); 
   return true;
}


///////////////////////////////////////////////////////////////////////////////
// AddDirector
//
// Add a DLL Director to the current DLL Director's list.
//
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


///////////////////////////////////////////////////////////////////////////////
// CanUnloadNow
//
// Whether it is safe to unload this DLL or not.
// The default behavior is that we are safe if and only if
// the global reference count of objects is zero.
//
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


///////////////////////////////////////////////////////////////////////////////
// GetHeapAllocatedSize
//
// This function gets the allocated heap size for the given dynamic library. 
//
Uint32 cRZCOMDllDirector::GetHeapAllocatedSize()
{
   //We simply call RZGetHeapAllocatedSize. In doing so we are assuming that 
   //this code is executing from the dynamic library itself.
   return RZGetHeapAllocatedSize();
}


///////////////////////////////////////////////////////////////////////////////
// AddCls
//
// Add a class ID.
// This should be called for every class in your DLL director in the ctor
// or OnStart() of your DLL director (thus the function is not virtual).
//
// Parameters -
// clsid : the class ID
// pffx  : a callback function that creates or returns an instance
//    of the given class.
//
void cRZCOMDllDirector::AddCls( GZCLSID clsid, cRZCOMDllDirector::FactoryFunctionPtr1 pff1)
{
   ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
   RZ_ASSERT(it == mClassObjectMap.end());

   const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff1), kFactorFunctionType1));
   mClassObjectMap.insert(entry);
}


void cRZCOMDllDirector::AddCls( GZCLSID clsid, cRZCOMDllDirector::FactoryFunctionPtr2 pff2)
{
   ClassObjectMap::iterator it(mClassObjectMap.find(clsid));
   RZ_ASSERT(it == mClassObjectMap.end());

   const ClassObjectMap::value_type entry(clsid, FactoryFuncRecord(DummyFunctionPtr(pff2), kFactorFunctionType2));
   mClassObjectMap.insert(entry);
}


///////////////////////////////////////////////////////////////////////////////
// cIGZFrameWorkHooks functions
//
cIGZCOM* cRZCOMDllDirector::GZCOM()
{
   return mpCOM;
}


///////////////////////////////////////////////////////////////////////////////
// cIGZFrameWorkHooks functions
//
bool cRZCOMDllDirector::PreFrameWorkInit()
{
   return true;
}
bool cRZCOMDllDirector::PreAppInit()
{
   return true;
}
bool cRZCOMDllDirector::PostAppInit()
{
   return true;
}
bool cRZCOMDllDirector::PreAppShutdown()
{
   return true;
}
bool cRZCOMDllDirector::PostAppShutdown()
{
   return true;
}
bool cRZCOMDllDirector::PostSystemServiceShutdown()
{
   return true;
}
bool cRZCOMDllDirector::AbortiveQuit()
{
   return true;
}

bool cRZCOMDllDirector::OnInstall()
{
   return true;
}