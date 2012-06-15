#include "stdafx.h"

// Type definitions
typedef void (*ClassObjectEnumerationCallback)(uint32_t, int, void*);

#ifndef RZCOM_H
	#define RZCOM_H

	// Including type and class definitions
	#include "Framework.h"
	#include "FrameworkHooks.h"
	#include "IGZCOM.h"
	#include "Unknown.h"

	// Forward undefined classes
	class cRZCOMDllDirector;

	// Functions declared in our DLL's entry point
    /**/

	// Declare the main class
	class cRZCOMDllDirector : public cIGZFrameWorkHooks
	{
		public:
			cRZCOMDllDirector();
			virtual ~cRZCOMDllDirector();

		public:
			// Server GUID (how GZCOM refers to this server/its name)
			virtual DWORD GetDirectorID() const = 0;

			// cIGZUnknown
			virtual bool     QueryInterface( DWORD riid, void** ppvObj );
			virtual uint32_t AddRef();

			// Does NOT delete the director at any time. The lifetime
			// of directors is controlled by GZCOM.
			virtual uint32_t Release();

			// Decrement the global reference count without deleting
			// the director.
			virtual uint32_t RemoveRef();

			// Return the global reference count.
			virtual uint32_t RefCount();

		public:
			// Type definitions
			typedef void          (*DummyFunctionPtr)();
			typedef cIGZUnknown*  (*FactoryFunctionPtr1)();
			typedef bool          (*FactoryFunctionPtr2)(DWORD, void**);

			// Provides initialization of cIGZCOMDirector for use by GZCOM.
			bool InitializeCOM( cIGZCOM* pCOM, const std::string& sLibraryPath );

			// Called by GZCOM the first time the DLL is loaded only, unlike
			// InitializeCOM() which is called every time the DLL is loaded.
			//
			// Override this method to add system services, make entries into
			// the register or load other DLLs.
			bool OnStart          ( cIGZCOM* pCOM );

			// Returns the path of this module.
			// (cIGZString& is unknown)
			bool GetLibraryPath   ( std::string& sLibraryPath );

			// Used by GZCOM when the requested class ID resides within the
			// scope of this director.
			virtual bool GetClassObject( DWORD rclsid, DWORD riid, void** ppvObj );

			// The director is going to be released, unload any DLLs we have
			// and clean up after ourselves.
			bool OnUnload() { return true; }

			// Return a pointer to the framework, which is set up during
			// InitializeFramework through COM.
			cIGZFrameWork * FrameWork();

			// Get the GZCOM pointer
			cIGZCOM * GZCOM();

			// Enumerate all CLSIDs
			void EnumClassObjects( ClassObjectEnumerationCallback pCallback, void* pContext );

			// Is it safe for this DLL to unload?
			// Default behavior is we are safe if and only if the global reference
			//     count of objects is zero.
			bool CanUnloadNow();

			// Add/nest a director to the current director's list. Each link
			//     module (exe or dll) has only one main director. Subdirectors
			//     should be attached to the main director in the constructor.
			void AddDirector( cRZCOMDllDirector* pCOMDirector );

			// Returns the number of bytes allocated on the default heap used by
			// this COM director.
			DWORD GetHeapAllocatedSize();

		public:
			// cIGZFrameWorkHooks
			// Proactive registration with the framework is required to use these.
			bool PreFrameWorkInit();
			bool PreAppInit();
			bool PostAppInit();
			bool PreAppShutdown();
			bool PostAppShutdown();
			bool PostSystemServiceShutdown();
			bool AbortiveQuit();
			bool OnInstall();

		protected:
			enum FactorFunctionType
			{
				kFactorFunctionType1 = 1,
				kFactorFunctionType2 = 2
			};

			// Used to add a class ID. This should be called for every class
			// in your director in the constructor of your DLL director (thus
			// the function is not virtual).
			//
			// Parameters:
			//     clsid   - the class ID
			//     pCreate - a callback function that creates/returns an instance
			//               of the given class.
			void AddCls( DWORD clsid, FactoryFunctionPtr1 pff1 );
			void AddCls( DWORD clsid, FactoryFunctionPtr2 pff2 );

		protected:
			uint32_t       mnRefCount;    // Global reference count
			DWORD          mDirectorID;   //
			std::string    msLibraryPath; // Under Win32, path to the DLL
			cIGZCOM*       mpCOM;         //
			cIGZFrameWork* mpFrameWork;   //

			// An array containing all child directors of this DLL director.
			typedef std::vector<cRZCOMDllDirector*> ChildDirectorArray;
			ChildDirectorArray mChildDirectorArray;

			// A map of CLSIDs to creation functions.
			typedef DWORD                                           ClassObjectID;
			typedef std::pair<DummyFunctionPtr, int>                FactoryFuncRecord;
			typedef std::hash_map<ClassObjectID, FactoryFuncRecord> ClassObjectMap;

			ClassObjectMap mClassObjectMap;
	};

	// Gets the framework within the scope of this DLL
	inline cIGZFrameWork* RZGetFramework() { return RZGetCOMDllDirector()->FrameWork(); }

	// I honestly don't know what this would be used for
	template <class Class>
	class cRZCOMDllGenericClassFactoryT
	{
		public:
			static bool CreateInstance( DWORD iid, void** ppVoid )
			{
				// Spawn a new instance of <Class>
				Class* const pClass = new Class();

				// Add a reference to that instance
				pClass->AddRef();

				// See if we can query the class' interface
				const bool result = pClass->QueryInterface( iid, ppVoid );

				// Release our reference to the instance
				pClass->Release();

				// Done.
				return result;
			}
	};

#endif