/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4OccupantManager.h
 *
 * Copyright (C) 2016 Nelson Gomez
 * Copyright (C) 2025 Nicholas Hayes
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, under
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include "cIGZUnknown.h"

class cISC4Occupant;
class cISC4OccupantFilter;

template <typename T> class SC4List;

class cISC4OccupantManager : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool SetCitySize(float fX, float fZ) = 0;
		virtual bool GetOccupantManagerCellSizes(float& fX, float& fZ) = 0;
		virtual bool GetWorldCellCount(int& nX, int& nZ) = 0;
		virtual bool GetOccupantManagerCellCount(int& nX, int& nZ) = 0;
		virtual bool GetOccupantManagerCellBounds(int& nTL, int& nTR, int& nBL, int& nBR) = 0;
		virtual bool WorldCellToOccupantManagerCell(int nX, int nZ, int& nManagerX, int& nManagerZ) = 0;
		virtual bool OccupantManagerCellToWorldCell(int nX, int nZ, int& nWorldX, int& nWorldZ) = 0;
		virtual bool WorldCellToStandardCityCell(int nX, int nZ, int& nCityX, int& nCityZ) = 0;
		virtual bool StandardCityCellToWorldCell(int nX, int nZ, int& nWorldX, int& nWorldZ) = 0;
		virtual bool WorldCellToPosition(int nX, int nZ, float& fX, float& fZ) = 0;
		virtual bool PositionToWorldCell(float fX, float fZ, int& nX, int& nZ) = 0;
		virtual bool OccupantManagerCellToPosition(int nX, int nZ, float& fX, float& fZ) = 0;
		virtual bool PositionToOccupantManagerCell(float fX, float fZ, int& nX, int& nZ) = 0;
		virtual bool StandardCityCellToPosition(int nX, int nZ, float& fX, float& fZ) = 0;
		virtual bool PositionToStandardCityCell(float fX, float fZ, int& nX, int& nZ) = 0;

		virtual bool InsertOccupant(cISC4Occupant* pOccupant, uint32_t dwMsgData) = 0;
		virtual bool RemoveOccupant(cISC4Occupant*, bool bShutOccupantDown, uint32_t dwMsgData) = 0;
		virtual bool RemoveOccupants(int32_t dwUnknown, bool bShutOccupantsDown, uint32_t dwMsgData) = 0;
		virtual bool RemoveOccupants(cISC4OccupantFilter* pFilter, bool bShutOccupantsDown, uint32_t dwMsgData) = 0;
		virtual bool MoveOccupant(cISC4Occupant* pOccupant, bool bUnknown) = 0;

		virtual bool IsCellEmpty(int32_t nX, int32_t nZ) = 0;
		virtual int32_t GetBoundingCells(int nUnknown1, int nUnknown2, int* nUnknown3[2], int& nUnknown4) = 0;
		
		virtual bool FindOccupant(cISC4Occupant* pOccupant, bool bUnknown, int* nX, int* nZ) = 0;
		virtual bool GetFirstOccupantByPosition(cISC4Occupant*& ppOccupant, float fX, float fZ, uint32_t dwUnknown) = 0;
		virtual bool GetFirstOccupantByPosition(cISC4Occupant*& ppOccupant, float fX, float fZ, cISC4OccupantFilter* pFilter) = 0;
		virtual bool GetFirstOccupant(cISC4Occupant*& ppOccupant, int nX, int nZ, uint32_t dwUnknown) = 0;
		virtual bool GetFirstOccupant(cISC4Occupant*& ppOccupant, int nX, int nZ, cISC4OccupantFilter* pFilter) = 0;
		virtual bool GetFirstOccupantByStandardCityCell(cISC4Occupant*& ppOccupant, int nX, int nZ, uint32_t dwUnknown) = 0;
		virtual bool GetFirstOccupantByStandardCityCell(cISC4Occupant*& ppOccupant, int nX, int nZ, cISC4OccupantFilter* pFilter) = 0;
		virtual bool GetFirstOccupantByStandardCityCells(cISC4Occupant*& ppOccupant, int const* nXCells, int const* nZCells, uint32_t dwUnknown) = 0;
		virtual bool GetFirstOccupantByStandardCityCells(cISC4Occupant*& ppOccupant, int const* nXCells, int const* nZCells, cISC4OccupantFilter* pFilter) = 0;

		virtual bool GetOccupantsByBBox(SC4List<cISC4Occupant*>& sOccupants, float const* fXCells, float const* fZCells, uint32_t dwType, uint32_t dwUnknown) = 0;
		virtual bool GetOccupantsByBBox(SC4List<cISC4Occupant*>& sOccupants, float const* fXCells, float const* fZCells, cISC4OccupantFilter* pFilter, uint32_t dwUnknown) = 0;
		virtual bool GetOccupantsByOccupantManagerCells(SC4List<cISC4Occupant*>& sOccupants, int const* fXCells, int const* fZCells, uint32_t dwType, uint32_t dwUnknown) = 0;
		virtual bool GetOccupantsByOccupantManagerCells(SC4List<cISC4Occupant*>& sOccupants, int const* fXCells, int const* fZCells, cISC4OccupantFilter* pFilter, uint32_t dwUnknown) = 0;
		virtual bool GetOccupantsByStandardCityCells(SC4List<cISC4Occupant*>& sOccupants, int const* fXCells, int const* fZCells, uint32_t dwType, uint32_t dwUnknown) = 0;
		virtual bool GetOccupantsByStandardCityCells(SC4List<cISC4Occupant*>& sOccupants, int const* fXCells, int const* fZCells, cISC4OccupantFilter* pFilter, uint32_t dwUnknown) = 0;

		virtual bool IterateOccupantsByBBox(bool(*pfIterator)(cISC4Occupant*, void*), void* pData, float const* pfUnknown1, float const* pfUnknown2, uint32_t dwUnknown) = 0;
		virtual bool IterateOccupantsByBBox(bool(*pfIterator)(cISC4Occupant*, void*), void* pData, float const* pfUnknown1, float const* pfUnknown2, cISC4OccupantFilter* pFilter) = 0;
		virtual bool IterateOccupants(bool(*pfIterator)(cISC4Occupant*, void*), void* pData, int const* pnUnknown1, int const* pnUnknown2, uint32_t dwUnknown) = 0;
		virtual bool IterateOccupants(bool(*pfIterator)(cISC4Occupant*, void*), void* pData, int const* pnUnknown1, int const* pnUnknown2, cISC4OccupantFilter* pFilter) = 0;
		virtual bool IterateOccupantsByStandardCityCell(bool(*pfIterator)(cISC4Occupant*, void*), void* pData, int const* pnUnknown1, int const* pnUnknown2, uint32_t dwUnknown) = 0;
		virtual bool IterateOccupantsByStandardCityCell(bool(*pfIterator)(cISC4Occupant*, void*), void* pData, int const* pnUnknown1, int const* pnUnknown2, cISC4OccupantFilter* pFilter) = 0;

		virtual bool ReleaseOccupantList(SC4List<cISC4Occupant*>& sList) = 0;
};