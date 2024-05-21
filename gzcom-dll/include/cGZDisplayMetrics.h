#pragma once
#include <cstdint>

class cGZDisplayMetrics
{
public:
	uint32_t width;        // 0x0
	uint32_t height;       // 0x4
	uint32_t bitDepth;     // 0x8
	uint32_t field3_0xc;   // 0xc
	uint32_t field4_0x10;  // 0x10
	uint32_t field5_0x14;  // 0x14
	uint32_t field6_0x18;  // 0x18
};