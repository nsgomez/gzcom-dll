#pragma once
#include "cIGZUnknown.h"

class cGZMessage;
class cIGZCanvas;
class cIGZString;
class cIGZWin;
class cIGZWinMessageFilter;

/**
 * @brief An interface for a window manager for the game UI
 */
class cIGZWinMgr : public cIGZUnknown
{
	public:
		virtual cIGZWin* GetMainWindow(void) = 0;
		virtual bool SetMainWindow(cIGZWin* pWin) = 0;
		virtual bool GetMainWinAs(uint32_t riid, void** ppvObj) = 0;

		virtual void Plot(void) = 0;
		virtual bool AppendToPlotStrategy(cIGZWin* pWin) = 0;
		virtual bool ExecutePlotStrategy(void) = 0;

		virtual bool GZWinMsgPost(uint32_t, uint32_t, uint32_t) = 0;
		virtual bool GZWinMsgPost_Mouse(uint32_t, int32_t, int32_t, uint32_t) = 0;
		virtual bool GZWinMsgPost_Keyboard(uint32_t, uint32_t, uint32_t) = 0;

		virtual bool SendMessageToTarget(cGZMessage& sMessage) = 0;
		virtual bool SendMessageToTarget(cIGZWin* pWin, uint32_t, uint32_t, uint32_t, uint32_t) = 0;
		
		virtual bool PostMessageToTarget(cIGZWin* pWin, cGZMessage const& sMessage) = 0;
		virtual bool PostMessageToTarget(cIGZWin* pWin, uint32_t, uint32_t, uint32_t, uint32_t) = 0;

		virtual bool ProcessPostedMessages(void) = 0;
		virtual bool ProcessMouseMessage(cGZMessage& sMessage) = 0;
		virtual bool ProcessKeyboardMessage(cGZMessage& sMessage) = 0;
		virtual bool FlushInputMessageQueue(void) = 0;

		virtual bool AddWindowToValidList(cIGZWin* pWin) = 0;
		virtual bool RemoveWindowFromValidList(cIGZWin* pWin) = 0;
		virtual bool CleanUpWindowReferences(cIGZWin* pWin) = 0;
		
		virtual bool DestroyWindow(cIGZWin* pWin) = 0;
		virtual bool IsWindowValid(cIGZWin* pWin) = 0;
		virtual cIGZWin* GetWindowFromPoint(int32_t nX, int32_t nZ) = 0;

		virtual bool SetCurrentMouseWin(cIGZWin* pWin) = 0;
		virtual cIGZCanvas* GetCanvas(void) = 0;

		virtual cIGZWin* GZGetCapture(void) = 0;
		virtual bool GZSetCapture(cIGZWin* pWin) = 0;
		virtual bool GZReleaseCapture(cIGZWin* pWin) = 0;
		
		virtual bool GZShowCursor(bool bShow) = 0;
		virtual intptr_t GetCursorManager(void) = 0;
		virtual bool GetCursorScreenPosition(int32_t& nX, int32_t& nZ) = 0;
		virtual bool GetCursorRelativePosition(cIGZWin* pWin, int32_t& nX, int32_t& nZ) = 0;
		virtual bool SetCursorPosition(int32_t nX, int32_t nZ) = 0;

		virtual cIGZWin* GZGetFocus(void) = 0;
		virtual bool GZSetFocus(cIGZWin* pWin) = 0;
		
		virtual intptr_t GetKeyboard(void) = 0;

		virtual bool GZRegisterKeyFilter(cIGZWinMessageFilter* pFilter) = 0;
		virtual bool GZUnregisterKeyFilter(cIGZWinMessageFilter* pFilter) = 0;

		virtual bool DoModalWin(cIGZWin* pWin) = 0;
		virtual bool IsModal(void) = 0;
		virtual int32_t GetModalNestCount(void) = 0;

		virtual bool GZMsgBox(cIGZString const&, cIGZString const&, uint32_t, bool, uint32_t) = 0;
		virtual bool SetGZMsgBoxCMDID(uint32_t, uint32_t, bool) = 0;
		virtual bool GetGZMsgBoxCMDID(uint32_t&, uint32_t&, bool&) = 0;

		virtual bool DebugIsFocusGadgetVisible(void) = 0;
		virtual void DebugSetFocusGadgetVisible(bool bVisible) = 0;

		virtual bool DebugIsCaptureGadgetVisible(void) = 0;
		virtual void DebugSetCaptureGadgetVisible(bool bVisible) = 0;

		virtual bool DebugIsInvalidateGadgetVisible(void) = 0;
		virtual void DebugSetInvalidateGadgetVisible(bool bVisible) = 0;

		virtual void DebugDumpWindowList(void) = 0;
};