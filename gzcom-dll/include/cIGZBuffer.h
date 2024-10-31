#pragma once
#include "cIGZUnknown.h"
#include "cGZBufferType.h"

class cGZBufferColorType;
class cIGZBufferHardwareCache;
template<typename T> class SC4Rect;

class cIGZBuffer : public cIGZUnknown
{
public:
	virtual bool Init(int width, int height, cGZBufferType bufferType, int bitsPerPixel) = 0;
	virtual bool Shutdown() = 0;
	virtual bool Uninitialize() = 0;

	virtual bool Lock(uint32_t lockFlags) = 0;
	virtual bool Unlock(uint32_t lockFlags) = 0;
	virtual bool IsLocked() = 0;

	virtual int32_t Width() const = 0;
	virtual int32_t Height() const = 0;

	virtual SC4Rect<int32_t>* GetBufferArea() const = 0;
	virtual void GetBufferArea(SC4Rect<int32_t>& rect) const = 0;
	virtual uint32_t GetMemoryUsage() const = 0;

	virtual cGZBufferColorType GetColorType() const = 0;
	virtual void GetColorType(cGZBufferColorType& colorType) const = 0;
	virtual uint32_t GetBitsPerPixel() const = 0;
	virtual uint32_t GetBytesPerPixel() const = 0;

	virtual bool Fill(uint32_t value, SC4Rect<int32_t> const& bounds, SC4Rect<int32_t>* outFilledBounds) = 0;
	virtual bool Fill(uint32_t value, int32_t left, int32_t top, int32_t right, int32_t bottom, SC4Rect<int32_t>* outFilledBounds) = 0;
	virtual bool Fill(uint32_t value, SC4Rect<int32_t>* outFilledBounds) = 0;

	virtual uint32_t GetPixel(uint32_t x, uint32_t y) const = 0;
	virtual void SetPixel(uint32_t x, uint32_t y, uint32_t value) = 0;

	virtual void SetTransparency(uint32_t transparentColor) = 0;
	virtual bool GetTransparency() const = 0; // Indicates if the buffer supports transparent colors
	virtual bool IsPixelTransparent(uint32_t x, uint32_t y) = 0;
	virtual bool GetTransparentColor(uint32_t& transparentColor) const = 0;
	virtual void RemoveTransparency() = 0;

	virtual bool DrawLine(int32_t unknown1, int32_t unknown2, int32_t unknown3, int32_t unknown4, int32_t unknown5, uint32_t unknown6) = 0;
	virtual bool Blt(cIGZBuffer* unknown1, SC4Rect<int32_t> const& unknown2, SC4Rect<int32_t> const& unknown3, SC4Rect<int32_t> const& unknown4) = 0;

	virtual uint32_t ConvertRGBValueToNative(uint8_t red, uint8_t green, uint8_t blue) = 0;
	virtual bool ConvertNativeValueToRGB(uint32_t value, uint8_t& outRed, uint8_t& outGreen, uint8_t& outBlue) = 0;
	virtual uint32_t ConvertRGBAValueToNative(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) = 0;
	virtual bool ConvertNativeValueToRGBA(uint32_t value, uint8_t& outRed, uint8_t& outGreen, uint8_t& outBlue, uint8_t& outAlpha) = 0;

	virtual void* GetColorSurfaceBits() = 0;
	virtual uint32_t GetColorSurfaceStride() = 0;

	virtual uint32_t GetChangeCounter() = 0;
	virtual cIGZBufferHardwareCache* GetHardwareCache() = 0;
	virtual bool SetHardwareCache(cIGZBufferHardwareCache* cache) = 0;
	virtual bool IsReady() = 0;
};