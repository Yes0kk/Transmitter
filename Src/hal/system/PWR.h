#pragma once

<<<<<<<< HEAD:Src/hal/Registers/system/pwr.h
#include "../device/memory_map.h"
========
#include "../device/base_addresses.h"
>>>>>>>> 889d5c478d538e0c1e3ec228e59dd548133ea27a:Src/hal/system/PWR.h


/* PWR Base Address */
#define PWR_BASE	(APB1_BASE + 0x00007000UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* POWER CONTROL */
typedef struct PWR_TypeDef
{
	volatile uint32_t CR;		// 0x00
	volatile uint32_t CSR;		// 0x04
} PWR_TypeDef;


// PWR
#define PWR ((PWR_TypeDef *) PWR_BASE)
