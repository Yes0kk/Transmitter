#pragma once

#include "../device/memory_map.h"


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
