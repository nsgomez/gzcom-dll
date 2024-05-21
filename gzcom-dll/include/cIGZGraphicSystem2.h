#pragma once
#include "cIGZUnknown.h"

class cGZDisplayMetrics;
class cGZGPixelFormatDesc;
class cIGZGDriver;
class cIGZBuffer;
class cIGZString;
class cRZRect;

static const uint32_t GZIID_cIGZGraphicSystem2 = 0xC47B747C;

class cIGZGraphicSystem2 : public cIGZUnknown
{
public:
	virtual cIGZGDriver* GetGDriver() = 0;
	virtual uint32_t GetGDriverCount() const = 0;
	virtual cIGZGDriver* GetGDriverByIndex(uint32_t) const = 0;
	virtual cIGZGDriver* GetGDriverByID(uint32_t) const = 0;
	virtual void SetGDriver(cIGZGDriver*) = 0;

	virtual void SetDefaultDriverClassID(uint32_t) = 0;
	virtual void SetDriverSettingsIniFilePath(cIGZString const&) = 0;

	virtual bool IsScreenSettingAvailable(cGZDisplayMetrics const&, uint32_t) = 0;
	virtual bool DowngradeToAvailableScreenSetting(cGZDisplayMetrics&, uint32_t) = 0;
	virtual void SetUIRenderingMode() = 0;
	virtual bool RenderBufferToScreen(cIGZBuffer*, cRZRect const&, cRZRect const&) = 0;
	virtual void DisableScreenBuffer() = 0;

	virtual void GetScreenPixelFormat(cGZGPixelFormatDesc&) = 0;

	virtual void LazyFlush() = 0;

	virtual void SetEnableRenderToScreen(bool) = 0;

	virtual void SetForceNoTranslucency(bool, float) = 0;
	virtual bool IsTranslucencyEnabled() = 0;
	virtual float GetTranslucencyThreshold() = 0;

	virtual void EnableCursorEmulation(bool) = 0;

	virtual void EnablePageFlipping(bool) = 0;
	virtual bool IsPageFlippingEnabled() = 0;
};