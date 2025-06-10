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