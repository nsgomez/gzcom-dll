#pragma once
#include "cIGZUnknown.h"

class cISC4Lot;
class cISC4Occupant;
class cISC4OccupantFilter;
template<typename T> class SC4CellRegion;
template<typename T> class SC4List;
template<typename T> class SC4Rect;

class cISC4Demolition : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetDefaultOccupantFilter(cISC4OccupantFilter* pFilter) = 0; // No-op
	virtual bool DemolishRegion(bool demolish, SC4CellRegion<int32_t> const& cellRegion, int32_t privilegeType, uint32_t flags, bool clearZonedArea, cISC4OccupantFilter* pOccupantFilter, int64_t* totalCost, intptr_t demolishedOccupantSet, cISC4Occupant* unknown9, long unknown10, long unknown11) = 0;
	virtual bool DemolishLots(bool demolish, SC4List<cISC4Lot*> const& lots, int32_t privilegeType, uint32_t flags, bool clearZonedArea, cISC4OccupantFilter* pOccupantFilter, int64_t* totalCost, intptr_t demolishedOccupantSet) = 0;
	virtual bool DemolishOccupant(bool demolish, cISC4Occupant* pOccupant, int32_t privilegeType, uint32_t flags, int64_t* totalCost, bool excludeNetworks, SC4List<cISC4Occupant*>* demolishedOccupants) = 0;

	virtual int32_t ModifyTerrainHeight(bool unknown1, bool unknown2, int unknown3, int unknown4, int unknown5, int unknown6, float unknown7, cISC4Lot* unknown8, uint32_t unknown9, int64_t* totalCost) = 0;
	virtual void DoDemolishOccupantEffect(cISC4Occupant* unknown1, uint32_t unknown2, cISC4Lot* unknown3, bool unknown4, long unknown5, long unknown6) = 0;
	virtual void DoDemolishGroupEffect(uint32_t unknown1, int unknown2, int unknown3, SC4Rect<int32_t> const& unknown4) = 0;
};