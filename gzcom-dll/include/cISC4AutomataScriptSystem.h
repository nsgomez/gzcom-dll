#pragma once
#include "cIGZUnknown.h"

class cSC4OccupantGroupTemplate;
class SC4String;
class tControllerTemplate;

template <typename T> class SC4List;

class cISC4AutomataScriptSystem : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual intptr_t GetAutomataGroupMap() const = 0; // Returns std::map<std::string, cSC4OccupantGroupTemplate*>&
	virtual uint32_t GetAutomataGroup(SC4String const& param_1) = 0;
	virtual uint32_t GetAutomataGroup(uint32_t group) = 0;

	virtual intptr_t GetOccupantGroupNameMap() const = 0; // Returns std::map<std::string, cSC4OccupantGroupTemplate*>&
	virtual intptr_t GetOccupantGroupIDMap() const = 0; // Returns std::map<uint32_t, cSC4OccupantGroupTemplate*>&
	virtual SC4List<cSC4OccupantGroupTemplate*>& GetSpecialFilterOccupantGroups() const = 0;
	virtual uint32_t GetOccupantGroup(SC4String const& param_1) = 0;
	virtual uint32_t GetOccupantGroup(uint32_t param_1) = 0;
	virtual intptr_t CreateOccupantGroup(SC4String const& param_1, uint32_t param_2, bool param_3) = 0; // Returns cSC4OccupantGroupTemplate*

	virtual int32_t GetDriveCommand(uint32_t param_1) const = 0; // Returns cISC4Automaton::ePlayerDriveCommand
	virtual intptr_t GetControllerTemplateMap() const = 0; // Returns std::map<std::string, tControllerTemplate*>&
	virtual tControllerTemplate* CreateControllerTemplate(SC4String const& param_1, uint32_t param_2) = 0;
	virtual tControllerTemplate* GetControllerTemplate(SC4String const& param_1) = 0;
	virtual SC4List<uint32_t>& GetTrackBuildingGroups() const = 0;
};