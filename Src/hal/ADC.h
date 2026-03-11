#pragma once

#include "common.h"


/* ADC Base Addresses*/
#define ADC3_BASE       (APB2_BASE + 0x00003C00UL)
#define ADC2_BASE       (APB2_BASE + 0x00002800UL)
#define ADC1_BASE       (APB2_BASE + 0x00002400UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* ANALOG-TO-DIGITAL CONVERTER */
typedef struct ADC_TypeDef
{
	volatile uint32_t SR;		// 0x00
	volatile uint32_t CR1;		// 0x04
	volatile uint32_t CR2;		// 0x08
	volatile uint32_t SMPR1;	// 0x0C
	volatile uint32_t SMPR2;	// 0x10
	volatile uint32_t JOFR1;	// 0x14
	volatile uint32_t JOFR2;	// 0x18
	volatile uint32_t JOFR3;	// 0x1C
	volatile uint32_t JOFR4;	// 0x20
	volatile uint32_t HTR;		// 0x24
	volatile uint32_t LTR;		// 0x28
	volatile uint32_t SQR1;		// 0x2C
	volatile uint32_t SQR2;		// 0x30
	volatile uint32_t SQR3;		// 0x34
	volatile uint32_t JSQR;		// 0x38
	volatile uint32_t JDR1;		// 0x3C
	volatile uint32_t JDR2;		// 0x40
	volatile uint32_t JDR3;		// 0x44
	volatile uint32_t JDR4;		// 0x48
	volatile uint32_t DR;		// 0x4C
} ADC_TypeDef;


// ADCs
#define ADC1 ((ADC_TypeDef *) ADC1_BASE)
#define ADC2 ((ADC_TypeDef *) ADC2_BASE)
#define ADC3 ((ADC_TypeDef *) ADC3_BASE)


