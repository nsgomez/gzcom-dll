/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * GZWinKyeAcceleratorUtil.h
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
#include <cstdint>
#include <type_traits>
#include <Windows.h>

namespace GZWinKeyAcceleratorUtil
{
	namespace detail
	{
		static const uint32_t ControlModifierMask = 0x20000;
		static const uint32_t AltModifierMask = 0x40000;
		static const uint32_t ShiftModifierMask = 0x10000;

		static const uint32_t KeyUpMask = 0x10000000;
	}

	enum class ModifierKeys : uint32_t
	{
		None = 0,
		Control = (1 << 0),
		Alt = (1 << 1),
		Shift = (1 << 2),
	};

	inline constexpr ModifierKeys operator|(ModifierKeys lhs, ModifierKeys rhs)
	{
		using underlyingType = std::underlying_type<ModifierKeys>::type;

		return static_cast<ModifierKeys>(static_cast<underlyingType>(lhs) | static_cast<underlyingType>(rhs));
	}

	inline ModifierKeys& operator|=(ModifierKeys& lhs, ModifierKeys rhs)
	{
		using underlyingType = std::underlying_type<ModifierKeys>::type;

		return reinterpret_cast<ModifierKeys&>(
			reinterpret_cast<std::underlying_type<ModifierKeys>::type&>(lhs) |= static_cast<underlyingType>(rhs));
	}

	inline constexpr ModifierKeys operator&(ModifierKeys lhs, ModifierKeys rhs)
	{
		using underlyingType = std::underlying_type<ModifierKeys>::type;

		return static_cast<ModifierKeys>(static_cast<underlyingType>(lhs) & static_cast<underlyingType>(rhs));
	}

	inline ModifierKeys& operator&=(ModifierKeys& lhs, ModifierKeys rhs)
	{
		using underlyingType = std::underlying_type<ModifierKeys>::type;

		return reinterpret_cast<ModifierKeys&>(
			reinterpret_cast<std::underlying_type<ModifierKeys>::type&>(lhs) &= static_cast<underlyingType>(rhs));
	}

	uint32_t MakeAcceleratorKeyCode(uint8_t vkCode, ModifierKeys modifierKeys, bool keyUp = false)
	{
		uint32_t code = static_cast<uint32_t>(vkCode);

		if ((modifierKeys & ModifierKeys::Control) != ModifierKeys::None)
		{
			code |= detail::ControlModifierMask;
		}

		if ((modifierKeys & ModifierKeys::Alt) != ModifierKeys::None)
		{
			code |= detail::AltModifierMask;
		}

		if ((modifierKeys & ModifierKeys::Shift) != ModifierKeys::None)
		{
			code |= detail::ShiftModifierMask;
		}

		if (keyUp)
		{
			code |= detail::KeyUpMask;
		}

		return code;
	}

	void SplitAcceleratorKeyCode(uint32_t acceleratorCode, uint8_t& vkCode, ModifierKeys& modifierKeys, bool& keyUp)
	{
		vkCode = static_cast<uint8_t>(acceleratorCode & 0x000000FF);
		keyUp = (acceleratorCode & detail::KeyUpMask) != 0;

		if ((acceleratorCode & detail::ControlModifierMask) != 0)
		{
			modifierKeys |= ModifierKeys::Control;
		}

		if ((acceleratorCode & detail::AltModifierMask) != 0)
		{
			modifierKeys |= ModifierKeys::Alt;
		}

		if ((acceleratorCode & detail::ShiftModifierMask) != 0)
		{
			modifierKeys |= ModifierKeys::Shift;
		}
	}
}