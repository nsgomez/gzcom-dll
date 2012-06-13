///////////////////////////////////////////////////////////////////////////////
// GZCOMDirector.h
//
// Maintained by Paul Pedriana and Greg Kearney.
//
// Copyright (c) 1996 Maxis, Inc. -- All Rights Reserved World Wide.
///////////////////////////////////////////////////////////////////////////////


#ifndef RZCOMDIRECTOR_H
#define RZCOMDIRECTOR_H


///////////////////////////////////////////////////////////////////////////////
// Include files
//
#ifndef IGZFRAMEWORK_H
   #include <IGZFrameWork.h>
#endif
#ifndef RZSTRING_H
   #include <RZString.h>
#endif
#ifndef RZINTERFACE_H
   #include <RZInterface.h>
#endif
#ifndef IGZCOMDIRECTOR_H
   #include <IGZCOMDirector.h>
#endif
#ifndef RZXGLOBAL_H
   #include <RZXGlobal.h>
#endif



///////////////////////////////////////////////////////////////////////////////
// Forward declarations
//
class cIGZCOM;



///////////////////////////////////////////////////////////////////////////////
// cRZCOMDllDirector
//
// This class encapsulates the COM object manipulation functions for the DLL or
// library.
//
// To override the default functionality for your DLL, do not include
// RZCOMDllDefault.obj in your project.  Instead, write a RZGetCOMDllDirector()
// function that returns an instance of a class derived from cRZCOMDllDirector,
// overriding any virtual functions for your class.
//
///////////////////////////////////////////////////////////////////////////////
class cRZCOMDllDirector : public cIGZCOMDirector, public cIGZFrameWorkHooks
{
public:
   cRZCOMDllDirector();
   virtual ~cRZCOMDllDirector();

public:
   //GetDirectorID
   //Server GUID .. essentially how GZCOM refers to this server or it's name.
   virtual GZGUID GetDirectorID() const = 0;

   //cIGZUnknown
   virtual bool   QueryInterface(GZREFIID riid, void** ppvObj);
   virtual Uint32 AddRef();

   // The default for Release is to NOT delete the director at any time.
   // The lifetime of directors is controlled by GZCOM. Thus, they will
   // be loaded/unloaded by GZCOM regardless of refcount.
   virtual Uint32 Release();

   // Decrement the global reference count without possibly deleting the
   // director.
   virtual Uint32 RemoveRef();

   // Return the global reference count
   virtual Uint32 RefCount();

public:
   //Typedef
   typedef void         (*DummyFunctionPtr)();
   typedef cIGZUnknown* (*FactoryFunctionPtr1)();
   typedef bool         (*FactoryFunctionPtr2)(GZIID, void**);

   // Provides the initializtion of the cIGZCOMDirector for use by GZCOM.
   bool InitializeCOM(cIGZCOM* pCOM, const cIGZString& sLibraryPath);

   // OnStart
   // This is called by GZCOM the first time the dll is loaded only (unlike
   // InitializeCOM() which is called every time the dll is loaded).
   // Override this method to add system services, make entries into
   // the register or load other dlls.
   bool OnStart(cIGZCOM* pCOM);

   // GetLibraryPath
   // Return the path of this module.
   bool GetLibraryPath(cIGZString& sLibraryPath);

   // GetClassObject
   // Used by GZCOM when the requested classid resides within the scope of
   // this director.
   virtual bool GetClassObject(GZCLSID rclsid, GZIID riid, void** ppvObj);

   // OnUnload
   // The director is going to be released... do what you gotta do.
   bool OnUnload() { return true; }

   // FrameWork
   // Return a pointer to the framework.  This pointer is set up during
   // InitializeFramework through COM.
   cIGZFrameWork* FrameWork();

   // GZCOM
   // Get the GZCOM pointer
   cIGZCOM* GZCOM();

   // EnumClassObjects
   // Enumerate all CLSIDs
   void EnumClassObjects(ClassObjectEnumerationCallback pCallback, void* pContext);

   // CanUnloadNow
   // Whether it is safe to unload this DLL or not.
   // The default behavior is that we are safe if and only if
   // the global reference count of objects is zero.
   bool CanUnloadNow();

   // AddDirector
   // Add/Nest a Director to the current Director's list
   // each link module (exe or dll) only has one main director
   // sub directors (e.g libraries or code groups) should
   // be attached to the main director in the constructo of
   // the main director
   void AddDirector(cRZCOMDllDirector* pCOMDirector);

   // GetHeapAllocatedSize
   // Returns the number of bytes allocated on the default heap used by this com director.
   Uint32 GetHeapAllocatedSize();

public:
   // cIGZFrameWorkHooks
   // Proactive registeration with the framework is required to activate these callbacks. 
   bool PreFrameWorkInit();
   bool PreAppInit();
   bool PostAppInit();
   bool PreAppShutdown();
   bool PostAppShutdown();
   bool PostSystemServiceShutdown();
   bool AbortiveQuit(); 
   bool OnInstall(); 

protected:
   enum FactorFunctionType{
      kFactorFunctionType1 = 1,
      kFactorFunctionType2 = 2
   };

   // AddCls
   // Used to add a class ID.
   // This should be called for every class in your director in the ctor
   // of your DLL director (thus the function is not virtual).
   // Parameters:
   //    clsid   - the class ID
   //    pCreate - a callback function that creates or returns an instance of the given class.
   void AddCls(GZCLSID clsid, FactoryFunctionPtr1 pff1);
   void AddCls(GZCLSID clsid, FactoryFunctionPtr2 pff2);

protected:
   Uint32         mnRefCount;    // The global reference count
   GZGUID         mDirectorID;   //
   cRZString      msLibraryPath; // Under Win32, this would be the path to the DLL.
   cIGZCOM*       mpCOM;         //
   cIGZFrameWork* mpFrameWork;   //

   // tChildDirectorArray
   // An array containing all child directors of this DLL Director.
   typedef vector<cRZCOMDllDirector*> ChildDirectorArray;
   ChildDirectorArray mChildDirectorArray;

   // tClassObjectMap
   // A map of CLSIDs to creation functions.
   typedef GZCLSID                                    ClassObjectID;
   typedef pair<DummyFunctionPtr, Sint32>             FactoryFuncRecord;
   typedef hash_map<ClassObjectID, FactoryFuncRecord> ClassObjectMap;

   ClassObjectMap mClassObjectMap;
};
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// RZGetFramework
//
// Note that 'RZGetFrameWork' (as opposed to 'RZGetFramework') is deprecated.
//
#if defined(_GZDLL)
   inline cIGZFrameWork* RZGetFrameWork() { return RZGetCOMDllDirector()->FrameWork(); }
   inline cIGZFramework* RZGetFramework() { return RZGetCOMDllDirector()->FrameWork(); }
#endif




///////////////////////////////////////////////////////////////////////////////
// cRZCOMDllGenericClassFactoryT
//
template <class Class>
class cRZCOMDllGenericClassFactoryT
{
public:
   static bool CreateInstance(GZIID iid, void** ppVoid){
      Class* const pClass = new Class();
      pClass->AddRef();
      const bool result = pClass->QueryInterface(iid, ppVoid); 
      pClass->Release();
      return result;
   }
};
///////////////////////////////////////////////////////////////////////////////



#endif // Sentry