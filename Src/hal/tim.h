#pragma once

#include "common.h"


#define TIM14_BASE (APB1_BASE + 0x00002000UL)
#define TIM13_BASE (APB1_BASE + 0x00001C00UL)
#define TIM12_BASE (APB1_BASE + 0x00001800UL)
#define TIM11_BASE (APB2_BASE + 0x00005400UL)
#define TIM10_BASE (APB2_BASE + 0x00005000UL)
#define TIM9_BASE  (APB2_BASE + 0x00004C00UL)
#define TIM8_BASE  (APB2_BASE + 0x00003400UL)
#define TIM7_BASE  (APB1_BASE + 0x00001400UL)
#define TIM6_BASE  (APB1_BASE + 0x00001000UL)
#define TIM5_BASE  (APB1_BASE + 0x00000C00UL)
#define TIM4_BASE  (APB1_BASE + 0x00000800UL)
#define TIM3_BASE  (APB1_BASE + 0x00000400UL)
#define TIM2_BASE  (APB1_BASE + 0x00000000UL)
#define TIM1_BASE  (APB2_BASE + 0x00002C00UL)

/*====================*/
// Struct Definitions //
/*====================*/

/* ADVANCED-CONTROL TIMERS (TIM1, TIM8) */
typedef struct TIM_Adv_TypeDef
{
	volatile uint32_t CR1;		// 0x00
	volatile uint32_t CR2;		// 0x04
	volatile uint32_t SMCR;		// 0x08
	volatile uint32_t DIER;		// 0x0C
	volatile uint32_t SR;		// 0x10
	volatile uint32_t EGR;		// 0x14
	volatile uint32_t CCMR1;	// 0x18
	volatile uint32_t CCMR2;	// 0x1C
	volatile uint32_t CCER;		// 0x20
	volatile uint32_t CNT;		// 0x24
	volatile uint32_t PSC;		// 0x28
	volatile uint32_t ARR;		// 0x2C
	volatile uint32_t RCR;		// 0x30
	volatile uint32_t CCR1;		// 0x34
	volatile uint32_t CCR2;		// 0x38
	volatile uint32_t CCR3;		// 0x3C
	volatile uint32_t CCR4;		// 0x40
	volatile uint32_t BDTR;		// 0x44
	volatile uint32_t DCR;		// 0x48
	volatile uint32_t DMAR;		// 0x4C
} TIM_Adv_TypeDef;

/* BASIC TIMERS (TIM6, TIM7) */
typedef struct TIM_Basic_TypeDef
{
	volatile uint32_t CR1;		// 0x00
	volatile uint32_t CR2;		// 0x04
	uint32_t RESERVED0;			// 0x08
	volatile uint32_t DIER;		// 0x0C
	volatile uint32_t SR;		// 0x10
	volatile uint32_t EGR;		// 0x14
	uint32_t RESERVED1[3];		// 0x18-0x20
	volatile uint32_t CNT;		// 0x24
	volatile uint32_t PSC;		// 0x28
	volatile uint32_t ARR;		// 0x2C
} TIM_Basic_TypeDef;

/* GENERAL-PURPOSE TIMERS ONE CHANNEL (TIM10, TIM11, TIM13, TIM14) */
typedef struct TIM_Gen1_TypeDef
{
	volatile uint32_t CR1;		// 0x00
	uint32_t RESERVED0[2];		// 0x04-0x08
	volatile uint32_t DIER;		// 0x0C
	volatile uint32_t SR;		// 0x10
	volatile uint32_t EGR;		// 0x14
	volatile uint32_t CCMR1;	// 0x18
	uint32_t RESERVED2;			// 0x1C
	volatile uint32_t CCER;		// 0x20
	volatile uint32_t CNT;		// 0x24
	volatile uint32_t PSC;		// 0x28
	volatile uint32_t ARR;		// 0x2C
	uint32_t RESERVED3;			// 0x30
	volatile uint32_t CCR1;		// 0x34
} TIM_Gen1_TypeDef;

/* GENERAL-PURPOSE TIMERS TWO CHANNELS (TIM9, TIM12) */
typedef struct TIM_Gen2_TypeDef
{
	volatile uint32_t CR1;		// 0x00
	uint32_t RESERVED0;			// 0x04
	volatile uint32_t SMCR;		// 0x08
	volatile uint32_t DIER;		// 0x0C
	volatile uint32_t SR;		// 0x10
	volatile uint32_t EGR;		// 0x14
	volatile uint32_t CCMR1;	// 0x18
	uint32_t RESERVED1;			// 0x1C
	volatile uint32_t CCER;		// 0x20
	volatile uint32_t CNT;		// 0x24
	volatile uint32_t PSC;		// 0x28
	volatile uint32_t ARR;		// 0x2C
	uint32_t RESERVED2;			// 0x30
	volatile uint32_t CCR1;		// 0x34
	volatile uint32_t CCR2;		// 0x38
} TIM_Gen2_TypeDef;

/* GENERAL-PURPOSE TIMERS FOUR CHANNELS (TIM2, TIM3, TIM4, TIM5)*/
typedef struct TIM_Gen4_TypeDef
{
	volatile uint32_t CR1;		// 0x00
	volatile uint32_t CR2;		// 0x04
	volatile uint32_t SMCR;		// 0x08
	volatile uint32_t DIER;		// 0x0C
	volatile uint32_t SR;		// 0x10
	volatile uint32_t EGR;		// 0x14
	volatile uint32_t CCMR1;	// 0x18
	volatile uint32_t CCMR2;	// 0x1C
	volatile uint32_t CCER;		// 0x20
	volatile uint32_t CNT;		// 0x24
	volatile uint32_t PSC;		// 0x28
	volatile uint32_t ARR;		// 0x2C
	uint32_t RESERVED0;			// 0x30
	volatile uint32_t CCR1;		// 0x34
	volatile uint32_t CCR2;		// 0x38
	volatile uint32_t CCR3;		// 0x3C
	volatile uint32_t CCR4;		// 0x40
	uint32_t RESERVED1; 		// 0x44
	volatile uint32_t DCR;		// 0x48
	volatile uint32_t DMAR;		// 0x4C
} TIM_Gen4_TypeDef;


// Advanced-Control Timers
#define TIM1	((TIM_Adv_TypeDef*)  	TIM1_BASE)
#define TIM8	((TIM_Adv_TypeDef*)  	TIM8_BASE)
// Basic Timers
#define TIM6	((TIM_Basic_TypeDef*) 	TIM6_BASE)
#define TIM7	((TIM_Basic_TypeDef*) 	TIM7_BASE)
// General-Purpose Timers, One Channel
#define TIM10	((TIM_Gen1_TypeDef*) 	TIM10_BASE)
#define TIM11	((TIM_Gen1_TypeDef*) 	TIM11_BASE)
#define TIM13	((TIM_Gen1_TypeDef*) 	TIM13_BASE)
#define TIM14	((TIM_Gen1_TypeDef*) 	TIM14_BASE)
// General-Purpose Timers, Two Channels
#define TIM9	((TIM_Gen2_TypeDef*) 	TIM9_BASE)
#define TIM12	((TIM_Gen2_TypeDef*) 	TIM12_BASE)
// General-Purpose Timers, Four Channels
#define TIM2	((TIM_Gen4_TypeDef*) 	TIM2_BASE)
#define TIM3	((TIM_Gen4_TypeDef*) 	TIM3_BASE)
#define TIM4	((TIM_Gen4_TypeDef*) 	TIM4_BASE)
#define TIM5	((TIM_Gen4_TypeDef*) 	TIM5_BASE)
