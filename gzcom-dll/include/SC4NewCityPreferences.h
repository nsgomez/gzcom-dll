#pragma once
#include <cstdint>

class SC4NewCityPreferences
{
public:
    char cityName[512];        // 0x0
    char mayorName[512];       // 0x200
    uint32_t difficultyLevel;  // 0x400
};

