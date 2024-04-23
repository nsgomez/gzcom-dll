#pragma once
#include <cstdint>

struct EdgeConnection
{
	uint32_t networkType;
	// The game stores the edge data in a uint32_t using the order 0xWWNNEESS. We
	// place the uint32_t in a union to allow the individual byte fields to be
	// accessed without bit-shifting.
	union
	{
		uint32_t packedEdgeData;
		struct
		{
			uint8_t west;
			uint8_t north;
			uint8_t east;
			uint8_t south;
		} directions;
	} edgeData;
};

static_assert(sizeof(EdgeConnection) == 8, "sizeof(EdgeConnection) != 8");

class cSC4EdgeConnectionStore
{
public:
	uint32_t additionalNetworkCount;        // 0
	EdgeConnection firstNetwork;            // 4
	EdgeConnection* additionalNetworkArray; // 12
};

static_assert(sizeof(cSC4EdgeConnectionStore) == 16, "sizeof(EdgeConnection) != 16");
