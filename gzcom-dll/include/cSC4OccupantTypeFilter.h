#pragma once
#include "cISC4OccupantFilter.h"
#include "cRZUnknown.h"
#include <unordered_set>

class cISC4Occupant;
class cISCPropertyHolder;

class cSC4OccupantTypeFilter : public cISC4OccupantFilter, public cRZUnknown
{
	public:
		virtual bool IsOccupantIncluded(cISC4Occupant* pOccupant) {
			return true;
		}

		virtual bool IsPropertyHolderIncluded(cISCPropertyHolder* pProperties) {
			return true;
		}

		virtual bool IsOccupantTypeIncluded(uint32_t dwType) {
			return (m_sOccupantTypes.find(dwType) != m_sOccupantTypes.end());
		}

	public:
		void AddOccupantType(uint32_t dwType) {
			m_sOccupantTypes.insert(dwType);
		}

	protected:
		std::unordered_set<uint32_t> m_sOccupantTypes;
};