#pragma once

<<<<<<<< HEAD:Src/hal/Registers/watchdog/wdg.h
#include "../device/memory_map.h"
========
#include "../device/base_addresses.h"
>>>>>>>> 889d5c478d538e0c1e3ec228e59dd548133ea27a:Src/hal/system/watchdog.h


/* Watchdog Base Addresses*/
#define IWDG_BASE       (APB1_BASE + 0x00003000UL)
/* Independent Watchdog Base Address */
#define WWDG_BASE       (APB1_BASE + 0x00002C00UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* INDEPENDENT WATCHDOG */
typedef struct IWDG_TypeDef
{
	volatile uint32_t KR;		// 0x00
	volatile uint32_t PR;		// 0x04
	volatile uint32_t RLR;		// 0x08
	volatile uint32_t SR;		// 0x0C
} IWDG_TypeDef;

/* WINDOW WATCHDOG */
typedef struct WWDG_TypeDef
{
	volatile uint32_t CR;		// 0x00
	volatile uint32_t CFR;		// 0x04
	volatile uint32_t SR;		// 0x08
} WWDG_TypeDef;


// Watchdog 
#define IWDG ((IWDG_TypeDef *) IWDG_BASE)
#define WWDG ((WWDG_TypeDef *) WWDG_BASE)
