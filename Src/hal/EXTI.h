#pragma once

#include "common.h"

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
