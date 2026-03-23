#pragma once

/*=========================*/
/* CLock Source Selection  */
/*=========================*/
#define CONFIG_USE_HSI      0
#define CONFIG_USE_HSE      1


/*=========================*/
/* HSE Settings            */
/*=========================*/
// 8 MHz crystal
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


