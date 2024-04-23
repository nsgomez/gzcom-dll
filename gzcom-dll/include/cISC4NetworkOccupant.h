#pragma once
#include "cIGZUnknown.h"

class cIS3DModelInstance;
class cISC4Occupant;
class cS3DVector3;
class cSC4EdgeConnectionStore;

static const uint32_t GZIID_cISC4NetworkOccupant = 0xA821EF94;

class cISC4NetworkOccupant : public cIGZUnknown
{
public:
	enum eNetworkType : uint32_t
	{
		Road = 0,
		Rail = 1,
		Highway = 2,
		Street = 3,
		WaterPipe = 4,
		PowerPole = 5,
		Avenue = 6,
		Subway = 7,
		LightRail = 8,
		Monorail = 9,
		OneWayRoad = 10,
		DirtRoad = 11,
		GroundHighway = 12,
	};

	virtual bool Init(float const unknownArray[3]) = 0;
	virtual bool Shutdown() = 0;

	virtual bool IsManagedGlobally() const = 0;
	virtual bool CheckForRetrofit() = 0;
	virtual void SetRetrofitFlag(bool value) = 0;

	virtual bool HasNetworkFlag(uint32_t flag) const = 0;
	virtual bool HasAnyNetworkFlag(uint32_t flag) const = 0;
	virtual void SetNetworkFlag(uint32_t flag) = 0;
	virtual void ClearNetworkFlag(uint32_t flag) = 0;
	virtual uint32_t GetNetworkFlag() = 0;

	virtual bool GetConnectionNodeEdgeTypes(uint32_t& unknown1, uint32_t& unknown2) = 0;
	virtual void SetConnectionNodeEdgeTypes(uint32_t unknown1, uint32_t unknown2) = 0;
	virtual uint32_t GetConnectionPathIDOverride() = 0;
	virtual void SetConnectionPathIDOverride(uint32_t unknown1) = 0;

	virtual bool IsImmovable() const = 0;
	virtual void SetImmovable(bool value) = 0;

	virtual bool IsUsable() const = 0;
	virtual void SetUsable(bool value) = 0;

	virtual bool IsPlaced() = 0;
	virtual bool IsOfType(eNetworkType type) const = 0;

	virtual uint32_t PieceId() const = 0;
	virtual uint8_t GetRotation() const = 0;
	virtual uint8_t GetFlip() const = 0;
	virtual uint8_t GetRotationAndFlip() const = 0;

	virtual void SetVariation(uint8_t value) = 0;
	virtual uint8_t GetVariation() = 0;

	virtual void SetUnderTexture(uint32_t value) = 0;
	virtual void SetQuadDraw(uint32_t unknown1, uint8_t unknown2) = 0;

	virtual void AddPart(float const unknown1[3], float const unknown2[2], uint32_t const* unknown3, uint32_t unknown4) = 0;
	virtual bool HasViewDependentModel() = 0;
	virtual void GetModelInstances(int32_t unknown1, int32_t unknown2, cIS3DModelInstance** unknown3, int32_t unknown4, int32_t* unknown5) = 0;

	virtual void GetVertexHeights(float unknown1[4]) const = 0;
	virtual float GetVertexHeight(int32_t unknown1) const = 0; // Not sure if the return value is double or float
	virtual void SetVertexHeights(float const unknown1[4]) = 0;

	virtual void SetEdgeTypesFlag(eNetworkType type, uint32_t unknown2) = 0;
	virtual uint32_t GetEdgeTypesFlag(eNetworkType type) = 0;
	virtual void SetEdgeType(eNetworkType type, int32_t unknown2, uint8_t unknown3) = 0;

	virtual uint32_t GetActiveEdges() = 0;
	virtual uint32_t GetActiveEdgesForType(eNetworkType type) = 0;
	virtual uint32_t GetActiveEdgesForTypeNoGroup(eNetworkType type) = 0;
	virtual uint32_t GetGroupedEdges() = 0;
	virtual void SetEdgeStore(cSC4EdgeConnectionStore const& unknown1) = 0;
	virtual cSC4EdgeConnectionStore* GetEdgeStore() const = 0;

	virtual void MarkLightingUpdateNeeded() = 0;
	virtual bool ConnectsToNeighbor(int32_t unknown1, eNetworkType type) = 0;
	virtual cISC4Occupant* AsOccupant() = 0;

	virtual intptr_t GetPathInfo() = 0;
	virtual void ReleasePathInfo() = 0;

	virtual void SetPathIDOverride(uint32_t unknown1) = 0;
	virtual uint32_t GetPathIDOverride() = 0;

	virtual void AddPathConnection(uint32_t pathType, uint8_t unknown2, uint8_t unknown3) = 0;
	virtual bool PathConnectionExists(uint32_t pathType, uint8_t unknown2, uint8_t unknown3) = 0;

	virtual bool IsIntersection() const = 0;

	virtual float GetAltitude(float unknown1, float unknown2) const = 0; // Not sure if the return value is double or float
	virtual float GetNormal(float unknown1, float unknown2) const = 0;
	virtual void SetTranslucency(bool unknown1, uint8_t unknown2) = 0;
	virtual void GetOccupiedCell(uint32_t& unknown1, uint32_t& unknown2) = 0;

	virtual bool IsLit() const = 0;
	virtual void SetLit(bool unknown1) = 0;
	virtual bool CanBeLit() const = 0;

	virtual int64_t GetCostOfDemolition() = 0;
	virtual void SetCostOfDemolition(int64_t value) = 0;

	virtual void TransformNode(cS3DVector3& vector) = 0;
	virtual bool IsPartOfTheSameStructure(class cISC4NetworkOccupant* unknown1) = 0;

	virtual bool GetPassageCeiling(float& unknown1) = 0;
	virtual void SetPassageCeiling(float unknown1) = 0;

	virtual uint8_t GetOneWayDirections() = 0;
	virtual void SetOneWayDirections(uint8_t unknown1) = 0;

	virtual bool GetComplexPieceOrigin(long& unknown1, long& unknown2) = 0;
	virtual void SetComplexPieceOrigin(long unknown1, long unknown2) = 0;

	virtual bool IsSupportPylonPresent() const = 0;
};