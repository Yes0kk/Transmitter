#pragma once

#include "../device/memory_map.h"


/* DAC Base Address */
#define DAC_BASE	(APB1_BASE + 0x00007400UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* DIGITAL TO ANALOG CONVERTER */
typedef struct DAC_TypeDef
{
	volatile uint32_t CR;		// 0x00
	volatile uint32_t SWTRIGR;	// 0x04
	volatile uint32_t DHR12R1;	// 0x08
	volatile uint32_t DHR12L1;	// 0x0C
	volatile uint32_t DHR8R1;	// 0x10
	volatile uint32_t DHR12R2;	// 0x14
	volatile uint32_t DHR12L2;	// 0x18
	volatile uint32_t DHR8R2;	// 0x1C
	volatile uint32_t DHR12RD;	// 0x20
	volatile uint32_t DHR12LD;	// 0x24
	volatile uint32_t DHR8RD;	// 0x28
	volatile uint32_t DOR1;		// 0x2C
	volatile uint32_t DOR2;		// 0x30
} DAC_TypeDef;


// DAC
#define DAC ((DAC_TypeDef *) DAC_BASE)