#pragma once
#include "cIGZUnknown.h"

class cISC4City;
class cISC4NeighborConnection;
class cISC4NeighborDeal;
class cISC4Occupant;
class cISC4RegionalCity;
class cISCResExemplar;

template <typename T> class SC4List;

class cISC4NeighborsSimulator : public cIGZUnknown
{
public:
	enum class ConnectionType : uint32_t
	{
		None = 0,
		Rail = 1,
		Road = 2,
		Highway = 3,
		PowerPole = 4,
		Pipe = 5,
		Subway = 6,
		LightRail = 7,
		Avenue = 8,
		Ferry = 9,
		DirtRoad = 10,
		Monorail = 11,
		GroundHighway = 12
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool RequestCreateConnection(ConnectionType type, int32_t x, int32_t z, bool unknown4) = 0;
	virtual cISC4NeighborConnection* CreateConnection(ConnectionType type, int32_t x, int32_t z, bool unknown4) = 0;
	virtual void DeleteConnection(ConnectionType type, int32_t x, int32_t z) = 0;
	virtual void DeleteOccupantConnection(cISC4Occupant* pOccupant) = 0;
	virtual void DeleteAllConnectionsOfType(ConnectionType type) = 0;

	virtual bool HasConnection(ConnectionType type, int32_t x, int32_t z) const = 0;
	virtual cISC4NeighborConnection* FindConnection(ConnectionType type, int32_t x, int32_t z) = 0;
	virtual cISC4RegionalCity* FindCityOnOtherSideOfConnection(int32_t x, int32_t z) = 0;
	virtual cISC4NeighborConnection* FindConnectionOnOtherSide(ConnectionType connectionType, int32_t x, int32_t z) = 0;
	virtual cISC4NeighborConnection* FindConnectionOnOtherSide(cISC4NeighborConnection* pConnection) = 0;
	virtual cISC4NeighborConnection* FindUnvisitedConnection(ConnectionType type, cISC4RegionalCity const* pRegionalCity) = 0;

	virtual void GetAllConnections(SC4List<cISC4NeighborConnection*>& list) const = 0;
	virtual void GetConnectionsOfType(ConnectionType type, SC4List<cISC4NeighborConnection*>& list) const = 0;
	virtual void GetConnectionsOfTypeToCity(ConnectionType type, cISC4RegionalCity const* pRegionalCity, SC4List<cISC4NeighborConnection*>& list) const = 0;
	virtual void GetConnectionsToCity(cISC4RegionalCity const* pRegionalCity, SC4List<cISC4NeighborConnection*>& list) = 0;
	virtual void GetAdjacentCities(SC4List<cISC4RegionalCity*>& list, bool includeUnestablished) = 0;
	virtual void GetConnectedCities(SC4List<cISC4RegionalCity*>& list, bool includeUnestablished) = 0;
	virtual void GetAllConnectedCities(SC4List<cISC4RegionalCity*>& list, bool includeUnestablished) = 0;
	virtual cISC4NeighborConnection* FindConnectionSuitableForDeal(int32_t dealType, cISC4RegionalCity const* pRegionalCity) = 0;
	virtual bool ProposeDeal(int32_t dealType, cISC4RegionalCity* otherCity, cISC4NeighborDeal** outDeal) = 0;
	virtual bool ProposeDeals(SC4List<cISC4NeighborConnection*>& deals, bool unknown2) = 0;
	virtual bool AddDeal(cISC4NeighborDeal* pDeal) = 0;
	virtual void SetUIDisableFlag(bool flag) = 0;
	virtual void FindDealsAll(SC4List<cISC4NeighborConnection*>& deals) = 0;
	virtual void FindDeals(int32_t dealType, SC4List<cISC4NeighborConnection*>& deals) = 0;
	virtual void FindDeals(int32_t dealType, cISC4RegionalCity* pRegionalCity, SC4List<cISC4NeighborConnection*>& deals) = 0;
	virtual void MarkDealsDirty() = 0;

	virtual int64_t GetTotalMonthlyNeighborDealIncome() = 0;
	virtual int64_t GetTotalMonthlyNeighborDealExpense() = 0;
	virtual void UpdateCommodityStats(cISC4City* pCity) = 0;

	virtual int64_t GetDealCost(int32_t dealType, double unknown2, cISC4RegionalCity const* pRegionalCity) = 0;
	virtual int64_t GetDealMaxAmount(int32_t dealType, cISC4RegionalCity const* pRegionalCity) = 0;
	virtual cISCResExemplar* GetTuningExemplar() = 0;
};