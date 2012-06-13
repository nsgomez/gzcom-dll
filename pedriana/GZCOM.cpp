///////////////////////////////////////////////////////////////////////////////
// GZCOM.cpp
//
// Maintained by Paul Pedriana and Greg Kearney.
//
// Copyright (c) 1996 Maxis, Inc. -- All Rights Reserved World Wide.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Include files
//
#include <Gonzo.h>
#ifndef GZCOM_H
   #include <GZCOM.h>
#endif
#ifndef RZCOMDIRECTOR_H
   #include <RZCOMDirector.h>
#endif
#ifndef RZTIME_H
   #include <RZTime.h>
#endif
#ifndef RZDATE_H
   #include <RZDate.h>
#endif
#ifndef RZLOCK_H
   #include <RZLock.h>
#endif
#ifndef RZTHREAD_H
   #include <RZThread.h>
#endif
#ifndef AUTHOR_H
   #include <author.h>
#endif

#ifdef RZ_HAS_DLOPEN
   #include <dlfcn.h>
#endif


///////////////////////////////////////////////////////////////////////////////
// Debug Stuff
//
#if defined(MASTER_DEBUG) && defined(DEBUG_GZCOM) //You can define this in your author file or your environment variables.
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
// Constants
//
// There really isn't much flexibility for this to change without modifying
// RZCOMDirector source code. But we define it as a constant for consistency
// here anyway.
const RZChar kCOMDirectorFunctionName[] = RZText("GZDllGetGZCOMDirector");




///////////////////////////////////////////////////////////////////////////////
// Win32 helper functions
//
#if defined(_WIN32) && !defined(UNIX_WINE)

   //We place Win32 library load code in separate functions because the compiler
   //doesn't like functions using both C++ EH and Win32 SEH.

   static bool GZCOMLoadLibrary(cIGZCOMLibrary::GZLibraryHandle& handle, const RZChar* pPathA){
      #ifdef _MSC_VER
         __try {
            handle = ::LoadLibrary(pPathA);
         }
         __except (EXCEPTION_EXECUTE_HANDLER) {
            return false;
         }
      #else
         handle = ::LoadLibrary(pPathA);
      #endif

      return true;
   }

   static bool GZCOMLoadLibraryW(cIGZCOMLibrary::GZLibraryHandle& handle, const Uint16* pPathW){
      #ifdef _MSC_VER
         __try {
            handle = ::LoadLibraryW(pPathW);     // LoadLibraryW() is present in Windows 95/98 even if it doesn't work.
         }
         __except (EXCEPTION_EXECUTE_HANDLER) {
            return false;
         }
      #else
         handle = ::LoadLibraryW((const WCHAR*)pPathW);
      #endif

      return true;
   }

   static void GZCOMFreeLibrary(HINSTANCE handle, const RZChar* pPath){
      #ifdef _MSC_VER
         __try {
            ::FreeLibrary(handle); 
         }
         __except (EXCEPTION_EXECUTE_HANDLER) {
            RZ_DEBUG_OUTPUT("cGZCOMLibrary::Free(): Error unloading library %s.\n", pPath);
         }
      #else
         pPath;
         ::FreeLibrary(handle); 
      #endif
   }

   static bool GZCOMGetProcAddress(cIGZCOMDirector *(*&pfn)(), const cIGZCOMLibrary::GZLibraryHandle& handle, const RZChar *ppfnName){
      #ifdef _MSC_VER
         __try {
            pfn = (cIGZCOMDirector *(*)()) ::GetProcAddress( static_cast<HINSTANCE>(handle), ppfnName);
         }
         __except (EXCEPTION_EXECUTE_HANDLER) {
            return false;
         }
      #else
         pfn = (cIGZCOMDirector *(*)()) ::GetProcAddress( static_cast<HINSTANCE>(handle), ppfnName);
      #endif

      return true;
   }

#endif




