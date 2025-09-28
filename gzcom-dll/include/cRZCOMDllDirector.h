/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cRZCOMDllDirector.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2024 memo
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "cIGZCOMDirector.h"
#include "cIGZFrameWorkHooks.h"
#include "cRZBaseString.h"

// TODO: use EASTL instead
#include <unordered_map>
#include <vector>

// This class is derived from Paul Pedriana's released code and should be perfect.
class cRZCOMDllDirector : public cIGZCOMDirector, public cIGZFrameWorkHooks
{
	public:
		cRZCOMDllDirector(void);
		virtual ~cRZCOMDllDirector(void);

	public:
		virtual uint32_t GetDirectorID(void) const = 0;

		virtual bool QueryInterface(uint32_t riid, void** ppvObj);
		virtual uint32_t AddRef(void);
		virtual uint32_t Release(void);

		virtual uint32_t RemoveRef(void);
		virtual uint32_t RefCount(void);

	public:
		typedef void (*DummyFunctionPtr)();
		typedef cIGZUnknown* (*FactoryFunctionPtr1)();
		typedef bool (*FactoryFunctionPtr2)(uint32_t, void**);

		bool InitializeCOM(cIGZCOM* pCOM, const cIGZString& sLibraryPath);
		bool OnStart(cIGZCOM* pCOM);
		bool GetLibraryPath(cIGZString& sLibraryPath);

		virtual bool GetClassObject(uint32_t rclsid, uint32_t riid, void** ppvObj);
		bool OnUnload(void) { return true; }
		cIGZFrameWork* FrameWork(void);
		cIGZCOM* GZCOM(void);
		void EnumClassObjects(ClassObjectEnumerationCallback pCallback, void* pContext);
		bool CanUnloadNow(void);
		void AddDirector(cIGZCOMDirector* pCOMDirector);
		uint32_t GetHeapAllocatedSize(void);

	public:
		bool PreFrameWorkInit(void);
		bool PreAppInit(void);
		bool PostAppInit(void);
		bool PreAppShutdown(void);
		bool PostAppShutdown(void);
		bool PostSystemServiceShutdown(void);
		bool AbortiveQuit(void);
		bool OnInstall(void);

	protected:
		enum FactorFunctionType {
			kFactorFunctionType1 = 1,
			kFactorFunctionType2 = 2
		};

		enum GZIIDList : uint32_t {
			GZIID_cIGZFrameWorkHooks = 0x03FA40BF,
			kGZIID_cIGZCOMDirector = 0xA21EE941
		};

		void AddCls(uint32_t clsid, FactoryFunctionPtr1 pff1);
		void AddCls(uint32_t clsid, FactoryFunctionPtr2 pff2);

	protected:
		uint32_t mnRefCount;
		uint32_t mDirectorID;
		cRZBaseString msLibraryPath;
		cIGZCOM* mpCOM;
		cIGZFrameWork* mpFrameWork;

		typedef std::vector<cRZCOMDllDirector*> ChildDirectorArray;
		ChildDirectorArray mChildDirectorArray;

		typedef uint32_t ClassObjectID;
		typedef std::pair<DummyFunctionPtr, int32_t> FactoryFuncRecord;
		typedef std::unordered_map<ClassObjectID, FactoryFuncRecord> ClassObjectMap;

		ClassObjectMap mClassObjectMap;
};

cRZCOMDllDirector* RZGetCOMDllDirector();
inline cIGZFrameWork* RZGetFrameWork() { return RZGetCOMDllDirector()->FrameWork(); }
inline cIGZFrameWork* RZGetFramework() { return RZGetCOMDllDirector()->FrameWork(); }