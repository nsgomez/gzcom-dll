#pragma once
#include "cIGZUnknown.h"
#include "SC4Rect.h"
#include <list>

class cISC4Lot;
class cISC4LotConfiguration;
class cISC4Occupant;
class cS3DVector3;

class cISC4LotManager : public cIGZUnknown
{
	public:
		virtual bool GetLot(int32_t nCellX, int32_t nCellY, bool bUnknown) = 0;
		virtual bool GetLot(cS3DVector3 const& sPoint) = 0;

		virtual bool GetLotsInCellRect(std::list<cISC4Lot>& sLotList, int32_t nTopLeftCellX, int32_t nTopLeftCellY, int32_t nBottomRightCellX, int32_t nBottomRightCellY, bool bUnknown) = 0;
		virtual bool GetLotsSurroundingLot(cISC4Lot const* pLot, std::list<cISC4Lot*>& sList, int32_t nFlags) = 0;
		virtual bool GetLotsSurroundingLot(int32_t nCellX, int32_t nCellY, std::list<cISC4Lot*>& sList, int32_t nFlags) = 0;
		virtual bool GetLotsSurroundingRect(SC4Rect<long> const& sRect, std::list<cISC4Lot*>& sList, int32_t nFlags) = 0;
		virtual bool GetVerticesAtEdgeOfLot(SC4Rect<long> const& sLotCells, int32_t nFlags, SC4Rect<long>& sVertices) = 0;
		virtual bool GetNeighborCellsAtEdgeOfLot(SC4Rect<long> const& sLotCells, int32_t nFlags, SC4Rect<long>& sCells) = 0;
		
		virtual cISC4Lot* GetRandomLot(void) = 0;
		virtual cISC4Lot* GetOccupantLot(cISC4Occupant* pOccupant) = 0;
		virtual intptr_t GetSafeLotIterator(void) = 0;

		virtual int32_t GetLotCount(void) = 0;
		
		virtual int32_t GetLotSavvyTerrainVertexAltitude(int32_t nPointX, int32_t nPointY, cISC4Lot* pLot, bool& bSucceeded) = 0;
		virtual int32_t GetLotSavvyTerrainAltitude(float fPointX, float fPointY, bool& bSucceeded) = 0;
		virtual int32_t GetLotSavvyCellAltitude(int32_t nCellX, int32_t nCellY, bool& bSucceeded) = 0;

		virtual bool CanCreateLot(int32_t nTopLeftCellX, int32_t nTopLeftCellY, int32_t nBottomRightCellX, int32_t nBottomRightCellY, bool bZoneNotNeeded, bool bIgnoreConfig, cISC4LotConfiguration* pConfig) = 0;
		virtual bool CanCreatePloppedLot(SC4Rect<long> sBounds, int32_t nUnknown, cISC4LotConfiguration* pConfig) = 0;

		virtual bool CreateLotIfPossible(int32_t nTopLeftCellX, int32_t nTopLeftCellY, int32_t nBottomRightCellX, int32_t nBottomRightCellY, int32_t nUnknown, bool bZoneNotNeeded, bool bIgnoreConfig, cISC4LotConfiguration* pConfig) = 0;
		virtual bool CreateLot(int32_t nTopLeftCellX, int32_t nTopLeftCellY, int32_t nBottomRightCellX, int32_t nBottomRightCellY, int32_t nUnknown, cISC4LotConfiguration* pConfig) = 0;
		virtual bool DeleteLot(cISC4Lot* pLot) = 0;
		virtual bool DeleteLots(int32_t nTopLeftCellX, int32_t nTopLeftCellY, int32_t nBottomRightCellX, int32_t nBottomRightCellY) = 0;

		virtual bool GetLotVertexAltitudeAdjustmentRange(int32_t nCellX, int32_t nCellY, float& fRangeX, float& fRangeY) = 0;
		
		virtual intptr_t GetMaximumCapacityGrid(void) = 0;
};