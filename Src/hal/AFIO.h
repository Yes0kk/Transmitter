#pragma once 

#include "common.h"


// AFIO base address
#define AFIO_BASE		(APB2_BASE + 0x00000000UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* GENERAL-PURPOSE AND ALTERNATE-FUNCTION I/Os */
typedef struct AFIO_TypeDef
{
	volatile uint32_t EVCR;		// 0x00
	volatile uint32_t MAPR;		// 0x04
	volatile uint32_t EXTICR[4];	// 0x08 - 0x14
	volatile uint32_t MAPR2;	// 0x18
} AFIO_TypeDef;


// AFIO
#define AFIO 	((AFIO_TypeDef *) AFIO_BASE)
