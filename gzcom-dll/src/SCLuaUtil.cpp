/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * SCLuaUtil.cpp
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

#include "SCLuaUtil.h"
#include "cISC4AdvisorSystem.h"

cRZAutoRefCount<cISCLua> SCLuaUtil::GetISCLuaFromFunctionState(lua_State* pState)
{
	// The cIGZLua5Thread instance is located one pointer up from the state address.

	cIGZLua5Thread* pIGZLua5Thread = *reinterpret_cast<cIGZLua5Thread**>(reinterpret_cast<intptr_t>(pState) + -4);

	cRZAutoRefCount<cISCLua> pLua;

	if (pIGZLua5Thread)
	{
		// The cISCLua class is the implementing class of the cIGZLua5Thread instance.
		pIGZLua5Thread->QueryInterface(GZIID_cISCLua, pLua.AsPPVoid());
	}

	return pLua;
}

SCLuaUtil::RegisterLuaFunctionStatus SCLuaUtil::RegisterLuaFunction(
	cISC4AdvisorSystem* pAdvisorSystem,
	const char* tableName,
	const std::string_view& functionName,
	lua_CFunction pFunction)
{
	RegisterLuaFunctionStatus status = RegisterLuaFunctionStatus::InvalidParameter;

	if (pAdvisorSystem && !functionName.empty() && pFunction)
	{
		// The Lua system can have different instances active.
		// We use the one from the advisor system so that the commands are registered
		// in its Lua instance.

		cISCLua* const pLua = pAdvisorSystem->GetScriptingContext();

		if (pLua)
		{
			int32_t top = pLua->GetTop();

			if (tableName)
			{
				pLua->GetGlobal(tableName);
			}
			else
			{
				pLua->GetGlobals();
			}

			int32_t functionTableTop = pLua->GetTop();

			if (top != functionTableTop)
			{
				cIGZLua5Thread::LuaType type = pLua->Type(-1);

				if (type == cIGZLua5Thread::LuaTypeTable)
				{
					const char* const kTempFunctionName = "_temp_";

					// We have to register the function with a temporary name and then rename it.
					// Just registering the function with the intended name doesn't work.
					//
					// SC4 uses the same technique when registering the game table functions
					// (e.g. game.trend_slope).

					pLua->Register(pFunction, kTempFunctionName);
					pLua->PushLString(functionName.data(), functionName.size());
					pLua->GetGlobal(kTempFunctionName);
					pLua->SetTable(-3);
					pLua->Pop(1);
					status = RegisterLuaFunctionStatus::Ok;
				}
				else
				{
					status = RegisterLuaFunctionStatus::TableWrongType;
				}
			}
			else
			{
				status = RegisterLuaFunctionStatus::TableNotFound;
			}

			pLua->SetTop(top);
		}
	}

	return status;
}
