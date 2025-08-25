#pragma once
#include "cIGZUnknown.h"

class cISC4PropRequester;

class cISC4PropDeveloper : public cIGZUnknown
{
public:
	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void AddPropRequester(cISC4PropRequester* pPropRequester) = 0;
	virtual void RemovePropRequester(cISC4PropRequester* pPropRequester) = 0;
	virtual void UpdateAllOptionalProps() = 0;

	virtual void ShowSignsAndLabels(bool show) = 0;
	virtual void ToggleSignsAndLabels() = 0;
	virtual bool AreSignsAndLabelsVisible() = 0;
};