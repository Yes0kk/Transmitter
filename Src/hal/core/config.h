#pragma once



/*=========================*/
/* MCO Settings			   */
/*=========================*/

/* 	0b0xx -> No Clock, 
	0b100 -> SYSCLK, 
	0b101 -> HSI, 
	0b110 -> HSE, 
	0b111 -> PLL/2
*/
#define CONFIG_MCO_USE_CLOCK 0b100

/*=========================*/
/* SYSCLK Settings		   */
/*=========================*/

/*	0b00 -> HSI,
	0b01 -> HSE,
	0b10 -> PLL,
	0b11 -> NOT ALLOWED
*/
#define CONFIG_SYSCLK 0b10

/*=========================*/
/* CLOCK Settings          */
/*=========================*/

#define CONFIG_CLOCK_TIMEOUT 1000000

/*=========================*/
/* HSE Settings            */
/*=========================*/
// 8 MHz crystal, change value if not
#define CONFIG_HSE_FREQ      8000000UL  
// 1 for external clock, 0 for crystal oscillator
#define CONFIG_HSE_BYPASS    0

/*=========================*/
/* PLL Settings            */
/*=========================*/

#define CONFIG_USE_PLL         1
// 1 = HSE, 0 = HSI / 2
#define CONFIG_PLL_SOURCE_HSE  1
// x*Clock speed = System clock speed (max 72 MHz) 
#define CONFIG_PLL_MUL         9


/*=========================*/
/* PLL Settings            */
/*=========================*/
// No division
#define CONFIG_AHB_PRESCALER   1
// max 36 Mhz
#define CONFIG_APB1_PRESCALER  2
#define CONFIG_APB2_PRESCALER  1


//=========== PERMANENT CONFIG (Know what you're doing) ==========*/


/*=========================*/
/* DEVICE		           */
/*=========================*/

// Maximum SYSCLK speed as defined in RM0008
#define SETTING_DEVICE_MAX_SYSCLK_FREQ 	72000000UL
// Maximum MCO frequency output as defiend in RM0008
#define SETTING_DEVICE_MAX_MCO_FREQ 	50000000UL

/*=========================*/
/* HSI			           */
/*=========================*/
// HSI frequency as defined in RM0008
#define SETTING_HSI_FREQ 	8000000UL
