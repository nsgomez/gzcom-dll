#pragma once
#include "cIGZUnknown.h"

class cGZMessage;
class cIGZKeyboard;
class cIGZWinMgr;

/**
 * @brief An interface for the game's UI windows
 */
class cIGZWin : public cIGZUnknown
{
	public:
		virtual bool DoMessage(cGZMessage& sMessage) = 0;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual cIGZWinMgr* GetWindowManager(void) = 0;
		virtual bool SetWindowManager(cIGZWinMgr* pWinMgr) = 0;

		virtual cIGZKeyboard* GetKeyboard(void) = 0;
		virtual bool SetKeyboard(cIGZKeyboard* pKeyboard) = 0;

		virtual cIGZWin* GetMainWindow(void) = 0;
		virtual cIGZWin* GetParentWin(void) = 0;
		virtual bool SetParentWin(cIGZWin* pWin) = 0;

		virtual int32_t GetChildCount(void) = 0;
		virtual bool ChildAdd(cIGZWin* pWin) = 0;
		virtual bool ChildRemove(cIGZWin* pWin) = 0;
		virtual bool ChildDelete(cIGZWin* pWin) = 0;
		virtual bool ChildDeleteAbsolute(cIGZWin* pWin) = 0;
		virtual bool ChildDeleteAll(void) = 0;
		virtual bool ChildExists(cIGZWin* pWin) = 0;
		virtual bool ChildExists(uint32_t dwWinID) = 0;
		virtual bool IsWinInParentChain(cIGZWin* pWin) = 0;
		virtual bool IsWinInChildChain(cIGZWin* pWin) = 0;
		
		virtual bool PullToFront(void) = 0;
		virtual bool SendToBack(void) = 0;
		virtual bool ChildToFront(cIGZWin* pWin) = 0;
		virtual bool ChildToFront(uint32_t dwWinID) = 0;
		virtual bool ChildToBack(cIGZWin* pWin) = 0;
		virtual bool ChildStepFront(cIGZWin* pWin) = 0;
		virtual bool ChildStepBack(cIGZWin* pWin) = 0;
		virtual bool MoveRelativeTo(cIGZWin* pWin, bool) = 0;
		virtual bool ChildMoveRelative(cIGZWin*, cIGZWin*, bool) = 0;

		virtual bool EnumChildren(uint32_t, bool(*)(cIGZWin*, uint32_t, void*, void*), void*) = 0;
		virtual bool SortChildren(bool(*)(cIGZWin*, cIGZWin*, void*), void*, bool) = 0;

		virtual cIGZWin* GetChildWindowFromID(uint32_t dwWinID) = 0;
		virtual cIGZWin* GetChildWindowFromIDRecursive(uint32_t dwWinID) = 0;

		virtual bool GetChildAs(uint32_t dwWinID, uint32_t riid, void** ppvObj) = 0;
		virtual bool GetChildAsRecursive(uint32_t dwWinID, uint32_t riid, void** ppvObj) = 0;

		virtual cIGZWin* GetWindowFromPoint(int32_t nX, int32_t nZ) = 0;
		virtual cIGZWin* GetChildWindowFromPoint(int32_t nX, int32_t nZ) = 0;
		virtual cIGZWin* GetChildWindowFromCursorPoint(int32_t nX, int32_t nZ) = 0;

		// <TODO>
};