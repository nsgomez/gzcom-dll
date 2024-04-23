#pragma once
#include <cstdint>

class SC4VideoPreferences
{
public:
	uint8_t field0_0x0;                // 0x0
	uint8_t visualEffects;             // 0x1
	uint8_t carsAnsSims;               // 0x2
	uint8_t shadows;                   // 0x3
	uint8_t textureQuality;            // 0x4
	uint8_t bAtmosphericEffects;       // 0x5
	uint8_t bWaterEffects;             // 0x6
	uint8_t driverType;                // 0x7
	uint8_t cursorType;                // 0x8
	uint8_t bTranslucency;             // 0x9
	uint8_t cityDetail;                // 0xa
	uint8_t bFullScreen;               // 0xb
	uint32_t variableSpeedAutomata;    // 0xc
	uint32_t width;                    // 0x10
	uint32_t height;                   // 0x14
	uint32_t bitDepth;                 // 0x18
	uint32_t buildingLoaderSpeedGroup; // 0x1c
	uint32_t field17_0x20;             // 0x20
	uint32_t field18_0x24;             // 0x24
};