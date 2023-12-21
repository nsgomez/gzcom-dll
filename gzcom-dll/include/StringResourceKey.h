#pragma once
#include <cstdint>

struct StringResourceKey
{
	StringResourceKey() : groupID(0), instanceID(0)
	{
	}

	/**
	 * @brief Constructs a StringResourceKey with the specified group and instance IDs.
	 * @param defaultLanguageGroupID The group ID of the language resource.
	 * @param instanceID The instance ID of the language resource.
	*/
	StringResourceKey(uint32_t groupID, uint32_t instanceID)
		: groupID(groupID), instanceID(instanceID)
	{
	}

	uint32_t groupID;
	uint32_t instanceID;
};