#pragma once
#include "cIGZUnknown.h"

class cISC4Lot;
class SC4Percentage;

template <typename T> class SC4Point;
template <typename T> class SC4Vector;

class cISC4PortDeveloper : public cIGZUnknown
{
public:
	enum class ePortSize : int32_t
	{
		All = 0,
		Small = 1,
		Medium = 2,
		Large = 3,
	};

	inline int32_t PortSizeEnumToFlag(ePortSize value)
	{
		switch (value)
		{
		case cISC4PortDeveloper::ePortSize::Small:
			return 1;
		case cISC4PortDeveloper::ePortSize::Medium:
			return 2;
		case cISC4PortDeveloper::ePortSize::Large:
			return 4;
		case cISC4PortDeveloper::ePortSize::All:
		default:
			return 31;
		}
	}

	enum ePortGrowthStages : int32_t
	{
		// These values are bit flags.

		PortGrowthStage_Stage1 = 1,
		PortGrowthStage_Stage2 = 2,
		PortGrowthStage_Stage3 = 4,

		// The All flag value is 31 in the game code, which implies
		// that there could be stage 4 and stage 5 in the enumeration.

		PortGrowthStage_Stage4 = 8,
		PortGrowthStage_Stage5 = 16,
		PortGrowthStage_All = PortGrowthStage_Stage1 | PortGrowthStage_Stage2 | PortGrowthStage_Stage3 | PortGrowthStage_Stage4 | PortGrowthStage_Stage5
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual SC4Percentage GetAvgEfficiency() = 0;
	virtual uint32_t GetSimulatorType() = 0;
	virtual bool GetLeastEfficientPort(SC4Percentage&, SC4Point<int32_t>&) = 0;
	virtual void GetAllPortLots(SC4Vector<cISC4Lot*>&) = 0;

	/**
	 * @brief Gets the number of ports matching the specified criteria.
	 * @param portSizeFlags A combination of ePortSize values. See PortSizeEnumToFlag.
	 * @param growthStages The a bitwise combination of ePortGrowthStages.
	 * @return The number of ports matching the specified criteria.
	 */
	virtual uint32_t GetNumPorts(int32_t portSizeFlags, ePortGrowthStages growthStages) = 0;
};