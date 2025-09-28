/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cIGZKeyboard.h
 *
 * Copyright (C) 2025 Nicholas Hayes
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
#include <cstdint>

class cIGZKeyboard
{
public:
	// Clears the internal list of keys that have been pressed.
	virtual void ClearKeyboard() = 0;

	// The vKey parameters are Windows Virtual-Key Codes:
	// https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

	virtual bool IsKeyDown(int32_t vKey) = 0;
	virtual bool IsKeyDown(int32_t vKey, uint32_t modifiers) = 0;
	/**
	 * @brief Checks if the specified key is currently being pressed.
	 * @param vKey The virtual key code.
	 * @return true if the key is currently being pressed; otherwise, false.
	 */
	virtual bool IsKeyDownNow(int32_t vKey) = 0;

	virtual bool CharIsModifier(int32_t vKey) = 0;
	virtual uint32_t GetCurrentModifierState() = 0;
	/**
	 * @brief Gets the key state of the toggle keys.
	 * @param vKey The virtual key code.
	 * @return true if the toggle key is on; otherwise, false if it is off.
	 * @remarks The toggle keys are NUM LOCK, CAPS LOCK, and SCROLL LOCK.
	 */
	virtual bool IsToggleKeySet(int32_t vKey) = 0;

	// The following functions add or remove pressed keys
	// from the tracking list.

	virtual void ProcessKeyDown(int32_t vKey) = 0;
	virtual void ProcessKeyUp(int32_t vKey) = 0;
};