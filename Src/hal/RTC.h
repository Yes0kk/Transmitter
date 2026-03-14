#pragma once

#include "common.h"


/* RTC Base Address */
#define RTC_BASE	(APB1_BASE + 0x00002800UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* REAL-TIME CLOCK */
typedef struct RTC_TypeDef
{
	volatile uint32_t CRH;		// 0x00
	volatile uint32_t CRL;		// 0x04
	volatile uint32_t PRLH;		// 0x08
	volatile uint32_t PRLL;		// 0x0C
	volatile uint32_t DIVH;		// 0x10
	volatile uint32_t DIVL;		// 0x14
	volatile uint32_t CNTH;		// 0x18
	volatile uint32_t CNTL;		// 0x1C
	volatile uint32_t ALRH;		// 0x20
	volatile uint32_t ALRL;		// 0x24
} RTC_TypeDef;


// RTC
#define RTC ((RTC_TypeDef *) RTC_BASE)
