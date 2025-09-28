/*
 * gzcom-dll - an open-source DLL Plugin SDK for SimCity 4
 *
 * cISC4NetworkTool.h
 *
 * Copyright (C) 2025 Casper Van Gheluwe
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
#include "cISC4NetworkManager.h"
#include "cISC4NetworkOccupant.h"
#include "SC4Point.h"
#include "SC4Vector.h"

class cISC4Lot;
class cISC4NetworkOccupant;
class cISC4NetworkTool;
class cISC4Occupant;
class cISC4OccupantFilter;
class cISC4NetworkToolUI;

// Forward declarations only, actual structure has not been decoded fully.
class NeighborConnectionInfo;
struct tPlacementParams;

class cISC4NetworkTool : public cIGZUnknown
{
public:
	virtual bool Init(void) = 0;
	virtual bool Shutdown(void) = 0;

	/**
	 * Resets the network tool to a clean state.
	 *
	 * Clears the world cache, resets internal flags/caches, reinitializes
	 * tool state, and discards transient UI state.
	 *
	 * @return void
	 */
	virtual void Reset() = 0;

	/**
	 * Creates and returns a UI helper for this network tool.
	 *
	 * Allocates and initializes a cSC4NetworkToolUI bound to this tool and
	 * its current network type, then returns it via out-parameter.
	 *
	 * @param outUi  Receives the created UI object (AddRef'd).
	 *
	 * @return 1 on success, 0 on failure.
	 */
	virtual uint32_t GetUITool(cISC4NetworkToolUI** outUi) = 0;

	/**
	 * Places a stretch of network between two map cells.
	 *
	 * Clamps the given endpoints to city bounds, validates each segment,
	 * resolves conflicts with existing occupants, and commits placement
	 * if allowed.
	 *
	 * @param startX         X coordinate of the starting cell.
	 * @param startZ         Z coordinate of the starting cell.
	 * @param endX           X coordinate of the ending cell.
	 * @param endZ           Z coordinate of the ending cell.
	 * @param networkMask    Bitmask of network types to consider when scanning.
	 *                       If 0, a direct placement attempt is made.
	 * @param toolCallback   Optional callback interface notified of edits or conflicts.
	 * @param bUseWorldCache If true, clears the world cache before placement and
	 *                       avoids cache-based reuse; if false, cache entries may
	 *                       influence trimming.
	 * @param networkType    Network type/variant to use; if negative, defaults to the
	 *                       tool’s current setting.
	 *
	 * @return 1 on success, 0 if validation failed or placement was aborted.
	 */
	virtual uint32_t PlaceNetworkOccupants(
	    uint32_t startX,
	    uint32_t startZ,
	    uint32_t endX,
	    uint32_t endZ,
	    unsigned long networkMask,
	    cISC4NetworkTool* toolCallback,
	    bool bUseWorldCache,
	    cISC4NetworkOccupant::eNetworkType networkType) = 0;


	/**
	 * Places a single network occupant at the specified cell.
	 *
	 * Builds a cell descriptor for the given coordinates and network type,
	 * queries placement logic, and creates the occupant. Optionally marks
	 * the occupant as active.
	 *
	 * @param x             X coordinate of the cell.
	 * @param z             Z coordinate of the cell.
	 * @param occupantId    Identifier or type value for the occupant.
	 * @param bSelect       If true, newly placed occupants are flagged/selected.
	 * @param networkType   Network type to place (road, rail, subway, etc.).
	 *
	 * @return void
	 */
	virtual void PlaceNetworkOccupantById(
	    int x,
	    int z,
	    unsigned long occupantId,
	    bool bSelect,
	    cISC4NetworkOccupant::eNetworkType networkType) = 0;

	/**
	 * Checks whether a network occupant exists at a cell for a given mask.
	 *
	 * Looks up cell info at (x,z); if the cell is valid, marked occupied, and
	 * matches the provided mask, returns the occupant ID for the current
	 * network type and writes it to outOccupantId.
	 *
	 * @param x              Cell X coordinate.
	 * @param z              Cell Z coordinate.
	 * @param networkMask    Bitmask to match against the cell’s occupant flags.
	 * @param outOccupantId  Receives the found occupant ID (per current network type).
	 *
	 * @return 1 if an occupant matching the mask exists; 0 otherwise.
	 */
	virtual uint32_t OccupantExists(uint32_t x, uint32_t z, unsigned long networkMask, unsigned long& outOccupantId) = 0;

	virtual void UpdateOnZoneChange() = 0; // no-op

	/**
	 * Forces the tool to reload its internal data on the next update.
	 *
	 * @return void
	 */
	virtual void ForceReload();

	virtual void SetTraceFinal(bool enable) = 0; // no-op

	/**
	 * Resets the internal failure code to 0.
	 *
	 * @return void
	 */
	virtual void ClearFailureReason() = 0;

	/**
	 * Returns whether the tool is currently in a failure state.
	 *
	 * @return 1 if a failure code is set; 0 otherwise.
	 */
	virtual uint32_t GetFailureState() const = 0;

	/**
	 * Formats the current failure reason into a string.
	 *
	 * Resolves the internal failure code to a message and
	 * writes it to the provided string.
	 *
	 * @param outStr  Destination string to receive the failure message.
	 *
	 * @return void
	 */
	virtual void GetFailureReasonString(cIGZString& outStr) const = 0;

	/**
	 * Clears all highlight markers applied to network occupants and disposes any
	 * temporary highlight grid data.
	 * @note The method order is reversed compared to the Mac binaries.
	 * In the Windows binary, ClearOccupantHighlights is defined before ClearCellPreviews.
	 */
	virtual void ClearOccupantHighlights() = 0;

	/**
	 * Clears all cell preview visuals and tracked preview occupants.
	 *
	 * @note The method order is reversed compared to the Mac binaries.
	 * In the Windows binary, ClearOccupantHighlights is defined before ClearCellPreviews.
	 * @return void
	 */
	virtual void ClearCellPreviews() = 0;

	/**
	 * Computes a drawable network line between two points and validates bounds.
	 *
	 * Returns 1 if the drag is valid (within map and tool constraints), 0 otherwise.
	 */
	virtual uint32_t DrawNetworkLine(
		const SC4Point<uint32_t>& start,
		const SC4Point<uint32_t>& end,
		bool useWorldCache,
		cISC4NetworkOccupant::eNetworkType networkType) = 0;

	/**
	 * Places all pending line segments accumulated by the tool.
	 *
	 * Processes consecutive anchor points, validates, and commits placement;
	 * optionally uses a construction crew for supported network types.
	 */
	virtual void PlaceAllSegments(
		bool commit,
		bool previewOnly,
		bool allowDemolition,
		cISC4NetworkOccupant::eNetworkType networkType) = 0;

	/**
	 * Computes the total cost of the current solution (cells, segments, intersections, length).
	 *
	 * @return Cost in simoleons
	 */
	virtual int GetCostOfSolution() const = 0;

	// Enables or disables live preview updates during dragging.
	virtual void EnablePreviewUpdate(bool enable) = 0;

	// Replaces the current anchor point vector used for segment placement.
	virtual void SetAnchorPoints(const SC4Vector<SC4Point<uint32_t>>& points) = 0;

	// Returns the cells currently covered by the drag operation.
	virtual void GetDraggedCells(SC4Vector<SC4Point<uint32_t>>& outCells) const = 0;

	// Sets the number of valid drag steps and updates terrain highlight.
	virtual void SetValidStepCount(uint32_t count) = 0;

	// Returns the number of valid drag steps.
	virtual uint32_t GetValidStepCount() const = 0;

	// Returns the count of straight (axis-aligned) steps in the drag.
	virtual uint32_t GetStraightStepCount() const = 0;

	// Returns the total number of steps in the drag.
	virtual uint32_t GetTotalStepCount() const = 0;

	/**
	 * Returns whether the step at the given index is a “regular” step
	 * (e.g., axis-aligned vs. diagonal).
	 */
	virtual bool IsRegularStep(uint32_t stepIndex) const = 0;

	/**
	 * Writes the last valid grid point of the current drag/solution.
	 * Undefined if no valid steps exist.
	 */
	virtual void GetLastValidPoint(SC4Point<uint32_t>& outPoint) const = 0;

	/**
	 * Returns possible bridge options for the current drag, if any.
	 *
	 * @param outBridgeInstanceIds  Receives bridge instance identifiers.
	 * @return true if at least one bridge option exists; false otherwise.
	 */
	virtual bool GetPossibleBridges(SC4Vector<int32_t>& outBridgeInstanceIds) const = 0;

	// Returns the currently preferred bridge ID.
	virtual int GetPreferredBridge() const = 0;

	// Sets the preferred bridge ID.
	virtual void SetPreferredBridge(int bridgeId) = 0;

	virtual void GetBridgeAltitudeOverride() = 0; // no-op

	// Sets a manual altitude override for bridge placement.
	virtual void SetBridgeAltitudeOverride(float altitude) = 0;

	/**
	 * Resolves the localized (?) name of a bridge type into the provided string.
	 *
	 * @param outStr   Destination string for the name.
	 * @param bridgeInstanceId Bridge type identifier.
	 */
	virtual void GetBridgeName(cIGZString& outStr, int bridgeInstanceId) const = 0;

	/**
	 * Returns the current “major” bridge type in the drag, or -1 if none.
	 * @note: The meaning of "major" is not known
	 */
	virtual int GetMajorBridge() const = 0;

	/**
	 * Gets the altitude of the current major bridge.
	 *
	 * @param outAltitude Receives the altitude.
	 * @return true if a major bridge exists; false otherwise.
	 * @note: The meaning of "major" is not known
	 */
	virtual bool GetMajorBridgeAltitude(float& outAltitude) const = 0;

	/**
	 * Gets the reference altitude of the current major bridge.
	 *
	 * @param outAltitude Receives the reference altitude.
	 * @return true if a major bridge exists; false otherwise.
	 * @note: The meaning of "major" is not known
	 */
	virtual bool GetMajorBridgeReferenceAltitude(float& outAltitude) const = 0;

	/**
	 * Returns whether the major bridge is a land bridge.
	 *
	 * @return True if the major bridge is a land bridge; false otherwise.
	 * @note: The meaning of "major" is not known
	 */
	virtual bool IsMajorBridgeLandBridge() const = 0;

	/**
	 * Retrieves the bitmap key (exemplar IDs) for a bridge type.
	 *
	 * @param bridgeId  Bridge type identifier.
	 * @param outGroup  Receives the group ID.
	 * @param outInstance  Receives the instance ID.
	 * @return true if keys exist; false otherwise.
	 */
	virtual bool GetBridgeBitmapKey(long bridgeId, unsigned long& outGroup, unsigned long& outInstance) const = 0;

	/**
	 * Returns possible neighbor connection info if one exists.
	 *
	 * @param outInfo  Receives the neighbor connection details.
	 * @return true if a neighbor connection is available; false otherwise.
	 */
	virtual bool GetPossibleNeighborConnection(NeighborConnectionInfo& outInfo) const = 0;

	// Returns the view input control ID for this tool.
	virtual uint32_t ViewInputControlId() const = 0;

	// Returns the cursor resource ID.
	virtual uint32_t CursorId() const = 0;

	// Returns the base ID used for directional cursors.
	virtual uint32_t DirectionalCursorBase() const = 0;

	// Outputs the pen width (x/y) used for drawing previews.
	virtual void PenWidth(int& outWidthX, int& outWidthZ) const = 0;

	// Returns 1 to indicate picking stops at water.
	virtual uint32_t StopPickAtWater() const = 0;

	// Returns the tool view ID.
	virtual uint32_t GetToolViewId() const = 0;

	// Copies current placement parameters into the provided struct.
	virtual void GetPlacementParams(tPlacementParams& outParams) const = 0;

	// Prompts the user about potential intersection placements (UI flow + effects).
	virtual void QueryUserForPotentialIntersections() = 0;

	// Destroys the given occupants and resolves network topology/terrain afterward.
	virtual void DestroyOccupantsAndResolve(const SC4Vector<cISC4NetworkOccupant*>& occupants) = 0;

};
