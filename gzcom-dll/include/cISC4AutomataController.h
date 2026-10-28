/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4AutomataController.h
 *
 * Copyright (C) 2026 Casper Van Gheluwe
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
#include "SC4Rect.h"
#include "SC4Vector.h"

class cIGZString;
class cISC4Automaton;
class cISC4Occupant;
class cS3DVector3;
struct tBehaviorTemplate;
struct tControllerTemplate;
struct tControllerTime;

static const uint32_t GZIID_cISC4AutomataController = 0x6a1857f8;

// An automata attractor or generator placed on an occupant.
// Get these from cISC4AutomataControllerManager.
class cISC4AutomataController : public cIGZUnknown
{
public:
	// The flag values have not been recovered yet. They are bits in a 32-bit mask.
	enum tControllerFlag : uint32_t {};

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual uint32_t GetControllerType() const = 0;
	virtual cISC4Occupant* GetOccupant() const = 0;

	// Returns the template's name, or the controller's own name when it has no template.
	virtual cIGZString const& GetTemplateName() const = 0;
	virtual tControllerTemplate const* GetTemplate() const = 0;
	virtual float GetRadius() const = 0;
	virtual bool IsActive() const = 0;
	virtual void GetPosition(float* position) const = 0;

	virtual bool CheckFlag(cISC4AutomataController::tControllerFlag flag) const = 0;
	virtual void SetFlag(cISC4AutomataController::tControllerFlag flag, bool value) = 0;

	virtual void SetOccupant(cISC4Occupant* occupant) = 0;
	virtual void SetTemplate(tControllerTemplate const* controllerTemplate) = 0;
	virtual void SetAutomataGroups(SC4Vector<uint32_t> const& groups) = 0;
	virtual void SetPosition(float const* position) = 0;
	virtual void Activate(bool active) = 0;
	virtual void SetLifetime(float lifetime) = 0;

	virtual void GetOccupantBoundingBox(float* min, float* max) const = 0;
	virtual void GetBoundingBox(float* min, float* max) const = 0;
	virtual void GetLotFacingPoint(float* point) const = 0;
	virtual bool IsPointWithinRadius(float const* point, float* distance) = 0;

	virtual void CheckTimeOfDay(tControllerTime const& start, tControllerTime const& end) = 0;
	virtual void CheckEffectTriggers() = 0;
	virtual void NotifySourceDataChanged() = 0;
	virtual bool HandleViewChanged() = 0;

	virtual bool HandleStateTick(cISC4Automaton* automaton, uint32_t state, float elapsed) = 0;
	virtual bool HandleEnterState(cISC4Automaton* automaton, uint32_t state) = 0;
	virtual bool HandleExitState(cISC4Automaton* automaton, uint32_t state) = 0;
	virtual bool HandleRemoveAutomaton(cISC4Automaton* automaton) = 0;

	// Returns the first behavior in the template whose distance covers the
	// automaton, or nullptr when none does.
	virtual tBehaviorTemplate const* GetBehaviorTemplate(float distance, cS3DVector3 const& position) const = 0;
	virtual bool IsFull() const = 0;

	// The tract cells the controller covers, used by the controller grid.
	virtual SC4Rect<uint8_t>& TractRect() = 0;
};
