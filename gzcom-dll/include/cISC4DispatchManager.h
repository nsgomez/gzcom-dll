#pragma once
#include "cIGZUnknown.h"
#include "cS3DVector3.h"

class cISC4Automaton;
class cISC4DispatchSource;
class cISC4Occupant;
class cISC4PylonOccupant;
class cISC4ViewObject3D;

class cISC4DispatchManager : public cIGZUnknown
{
public:
	// Both tDispatchState and tDispatchType were most likely enumerations.

	typedef uint32_t tDispatchState;
	typedef int32_t tDispatchType;

	class DispatchInfo
	{
	public:
		tDispatchType dispatchType;
		uint32_t dispatchID;
		uint32_t unknown2;
		uint32_t unknown3;
		bool unknown4;
		cS3DVector3 unknown5;
		cISC4Occupant* automataOccupant;
		cISC4Automaton* automaton;
		cISC4PylonOccupant* pylonOccupant;
	};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual bool CanDispatch(tDispatchType type, float param_2, float param_3) = 0;
	virtual uint32_t Dispatch(tDispatchType type, float param_2, float param_3) = 0;

	virtual bool RevokeDispatchByID(uint32_t id) = 0;
	virtual bool RevokeDispatchByPylon(cISC4PylonOccupant* pPylon) = 0;
	virtual bool RevokeAllDispatches() = 0;

	virtual bool GetDispatchInfo(tDispatchType type, DispatchInfo& param_2) = 0;
	virtual uint32_t GetDispatchCount(tDispatchType type) = 0;
	virtual uint32_t GetDispatchIDArray(tDispatchType type, uint32_t* buffer, uint32_t& bufferSize) = 0;

	virtual void RegisterDispatchSource(cISC4DispatchSource* pSource) = 0;
	virtual void UnregisterDispatchSource(cISC4DispatchSource* pSource) = 0;
	virtual cISC4DispatchSource* GetDispatchSource(tDispatchType type) = 0;

	virtual bool BeginDispatchTool(tDispatchType type) = 0;
	virtual bool EndDispatchTool(tDispatchType type) = 0;

	virtual cISC4PylonOccupant* GetActivePylon() = 0;
	virtual void SetActivePylon(cISC4PylonOccupant* pPylon) = 0;
	virtual cISC4Automaton* GetAutomatonFromPylon(cISC4PylonOccupant* pPylon) = 0;
	virtual uint32_t GetAvailablePylonCount(tDispatchType type) = 0;
	virtual cISC4ViewObject3D* GetDispatchVehicleView() = 0;
};