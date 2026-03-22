#pragma once

#include "../clock/clock.h"
#include "../core/core.h"
#include "config.h"

typedef enum 
{
	CLOCK_SYSCLK_HSI = 0x0,
	CLOCK_SYSCLK_HSE = 0x1,
	CLOCK_SYSCLK_PLL = 0x2,
} CLOCK_SYSCLK_SOURCE;

typedef enum
{
	CLOCK_MCOCLK_SYSCLK 	= 0x4,
	CLOCK_MCOCLK_HSI		= 0x5,
	CLOCK_MCOCLK_HSE		= 0x6,
	CLOCK_MCOCLK_PLL_DIV2	= 0x7,
} CLOCK_MCOCLK_SOURCE;

HAL_status CLOCK_init(void);
