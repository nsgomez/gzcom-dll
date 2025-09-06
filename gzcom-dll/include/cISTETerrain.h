#pragma once
#include "cISTETerrainMap.h"

class cIGZPersistDBSegment;
class cISTETerrainView;
template<typename T> class SC4Point;

class cISTETerrain : public cISTETerrainMap
{
public:
	enum class eBrushTypes : int32_t
	{
		Mesa = 0,
		Volcano,
		CanyonSoft,
		Level,
		Smoothing,
		Unknown,
		Flora
	};

	enum class eHilightColorType : int
	{
		Red = 0,
		Green = 1,
		Blue = 2,
		Yellow = 3,
		Black = 4
	};

	struct tBrushParameters;

	struct tUIElementsForBrush
	{
		uint32_t unknown1;
		uint32_t unknown2;
		uint32_t unknown3;
		uint32_t unknown4;
		uint32_t unknown5;
		uint32_t unknown6;
		uint32_t unknown7;
		uint32_t unknown8;
		uint32_t unknown9;
		uint32_t unknown10;
	};

	virtual void DoPostCityInit() = 0;
	virtual bool SetTerrainType(int32_t unknown1) = 0;
	virtual int32_t TerrainType() = 0;
	virtual void CreateFlatAreas(bool unknown1) = 0;
	virtual bool CreateShoreCliffs(bool unknown1) = 0;

	virtual bool SetSeaLevel(float unknown1) = 0;
	virtual bool ChangeSeaLevel(bool unknown1) = 0;
	virtual float GetDefaultTerrainRaiseLowerAmount() const = 0;
	virtual void ChangeTerrainLevel(bool unknown1, float unknown2) = 0;

	virtual void SetAltitude(int32_t index, float unknown2) = 0;
	virtual void SetAltitudeAtVertex(int32_t x, int32_t z, float unknown3) = 0;
	virtual void SetAltitude(SC4Rect<int32_t> const& unknown1, float unknown2, bool unknown3, uint32_t unknown4) = 0;
	virtual void LockAltitude(SC4Rect<int32_t> const& unknown1, bool unknown2) = 0;

	virtual uint32_t NumberOfWaterVertices() const = 0;
	virtual uint32_t NumberOfWaterVertices(SC4Rect<int32_t> const& unknown1) = 0;
	virtual float GetSedimentValue(float x, float z) = 0;
	virtual void StartFlood() = 0;
	virtual bool ApplyBrush(uint32_t unknown1, tBrushParameters& unknown2) = 0;
	virtual bool GetBrushExemplarID(eBrushTypes type, uint32_t& unknown2) = 0;
	virtual void BeginBrushScrub(uint32_t unknown1) = 0;
	virtual void EndBrushScrub(uint32_t unknown1, uint32_t unknown2) = 0;
	virtual float BrushRadius(uint32_t unknown1) const = 0;
	virtual int64_t GetCostPerBrushApplication(uint32_t unknown1) = 0;
	virtual bool GetUIElementsForBrush(uint32_t unknown1, tUIElementsForBrush& unknown2) const = 0;
	virtual void UpdateWaveProducers() = 0;
	virtual bool IsGoodWaveProducerLocation(float unknown1, float unknown2, float unknown3) const = 0;

	virtual cISTETerrainView* GetView() = 0;
	virtual void DoLighting(SC4Rect<int32_t> const& unknown1) = 0;

	virtual void RedisplayTerrain(bool unknown1, bool unknown2, SC4Point<int32_t> const& unknown3, SC4Point<int32_t> const& unknown4, uint32_t unknown5) = 0;
	virtual void RedisplayTerrain(bool unknown1, bool unknown2, SC4Rect<int32_t> const& unknown3, uint32_t unknown4) = 0;
	virtual bool IsTriangulationFlipped(uint32_t x, uint32_t z) = 0;
	virtual void HideTerrainCell(uint32_t x, uint32_t z, bool unknown3) = 0;
	virtual void HideEvenTriangle(uint32_t x, uint32_t z, bool unknown3) = 0;
	virtual void HideOddTriangle(uint32_t x, uint32_t z, bool unknown3) = 0;

	virtual bool IsEvenTriangleHidden(uint32_t x, uint32_t z) const = 0;
	virtual bool IsOddTriangleHidden(uint32_t x, uint32_t z) const = 0;
	virtual bool IsWholeCellHidden(uint32_t x, uint32_t z) const = 0;
	virtual bool IsPointHidden(float x, float z) const = 0;

	virtual void StartAccumulatingTextureUpdates() = 0;
	virtual void StopAccumulatingTextureUpdates() = 0;
	virtual bool IsAccumulatingTextureUpdates() = 0;

	virtual bool SetTerrainCellFlags(uint32_t cX, uint32_t cZ, uint32_t flags) = 0;
	virtual uint32_t GetTerrainCellFlags(uint32_t cX, uint32_t cZ) = 0;

	virtual bool GetWaterSurfaceDisplayState() = 0;
	virtual void SetWaterSurfaceDisplayState(bool unknown1) = 0;
	virtual bool GetPlumbingInfoDisplayState() = 0;
	virtual void SetPlumbingInfoDisplayState(bool unknown1) = 0;

	virtual void BeginLongTerrainOperation() = 0;
	virtual void EndLongTerrainOperation() = 0;

	virtual void ReconcileEdgesWithNeighboringCities(bool unknown1, bool unknown2, bool unknown3) = 0;
	virtual bool SaveObliterated(cIGZPersistDBSegment* unknown1) = 0;
};
