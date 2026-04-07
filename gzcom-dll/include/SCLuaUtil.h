/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SCLuaUtil.h
 *
 * Copyright (C) 2024, 2025. 2026 Nicholas Hayes
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
	 *
	 * Native functions created for advisor/automata scripts typically use this,
	 * but functions created for cIGZLuaScriptServer or a private cIGZLua5 class
	 * instance must use GetIGZLua5ThreadFromFunctionState.
	 *
	 * @param pState The function state.
	 * @return The cISCLua instance.
	 */
	cRZAutoRefCount<cISCLua> GetISCLuaFromFunctionState(lua_State* pState);

	/**
	 * @brief Gets an cIGZLua5Thread instance from the Lua function state.
	 *
	 * cIGZLua5Thread is the low level interface for the game's Lua implementation,
	 * all native functions will have access to it from the function state.
	 *
	 * This is normally only used by native functions that interact with
	 * cIGZLuaScriptServer or a private cIGZLua5 class instance.
	 * Native functions created for advisor/automata scripts typically use
	 * GetISCLuaFromFunctionState.
	 *
	 * @param pState The function state.
	 * @return The cIGZLua5Thread instance.
	 */
	cRZAutoRefCount<cIGZLua5Thread> GetIGZLua5ThreadFromFunctionState(lua_State* pState);

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

	/**
	 * @brief Registers a C++ function to be called by the Lua system.
	 * @param pLua A pointer to the Lua instance.
	 * @param tableName The name of the Lua table that the function is defined in.
	 * Can be NULL to register a global function.
	 * @param functionName The name of the function.
	 * @param pFunction The C++ function that is called by the Lua system.
	 * @return The registration status.
	 */
	RegisterLuaFunctionStatus RegisterLuaFunction(
		cISCLua* pLua,
		const char* tableName,
		const std::string_view& functionName,
		lua_CFunction pFunction);

	/**
	 * @brief Registers a C++ function to be called by the Lua system.
	 * @param pLua A pointer to the Lua instance.
	 * @param tableName The name of the Lua table that the function is defined in.
	 * Can be NULL to register a global function.
	 * @param functionName The name of the function.
	 * @param pFunction The C++ function that is called by the Lua system.
	 * @return The registration status.
	 */
	RegisterLuaFunctionStatus RegisterLuaFunction(
		cIGZLua5* pLua,
		const char* tableName,
		const std::string_view& functionName,
		lua_CFunction pFunction);
}