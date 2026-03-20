#pragma once

<<<<<<<< HEAD:Src/hal/Registers/system/exti.h
#include "../device/memory_map.h"
========
#include "../device/base_addresses.h"
>>>>>>>> 889d5c478d538e0c1e3ec228e59dd548133ea27a:Src/hal/system/EXTI.h

// EXTI base address
#define EXTI_BASE       (APB2_BASE + 0x00000400UL)


/*====================*/
// Struct Definition  //
/*====================*/
 
/* INTERRUPTS AND EVENTS */
typedef struct EXTI_TypeDef
{
	volatile uint32_t IMR;		// 0x00
	volatile uint32_t EMR;		// 0x04
	volatile uint32_t RTSR;		// 0x08
	volatile uint32_t FTSR;		// 0x0C
	volatile uint32_t SWIER;	// 0x10
	volatile uint32_t PR;		// 0x14
} EXTI_TypeDef;


// EXTI
#define EXTI 	((EXTI_TypeDef *) EXTI_BASE)
