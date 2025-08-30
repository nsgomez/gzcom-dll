#pragma once
#include "cIGZUnknown.h"
#include "cISC4BuildingOccupant.h"
#include "cISC4ZoneManager.h"

class cIGZPersistDBSegment;
class cISC4Occupant;
class cISC4NetworkLot;
class cISC4NetworkLotConfiguration;

class cISC4NetworkLotManager : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4NetworkLot* GetNetworkLot(int32_t x, int32_t z) const = 0;
	virtual void GetNetworkLotConfigurationSet(intptr_t networkLotConfigurationSet) const = 0;
	virtual bool GetNetworkLotConfigurationById(uint32_t id, cISC4NetworkLotConfiguration* pNetworkLotConfiguration) const = 0;

	virtual cISC4Occupant* CreateProp(cISC4NetworkLot* pLot, uint32_t lotConfigurationObjectIndex, uint32_t propType) = 0;
	virtual cISC4ZoneManager::ZoneType GetZoneTypeForNetwork(int32_t x, int32_t z) = 0;
	virtual cISC4BuildingOccupant::WealthType GetWealthForNetwork(int32_t x, int32_t z) = 0;

	typedef bool (*NetworkLotIterationCallback)(uint32_t x, uint32_t z, cISC4NetworkLot* pLot, void* pContext);

	virtual bool IterateAllNetworkLots(NetworkLotIterationCallback callback, void* pContext) = 0;

	virtual void RedevelopLot(uint32_t x, uint32_t z, cISC4NetworkLot* pLot) = 0;
	virtual void SetLotConfigurationForNextPiece(cISC4NetworkLotConfiguration* pConfiguration) = 0;
	virtual bool WriteLotConfiguration(cISC4NetworkLotConfiguration* pConfiguration, cIGZPersistDBSegment* pSegment) = 0;
};