/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SC4Preferences.h
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
#include "SC4ViewPreferences.h"
#include "SC4AudioPreferences.h"
#include "SC4NewCityPreferences.h"
#include "SC4SimulatorPreferences.h"
#include "SC4DebugPreferences.h"
#include "SC4TipOfTheDayPreferences.h"
#include "SC4AppPreferences.h"
#include "SC4TutorialPreferences.h"
#include "SC4RegionPreferences.h"
#include "SC4GameOptionPreferences.h"
#include "SC4VideoPreferences.h"
#include "SC4TutorialPreferences2.h"
#include <cstddef>

class SC4Preferences
{
public:
	SC4ViewPreferences viewPreferences;
	SC4AudioPreferences audioPreferences;
	SC4NewCityPreferences newCityPreferences;
	SC4SimulatorPreferences simulatorPreferences;
	SC4DebugPreferences debugPreferences;
	SC4TipOfTheDayPreferences tipOfTheDayPreferences;
	SC4AppPreferences appPreferences;
	SC4TutorialPreferences tutorialPreferences;
	SC4RegionPreferences regionPreferences;
	SC4GameOptionPreferences gameOptionPreferences;
	SC4VideoPreferences videoPreferences;
	SC4TutorialPreferences2 tutorialPreferences2;
};

static_assert(sizeof(SC4Preferences) == 0x1734);
static_assert(offsetof(SC4Preferences, viewPreferences) == 0x0);
static_assert(offsetof(SC4Preferences, audioPreferences) == 0x4);
static_assert(offsetof(SC4Preferences, newCityPreferences) == 0x6c);
static_assert(offsetof(SC4Preferences, simulatorPreferences) == 0x470);
static_assert(offsetof(SC4Preferences, debugPreferences) == 0x474);
static_assert(offsetof(SC4Preferences, tipOfTheDayPreferences) == 0x49c);
static_assert(offsetof(SC4Preferences, appPreferences) == 0x4a4);
static_assert(offsetof(SC4Preferences, tutorialPreferences) == 0xe50);
static_assert(offsetof(SC4Preferences, regionPreferences) == 0xebc);
static_assert(offsetof(SC4Preferences, gameOptionPreferences) == 0xf08);
static_assert(offsetof(SC4Preferences, videoPreferences) == 0xf0c);
static_assert(offsetof(SC4Preferences, tutorialPreferences2) == 0xf34);
