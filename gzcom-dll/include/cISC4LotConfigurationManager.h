#pragma once
#include "cIGZUnknown.h"
#include <unordered_set>
#include <vector>

class cGZPersistResourceKey;
class cISC4LotConfiguration;
class cISC4LotConfigurationFilter;
class cS3DRect2D;
class cSC4LotConfigurationObject;

class cISC4LotConfigurationManager : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool AddLotConfiguration(cISC4LotConfiguration* pConfig, bool bUnknown) = 0;
		virtual bool AddLotConfiguration(cGZPersistResourceKey const& sUnknown, void* pUnknown) = 0;
		virtual bool RemoveLotConfiguration(uint32_t dwConfigID) = 0;
		
		virtual cISC4LotConfiguration* GetLotConfiguration(uint32_t dwConfigID) = 0;
		virtual bool GetLotConfigurationsByFilter(std::unordered_set<cISC4LotConfiguration*>& sConfigs, cISC4LotConfigurationFilter* pFilter) = 0;
		virtual bool GetLotConfigurationsByFamily(std::unordered_set<cISC4LotConfiguration*>& sConfigs, uint32_t dwFamily) = 0;
		virtual bool GetLotConfigurationsBySize(std::unordered_set<cISC4LotConfiguration*>& sConfigs, uint32_t sX, uint32_t sZ) = 0;
		virtual bool ClearLotConfigurationSet(std::unordered_set<cISC4LotConfiguration*>& sConfigs) = 0;

		virtual bool GetLotConfigurationIDsByFilter(std::unordered_set<uint32_t>& sConfigs, cISC4LotConfigurationFilter* pFilter) = 0;
		virtual bool GetLotConfigurationIDsByFamily(std::unordered_set<uint32_t>& sConfigs, uint32_t dwFamily) = 0;
		virtual bool GetLotConfigurationIDsBySize(std::unordered_set<uint32_t>& sConfigs, uint32_t sX, uint32_t sZ) = 0;

		virtual bool LotConfigurationHasBuildingFamily(cISC4LotConfiguration* pConfig, uint32_t dwFamily, cSC4LotConfigurationObject** ppObj) = 0;
		virtual bool LotConfigurationHasBuildingType(cISC4LotConfiguration* pConfig, uint32_t dwFamily, cSC4LotConfigurationObject** ppObj) = 0;

		virtual bool RegisterLotConfigurationFilter(cISC4LotConfigurationFilter* pFilter) = 0;
		virtual bool UnregisterLotConfigurationFilter(cISC4LotConfigurationFilter* pFilter) = 0;

		virtual intptr_t GetLotConfigurationMap(void) = 0;
		virtual intptr_t GetLotConfigurationFamilyIDSet(void) = 0;

		virtual bool CreateGenericLotConfiguration(cISC4LotConfiguration*& pConfig, uint32_t dwConfigID) = 0;
		virtual bool FixLotConfiguration(cISC4LotConfiguration* pConfig) = 0;

		virtual bool GetMaxFootprintForBuildingFamilies(std::vector<uint32_t> const& sFamilies, cS3DRect2D& sRect) = 0;
		virtual bool GetMaxFootprintForFloraFamilies(std::vector<uint32_t> const& sFamilies, cS3DRect2D& sRect) = 0;
		virtual bool GetMaxFootprintForPropFamilies(std::vector<uint32_t> const& sFamilies, cS3DRect2D& sRect) = 0;

		virtual bool GetObjectIDArray(cSC4LotConfigurationObject* pConfigObj, std::vector<uint32_t>& sArray) = 0;
};