#pragma once
#include "cISC4NetworkManager.h"
#include "cISC4NetworkOccupant.h"
#include "cISC4NetworkTool.h"
#include "SC4Vector.h"

// Forward declarations only. Some decoding is in progress for the NAM dll, see https://github.com/NAMTeam/nam-dll/blob/1742e15dcb4263465a42b7af2450cf8bcc30d571/src/NetworkStubs.h
class cSC4NetworkInfo;
class cSC4NetworkCellInfo;
class cSC4NetworkWorldCache;
class cSC4NetworkTypeInfo;
class cSC4TileNeighborhoodCompact;
class cSC4VertexHtConstraintSatisfier;
struct tSolvedCell;
struct tImmovablePortion;

class cSC4NetworkTool : public cISC4NetworkTool
{
public:
	/**
	 * Resolves the localized error into the provided string.
	 *
	 * @param instanceId	Instance ID of an LTEXT entry with group 2a592fd1 to resolve.
	 * @param outStr		Destination string for the error.
	 */
	virtual void GetFailureReasonString(long instanceId, cIGZString &outStr) = 0;

	virtual bool DoNetworkSpecificPlacement(bool bUnknown1, bool bUnknown2) = 0;

	/**
	 * Create and initialize a network occupant for a given cell.
	 *
	 * Builds a 4×3 world-space corner array from the cell instantiates the requested occupant subclass,
	 * applies flags/attrs, and returns an interface pointer.
	 *
	 * @param cellInfo    [in/out] Cell info (tile x/y, per-corner heights, flags, existing occ, payload).
	 * @param occupant	  [out] receives cISC4NetworkOccupant*.
	 * @param vertices    [out] float[4][3] corner positions in world space:
	 *                    (x, h0, y), (x, h1, y+1), (x+1, h2, y+1), (x+1, h3, y)
	 * @param occTypeId   [in] Occupant type selector:
	 *                      0x00000000 → cSC4NetworkOccupant
	 *                      0x49C1A034 → cSC4NetworkOccupantWithPreBuiltModel (recompute shear?)
	 *                      0x49CC1BCD → cSC4NetworkBridgeOccupant
	 *                      0x8A4BD52B → cSC4NetworkTunnelOccupant (extra flags)
	 */
	virtual void CreateNetworkOccupant(cSC4NetworkCellInfo& cellInfo, cISC4NetworkOccupant** occupant, float (*vertices)[3], uint32_t occTypeId) = 0;

	/**
	 * Insert or preview occupants for a set of solved cells.
	 *
	 * Behavior:
	 * - If (!placingMode || previewOnly): update cell heights, mark preview, and
	 *   draw preview/highlight overlays for each solved cell (no placement).
	 * - Else (placingMode && !previewOnly): for each solved cell, create/attach a
	 *   cISC4NetworkOccupant (or update an existing one), set flags/params, notify
	 *   the occupant manager, and optionally push the occupant to outPlaced.
	 *
	 * @param solved      [in]  Solved cells (each entry references a target cell).
	 * @param outPlaced   [out] Optional list to receive occupants actually placed (only in placement path).
	 * @param previewOnly [in]  Force preview-only processing even if the tool is in placing mode.
	 */
	virtual void InsertOccupantsForSolvedCells(
		const SC4List<tSolvedCell>& solved,
		SC4List<cISC4NetworkOccupant*>* outPlaced,
		bool previewOnly) = 0;

	/**
	 * Test whether the candidate tiles can be supported by the terrain for a given network type.
	 *
	 * High level:
	 * - Re-initialize the vertex-height constraint solver.
	 * - For each candidate cell and its four vertices:
	 *   - Seed with the current/known height; mark fixed if the cell/vertex is locked.
	 *   - Otherwise add a height **range** and preferred value based on per-network tolerances
	 *     (clearances/slopes), and account for support structures when present.
	 * - Add intersection constraints.
	 * - Solve; return true if a consistent solution exists (i.e., terrain can support the tiles).
	 *
	 * @param type  Network type whose tolerances/clearances are applied.
	 * @return      true if the constraints are solvable; false otherwise.
	 */
	virtual bool CanTilesBeSupportedOnTerrain(cISC4NetworkOccupant::eNetworkType type) = 0;

