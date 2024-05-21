#pragma once
#include "cIGZUnknown.h"

class cGZDisplayMetrics;
class cGZDisplayTiming;
class cIGZBuffer;
class cIGZCanvas;
class cIGZString;
class cRZRect;

static const uint32_t GZIID_cIGZGraphicSystem = 0x73283C;

class cIGZGraphicSystem : public cIGZUnknown
{
public:
	virtual bool CreateBuffer(uint32_t riid, void** ppvObj) = 0;
	virtual bool CreateBuffer(cIGZBuffer**) = 0;

	virtual bool IsForceSystemRAMSurfaces() = 0;
	virtual void SetForceSystemRAMSurfaces(bool) = 0;

	virtual cIGZBuffer* ScreenBuffer() = 0;
	virtual cIGZBuffer* ActiveDrawBuffer() = 0;
	virtual uint32_t GetScreenColorType() = 0;
	virtual void GetScreenMetrics(cGZDisplayMetrics&) = 0;
	virtual void GetGameMetrics(cGZDisplayMetrics&) = 0;

	virtual bool IsFullScreenMode() = 0;
	virtual bool IsScreenPaletted() = 0;

	virtual bool GetCanvas(uint32_t riid, void** ppvObj) = 0;
	virtual cIGZCanvas* GetCanvas() const = 0;
	virtual bool CanvasRect(cRZRect&) = 0;
	virtual bool Draw() = 0;

	virtual uint32_t PauseDraw() = 0;
	virtual uint32_t UnpauseDraw() = 0;
	virtual bool IsDrawPaused() const = 0;
	virtual uint32_t MessageBoxA(cIGZString const&, cIGZString const&) = 0;

	virtual uint32_t VideoMemoryFree(uint32_t videoMemoryType) = 0;
	virtual uint32_t VideoMemoryTotal(uint32_t videoMemoryType) = 0;
	virtual uint32_t VideoMemory(uint32_t videoMemoryType, bool freeMemory) = 0;

	virtual void TraceDriverInformation() = 0;
	virtual bool GetVideoDriverVersionInformation(uint32_t&, uint32_t&) = 0;
	virtual uint32_t GetVideoDriverInfoCount() = 0;
	virtual bool GetVideoDriverInfo(cIGZString&, cIGZString&, uint32_t) = 0;
	virtual bool GetVideoDriverInfoCurrent(cIGZString&, cIGZString&) = 0;

	virtual int32_t ShowCursor(bool) = 0;
	virtual bool SetCursorBuffer(cIGZBuffer*, long, long) = 0;
	virtual bool DoesSystemHaveCursorSupport() = 0;
	virtual bool GetCursorPosition(long&, long&) = 0;

	virtual bool ConvertRGBValueToNative(uint32_t&, unsigned char, unsigned char, unsigned char) = 0;
	virtual bool ConvertRGBValueToNative(unsigned char, unsigned char, unsigned char) = 0;
	virtual bool ConvertNativeValueToRGB(uint32_t, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool RGBToHSB(unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool RGBToHSB(unsigned char, unsigned char, unsigned char, float&, float&, float&) = 0;
	virtual bool HSBToRGB(unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool HSBToRGB(float, float, float, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool RGBToHLS(unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool RGBToHLS(unsigned char, unsigned char, unsigned char, float&, float&, float&) = 0;
	virtual bool HLSToRGB(unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool HLSToRGB(float, float, float, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool RGBToCYM(unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool CYMToRGB(unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool RGBToCYMK(unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&, unsigned char&) = 0;
	virtual bool CYMKToRGB(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char&, unsigned char&, unsigned char&) = 0;

	virtual void GetScreenTiming(cGZDisplayTiming&) = 0;
	virtual void GetRefreshRate(float&) = 0;
	virtual void GetRefreshRateAvg(float&) = 0;
	virtual void GetRefreshRateAvgLong(float&) = 0;

	virtual bool PreInitSetDesiredGameResolution(cGZDisplayMetrics const&) = 0;
	virtual bool PreInitSetHardware3DAccellerationUse(bool) = 0;
	virtual bool PreInitSetWindowedMode(bool) = 0;
	virtual bool PreInitSetDesiredVRAMForTextures(uint32_t) = 0;
	virtual bool PreInitSetDesiredVideoDriverIdentifier(unsigned char*) = 0;

	virtual uint32_t GetTotalSurfaceMemory() = 0;
	virtual uint32_t GetTotalSystemSurfaceMemory() = 0;
	virtual uint32_t GetTotalVideoSurfaceMemory() = 0;
	virtual bool IncrementTotalSystemSurfaceMemory(uint32_t) = 0;
	virtual bool DecrementTotalSystemSurfaceMemory(uint32_t) = 0;
	virtual bool IncrementTotalVideoSurfaceMemory(uint32_t) = 0;
	virtual bool DecrementTotalVideoSurfaceMemory(uint32_t) = 0;

	virtual cIGZString* MakeMemoryUsageString() = 0;
	virtual bool OnCanvasInit() = 0;
	virtual bool OnCanvasShutdown() = 0;
	virtual bool OnCanvasReInit() = 0;
};
