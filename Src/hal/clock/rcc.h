#pragma once

<<<<<<<< HEAD:Src/hal/Registers/rcc/rcc.h
#include "../device/memory_map.h"
========
#include "../device/base_addresses.h"
>>>>>>>> 889d5c478d538e0c1e3ec228e59dd548133ea27a:Src/hal/clock/rcc.h

/* RCC Base Address */
#define RCC_BASE (AHB_BASE + 0x00009000UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* RESET AND CLOCK CONTROL */
typedef struct RCC_TypeDef
{
	volatile uint32_t CR;			// 0x00
	volatile uint32_t CFGR;			// 0x04
	volatile uint32_t CIR;			// 0x08
	volatile uint32_t APB2RSTR;		// 0x0C
	volatile uint32_t APB1RSTR;		// 0x10
	volatile uint32_t AHBENR;		// 0x14
	volatile uint32_t APB2ENR;		// 0x18
	volatile uint32_t APB1ENR;		// 0x1C
	volatile uint32_t BDCR;			// 0x20
	volatile uint32_t CSR;			// 0x24
} RCC_TypeDef;


// Reset and Clock Control
#define RCC 	((RCC_TypeDef *) RCC_BASE)
