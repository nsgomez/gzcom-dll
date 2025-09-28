/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4GameDataRegistryNotificationTarget.h
 *
 * Copyright (C) 2024 Nicholas Hayes
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
#include "cISC4GameDataRegistry.h"

class cISC4GameDataRegistryNotificationTarget : public cIGZUnknown
{
	virtual void OnGameDataRegistryNotification(cISC4GameDataRegistry* registry, cISC4GameDataRegistry::eNotificationType type, cISC4GameDataRegistry::cEntry* entry) = 0;
};
