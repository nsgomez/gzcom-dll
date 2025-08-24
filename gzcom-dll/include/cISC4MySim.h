#pragma once
#include "cIGZUnknown.h"

class cGZPersistResourceKey;
class cIGZBuffer;
class cIGZString;
class cISC4Advisor;
class cISC4BuildingOccupant;
class cISCResExemplar;
class SC4Percentage;
class SC4String;

class cISC4MySim : public cIGZUnknown
{
public:
	enum class ScriptCommand : uint32_t
	{
		Die = 0xea4d269c,
		IncreaseWealth = 0x6a4a5e9e,
		LeaveCity = 0x0a57de1f,
		MoveOut = 0x6a47e79b,
		QuitJob = 0x6a5e6860,
		Retire = 0xaa4934b4,
		Spawn = 0x6a495f7f
	};

	enum class ZodiacSign : uint8_t
	{
		Capricorn = 0,
		Aquarius = 1,
		Pisces = 2,
		Aries = 3,
		Taurus = 4,
		Gemini = 5,
		Cancer = 6,
		Leo = 7,
		Virgo = 8,
		Libra = 9,
		Scorpio = 10,
		Sagittarius = 11,
	};

	virtual cISC4Advisor* AsAdvisor() = 0;

	virtual void MoveIn(uint8_t slot, cIGZString& name, bool isMale, ZodiacSign sign, SC4String& bio, uint32_t bitmapIID, SC4String& bitmapFilePath) = 0;
	virtual bool FindNewResidence() = 0;
	virtual bool ChangeResidence(cISC4BuildingOccupant*) = 0;
	virtual bool TestForResidence(cISC4BuildingOccupant*, bool, bool) = 0;
	virtual bool ChangeJob(cISC4BuildingOccupant*) = 0;

	virtual bool DeleteFromGame() = 0;

	virtual uint8_t GetSlot() const = 0;
	virtual cISC4BuildingOccupant* GetResidence() const = 0;
	virtual cISC4BuildingOccupant* GetJob() const = 0;
	virtual bool SetResidence(cISC4BuildingOccupant*) = 0;

	virtual bool GetLocation(float*) const = 0; // array has 3 elements in the order X, Y, Z
	virtual void GetVehicleKey(cGZPersistResourceKey&) const = 0;
	virtual ZodiacSign GetSign() const = 0;
	virtual uint8_t GetAge() const = 0;
	virtual bool IsMale() const = 0;
	virtual uint32_t GetWealth() const = 0;
	virtual bool IsActive() const = 0;
	virtual SC4String* GetBio() const = 0;
	virtual uint32_t GetBitmapID() const = 0;
	virtual SC4String* GetBitmapFile() const = 0;
	virtual bool GetBitmapBuffer(cIGZBuffer**) const = 0;
	virtual SC4String* GetHomeName() const = 0;
	virtual SC4String* GetJobName() const = 0;
	virtual SC4String* GetJobTitle() const = 0;

	virtual void GetEQAsText(cIGZString&) = 0;
	virtual void GetHQAsText(cIGZString&) = 0;

	virtual void Find() = 0;
	virtual void ShowResidence() = 0;
	virtual void HideResidence() = 0;
	virtual void ShowLocation() = 0;
	virtual void HideLocation() = 0;
	virtual void SetPylonVisibility(bool) = 0;
	virtual void UpdateResidence() = 0;
	virtual void LeaveForWork() = 0;
	virtual void ReturnHome() = 0;
	virtual void AnnounceMoveIn() = 0;

	virtual void DoScriptCommand(ScriptCommand) = 0;
	virtual void DoBuildingAdded(cISC4BuildingOccupant*) = 0;
	virtual void DoBuildingChanged(cISC4BuildingOccupant*) = 0;
	virtual void DoBuildingRemoved(cISC4BuildingOccupant*, uint32_t) = 0;
	virtual void DoFireAdded(float, float) = 0;
	virtual void DoPipeBurst(float, float) = 0;
	virtual void DoTornado(float, float) = 0;
	virtual void DoDisaster(uint32_t, int32_t, int32_t) = 0;
	virtual void DoNeighborConnectionRemoved(int32_t, int32_t) = 0;

	virtual int32_t DistanceToClosest(uint32_t buildingType) = 0;
	virtual int32_t DistanceToClosestSpecial(uint32_t buildingType) = 0;

	virtual void LocalSchoolGrade(SC4Percentage&) = 0;
	virtual void LocalHospitalGrade(SC4Percentage&) = 0;

	virtual void PlayNightSound() = 0;
	virtual bool GetCurrentScreenLocationXY(int32_t*, int32_t*) = 0;
	virtual void GetJobTitle(cISC4BuildingOccupant*, cIGZString&) = 0;
	virtual bool RequestToPlaySound() = 0;

	virtual bool SetCar(cISCResExemplar const*) = 0;
	virtual bool SetPedestrian(cISCResExemplar const*) = 0;

	virtual uint32_t GetModelButtonBitmapID(bool pedestrian) = 0;
	virtual void GetNextBalloonAdvice() = 0;
	virtual void GetNextBalloonEventAdvice() = 0;
	virtual uint32_t GetCurrentBalloonAdvice() const = 0;
	virtual uint32_t GetCurrentBalloonEventAdvice() const = 0;

	virtual bool CanUDriveIt() = 0;
	virtual bool EnterUDriveIt() = 0;
	virtual bool ExitUDriveIt() = 0;

	virtual bool CreateDispatchTool() = 0;
	virtual bool ActivateLuaContext() = 0;
};