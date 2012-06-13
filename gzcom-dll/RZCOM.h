#include "stdafx.h"

class cIGZCOM;
class cRZCOMDllDirector
{
	public:
		cRZCOMDllDirector();
		virtual ~cRZCOMDllDirector();

	public:
		virtual DWORD GetDirectorID() const = 0;

		virtual bool QueryInterface( DWORD riid, void** ppvObj );
		virtual DWORD AddRef();

		virtual DWORD Release();
		virtual DWORD RemoveRef();
		virtual DWORD RefCount();

	public:
		typedef void (*DummyFunctionPtr)();

		// unknown: cIGZUnknown*, replaced with void*
		typedef void* (*FactoryFunctionPtr1)();
		typedef bool  (*FactoryFunctionPtr2)(DWORD, void**);

		bool InitializeCOM( cIGZCOM* pCOM, const std::string& sLibraryPath );
		bool OnStart( cIGZCOM* pCOM );
		bool GetLibraryPath( std::string& sLibraryPath );

		virtual bool GetClassObject( DWORD rclsid, DWORD riid, void** ppvObj );
		bool OnUnload() { return true; }

		// unknown: cIGZFramework, replaced with void* which is probably way invalid
		void* FrameWork();
		cIGZCOM* GZCOM();

		// unknown: ClassObjectEnumerationCallback in pCallback, replaced with void*
		void EnumClassObjects( void* pCallback, void* pContext );

		bool CanUnloadNow();
		void AddDirector( cRZCOMDllDirector* pCOMDirector );
		DWORD GetHeapAllocatedSize();

	public:
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

		void AddCls( DWORD clsid, FactoryFunctionPtr1 pff1 );
		void AddCls( DWORD clsid, FactoryFunctionPtr2 pff2 );

	protected:
		DWORD          mnRefCount;
		DWORD          mDirectorID;
		std::string    msLibraryPath;
		cIGZCOM*       mpCOM;

		// unknown: cIGZFrameWork*, replaced with void*
		void* mpFrameWork;

		typedef std::vector<cRZCOMDllDirector*> ChildDirectorArray;
		ChildDirectorArray mChildDirectorArray;

		typedef DWORD                                           ClassObjectID;
		typedef std::pair<DummyFunctionPtr, int>                FactoryFuncRecord;
		typedef std::hash_map<ClassObjectID, FactoryFuncRecord> ClassObjectMap;

		ClassObjectMap mClassObjectMap;
};

#ifndef RZCOM_H
#define RZCOM_H
#endif