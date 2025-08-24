#pragma once
#include "cIGZUnknown.h"

template<typename T>
class cISC4SimGrid : public cIGZUnknown
{
	public:
		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;

		virtual uint32_t GetInstanceID(void) const = 0;
		virtual bool SetInstanceID(uint32_t dwInstanceID) = 0;

		virtual T GetCellValue(int32_t nCellX, int32_t nCellZ) const = 0;
		virtual T GetAverageValueInCellRect(int32_t nTopLeftX, int32_t nTopLeftZ, int32_t nBottomRightX, int32_t nBottomRightZ) const = 0;

		virtual bool SetTractSize(int32_t nSize) = 0;
		virtual int32_t GetTractSize(void) const = 0;

		virtual int32_t GetTractShift(void) const = 0;

		virtual int32_t GetTractCountX(void) const = 0;
		virtual int32_t GetTractCountZ(void) const = 0;

		virtual float GetTractWidthX(void) const = 0;
		virtual float GetTractWidthZ(void) const = 0;

		virtual float GetOneOverTractWidthX(void) const = 0;
		virtual float GetOneOverTractWidthZ(void) const = 0;

		virtual bool TractIsInBounds(uint32_t dwTractX, uint32_t dwTractZ) const = 0;
		virtual bool PositionToTract(float fPosX, float fPosZ, int32_t& nTractX, int32_t& nTractZ) const = 0;
		virtual bool TractCornerToPosition(int32_t nTractX, int32_t nTractZ, float& fPosX, float& fPosZ) const = 0;
		virtual bool TractCenterToPosition(int32_t nTractX, int32_t nTractZ, float& fPosX, float& fPosZ) const = 0;

		virtual T GetTractValue(int32_t nTractX, int32_t nTractZ) const = 0;
		virtual T GetAverageValueInTractRect(int32_t nTopLeftX, int32_t nTopLeftZ, int32_t nBottomRightX, int32_t nBottomRightZ) const = 0;

		virtual intptr_t GetGridData(void) = 0;
		virtual intptr_t GetGridData(void) const = 0;

		virtual void SetTractValue(int32_t nTractX, int32_t nTractZ, T value) = 0;
		virtual void SetTractValues(T value) = 0;
};