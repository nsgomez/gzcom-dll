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
	const char* functionName,
	lua_CFunction pFunction)
{
	RegisterLuaFunctionStatus status = RegisterLuaFunctionStatus::NullParameter;

	if (pAdvisorSystem && tableName && functionName && pFunction)
	{
		// The Lua system can have different instances active.
		// We use the one from the advisor system so that the commands are registered
		// in its Lua instance.

		cISCLua* const pLua = pAdvisorSystem->GetScriptingContext();

		if (pLua)
		{
			int32_t top = pLua->GetTop();
			pLua->GetGlobal(tableName);

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
					pLua->PushString(functionName);
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
