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

cRZAutoRefCount<cIGZLua5Thread> SCLuaUtil::GetIGZLua5ThreadFromFunctionState(lua_State* pState)
{
	// The cIGZLua5Thread instance is located one pointer up from the state address.

	cIGZLua5Thread* pIGZLua5Thread = *reinterpret_cast<cIGZLua5Thread**>(reinterpret_cast<intptr_t>(pState) + -4);

	cRZAutoRefCount<cIGZLua5Thread> pLua;

	if (pIGZLua5Thread)
	{
		pLua = pIGZLua5Thread;
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

	if (pAdvisorSystem)
	{
		// The Lua system can have different instances active.
		// We use the one from the advisor system so that the commands are registered
		// in its Lua instance.

		cISCLua* const pLua = pAdvisorSystem->GetScriptingContext();

		status = SCLuaUtil::RegisterLuaFunction(pLua, tableName, functionName, pFunction);
	}

	return status;
}

SCLuaUtil::RegisterLuaFunctionStatus SCLuaUtil::RegisterLuaFunction(
	cISCLua* pLua,
	const char* tableName,
	const std::string_view& functionName,
	lua_CFunction pFunction)
{
	RegisterLuaFunctionStatus status = RegisterLuaFunctionStatus::InvalidParameter;

	if (pLua)
	{
		status = SCLuaUtil::RegisterLuaFunction(pLua->AsIGZLua5(), tableName, functionName, pFunction);
	}

	return status;
}

SCLuaUtil::RegisterLuaFunctionStatus SCLuaUtil::RegisterLuaFunction(
	cIGZLua5* pLua,
	const char* tableName,
	const std::string_view& functionName,
	lua_CFunction pFunction)
{
	RegisterLuaFunctionStatus status = RegisterLuaFunctionStatus::InvalidParameter;

	if (pLua && !functionName.empty() && pFunction)
	{
		cIGZLua5Thread* const pLuaThread = pLua->AsIGZLua5Thread();

		if (pLuaThread)
		{
			int32_t top = pLuaThread->GetTop();

			if (tableName)
			{
				pLuaThread->GetGlobal(tableName);
			}
			else
			{
				pLuaThread->GetGlobalTable();
			}

			int32_t functionTableTop = pLuaThread->GetTop();

			if (top != functionTableTop)
			{
				cIGZLua5Thread::LuaType type = pLuaThread->Type(-1);

				if (type == cIGZLua5Thread::LuaTypeTable)
				{
					const char* const kTempFunctionName = "_temp_";

					// We have to register the function with a temporary name and then rename it.
					// Just registering the function with the intended name doesn't work.
					//
					// SC4 uses the same technique when registering the game table functions
					// (e.g. game.trend_slope).

					pLuaThread->Register(pFunction, kTempFunctionName);
					pLuaThread->PushLString(functionName.data(), functionName.size());
					pLuaThread->GetGlobal(kTempFunctionName);
					pLuaThread->SetTable(-3);
					pLuaThread->Pop(1);
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

			pLuaThread->SetTop(top);
		}
	}

	return status;
}