///////////////////////////////////////////////////////////////////////////////
// cGZCOMLibrary
//
cGZCOMLibrary::cGZCOMLibrary() 
   :  mbLoaded(false),
      mnRefCount(0),
      mpDirector(NULL),
      msLibraryPath(),
      mHandle(NULL) 
{
   //Empty
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOMLibrary
//
cGZCOMLibrary::cGZCOMLibrary(const cIGZString& sLibraryPath)
   :  mbLoaded(false),
      mnRefCount(0),
      mpDirector(NULL),
      msLibraryPath(sLibraryPath),
      mHandle(NULL) 
{
   //Empty
}


///////////////////////////////////////////////////////////////////////////////
// QueryInterface
//
bool cGZCOMLibrary::QueryInterface(GZREFIID riid, void** ppvObj){
   if(riid == kGZIID_cIGZCOMLibrary){
      *ppvObj = static_cast<cIGZCOMLibrary*>(this);
      AddRef();
      return true;
   }
   else if(riid == GZIID_cIGZUnknown){
      *ppvObj = static_cast<cIGZUnknown*>(this);
      AddRef();
      return true;
   }
   return false;
}


///////////////////////////////////////////////////////////////////////////////
// AddRef
//
Uint32 cGZCOMLibrary::AddRef(){
   return ++mnRefCount;
}


///////////////////////////////////////////////////////////////////////////////
// Release
//
Uint32 cGZCOMLibrary::Release(){
   RZ_ASSERT(mnRefCount > 0);
   return --mnRefCount; //Note that we don't delete ourselves. Only our owner can do that.
}


///////////////////////////////////////////////////////////////////////////////
// Load
//
bool cGZCOMLibrary::Load()
{
   if(!mbLoaded){
      cRZString sOSEncodedPath;

      ::ConvertStringEncoding(msLibraryPath, sOSEncodedPath, kCodePageSystem);

      ///////////////////////////////////////////////////////////////
      //Platform-specific dynamic library loading
      //
      #if defined(K_WIN32)

         bool bCriticalFailure = false;

         #if defined(_UTF16)
            bCriticalFailure = !::GZCOMLoadLibrary(mHandle, sOSEncodedPath.c_str());
         #else
            if(::GetVersion() & 0x80000000)     //Windows 95/98/ME -- use ANSI path
               bCriticalFailure = !::GZCOMLoadLibrary(mHandle, sOSEncodedPath.c_str());
            else{
               Uint32                        nWideLength = msLibraryPath.size();
               std::vector<RZUnicodeChar>    widePath(nWideLength+1);

               ::ConvertStringEncoding(msLibraryPath, &widePath[0], nWideLength, kCodePageUTF16);
               widePath[nWideLength] = 0;

               bCriticalFailure = !::GZCOMLoadLibraryW(mHandle, &widePath[0]);
            }
         #endif

         if(bCriticalFailure){
            RZ_DEBUG_OUTPUT("cGZCOMLibrary::Load() Error loading library %s\n", msLibraryPath.c_str() );
         }

         if(!mHandle){ //If the library load failed...
            cRZString sFailureMessage;
            RZChar*   pWin32Message = NULL;

            ::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                            NULL, GetLastError(),
                            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&pWin32Message, 0, NULL); 

            if(pWin32Message){
               sFailureMessage.Sprintf(RZText("Failed to load the requested dll \"%s\"\nWindows error message - \"%s\""), sOSEncodedPath.c_str(), pWin32Message);
               RZ_ASSERT_MESSAGE(false, sFailureMessage.c_str());
               ::LocalFree(pWin32Message);
            }
            return false;
         }

      #elif defined(RZ_HAS_DLOPEN)
         try {
            mHandle = ::dlopen(sOSEncodedPath.c_str(), RTLD_NOW);
         }
         catch(...){
            RZ_DEBUG_OUTPUT("cGZCOMLibrary::Load() Error loading library %s\n", msLibraryPath.c_str() );
         }

         if(!mHandle){ //If the library load failed...
            cRZString sFailureMessage;
            const char* const pdlError = dlerror();

            sFailureMessage.Sprintf("Failed to load the requested dll '%s' (%s)\n", msLibraryPath.c_str(), pdlError);
            RZ_ASSERT_MESSAGE(false, sFailureMessage.c_str());
            return false;
         }

      #else
         RZ_ASSERT(false);
      #endif
      ///////////////////////////////////////////////////////////////

      // Mark the library as loaded. 
      mbLoaded = true;

      // Get the com director accessor method. GZCOM will perform all necessary 
      // functions via the GZCOMDirector.
      typedef cIGZCOMDirector *(*FunctionTypeGD)();
      FunctionTypeGD pfn = NULL;

      ///////////////////////////////////////////////////////////////
      //Platform-specific dynamic library loading
      //
      #if defined(K_WIN32)
         if (!::GZCOMGetProcAddress( pfn, static_cast<HINSTANCE>(mHandle), kCOMDirectorFunctionName)){
            RZ_DEBUG_OUTPUT("cGZCOMLibrary::Load() Library %s does not have function %s(). Presumably it's not a GZCOM DLL.\n", kCOMDirectorFunctionName, msLibraryPath.c_str() );
         }

      #elif defined(RZ_HAS_DLOPEN)
         try {
            pfn = (FunctionTypeGD) ::dlsym(mHandle, kCOMDirectorFunctionName);
         }
         catch(...){
            RZ_DEBUG_OUTPUT("cGZCOMLibrary::Load() Library %s does not have function %s(). Presumably it's not a GZCOM DLL.\n", kCOMDirectorFunctionName, msLibraryPath.c_str() );
         }

      #else
         RZ_ASSERT(false);
      #endif
      ///////////////////////////////////////////////////////////////

      //Check if the function was found in the library. If not, it may not be a problem as the
      //library may simply not be one that we want to use. 
      if(!pfn){
         RZ_DEBUG_OUTPUT("cGZCOMLibrary::Load: The function '%s()' was not found in library: \"%s\"\n", kCOMDirectorFunctionName, msLibraryPath.c_str());

         Free();
         return false;
      }

      //Call the COMDirector function 
      cIGZCOMDirector* const pCOMDirector = pfn();
      if(!pCOMDirector){
         cRZString sMessage;
         sMessage.Sprintf("cGZCOMLibrary::Load: Failed to aquire GZCOM director from library: \"%s\"\n", msLibraryPath.c_str());
         RZ_ASSERT_MESSAGE(false, sMessage.c_str());

         Free();
         return false;
      }

      RZ_ASSERT(!mpDirector);
      mpDirector = pCOMDirector;

      // Toss over a pointer to GZCOM .. provides the ability for the dll to 
      // call into the framework. Note: this function is called EVERY time 
      // the dll is loaded.
      if(!pCOMDirector->InitializeCOM(GZCOM(), msLibraryPath)){
         cRZString sMessage;
         sMessage.Sprintf("cGZCOMLibrary::Load: GZCOM Director failed initialization in library: \"%s\"\n", msLibraryPath.c_str());
         RZ_ASSERT_MESSAGE(false, sMessage.c_str());

         Free();
         return false;
      }
   }
   return true;
}


