/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SCLuaUtil.h
 *
 * Copyright (C) 2024, 2025 Nicholas Hayes
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
#include "cISCLua.h"
#include "cRZAutoRefCount.h"
#include <string_view>

class cISC4AdvisorSystem;

namespace SCLuaUtil
{
	/**
	 * @brief Gets an cISCLua instance from the Lua function state.
	 * @param pState The function state.
	 * @return The cISCLua instance.
	 */
	cRZAutoRefCount<cISCLua> GetISCLuaFromFunctionState(lua_State* pState);

	enum class RegisterLuaFunctionStatus : int32_t
	{
		Ok = 0,
		// A parameter was invalid.
		InvalidParameter,
		// The table parameter does not exist.
		TableNotFound,
		// The table parameter is not a Lua table.
		TableWrongType
	};

	/**
	 * @brief Registers a C++ function to be called by the Lua system.
	 * @param pAdvisorSystem A pointer to the game's advisor system instance.
	 * @param tableName The name of the Lua table that the function is defined in.
	 * Can be NULL to register a global function.
	 * @param functionName The name of the function.
	 * @param pFunction The C++ function that is called by the Lua system.
	 * @return The registration status.
	 */
	RegisterLuaFunctionStatus RegisterLuaFunction(
		cISC4AdvisorSystem* pAdvisorSystem,
		const char* tableName,
		const std::string_view& functionName,
		lua_CFunction pFunction);
}