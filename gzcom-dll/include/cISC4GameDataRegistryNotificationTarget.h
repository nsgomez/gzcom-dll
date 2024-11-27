#pragma once
#include "cISC4GameDataRegistry.h"

class cISC4GameDataRegistryNotificationTarget : public cIGZUnknown
{
	virtual void OnGameDataRegistryNotification(cISC4GameDataRegistry* registry, cISC4GameDataRegistry::eNotificationType type, cISC4GameDataRegistry::cEntry* entry) = 0;
};
