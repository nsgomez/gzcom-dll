///////////////////////////////////////////////////////////////////////////////
// GZCOM.h
//
// Maintained by Paul Pedriana and Greg Kearney.
//
// Copyright (c) 1996 Maxis, Inc. -- All Rights Reserved World Wide.
///////////////////////////////////////////////////////////////////////////////


#ifndef GZCOM_H
#define GZCOM_H


///////////////////////////////////////////////////////////////////////////////
// Include files
//
#ifndef IGZCOM_H
   #include <IGZCOM.h>
#endif
#ifndef RANDOM_H
   #include <RZRandom.h>
#endif
#ifndef RZTHREADSAFEOBJECT_H
   #include <RZThreadSafeObject.h>
#endif
#ifndef _GZ_NO_SYSTEM_SERVICES // If you define '_GZ_NO_SYSTEM_SERVICES', then classes 
   #ifndef RSYSSER_H           // that are normally system services won't be so. 
      #include <RZSysSer.h>
   #endif
#endif



///////////////////////////////////////////////////////////////////////////////
// Forward Declarations
//
class cGZCOM;
class cGZFileSystem;
class cIGZCOMDirector;



///////////////////////////////////////////////////////////////////////////////
// Extern
//
extern cIGZFramework* RZGetFramework();



///////////////////////////////////////////////////////////////////////////////
// cGZCOMLibrary
//
// Encapsulates a library's properties, such as its name and whether or not
// it is currently loaded. This class is an opaque platform depenedent 
// implementation -- no platform dependencies are required outside of the GZCOM.cpp
// file. 
//
class cGZCOMLibrary : public cIGZCOMLibrary{
public:
   cGZCOMLibrary();
   cGZCOMLibrary(const cIGZString& sLibraryPath);
   virtual ~cGZCOMLibrary() {};

   //cIGZUnknown
   bool   QueryInterface(GZREFIID riid, void** ppvObj);
   Uint32 AddRef();
   Uint32 Release();

   //cIGZCOMLibrary
   bool Load();
   bool Free();

   void GetPath(cIGZString& sPath) const;
   bool SetPath(const cIGZString& sPath);

   GZLibraryHandle GetHandle() const;
   void            SetHandle(GZLibraryHandle handle);

   cIGZCOMDirector* GetDirector() const;
   void             SetDirector(cIGZCOMDirector* pDirector);

   bool IsLoaded() const;
   void SetLoaded(bool bUse);

   bool operator<  (const cGZCOMLibrary& rhs) const;
   bool operator>  (const cGZCOMLibrary& rhs) const;
   bool operator== (const cGZCOMLibrary& rhs) const;

protected:
   bool             mbLoaded;       // Is the library currently loaded.
   Uint32           mnRefCount;     // RefCount.
   cIGZCOMDirector* mpDirector;     // The interface used by GZCOM to manipulate the dll.
   cRZString        msLibraryPath;  // Full path to library file (e.g. Win32 DLL).
   GZLibraryHandle  mHandle;        // Library (OS-level) handle.
};




///////////////////////////////////////////////////////////////////////////////
// cGZCOM
//
class cGZCOM : public cIGZCOM,
               public cRZThreadSafeObject
               #ifndef _GZ_NO_SYSTEM_SERVICES
               , public cRZSystemService
               #endif
{
public:
   cGZCOM();
   virtual ~cGZCOM();

   //cIGZUnknown
   bool   QueryInterface(GZREFIID riid, void** ppvObj);
   Uint32 AddRef();
   Uint32 Release();

   //cRZSystemService
   bool Init();
   bool Shutdown();

   //cIGZCOM
   cIGZFramework* FrameWork() { return mpFramework; }

   // COM is maintained in the system service list; however,
   // it initialized and shutdown separately from the rest.
   bool RealInit(); 
   void RealShutdown(); 
   void SetServiceRunning( bool bRunning );
   bool OnInstall();
   bool UpdateClassRegistry(cGZCOMLibrary& lib);

   bool GetClassObject(GZCLSID clsid, GZIID iid, void** ppvObj);
   bool GetLibObject(cGZCOMLibrary& lib, GZCLSID clsid, GZIID iid, void** ppvObj);

   // FreeUnusedLibraries unloads any DLLs that have been loaded by cGZCOM::LoadLibrary but 
   // are no longer in use. Applications should call this function periodically to free resources, 
   // either at the top of their message loop or in some idle-time task.
   void FreeUnusedLibraries();
   void FreeAllLibraries();
   bool CanUnloadLibrary(cGZCOMLibrary& lib);
   bool CreateGuid(GZGUID* pGuid);
   bool CreateGuids(GZGUID pGuidArray[], Uint32 nCount);
   bool AddLibrary(const cIGZString& sPath);

   //Library enumeration
   Uint32 EnumerateLibraries(cIGZCOMLibrary* pLibraries[], Uint32& nCount);   //You pass in an array of pointers, it returns a refcounted array of library pointers.
   void   EnumerateLibraries(GZCOMLibraryIterationFunction, void* pContext);  //Calls you back.

protected:
   static void AddEntryCallback(GZREFCLSID rclsid, Uint32 nVersion, void* pContext);

protected:
   typedef pair<Uint32, cGZCOMLibrary*>   tClassObjectData;
   typedef map<GZCLSID, tClassObjectData> tIDMap;
   typedef set<cGZCOMLibrary>             tLibraries;

   bool                                   mbInitialized;    //
   Uint32                                 mnRefCount;       //Used only if _GZ_NO_SYSTEM_SERVICES is defined.
   tIDMap                                 mIDMap;           //
   tLibraries                             mLibraries;       //
   cGZCOMLibrary*                         mpCurrentLib;     //
   cIGZFramework*                         mpFramework;      //We don't AddRef this, as it is an app-wide singleton.
   cIGZCOMDirector*                       mpCOMDirector;    //We don't AddRef this, as it is an app-wide singleton.
   RZRandom                               mRandom;          //Random number generator for GUIDs.
   int                                    mnNextGuidGenTime;//The next time we can safely start generating new GUIDs.
};



#endif // Sentry