	/**
	 * Apply solved vertex heights to terrain and record which vertices changed.
	 *
	 * - Reads solved vertices from the internal solver, compares to current height (ε = 1e-3).
	 * - For each changed vertex: marks it dirty and pushes its id to `changedVerts`.
	 * - Computes a padded bounding box of changed tiles and asks the terrain system to refresh it.
	 *
	 * @param changedVerts [out] Cleared then filled with vertex ids that changed.
	 */
	virtual void UpdateTerrainHeights(SC4Vector<uint32_t>& changedVerts) = 0;

	/**
	 * Add a textured preview overlay for a solved cell.
	 *
	 * - Clears any existing preview at the cell, then adds a quad using the cell's four corner heights.
	 * - Chooses the texture set:
	 *   - Single-network cell → use the network bit set in cell.flags and the solved variant.
	 *   - Multi-network/intersection → resolve with SolveMultiTypeSeparation and pick the
	 *     appropriate texture subset.
	 * - Applies a tint based on a cell status flag (e.g., special/elevated vs normal).
	 *
	 * @param cell    [in]  Cell info (tile x/y in cell.x,cell.y; corner heights; network flags, etc.).
	 * @param solved  [in]  Solved-cell data: base texture set/index and an 8-bit variant
	 *                      (low 7 bits = variant, high bit = flip/mirror).
	 */
	virtual void AddCellPreview(
		cSC4NetworkCellInfo& cell,
		const tSolvedCell& solved) = 0;

	/**
	 * Recompute and apply occupant highlights for the current drag/solution.
	 *
	 * - Collects candidate tiles from the current solved ranges; skips occupied cells.
	 * - Rebuilds the demolition region and updates the highlighted-occupant set.
	 * - If no tiles to process, clears highlights.
	 *
	 * @param budget  Step/countdown to drive repeated updates.
	 * @return        Updated budget: unchanged if a demolition region was produced,
	 *                otherwise decremented by 1.
	 */
	virtual int UpdateOccupantHighlights(int budget) = 0;

	/**
	 * Demolish all currently highlighted occupants, then clear highlights.
	 *
	 * Uses the demolition service with a default occupant filter to remove
	 * occupants within the internally stored demolition region (built by
	 * UpdateOccupantHighlights). No-op if there is no region.
	 */
	virtual void DestroyHighlightedOccupants() = 0;

	/** Whether this tool permits bridge placement. */
	virtual bool AllowBridges() = 0;

	/** Whether this tool permits tunnel placement. */
	virtual bool AllowTunnels() = 0;

	/** Whether water tiles block this tool’s actions. */
	virtual bool IsStoppedByWater() = 0;

	/** Whether the tool should auto-connect to nearby networks. */
	virtual bool ShouldAutoConnect() = 0;

	/**
	 * Test if an auto-connect occupant applies at the given tile.
	 * @param x Tile X.
	 * @param y Tile Y.
	 * @return true if an auto-connect occupant should be used.
	 */
	virtual bool TestForAutoConnectOccupant(int x, int y) = 0;

	/**
	 *  Validate initial point; on failure sets outIndex=0.
	 *  @param outIndex [out] Set to 0 if the first point fails validation.
	 *  @return true if the start is valid; false otherwise.
	 */
	virtual bool IdentifyStartingConditions(int& outIndex) = 0;

	/**
	 *  Check for reserved occupants along current ranges (optionally skipping them) and per-point fallback.
	 *  @param inOutIndex [in/out] Range index to scan; set to offending index, or 0 if from fallback.
	 *  @param type       [in] Network type.
	 *  @param skipRanges [in] If true, only perform per-point fallback checks.
	 *  @return void
	 */
	virtual void CheckForReservedTiles(int& inOutIndex, cISC4NetworkOccupant::eNetworkType type, bool skipRanges) = 0;

	/**
	 *  Check a single tile for reserved occupants.
	 *  @param x    [in] Tile X.
	 *  @param y    [in] Tile Y.
	 *  @param type [in] Network type.
	 *  @return true if the tile is reserved/blocked; false otherwise.
	 */
	virtual bool CheckForReservedTiles(uint32_t x, uint32_t y, cISC4NetworkOccupant::eNetworkType type) = 0;

