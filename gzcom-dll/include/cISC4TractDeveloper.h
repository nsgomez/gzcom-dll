#pragma once
#include "cIGZUnknown.h"
#include <list>
#include <vector>

class cISC4TractDeveloper : public cIGZUnknown
{
	public:
		class GrowthProfile;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool Grow(cISC4TractDeveloper::GrowthProfile const& sProfile, std::list<int32_t>& sOutcomes, bool& bUnknown) = 0;
		virtual bool Decline(cISC4TractDeveloper::GrowthProfile const& sProfile) = 0;
		virtual bool UpdatePopulation(cISC4TractDeveloper::GrowthProfile const& sProfile) = 0;

		virtual int32_t GetCurrentStyle(void) const = 0;
		virtual std::vector<uint32_t>& GetActiveStyles(void) const = 0;
		virtual bool SetActiveStyles(std::vector<uint32_t> const& sStyles) = 0;
		
		virtual bool IsUsingAllStylesAtOnce(void) const = 0;
		virtual cISC4TractDeveloper* UseAllStylesAtOnce(bool bFlag) = 0;

		virtual int32_t GetYearsBetweenStyleChanges(void) const = 0;
		virtual cISC4TractDeveloper* SetYearsBetweenStyleChanges(int32_t nYears) = 0;
};