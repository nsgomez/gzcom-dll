#pragma once
#include <cstdint>

class SC4RegionPreferences
{
public:
    uint8_t regionName[64];  // 0x0
    uint32_t field1_0x40;    // 0x40
    uint32_t field2_0x44;    // 0x44
    uint8_t field3_0x48;     // 0x48
    uint8_t field4_0x49;     // 0x49
    uint8_t field5_0x4a;     // 0x4a
    uint8_t field6_0x4b;     // 0x4b
};

