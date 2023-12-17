#pragma once
#include "cIGZUnknown.h"

class cIGZString;
class cISC4Ordinance;

class cISC4OrdinanceSimulator : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual bool AddOrdinance(cISC4Ordinance& ordinance) = 0;
		virtual bool RemoveOrdinance(cISC4Ordinance& ordinance) = 0;

		virtual bool IsOrdinanceAvailable(uint32_t clsid) = 0;
		virtual bool IsOrdinanceOn(uint32_t clsid) = 0;
		virtual bool IsOrdinanceAvailableButOff(uint32_t clsid) = 0;

		virtual bool SetOrdinanceAvailable(uint32_t clsid, bool available) = 0;
		virtual uint32_t GetOrdinanceAvailableCount(void) = 0;
		virtual uint32_t GetOrdinanceAvailableArray(uint32_t* pCLSIDsOut, uint32_t& dwCountOut) = 0;

		virtual bool SetOrdinanceOn(uint32_t clsid, bool on) = 0;
		virtual uint32_t GetOrdinanceOnCount(void) = 0;
		virtual uint32_t GetOrdinanceOnArray(uint32_t* pCLSIDsOut, uint32_t& dwCountOut) = 0;

		virtual bool IsOrdinanceEnabled(uint32_t clsid) = 0;
		virtual bool SetOrdinanceEnabled(uint32_t clsid, bool enabled) = 0;

		virtual uint32_t GetOrdinanceIDArray(uint32_t* pCLSIDsOut, uint32_t& dwCountOut) = 0;
		virtual uint32_t GetOrdinanceIDByName(cIGZString const& name) = 0;

		virtual cISC4Ordinance* GetOrdinanceByID(uint32_t clsid) = 0;
		virtual cISC4Ordinance* GetOrdinanceByName(cIGZString const& name) = 0;

		virtual int64_t GetOrdinanceMonthlyExpense(void) = 0;
		virtual int64_t GetOrdinanceMonthlyIncome(void) = 0;

		// TODO: Verify that the return values are correct for these methods.
		virtual int64_t GetCumulativeOffset(uint32_t unknown1, uint32_t unknown2) = 0;
		virtual float GetCumulativeFactor(uint32_t unknown1, uint32_t unknown2) = 0;
};