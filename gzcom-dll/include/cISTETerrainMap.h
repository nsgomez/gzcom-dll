#pragma once
#include "cIGZUnknown.h"

class cS3DVector3;
template<typename T> class SC4Rect;

class cISTETerrainMap : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;
	virtual bool IsInitialized() = 0;

	virtual uint32_t CellWidth() = 0;
	virtual uint32_t CellCountX() = 0;
	virtual uint32_t CellCountZ() = 0;

	virtual int32_t GetVertIndex(int32_t x, int32_t z) const = 0;
	virtual void GetVertex(int32_t index, int32_t& x, int32_t& z) const = 0;
	virtual bool LocationIsInBounds(float x, float z) const = 0;

	virtual float GetAltitude(float x, float z) = 0;
	virtual float GetAltitude(int32_t index) = 0;
	virtual float GetAltitudeAtVertex(int32_t x, int32_t z) = 0;
	virtual void GetAltitudes(SC4Rect<int32_t> const& unknown1, float* unknown2, int32_t unknown3, int32_t unknown4) = 0;
	virtual void GetWaterDepths(SC4Rect<int32_t> const& unknown1, float* unknown2, int32_t unknown3, int32_t unknown4) = 0;
	virtual void GetCellCornerAltitudes(uint32_t unknown1, uint32_t unknown2, float* unknown3) = 0;
	virtual float GetMaxSurfaceLevel(uint32_t x, uint32_t z) = 0;
	virtual float GetAltitudeAtNearestGrid(float x, float z) = 0;
	virtual float GetAltitudeCheckSum(SC4Rect<int32_t> const& unknown1) const = 0;

	virtual float MinHeight() = 0;
	virtual float MaxHeight() = 0;
	virtual float MinAllowedHeight() = 0;
	virtual float MaxAllowedHeight() = 0;

	virtual int32_t GetTerrainGridIndex(float unknown1, float unknown2) = 0;
	virtual void GetFaceNormal(float unknown1, float unknown2, cS3DVector3& unknown3) = 0;
	virtual void GetLerpedNormal(float unknown1, float unknown2, cS3DVector3& unknown3) = 0;
	virtual void GetVertexNormal(uint32_t unknown1, uint32_t unknown2, cS3DVector3& unknown3) = 0;

	virtual float GetSeaLevel() const = 0;
	virtual float GetWaterLevel(int32_t index) = 0;
	virtual float GetWaterLevel(float unknown1, float unknown2) = 0;
	virtual float GetLerpedWaterLevel(float unknown1, float unknown2) = 0;
	virtual float GetWaterDepthAtVertex(int32_t unknown1, int32_t unknown2) = 0;
	virtual bool CellHasWater(uint32_t unknown1, uint32_t unknown2) const = 0;
	virtual bool CellHasLand(uint32_t unknown1, uint32_t unknown2) const = 0;
	virtual bool IsLandVertex(uint32_t unknown1, uint32_t unknown2) const = 0;
	virtual bool IsWaterVertex(uint32_t unknown1, uint32_t unknown2) const = 0;
	virtual bool IsSeaVertex(uint32_t unknown1, uint32_t unknown2) const = 0;
	virtual bool AreSeaVertices(SC4Rect<int32_t> const& unknown1) const = 0;
};