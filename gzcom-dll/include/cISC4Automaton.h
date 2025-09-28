/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4Automaton.h
 *
 * Copyright (C) 2025 Nicholas Hayes
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
#include "cIGZUnknown.h"
#include "cISC4DispatchManager.h"
#include "cISC4VisualEffect.h"

class cGZPersistResourceKey;
class cIGZMessageTarget2;
class cISC4AutomataController;
class cS3DTransform;
class SC4String;
class tAutomataState;
class tBehaviorTemplate;

static const uint32_t GZIID_cISC4Automaton = 0xa9b40f05;

class cISC4Automaton : public cIGZUnknown
{
public:
	typedef int32_t ePlayerDriveCommand;

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual cISC4Occupant* AsOccupant() const = 0;
	virtual cISC4Occupant* AsOccupant() = 0;

	virtual void GetPosition(cS3DVector3& position) = 0;
	virtual void SetPosition(cS3DVector3 const& position) = 0;
	virtual void SetVisible(bool visible) = 0;
	virtual void SetDestination(cS3DVector3 const& destination) = 0;
	virtual void GetDestination(cS3DVector3& destination) = 0;

	virtual bool GetTransform(cS3DTransform& transform) = 0;
	virtual void Remove(bool param_1) = 0;

	virtual void SetOrientation(cS3DVector3 const& orientation) = 0;
	virtual void GetOrientation(cS3DVector3& orientation) = 0;

	virtual void MoveTo(cS3DVector3 const* param_1, cS3DVector3 const* param_2) = 0;
	virtual float GetRadius() const = 0;
	virtual bool GetDisabled() const = 0;

	virtual bool PlayAnim(cGZPersistResourceKey const& key) = 0;
	virtual bool PlayAnim(uint32_t instanceOffset) = 0;
	virtual bool PlayAnimByName(SC4String const& name) = 0;
	virtual bool AttachAnim(cGZPersistResourceKey const& key, uint32_t /*cS3DAnimInfo::ePlayMode*/ playMode, bool param_3, float param_4) = 0;

	virtual uint16_t GetCallNumber() const = 0;
	virtual void SetCallNumber(uint16_t value) = 0;
	virtual void SetDispatchState(cISC4DispatchManager::tDispatchState value) = 0;
	virtual cISC4DispatchManager::tDispatchState GetDispatchState() const = 0;
	virtual uint32_t GetDispatchInfoID() const = 0;
	virtual void SetDispatchInfoID(uint32_t id) = 0;
	virtual void ReturnToSourceOccupant() = 0;

	virtual void SetAutomataFlag(uint32_t flag, bool value) = 0;
	virtual bool CheckAutomataFlag(uint32_t flag) const = 0;

	virtual float GetOpacity() const = 0;
	virtual void SetOpacity(float param_1, float param_2) = 0;

	virtual float GetCurrentSpeed() const = 0;
	virtual float GetDefaultSpeed() const = 0;
	virtual void SetSpeed(float param_1, float param_2) = 0;
	virtual float GetMaxSpeed() const = 0;
	virtual float GetActualSpeed() const = 0;

	virtual void AddCallback(cIGZMessageTarget2* param_1) = 0;
	virtual void RemoveCallback(cIGZMessageTarget2* param_1) = 0;
	virtual void AddRegEffect(SC4String const& param_1, SC4String const& param_2) = 0;
	virtual intptr_t FindRegEffect(SC4String const& param_1) = 0;
	virtual void RemoveRegEffect(SC4String const& param_1) = 0;
	virtual bool StartNamedEffects(SC4String const& param_1, cISC4VisualEffect::tTransitionType param_2, bool param_3) = 0;
	virtual void StopNamedEffects(SC4String const& param_1, cISC4VisualEffect::tTransitionType param_2) = 0;
	virtual void ToggleNamedEffects(SC4String const& param_1, cISC4VisualEffect::tTransitionType param_2, bool param_3) = 0;
	virtual void RecreateNamedEffects(SC4String const& param_1, cISC4VisualEffect::tTransitionType param_2, bool param_3) = 0;

	virtual cISC4Automaton* GetLeader() const = 0;
	virtual void SetLeader(cISC4Automaton* param_1) = 0;
	virtual cISC4Automaton* FindDrivingAutomaton() = 0;

	virtual bool SetState(uint32_t param_1, cISC4AutomataController* param_2, float param_3, bool param_4, uint32_t param_5, uint32_t param_6, tBehaviorTemplate const* param_7) = 0;
	virtual bool PushState(uint32_t param_1, cISC4AutomataController* param_2, float param_3, bool param_4, uint32_t param_5, uint32_t param_6, tBehaviorTemplate const* param_7) = 0;
	virtual bool PopState() = 0;
	virtual bool SetBehavior(tBehaviorTemplate const* param_1, cISC4AutomataController* param_2) = 0;
	virtual bool PushBehavior(tBehaviorTemplate const* param_1, cISC4AutomataController* param_2) = 0;
	virtual tAutomataState* GetState() = 0;
	virtual tAutomataState* FindState(uint32_t param_1) = 0;
	virtual tAutomataState* PrevState(tAutomataState const* param_1) = 0;
	virtual tBehaviorTemplate* GetBehavior() = 0;

	virtual bool HandlePlayerDriveCommand(ePlayerDriveCommand param_1, bool param_2) = 0;

	virtual bool StartSFX(uint32_t param_1) = 0;
	virtual bool StopSFX(uint32_t param_1) = 0;

	virtual uint8_t GetPriority() = 0;
	virtual void SetPriority(uint8_t priority) = 0;

	virtual bool HandleCollision(cS3DVector3 const& param_2) = 0;
	virtual void GetCollidePosition(cS3DVector3& param_1) = 0;
	virtual uint32_t GetAutomataGroup() = 0;

	virtual void RegisterInGameDataRegistry() = 0;
	virtual void UnregisterInGameDataRegistry() = 0;
};