#pragma once 

<<<<<<<< HEAD:Src/hal/Registers/gpio/gpio.h
#include "../device/memory_map.h"
========
#include "../device/base_addresses.h"
>>>>>>>> 889d5c478d538e0c1e3ec228e59dd548133ea27a:Src/hal/system/GPIO.h



/* GPIO Ports */
#define GPIOA_BASE	(APB2_BASE + 0x00000800UL)
#define GPIOB_BASE	(APB2_BASE + 0x00000C00UL)
#define GPIOC_BASE	(APB2_BASE + 0x00001000UL)
#define GPIOD_BASE	(APB2_BASE + 0x00001400UL)
#define GPIOE_BASE	(APB2_BASE + 0x00001800UL)
#define GPIOF_BASE	(APB2_BASE + 0x00001C00UL)
#define GPIOG_BASE	(APB2_BASE + 0x00002000UL)
/* AFIO Base Address */
#define AFIO_BASE	(APB2_BASE + 0x00000000UL)

/*====================*/
// Struct Definition  //
/*====================*/

/* GENERAL-PURPOSE AND ALTERNATE FUNCTION I/Os */
typedef struct GPIO_TypeDef
{
	volatile uint32_t CRL;		// 0x00
	volatile uint32_t CRH;		// 0x04
	volatile uint32_t IDR;		// 0x08
	volatile uint32_t ODR;		// 0x0C
	volatile uint32_t BSRR;		// 0x10
	volatile uint32_t BRR;		// 0x14
	volatile uint32_t LCKR;		// 0x18
} GPIO_TypeDef;

/* ALTERNATE FUNCTION I/O */
typedef struct AFIO_TypeDef
{
	volatile uint32_t EVCR;		// 0x00
	volatile uint32_t MAPR;		// 0x04
	volatile uint32_t EXTICR1;	// 0x08
	volatile uint32_t EXTICR2;	// 0x0C
	volatile uint32_t EXTICR3;	// 0x10
	volatile uint32_t EXTICR4;	// 0x14
	volatile uint32_t MAPR2;	// 0x18
} AFIO_TypeDef;


// GPIO Ports
#define GPIOA 	((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB 	((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC 	((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD 	((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE 	((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF 	((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG 	((GPIO_TypeDef *) GPIOG_BASE)
// AFIO
#define AFIO 	((AFIO_TypeDef *) AFIO_BASE)
