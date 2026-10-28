/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4PathFinder.h
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
#include "cISC4TrafficSimulator.h"
#include "SC4Rect.h"
#include "SC4Vector.h"
#include <cstddef>

static const uint32_t GZIID_cISC4PathFinder = 0xaa0db766;

// A single trip search over the transport network.
// Get one from cISC4TrafficSimulator::CreatePathFinder, configure it with the
// setters, then call FindPath and read the results.
//
// The game sets up a commute like this (cSC4TrafficSimulator::SetupTrip):
// SetTrafficDensity, SetTripDestinationFilter, the destination flags or the
// end rect, SetMaxWorkTime, SetStartRect, ClearAllFlags,
// ClearAllTravelTypeFlags, SetStartingCostArray, SetMaxTripLength, then the
// trip settings and travel type flags.
//
// Enumerator names are not in the game's symbols. They describe what the
// Mac and Windows code does with each value.
class cISC4PathFinder : public cIGZUnknown
{
public:
	// Bits for SetFlag and ClearFlag. Several can be combined.
	enum TripSettings : uint32_t
	{
		// Accept any trip cost. Without it, a step whose total cost would go
		// over the max trip length plus that travel type's starting cost is
		// dropped. The game sets this for freight trips and for the traffic
		// automata route search.
		TripSetting_IgnoreMaxTripLength = 0x1,

		// With TripDestinationFilter_EndRect and a route set by SetRouteInfo,
		// a search that runs out of nodes still succeeds. It ends at the
		// explored node closest to the end rect.
		TripSetting_AcceptClosestNode = 0x2,

		// Keep the nodes of the previous search instead of releasing them and
		// creating new start nodes. With the standard destination filter the
		// node scores are recalculated for the new destinations.
		TripSetting_ReuseSearchTree = 0x4,

		// Let the route pick up a car again at the cell where the previous
		// successful route left its car. Without this bit FindPath forgets that
		// cell.
		TripSetting_ReturnToParkedCar = 0x8,

		// Do not follow ferry links between ferry terminals.
		TripSetting_NoFerries = 0x10,
	};

	// What counts as a destination. Passed to SetTripDestinationFilter.
	enum TripDestinationFilter : uint32_t
	{
		// Any lot or neighbor connection whose cells match the destination
		// flags and that still has spare trip capacity of a matching kind.
		// GetTrafficArrived then returns the traffic that fit.
		TripDestinationFilter_StandardDestinations = 0,

		// Nothing is a destination, so the search only ends when it runs out
		// of nodes or work time.
		TripDestinationFilter_None = 1,

		// Any occupant accepted by an occupant filter that this interface has
		// no setter for. The filter pointer starts out null, so this value is
		// only safe on a path finder the game configured itself.
		TripDestinationFilter_OccupantFilter = 2,

		// Any cell inside the end rect, or next to it. This is the default.
		TripDestinationFilter_EndRect = 3,
	};

	// Kinds of trip capacity a standard destination must offer. Combine bits
	// to accept several kinds. Only the low four bits are used.
	enum DestinationFlag : uint32_t
	{
		// Jobs for low, medium and high wealth workers. A commute sets the bit
		// for the commuter's wealth. The neighbor connection code fills
		// capacity 0, 1 and 2 from the region job counts for $, $$ and $$$.
		DestinationFlag_JobsLowWealth = 0x1,
		DestinationFlag_JobsMediumWealth = 0x2,
		DestinationFlag_JobsHighWealth = 0x4,

		// Freight destinations. Freight trips set this bit and seaports
		// publish their capacity under it.
		DestinationFlag_Freight = 0x8,
	};

	// How ApplyTraffic adds the found route to the traffic maps.
	enum TrafficApplicationStyle : uint32_t
	{
		// Count the route once as morning commute traffic.
		TrafficApplicationStyle_MorningCommute = 0,

		// Count the route once as evening commute traffic, in the direction
		// it was found.
		TrafficApplicationStyle_EveningCommute = 1,

		// Count the route as a morning trip and as an evening trip back along
		// the same cells. Network loads and transit switch use count twice.
		TrafficApplicationStyle_RoundTrip = 2,
	};

	// The value FindPath returns.
	enum FindPathResult : uint32_t
	{
		// No route. The setup was invalid or the search ran out of nodes.
		FindPathResult_Failed = 0,

		// A route was found. The getters and ApplyTraffic now describe it.
		FindPathResult_Found = 1,

		// The max work time ran out. Call FindPath again to continue the same
		// search, or Reset to start over.
		FindPathResult_InProgress = 2,
	};

	// One cell of a route, as written into the deque passed to SetRouteInfo.
	// The route runs from the start to the end. Cells of neighbor connections
	// lie outside the map and their coordinates wrap around to a byte.
	struct RouteData
	{
		uint8_t x;
		uint8_t z;
		uint8_t travelType; // a cISC4TrafficSimulator::TravelType value
	};

