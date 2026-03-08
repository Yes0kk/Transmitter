#pragma once

#include <stdint.h>
#include <stdio.h>

#pragma region Peripheral Base
#define PERIPHERAL_BASE (0x40000000UL)
#pragma endregion

#pragma region Bus Bases
#define AHB_BASE  (PERIPHERAL_BASE + 0x00018000UL)
#define APB2_BASE (PERIPHERAL_BASE + 0x00010000UL)
#define APB1_BASE (PERIPHERAL_BASE + 0x00000000UL)
#pragma endregion
