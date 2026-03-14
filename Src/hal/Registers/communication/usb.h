#pragma once

#include "../device/memory_map.h"


/* USB Base Address */
#define USB_BASE	(APB1_BASE + 0x00005C00UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* UNIVERSAL SERIAL BUS FULL-SPEED DEVICE INTERFACE */
typedef struct USB_TypeDef
{
	volatile uint32_t EP0R;		// 0x00
	volatile uint32_t EP1R;		// 0x04
	volatile uint32_t EP2R;		// 0x08
	volatile uint32_t EP3R;		// 0x0C
	volatile uint32_t EP4R;		// 0x10
	volatile uint32_t EP5R;		// 0x14
	volatile uint32_t EP6R;		// 0x18
	volatile uint32_t EP7R;		// 0x1C
	uint32_t RESERVED[8];		// 0x20-0x3F
	volatile uint32_t CNTR;		// 0x40
	volatile uint32_t ISTR;		// 0x44
	volatile uint32_t FNR;		// 0x48
	volatile uint32_t DADDR;	// 0x4C
	volatile uint32_t BTABLE;	// 0x50
} USB_TypeDef;


// USB
#define USB ((USB_TypeDef *) USB_BASE)
