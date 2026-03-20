#pragma once

<<<<<<<< HEAD:Src/hal/Registers/communication/i2c.h
#include "../device/memory_map.h"
========
#include "../device/base_addresses.h"
>>>>>>>> 889d5c478d538e0c1e3ec228e59dd548133ea27a:Src/hal/comm/I2C.h


// I2C Base Addresses
#define I2C1_BASE       (APB1_BASE + 0x00005400UL)
#define I2C2_BASE       (APB1_BASE + 0x00005800UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* INTER-INTEGRATED CIRCUIT INTERFACE */
typedef struct I2C_TypeDef
{
	volatile uint32_t CR1;		// 0x00
	volatile uint32_t CR2;		// 0x04
	volatile uint32_t OAR1;		// 0x08
	volatile uint32_t OAR2;		// 0x0C
	volatile uint32_t DR;		// 0x10
	volatile uint32_t SR1;		// 0x14
	volatile uint32_t SR2;		// 0x18
	volatile uint32_t CCR;		// 0x1C
	volatile uint32_t TRISE;	// 0x20
} I2C_TypeDef;


// I2C 
#define I2C1 	((I2C_TypeDef *) I2C1_BASE)
#define I2C2 	((I2C_TypeDef *) I2C2_BASE)