///////////////////////////////////////////////////////////////////////////////
// Free
//
bool cGZCOMLibrary::Free(){
   if(mbLoaded){
      DEBUG_OUTPUT_LOCAL("cGZCOMLibrary::Free: %s\n", msLibraryPath.c_str());

      if(mpDirector) 
         mpDirector = NULL;

      ///////////////////////////////////////////////////////////////
      //Platform-specific dynamic library unloading
      //
      #if defined(K_WIN32)
         ::GZCOMFreeLibrary(static_cast<HINSTANCE>(mHandle), msLibraryPath.ToChar());
      #elif defined(RZ_HAS_DLOPEN)
         ::dlclose(mHandle); 
      #else
         RZ_ASSERT(false);
      #endif
      ///////////////////////////////////////////////////////////////

      mHandle  = NULL;
      mbLoaded = false;
   }

   return true;
}


///////////////////////////////////////////////////////////////////////////////
// GetPath
//
void cGZCOMLibrary::GetPath(cIGZString& sPath) const{
   sPath.Copy(msLibraryPath);
}


///////////////////////////////////////////////////////////////////////////////
// SetPath
//
bool cGZCOMLibrary::SetPath(const cIGZString& sPath){
   if(!mbLoaded){
      msLibraryPath.Copy(sPath);
      return true;
   }
   return false;
}


///////////////////////////////////////////////////////////////////////////////
// GetDirector
//
cIGZCOMDirector* cGZCOMLibrary::GetDirector() const { 
   return mpDirector; 
}


///////////////////////////////////////////////////////////////////////////////
// SetDirector
//
void cGZCOMLibrary::SetDirector(cIGZCOMDirector* pDirector){
   if(pDirector != mpDirector){
      if(pDirector) 
         pDirector->AddRef();
      if(mpDirector)
         mpDirector->Release();
      mpDirector = pDirector;
   }
}


///////////////////////////////////////////////////////////////////////////////
// operator <
//
bool cGZCOMLibrary::operator< ( const cGZCOMLibrary& rhs ) const{
   cRZString sCompareLibraryPath;
   rhs.GetPath(sCompareLibraryPath);
   return (msLibraryPath < sCompareLibraryPath);
}