	static_assert(sizeof(RouteData) == 3);
	static_assert(offsetof(RouteData, x) == 0);
	static_assert(offsetof(RouteData, z) == 1);
	static_assert(offsetof(RouteData, travelType) == 2);

	virtual bool Init() = 0;
	virtual bool Shutdown() = 0;

	virtual void SetFlag(cISC4PathFinder::TripSettings flag) = 0;
	virtual void ClearFlag(cISC4PathFinder::TripSettings flag) = 0;
	virtual void ClearAllFlags() = 0;

	// routeInfo is a game std::deque<RouteData>*, or null for no route output.
	// The game's deque layout has no SDK equivalent, so it stays opaque.
	// FindPath clears it and fills it with the route when it succeeds.
	virtual void SetRouteInfo(void* routeInfo) = 0;

	virtual void SetTripDestinationFilter(cISC4PathFinder::TripDestinationFilter filter) = 0;
	virtual void SetDestinationFlag(cISC4PathFinder::DestinationFlag flag) = 0;
	virtual void ClearDestinationFlag(cISC4PathFinder::DestinationFlag flag) = 0;
	virtual void ClearAllDestinationFlags() = 0;

	// Allows the route to use these travel types. When allowAsStartType is
	// set the trip may also begin in them. A new path finder allows only cars.
	// Passenger trips use 0x1cf with false and then Walk | Car with true.
	virtual void SetTravelTypeFlag(cISC4TrafficSimulator::TravelTypeFlag travelTypeFlags, bool allowAsStartType) = 0;
	// Removes the travel types from both the allowed and the start masks.
	virtual void ClearTravelTypeFlag(cISC4TrafficSimulator::TravelTypeFlag travelTypeFlags) = 0;
	virtual void ClearAllTravelTypeFlags() = 0;

	// costs points to 9 floats, one per cISC4TrafficSimulator::TravelType.
	// FindPath adds each one to the max trip length to get the cost limit for
	// that travel type. Pass null to use the simulator's default table.
	// The array is read at FindPath time, so it must stay alive until then.
	virtual void SetStartingCostArray(float* costs) = 0;

	// The cost budget of a trip. FindPath overwrites this field with the
	// found trip length, so set it again before each new search.
	virtual void SetMaxTripLength(float length) = 0;

	// The number of trips this search carries. The trip capacity check and
	// ApplyTraffic use it.
	virtual void SetTrafficDensity(uint32_t density) = 0;
	virtual void SetStartRect(SC4Rect<int32_t> rect) = 0;
	virtual void SetEndRect(SC4Rect<int32_t> rect) = 0;

	// A time budget for one FindPath call in milliseconds, or 0 for no limit.
	virtual void SetMaxWorkTime(uint32_t workTime) = 0;

	// Drops a search that FindPath left in progress, so the next call starts
	// over.
	virtual void Reset() = 0;

	virtual cISC4PathFinder::FindPathResult FindPath() = 0;

	// The traffic that reached the destination. With the standard destination
	// filter it is capped by the destination's spare trip capacity.
	virtual uint32_t GetTrafficArrived() = 0;
	virtual float GetTripLength() = 0;
	virtual float GetTripLengthScaledForDisplay() = 0;
	virtual void GetEndCell(int32_t& x, int32_t& z) const = 0;

	// Returns the cISC4TrafficSimulator::TravelType of the last path node as a
	// byte, or 0 when there is no path.
	virtual uint8_t GetLastTravelType() const = 0;

	virtual void ApplyTraffic(cISC4PathFinder::TrafficApplicationStyle style) = 0;
	virtual bool WasTripReversible() = 0;
	virtual void ReleasePathNodes() = 0;

	// Appends the found route to the vector as a byte stream and sets
	// travelTypesUsed to a cISC4TrafficSimulator::TravelTypeFlag mask of the
	// travel types on it.
	//
	// The stream starts with the travel type, x and z of the first cell.
	// Records follow, told apart by their first byte.
	// - Run, 0x40 | travelType: a count byte n (1 to 255), then n steps packed
	//   four to a byte, low bits first. Each step is 2 bits: 0 is x - 1,
	//   1 is z - 1, 2 is x + 1 and 3 is z + 1. A run changes the current
	//   travel type.
	// - Jump, travelType or 0x80 | travelType: the x and z of the next cell,
	//   for a step that is not to a neighboring cell, such as a mode change
	//   in place, a ferry or a neighbor connection. Bit 0x80 is set when the
	//   cell before the jump is off the map or is a ferry terminal.
	// Off-map cells are replaced by the inner cell of their neighbor
	// connection.
	virtual void GetCompressedRoute(SC4Vector<uint8_t>& route, uint32_t& travelTypesUsed) = 0;
};
