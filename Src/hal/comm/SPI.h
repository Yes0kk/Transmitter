#pragma once

#include "../device/base_addresses.h"


// SPI base addresses
#define SPI1_BASE       (APB2_BASE + 0x00003000UL)
#define SPI3_BASE       (APB1_BASE + 0x00003C00UL)
#define SPI2_BASE       (APB1_BASE + 0x00003800UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* SERIAL PERIPHERAL INTERFACE */
typedef struct SPI_TypeDef
{
	volatile uint32_t CR1;		// 0x00
	volatile uint32_t CR2;		// 0x04
	volatile uint32_t SR;		// 0x08
	volatile uint32_t DR;		// 0x0C
	volatile uint32_t CRCPR;	// 0x10
	volatile uint32_t RXCRCR;	// 0x14
	volatile uint32_t TXCRCR;	// 0x18
	volatile uint32_t I2SCFGR;	// 0x1C
	volatile uint32_t I2SPR;	// 0x20
} SPI_TypeDef;


// SPI
#define SPI1 	((SPI_TypeDef *) SPI1_BASE)
#define SPI2 	((SPI_TypeDef *) SPI2_BASE)
#define SPI3 	((SPI_TypeDef *) SPI3_BASE)
