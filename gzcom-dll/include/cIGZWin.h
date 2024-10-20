#pragma once
#include "cIGZUnknown.h"

class cGZMessage;
class cIGZCursor;
class cIGZKeyboard;
class cIGZString;
class cIGZVariant;
class cIGZWinKeyAccelerator;
class cIGZWinMessageFilter;
class cIGZWinMgr;
class cRZColor;
class cRZPoint;
class cRZRect;

static const uint32_t GZIID_cIGZWin = 0x22BA0121;

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

		virtual int32_t GetW() const = 0;
		virtual int32_t GetH() const = 0;

		virtual int32_t GetL() const = 0;
		virtual int32_t GetT() const = 0;
		virtual int32_t GetR() const = 0;
		virtual int32_t GetB() const = 0;

		virtual int32_t* GetArea() const = 0;
		virtual bool GetArea(cRZRect& rect) const = 0;
		virtual int32_t* GetAreaAbsolute() const = 0;
		virtual bool GetAreaAbsolute(cRZRect& rect) const = 0;

		virtual bool SetW(int32_t value) = 0;
		virtual bool SetH(int32_t value) = 0;
		virtual bool SetSize(int32_t unknown1, int32_t unknown2) = 0;

		virtual bool SetArea(int32_t left, int32_t top, int32_t right, int32_t bottom) = 0;
		virtual bool SetArea(const cRZRect& rect) = 0;

		virtual bool GZWinMoveTo(int32_t x, int32_t y) = 0;

		virtual bool FitRectToWindow(cRZRect& unknown1, int32_t unknown2) = 0;
		virtual bool ScreenToWindowCoordinates(int32_t& unknown1, int32_t& unknown2) const = 0;
		virtual bool WindowToScreenCoordinates(int32_t& unknown1, int32_t& unknown2) const = 0;
		virtual bool WindowToWindowCoordinates(cIGZWin* unknown1, int32_t& unknown2, int32_t& unknown3) const = 0;
		virtual bool IsPointInWindowScreenCoordinates(int32_t unknown1, int32_t unknown2) const = 0;

		virtual uint32_t GetID() const = 0;
		virtual bool SetID(uint32_t id) = 0;

		virtual uint32_t GetInstanceID() const = 0;
		virtual bool SetInstanceID(uint32_t id) = 0;

		virtual bool GetFlag(uint32_t flag) const = 0;
		virtual bool SetFlag(uint32_t flag, bool value) = 0;

		virtual bool ShowWindow() = 0;
		virtual bool HideWindow() = 0;

		virtual bool IsVisible() const = 0;
		virtual bool IsEnabled() const = 0;

		virtual cIGZString* GetCaption() const = 0;
		virtual bool SetCaption(cIGZString const& caption) = 0;

		virtual cIGZWinKeyAccelerator* GetKeyboardAccelerator() = 0;
		virtual bool SetKeyboardAccelerator(cIGZWinKeyAccelerator* pWinKeyAccelerator) = 0;

		virtual bool AccelerateKeyboardMsg() = 0;

		virtual uint32_t GetKeyEquivalent() = 0;
		virtual bool SetKeyEquivalent(uint32_t value) = 0;
		virtual bool CheckKeyEquivalent(uint32_t value) = 0;
		virtual uint32_t MakeKeyEquivalent(uint32_t unknown1, uint32_t unknown2) = 0;
		virtual bool IsChildKeyEquivalent(uint32_t unknown1, uint32_t unknown2) = 0;

		virtual bool ProcessCursorMessage(cGZMessage& msg) = 0;
		virtual bool UpdateCursor() = 0;
		virtual bool SetCursor(cIGZCursor* unknown1, bool unknown2) = 0;

		virtual bool SetNotificationTarget(cIGZWin* pTarget) = 0;
		virtual cIGZWin* GetNotificationTarget() = 0;

		virtual bool GZPaint() = 0;

		virtual bool Plot() = 0;
		virtual intptr_t CalcAbsoluteArea() = 0;

		virtual void InvalidateSelf() = 0;
		virtual void InvalidateSelfAndParents() = 0;

		virtual intptr_t GetDrawContext() = 0; // cIGZDrawContext*
		virtual intptr_t GetBufferToDrawTo() = 0; // cIGZBuffer*
		virtual void SetBufferToDrawTo() = 0;
		virtual void SetBufferToDrawToRecursive() = 0;

		virtual void SetAreaToDrawTo() = 0;
		virtual void SetAreaToDrawToRecursive() = 0;
		virtual intptr_t GetAreaToDrawTo() = 0; // cRZRect*

		virtual bool PrivateBuffer(bool unknown1) = 0;
		virtual intptr_t GetPrivateBuffer() = 0;// cIGZBuffer*

		virtual void GetFillColor(uint8_t& red, uint8_t& green, uint8_t& blue) = 0;
		virtual void SetFillColor(uint8_t red, uint8_t green, uint8_t blue) = 0;
		virtual uint32_t GetFillColor() = 0;
		virtual void SetFillColor(uint32_t fillColor) = 0;
		virtual bool GetFillColor(cRZColor& fillColor) = 0;
		virtual bool SetFillColor(cRZColor const& color) = 0;
		virtual bool MakeFillColor(uint8_t red, uint8_t green, uint8_t blue) = 0;

		virtual void SetFadeEffectPeriod(int32_t unknown1, int32_t unknown2) = 0;
		virtual void GetFadeEffectPeriod(int32_t& unknown1, int32_t& unknown2) = 0;

		virtual void SetShadeColor(cRZColor const& color) = 0;
		virtual void GetShadeColor(cRZColor& color) = 0;

		virtual bool GetParam(uint32_t key, cIGZVariant** ppVariant) = 0;
		virtual bool SetParam(uint32_t key, cIGZVariant* pVariant) = 0;

		typedef bool(*EnumParamsCallback)(cIGZWin* pWin, uint32_t id, cIGZVariant* pVariant, void* pContext);
		virtual bool EnumParams(EnumParamsCallback callback, void* pContext) = 0;

		virtual bool AddMessageFilter(cIGZWinMessageFilter* unknown1) = 0;
		virtual bool RemoveMessageFilter(cIGZWinMessageFilter* unknown1) = 0;

		virtual bool SetSize(cRZPoint const& size) = 0;
		virtual void CenterWindowInRect(cRZRect* rect) = 0;
		virtual void CenterWindowInRect() = 0;

		virtual bool IsPointInWindowWindowCoordinates(int32_t x, int32_t y) = 0;
		virtual bool IsPointInWindowParentCoordinates(int32_t x, int32_t y) = 0;

		virtual bool PlotComposite() = 0;
		virtual bool PlotPresent() = 0;

		virtual void SetFillColorRGB(uint32_t fillColor) = 0;
		virtual uint32_t GetFillColorRGB() = 0;
		virtual uint32_t ConvertPackedRGBToNative(uint32_t unknown1) = 0;
		virtual uint32_t ConvertNativeToPackedRGB(uint32_t unknown1) = 0;

		virtual bool GZOnCharacter(int8_t value) = 0;
		virtual bool GZOnKeyDown(uint32_t key, uint32_t modifier) = 0;
		virtual bool GZOnKeyUp(uint32_t key, uint32_t modifier) = 0;

		virtual bool GZOnSetFocus(uint32_t unknown1, uint32_t unknown2) = 0;
		virtual bool GZOnKillFocus(cIGZWin* pWinLostTo) = 0;

		virtual bool GZOnMouseDownL(int32_t unknown1, int32_t unknown2, uint32_t unknown3) = 0;
		virtual bool GZOnMouseDownR(int32_t unknown1, int32_t unknown2, uint32_t unknown3) = 0;
		virtual bool GZOnMouseUpL(int32_t unknown1, int32_t unknown2, uint32_t unknown3) = 0;
		virtual bool GZOnMouseUpR(int32_t unknown1, int32_t unknown2, uint32_t unknown3) = 0;
		virtual bool GZOnMouseMove(int32_t unknown1, int32_t unknown2, uint32_t unknown3) = 0;
		virtual bool GZOnMouseWheel(int32_t unknown1, int32_t unknown2, uint32_t unknown3) = 0;

		virtual bool GZOnCaptureChanged(cIGZWin* pWin, uint32_t data1, uint32_t data2, uint32_t data3) = 0;

		virtual bool GZOnMouseEnter(uint32_t data1, uint32_t data2) = 0;
		virtual bool GZOnMouseExit(uint32_t data1) = 0;

		virtual bool GZOnCommand(uint32_t unknown1) = 0;

		virtual bool SendMsg(cIGZWin* pWin, cGZMessage const& msg) = 0;
		virtual bool SendMsg(cIGZWin* pWin, uint32_t msgType, uint32_t data1, uint32_t data2, uint32_t data3) = 0;
		virtual bool PostMsg(cIGZWin* pWin, cGZMessage const& msg) = 0;
		virtual bool PostMsg(cIGZWin* pWin, uint32_t msgType, uint32_t data1, uint32_t data2, uint32_t data3) = 0;
};