	/**
     *  Validate terrain along current ranges and fallback points.
	 *  @param outIndex [out] Offending range index on failure; 0 if from fallback.
	 *  @return true if terrain is acceptable; false otherwise.
	 */
	virtual bool CheckForGoodTerrain(int& outIndex) = 0;

	/**
	 *  Begin placement workflow
	 *  @return void
	 */
	virtual void StartPlacing() = 0;

	/**
	 *  Create/refresh cell infos for all tiles in the current placement for the given network.
	 *  Initializes heights/flags and clamps against water as needed.
	 *
	 *  @param type  Network type to tag onto each cell.
	 *  @return void
	 */
	virtual void CreateCellInfosForCurrentPlacementTiles(cISC4NetworkOccupant::eNetworkType type) = 0;

	/**
	 *  Create and configure an occupant for a solved cell; apply flags/exemplar, notify managers,
	 *  and optionally append to an output list.
	 *
	 *  @param cell       [in,out] Target cell.
	 *  @param solved     [in]     Solved-cell descriptor (texture/variant).
	 *  @param outPlaced  [out]    Optional list to receive the created occupant.
	 *  @return void
	 */
	virtual void InsertNetworkOccupant(cSC4NetworkCellInfo& cell,
									   const tSolvedCell& solved,
									   SC4List<cISC4NetworkOccupant*>* outPlaced) = 0;

	/**
	 *  Ensure a network vertex height is available; use solver if present, otherwise query terrain.
	 *
	 *  @param vertexId  Vertex identifier.
	 *  @return void
	 */
	virtual void GetNetworkVertexHt(int vertexId) const = 0;

	/**
	 *  Map a terrain height to the corresponding network height (implementation-defined).
	 *
	 *  @param terrainHt  Input terrain height.
	 *  @return void
	 */
	virtual void GetNetworkHeightForTerrainHeight(float terrainHt) const = 0;

	/**
	 *  Expand the solved-cell set to improve continuity/smoothing across neighbors.
	 *
	 *  @return void
	 */
	virtual void PropagateSolvedCellsForSmoothing() = 0;

	/**
	 *  Insert solver constraints for a specific cell: fixed/range/preferred values based on
	 *  occupancy/locks; handles lot-adjacent edge fixing.
	 *
	 *  @param cellId  Packed tile id (x,y).
	 *  @return void
	 */
	virtual void InsertRangeConstraintsForCell(uint32_t cellId) = 0;

	/**
	 *  Constrain regular cells’ vertex heights to a reference plane inferred from immovable spans.
	 *  For each regular solved range, computes a best-fit plane and tightens per-vertex min/max
	 *  envelopes around the plane (with small slack), leaving non-regular ranges untouched.
	 *
	 *  @param portions [in] Spans/segments to anchor the plane computation.
	 *  @return void
	 */
	virtual void ApplyPlaneConstraintToRegularCells(SC4Vector<tImmovablePortion>& portions) = 0;

	/**
	 *  Hook for network-specific solver constraints for a single cell.
	 *
	 *  @param cellId [in] Packed tile id (x,y).
	 *  @return void
	 */
	virtual void InsertNetworkSpecificConstraintsForCell(uint32_t cellId) = 0;

	/**
	 *  Reload network-specific cached data/assets after external changes.
	 *
	 *  @param what [in] Unknown selector/mask (e.g., network type or resource key?).
	 *  @return void
	 */
	virtual void ReloadNetworkSpecificInfo(uint32_t what) = 0;

	/**
	 *  Choose which triangles of the cell quad to render for an occupant, based on neighborhood code.
	 *  Sets the occupant’s draw flags to pick TL/BR vs TR/BL and split styles.
	 *
	 *  @param occ   [in,out] Occupant to update.
	 *  @param nbhd  [in]     Compact neighborhood descriptor for the tile.
	 *  @return void
	 */
	virtual void SetQuadTrianglesToDraw(cISC4NetworkOccupant* occ,
										const cSC4TileNeighborhoodCompact& nbhd) = 0;

};
