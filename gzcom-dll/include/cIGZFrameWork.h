#pragma once
#include "cIGZUnknown.h"
#include <list>

class cIGZFrameWorkHooks;
class cIGZSystemService;

// A complete guess that's broken aside from the following functions:
//     - AddHook
class cIGZFrameWork : public cIGZUnknown
{
	public:
		// FrameWork function here
		//virtual bool sSetFrameWork(cIGZFrameWork* pFramework) = 0; // actually cGZFramework*
		//virtual bool sSetApplication(void* pIGZApp) = 0; // actually cIGZApp*
		// OnInstall here
		/*virtual void* GetDebugStream(void) = 0; // unknown ret type
		virtual int32_t DefaultDebugStream(void) = 0; // int??
		virtual int32_t DebugStream(void) = 0; // int??
		virtual bool SetDebugLevel(int32_t nLevel) = 0;
		virtual int32_t GetDebugLevel(void) = 0;
		virtual bool SetDebugStream(void* pIGZDebugStream) = 0; // is actually cIGZDebugStream
		virtual void* ExceptionNotificationObj(void) = 0; // actual return type unknown*/

		virtual bool AddHook(cIGZFrameWorkHooks* pHooks) = 0;
		virtual void AbortiveQuit(int32_t nUnknown) = 0;
		 // <possible entry point>
		virtual bool AddSystemService(cIGZSystemService* pService) = 0;
		 // <possible entry point>
		virtual bool AddToOnIdle(cIGZSystemService* pService) = 0;
		virtual bool AddToTick(cIGZSystemService* pService) = 0;
		 // <possible entry point>
		virtual void* Application(void) = 0; // Is actually an mpApp
		virtual bool AppInit(void) = 0;
		virtual bool AppShutdown(void) = 0;
		virtual char* CommandLine(void) = 0;
		 // <possible entry point>
		virtual bool EnumSystemServices(void* enumerator, cIGZUnknown* pUnknown, uint32_t dwUnknown) = 0; // ??? - enumerator is a function but what is prototype?
		virtual char* GetCOMObject(void) = 0;
		virtual int32_t GetOnIdleInterval(void) = 0;
		virtual int32_t GetState(void) = 0;
		virtual void* GetStream(void) = 0; // unknown ret type
		virtual void* GetSystemService(uint32_t dwUnknown1, uint32_t dwUnknown2, void** ppUnknown3) = 0; // ???
		virtual bool HookPostAppInit(void) = 0;
		virtual bool HookPreAppInit(void) = 0;
		virtual bool HookPreFrameWorkInit(void) = 0;
		virtual bool IsInstall(void) = 0;
		virtual bool IsTickEnabled(void) = 0;
		virtual int32_t MakeHookListCopy(std::list<cIGZFrameWorkHooks*>, std::allocator<cIGZFrameWorkHooks*>&) = 0;
		virtual int32_t MakeSystemServiceListCopy(std::list<cIGZSystemService*>, std::allocator<cIGZSystemService*>&) = 0;
		virtual int32_t OnTick(uint32_t dwUnknown) = 0;
		virtual bool PostAppInit(void) = 0;
		virtual bool PostAppShutdown(void) = 0;
		virtual bool PreAppInit(void) = 0;
		virtual bool PreAppShutdown(void) = 0;
		virtual int32_t Quit(int32_t nUnknown) = 0;
		virtual bool RemoveFromOnIdle(cIGZSystemService* pService) = 0;
		virtual bool RemoveFromTick(cIGZSystemService* pService) = 0;
		virtual bool RemoveHook(cIGZFrameWorkHooks* pHooks) = 0;
		virtual bool RemoveSystemService(cIGZSystemService* pService) = 0;
		virtual bool Run(void) = 0;
		virtual bool SetApplication(void* pIGZApp) = 0; // is actually cIGZApp*
		virtual bool SetCommandLine(std::string const& pszCmdLine) = 0; // is actually cRZCmdLine const&
		virtual bool SetOnIdleInterval(int32_t nInterval) = 0;
		virtual bool SetStream(int32_t nUnknown, cIGZUnknown* pUnknown) = 0; // ???

		/*
		virtual void ReportException(char const* szExcText) = 0;


		virtual int32_t StdErr(void) = 0; // ???
		virtual int32_t StdIn(void) = 0; // ???
		virtual int32_t StdOut(void) = 0; // ???
		
		virtual int32_t Main(std::string const& szCmdLine, bool) = 0; // sub string for cRZCmdLine
		virtual cIGZFrameWork* OnIdle(void) = 0; // is actually cGZFramework*
		virtual cIGZFrameWork* ToggleTick(bool bTick) = 0; // is actually cGZFramework*
		virtual bool sInit(const cIGZString& szCmdLine, bool bUnknown) = 0; // ???
		virtual bool sRun(void) = 0;
		virtual bool sShutdown(void) = 0;*/
};