#pragma once

#include "common.h"

/* BKP Base Address */
#define BKP_BASE	(APB1_BASE + 0x00002800UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* BACKUP REGISTERS */
typedef struct BKP_TypeDef
{
	uint32_t RESERVED0; 		// 0x00
	volatile uint32_t DR1[10];	// 0x04-0x28
	volatile uint32_t RTCCR;	// 0x2C
	volatile uint32_t CR;		// 0x30
	volatile uint32_t CSR;		// 0x34
	uint32_t RESERVED1[2];		// 0x38-0x3C
	volatile uint32_t DR2[32];	// 0x40-0xBC

} BKP_TypeDef;


// BKP
#define BKP ((BKP_TypeDef *) BKP_BASE)
