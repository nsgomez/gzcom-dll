#pragma once
#include "cIGZUnknown.h"
#include "SC4Point.h"
#include <vector>

class cISC4Occupant;

class cISC4LotBaseTextureOccupant : public cIGZUnknown
{
	public:
		class LotBaseTextureSpecification;

		virtual cISC4Occupant* AsOccupant(void) = 0;

		virtual int32_t GetUsage(void) = 0;
		virtual bool SetUsage(int32_t) = 0;

		virtual bool GetCellCoverage(std::vector<SC4Point<int>>&, std::vector<bool>*) = 0;
		virtual bool IsCellCovered(int32_t, int32_t, bool*) = 0;
		
		virtual bool SetTextureSpecification(cISC4LotBaseTextureOccupant::LotBaseTextureSpecification const*, uint32_t, bool*) = 0;

		virtual bool UpdateVertexAltitudes(bool, bool, bool*) = 0;

		virtual bool LoadModels(bool) = 0;
		virtual bool UnloadModels(void) = 0;
};