///////////////////////////////////////////////////////////////////////////////
// operator >
//
bool cGZCOMLibrary::operator> (const cGZCOMLibrary& rhs) const{
   cRZString sCompareLibraryPath;
   rhs.GetPath(sCompareLibraryPath);
   return (msLibraryPath > sCompareLibraryPath);
}


///////////////////////////////////////////////////////////////////////////////
// operator ==
//
bool cGZCOMLibrary::operator== (const cGZCOMLibrary& rhs) const{
   cRZString sCompareLibraryPath;
   rhs.GetPath(sCompareLibraryPath);
   return (msLibraryPath == sCompareLibraryPath);
}


///////////////////////////////////////////////////////////////////////////////
// IsLoaded
//
bool cGZCOMLibrary::IsLoaded() const{
   return mbLoaded;
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOMLibrary::SetLoaded
//
void cGZCOMLibrary::SetLoaded(bool bUse){
   mbLoaded = bUse;
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOMLibrary::SetHandle
//
void cGZCOMLibrary::SetHandle(GZLibraryHandle handle){
   mHandle = handle;
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOMLibrary::GetHandle
//
cIGZCOMLibrary::GZLibraryHandle cGZCOMLibrary::GetHandle() const{
   return mHandle;
}





///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////
// cGZCOM
//
cGZCOM::cGZCOM() :
   #ifndef _GZ_NO_SYSTEM_SERVICES
   cRZSystemService(kGZCLSID_cGZCOM, cIGZSystemService::kPriorityCOM),
   #endif
   mbInitialized(false),
   mnRefCount(0),
   mIDMap(),
   mLibraries(),
   mpCurrentLib(NULL),
   mpFramework(NULL),
   mpCOMDirector(NULL),
   mnNextGuidGenTime(0),
   mRandom()
{
   //Emtpy
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOM
//
cGZCOM::~cGZCOM(){
   RZ_ASSERT(!mbInitialized);
}


///////////////////////////////////////////////////////////////////////////////
// QueryInterface
//
bool cGZCOM::QueryInterface(GZREFIID riid, void** ppvObj){
   switch(riid){
      case kGZIID_cIGZCOM:
         *ppvObj = static_cast<cIGZCOM*>(this);
         AddRef();
         return true;
   }

   #ifdef _GZ_NO_SYSTEM_SERVICES
      return false;
   #else
      return cRZSystemService::QueryInterface(riid, ppvObj);
   #endif
}


///////////////////////////////////////////////////////////////////////////////
// AddRef
//
Uint32 cGZCOM::AddRef(){
   #ifdef _GZ_NO_SYSTEM_SERVICES
      return ++mnRefCount;
   #else
      return cRZSystemService::AddRef();
   #endif
}


///////////////////////////////////////////////////////////////////////////////
// Release
//
Uint32 cGZCOM::Release(){
   //What we do here is intentionally not decrement the reference count
   //and not call "delete this" if it drops to zero. This is because GZCOM
   //is intentionally designed to owned by the Framework and memory managed
   //as such.
   #ifdef _GZ_NO_SYSTEM_SERVICES
      return 1;
   #else
      return RemoveRef();
   #endif
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOM::Init
//
bool cGZCOM::Init(){
   if(!mbInitialized){
      //Do stuff here.

      //We intentionally don't set 'mbInitialized' to true here, 
      //as we wait for the RealInit to be called before doing so.
      //mbInitialized = true;
   }
   return true;
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOM::Shutdown
//
bool cGZCOM::Shutdown(){
   if(mbInitialized){
      //We intentionally don't set 'mbInitialized' to false here, 
      //as we wait for the RealShutdown to be called before doing so.
      //mbInitialized = true;

      //Do stuff here.
   }
   return true;
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOM::RealInit()
//
// System service initialization.
// Load the registry file into memory and set up the global framework object
// from the registry.
//
bool cGZCOM::RealInit(){
   if(!mbInitialized){
      //Get the Framework
      mpFramework = RZGetFramework(); //We don't AddRef this, as it is an app-wide singleton.
      RZ_ASSERT(mpFramework);

      //Get the COM director
      mpCOMDirector = RZGetCOMDllDirector();
      RZ_ASSERT(mpCOMDirector);

      //Get the app path name.
      cRZString sAppPath;
      ::RZGetCurrentAppPath(sAppPath); //Currently from RZXGlobal.h

      // Initialize the main exe COM directors
      if(mpCOMDirector->InitializeCOM(this, sAppPath)){
         mbInitialized = true;
         return true;
      }
      return false;
   }
   return true;
}



///////////////////////////////////////////////////////////////////////////////
// cGZCOM::RealShutdown()
//
// System service shutdown.
// Free all libraries currently loaded.
//
void cGZCOM::RealShutdown(){
   if(mbInitialized){
      FreeAllLibraries();
      mpFramework   = NULL;
      mbInitialized = false;
      //Caution below here, object is now dead 
   }
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOM::SetServiceRunning()
//
void cGZCOM::SetServiceRunning(bool bRunning){ 
   #ifdef _GZ_NO_SYSTEM_SERVICES
      //Do nothing.
   #else
      cRZSystemService::SetServiceRunning(bRunning);
   #endif
}


///////////////////////////////////////////////////////////////////////////////
// cGZCOM::AddLibrary
//
bool cGZCOM::AddLibrary(const cIGZString& sPath){
   cGZCOMLibrary lib(sPath);

   mCriticalSection.Lock();
   tLibraries::iterator it(mLibraries.find(lib));
   if(it != mLibraries.end()){ //If the library has already been added...
      mCriticalSection.Unlock();
      return true;
   }

   //The library is new, so added it to the library set.
   it = mLibraries.insert(lib).first;
   mCriticalSection.Unlock();

   cGZCOMLibrary& libInContainer = const_cast<cGZCOMLibrary&>(*it);
   if(UpdateClassRegistry(libInContainer)){
      cIGZCOMDirector* const pCOMDirector = libInContainer.GetDirector();
      RZ_ASSERT(pCOMDirector);
      if(pCOMDirector)
         pCOMDirector->OnStart(this);
      return true;
   }

   return false;
}



///////////////////////////////////////////////////////////////////////////////
// AddEntryCallback
//
// Must be Locked externally by caller.
//
void cGZCOM::AddEntryCallback(GZREFCLSID rclsid, Uint32 nVersion, void* pContext){
   cGZCOM* const pCOM = reinterpret_cast<cGZCOM*>(pContext);

   tIDMap::iterator it(pCOM->mIDMap.find(rclsid));                   // Look for an older version
   if((it != pCOM->mIDMap.end()) && ((*it).second.first < nVersion)) // If an older version found, replace old with new
      pCOM->mIDMap.erase(it); 
   pCOM->mIDMap.insert(pair<const GZCLSID, tClassObjectData>(rclsid, tClassObjectData(nVersion, pCOM->mpCurrentLib)));
}



///////////////////////////////////////////////////////////////////////////////
// GetClassObject
//
// Retrieve the given class ID, set it up with the given interface,
// and put it in the address buffer specified.
//
bool cGZCOM::GetClassObject(GZCLSID clsid, GZIID iid, void** ppvObj){
   mCriticalSection.Lock();

   tIDMap::iterator it = mIDMap.find(clsid);    // Find the class ID in our list.
   if(it == mIDMap.end()){                      // If the ID was not found...
      mCriticalSection.Unlock();

      // Make the framework a special exception to COM.
      if(clsid == GZCLSID_cGZFrameWork){
         RZ_ASSERT(mpFramework);
         return mpFramework->QueryInterface(iid, ppvObj);
      }

      // Return the app's main GetClassObject. COM directors do NOT contain
      // critical sections... they rely on GZCOM to ensure there threadsafeness.
      return mpCOMDirector->GetClassObject(clsid, iid, ppvObj); 
   }

   // Use the class ID to get the library,
   // Retrieve the object from the given library.
   cGZCOMLibrary* const pCOMLibrary = (*it).second.second;
   mCriticalSection.Unlock();

   return GetLibObject(*pCOMLibrary, clsid, iid, ppvObj);
}



///////////////////////////////////////////////////////////////////////////////
// GetLibObject
//
// Get the following class given its library, class ID, and interface ID.
//
bool cGZCOM::GetLibObject(cGZCOMLibrary& lib, GZCLSID clsid, GZIID iid, void** ppvObj){
   // If the library is not loaded and could not load the library
   if(!lib.IsLoaded() && !lib.Load()){
      RZ_ASSERT(false); // Could not load library
      return false;
   }

   cIGZCOMDirector* const pCOMDirector = lib.GetDirector();
   RZ_ASSERT(pCOMDirector);

   // Call the library's DllGetClassObject
   return pCOMDirector->GetClassObject(clsid, iid, ppvObj);
}




///////////////////////////////////////////////////////////////////////////////
// UpdateRegistry
//
// Registers all classes in a given library
//
bool cGZCOM::UpdateClassRegistry(cGZCOMLibrary& lib){
   // If the library isn't loaded in the first place fail... not catastrophic
   // could be a non-GZCOM dll --> Lib.Load() will fail in that event.
   if(lib.Load()){
      cIGZCOMDirector* const pCOMDirector = lib.GetDirector();
      RZ_ASSERT(pCOMDirector);

      // Call the module's EnumClassObjects. This is only called at the initial load.
      mCriticalSection.Lock();
      mpCurrentLib = &lib;
      pCOMDirector->EnumClassObjects(cGZCOM::AddEntryCallback, static_cast<cGZCOM*>(this));
      mCriticalSection.Unlock();

      return true;
   }
   return false;
}



///////////////////////////////////////////////////////////////////////////////
// FreeUnusedLibraries
//
// FreeUnusedLibraries unloads any DLLs that have been loaded by 
//   cGZCOM::LoadLibrary but are no longer in use. Applications should call 
//   this function periodically to free resources, either at the top of their 
//   message loop or in some idle-time task.
//
void cGZCOM::FreeUnusedLibraries(){   
   mCriticalSection.Lock();

   for(tLibraries::iterator it = mLibraries.begin(); it != mLibraries.end(); ++it){
      cGZCOMLibrary& library = const_cast<cGZCOMLibrary&>(*it);
      if(library.IsLoaded() && CanUnloadLibrary(library))
         library.Free();
   }

   mCriticalSection.Unlock();
}



///////////////////////////////////////////////////////////////////////////////
// FreeAllLibraries
//
// Frees all loaded libraries from GZCOM
//
void cGZCOM::FreeAllLibraries(){
   mCriticalSection.Lock();
   for(tLibraries::iterator it = mLibraries.begin(); it != mLibraries.end(); ++it){
      cGZCOMLibrary& library = const_cast<cGZCOMLibrary&>(*it);
      if(library.IsLoaded())
         library.Free();
   }
   mCriticalSection.Unlock();
}



///////////////////////////////////////////////////////////////////////////////
// CanUnloadLibrary
//
// Return whether a library is safe to be unloaded.
//
bool cGZCOM::CanUnloadLibrary(cGZCOMLibrary& lib){
   // If the library isn't loaded in the first place, return true
   if(lib.IsLoaded()){
      cIGZCOMDirector* const pCOMDirector = lib.GetDirector();
      RZ_ASSERT(pCOMDirector);
      return pCOMDirector->CanUnloadNow();
   }
   return true;
}



///////////////////////////////////////////////////////////////////////////////
// EnumerateLibraries
//
// Returns count of libraries returned. If you pass in NULL for the library 
// array, then the return value is the count of libraries available.
//
Uint32 cGZCOM::EnumerateLibraries(cIGZCOMLibrary* pLibraries[], Uint32& nCount){
   unsigned nActualLibraryCount(mLibraries.size());

   if(pLibraries){
      set<cGZCOMLibrary>::iterator it(mLibraries.begin());
      unsigned i(0);

      if(nCount > nActualLibraryCount)
         nCount = nActualLibraryCount;

      while(i < nCount){
         cGZCOMLibrary* const pLibrary = const_cast<cGZCOMLibrary*>(&(*it));
         pLibraries[i] = pLibrary;
         pLibraries[i]->AddRef();
         ++i;
         ++it;
      }
   }
   else{
      nCount = nActualLibraryCount;
   }

   return nCount;
}



///////////////////////////////////////////////////////////////////////////////
// EnumerateLibraries
//
// Enumerates libraries. They are not AddRefd in the call to you.
// 
void cGZCOM::EnumerateLibraries(GZCOMLibraryIterationFunction iterationFunction, void* pContext){
   if(iterationFunction){
      set<cGZCOMLibrary>::iterator it(mLibraries.begin());
      set<cGZCOMLibrary>::iterator itEnd(mLibraries.end());

      while(it != itEnd){
         cGZCOMLibrary* const pLibrary = const_cast<cGZCOMLibrary*>(&(*it));
         if(!iterationFunction(pLibrary, pContext))
            break;
         ++it;
      }
   }
}



///////////////////////////////////////////////////////////////////////////////
// OnInstall
//
// This function is -deprecated-.
//
bool cGZCOM::OnInstall()
{
   return true;
}



///////////////////////////////////////////////////////////////////////////////
// GetGuidGenSeconds
//
// See CreateGuid (directly below) for documenation.
//
static Uint32 GetGuidGenSeconds(){
   const cRZDate  dateBegin(2, 2, 1997);
   const cRZDate  dateToday;
   const cRZTime  timeNow;
   const Uint32   nDaysSinceBegin(dateToday - dateBegin);
   const Uint32   nSecondsSinceBegin(nDaysSinceBegin*86400 + 
                                     timeNow.Hour()*3600   + 
                                     timeNow.Minute()*60   +
                                     timeNow.Second());

   return nSecondsSinceBegin;
}



///////////////////////////////////////////////////////////////////////////////
// CreateGuid
//
// A GUID is a Uint32:
//   -------------------------------------------
//   | 3 bits        29 bits                   |
//   |-----------------------------------------|
//   | Random        Seconds since Feb 2, 1997 |
//   -------------------------------------------
//
// 29 bits of information is good for 17 years of unique seconds.
// Because there are 3 bits of randomness, the result is that with every 
// second that passes there are 8 new GUIDs that can exist. If you call
// this function more than once within a second, you could get a repeat
// of the returned GUID value.
//
bool cGZCOM::CreateGuid(GZGUID* pGuid){
   cRZLock autoLock(mCriticalSection);

   //Wait until it is 'safe' to generate new Guids.
   RZ_ASSERT(mnNextGuidGenTime < (time(NULL) + 60));
   while(time(NULL) < mnNextGuidGenTime)
      cRZThread::SleepCurrentThread(250000); //Sleep for 250 milliseconds.

   //Generate the Guid.
   const Uint32 nRandomBits(mRandom.RandomUint32Uniform(8) << 29);
   const Uint32 nSecondsBits(GetGuidGenSeconds() & 0x1FFFFFFF);
   pGuid[0] = nRandomBits | nSecondsBits;

   //Set the next time we can create new GUIDs. Because we only create a 
   //single GUID with this function, the next time need only be one second
   //from the current time. You might ask why we have a random factor in 
   //the GUID if we are unilaterally going to wait for a full second before
   //we will generate another GUID. The answer is that multiple instances
   //of GUID generators might be running for multiple users, and the random
   //factor simply makes collisions less likely.
   mnNextGuidGenTime = time(NULL)+1;

   return true;
}


///////////////////////////////////////////////////////////////////////////////
// CreateGuids
//
// This function will take as much as 1 second to execute for every 8 GUIDs
// that you request. Requesting 1 GUID, however, will always return immediately.
//
bool cGZCOM::CreateGuids(GZGUID pGuidArray[], Uint32 nCount){
   cRZLock autoLock(mCriticalSection);

   if(nCount){
      //We wait until the next second passes since the last time this function 
      //was called. That way, if this function is called twice in a row then 
      //it can't generate duplicate GUIDs.
      RZ_ASSERT(mnNextGuidGenTime < (time(NULL) + 60));
      while(time(NULL) < mnNextGuidGenTime)
         cRZThread::SleepCurrentThread(250000); //Sleep for 250 milliseconds.

      //Generate the Guids. What we do here is simply grab a linear array of
      //Guid values starting with the current second and random bit set to 0.
      //Each successive Guid will increment the random bit and on the 8th 
      //random bit it will increment the second bits by one and start over
      //with the random bits.
      const Uint32 nSecondsSinceBegin(GetGuidGenSeconds());
      for(Uint32 i(0); i<nCount; i++){
         const Uint32 nRandomBits((i % 8) << 29);
         const Uint32 nSecondsBits((nSecondsSinceBegin + (i/8)) & 0x1FFFFFFF);
         pGuidArray[i] = (nRandomBits | nSecondsBits);
      }

      //Set the next time we can create new GUIDs. Because we only create a 
      //single GUID with this function, the next time need only be one second
      //from the current time.
      const Uint32 nNumberOfSecondsToWait = ((nCount+7) & (-8)) / 8; //Round nCount up to nearest multiple of 8 then divides by 8.
      mnNextGuidGenTime = time(NULL) + nNumberOfSecondsToWait;
   }

   return true;
}