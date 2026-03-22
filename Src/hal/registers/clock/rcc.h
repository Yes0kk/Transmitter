#pragma once

#include <stdint.h>
#include "../device/base_addresses.h"

/*====================*/
/* RCC Base Address   */
/*====================*/

#define RCC_BASE (AHB_BASE + 0x00009000UL)

/*====================*/
/* RCC Register Map   */
/*====================*/

typedef struct
{
    volatile uint32_t CR;        // 0x00
    volatile uint32_t CFGR;      // 0x04
    volatile uint32_t CIR;       // 0x08
    volatile uint32_t APB2RSTR;  // 0x0C
    volatile uint32_t APB1RSTR;  // 0x10
    volatile uint32_t AHBENR;    // 0x14
    volatile uint32_t APB2ENR;   // 0x18
    volatile uint32_t APB1ENR;   // 0x1C
    volatile uint32_t BDCR;      // 0x20
    volatile uint32_t CSR;       // 0x24
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *) RCC_BASE)


/*====================*/
/* RCC_CR Register    */
/*====================*/

/* HSION: Internal High-Speed clock enable */
#define RCC_CR_HSION_Pos        0
#define RCC_CR_HSION_Msk        (1U << RCC_CR_HSION_Pos)

/* HSIRDY: Internal High-Speed clock ready flag */
#define RCC_CR_HSIRDY_Pos       1
#define RCC_CR_HSIRDY_Msk       (1U << RCC_CR_HSIRDY_Pos)

/* HSITRIM: Internal High-Speed clock trimming (5 bits) */
#define RCC_CR_HSITRIM_Pos      3
#define RCC_CR_HSITRIM_Msk      (0x1FU << RCC_CR_HSITRIM_Pos)

/* HSICAL: Internal High-Speed clock calibration (8 bits, read-only) */
#define RCC_CR_HSICAL_Pos       8
#define RCC_CR_HSICAL_Msk       (0xFFU << RCC_CR_HSICAL_Pos)

/* HSEON: External High-Speed clock enable */
#define RCC_CR_HSEON_Pos        16
#define RCC_CR_HSEON_Msk        (1U << RCC_CR_HSEON_Pos)

/* HSERDY: External High-Speed clock ready flag */
#define RCC_CR_HSERDY_Pos       17
#define RCC_CR_HSERDY_Msk       (1U << RCC_CR_HSERDY_Pos)

/* HSEBYP: External High-Speed clock bypass */
#define RCC_CR_HSEBYP_Pos       18
#define RCC_CR_HSEBYP_Msk       (1U << RCC_CR_HSEBYP_Pos)

/* CSSON: Clock Security System enable */
#define RCC_CR_CSSON_Pos        19
#define RCC_CR_CSSON_Msk        (1U << RCC_CR_CSSON_Pos)

/* PLLON: PLL enable */
#define RCC_CR_PLLON_Pos        24
#define RCC_CR_PLLON_Msk        (1U << RCC_CR_PLLON_Pos)

/* PLLRDY: PLL clock ready flag */
#define RCC_CR_PLLRDY_Pos       25
#define RCC_CR_PLLRDY_Msk       (1U << RCC_CR_PLLRDY_Pos)

/* HSITRIM: Internal High-Speed clock trimming (5 bits) */
#define RCC_CR_HSITRIM_VALUE(x)   (((x) & 0x1FU) << RCC_CR_HSITRIM_Pos)

/* HSICAL: Internal High-Speed clock calibration (8 bits, read-only) */
#define RCC_CR_HSICAL_VALUE(x)    (((x) & 0xFFU) << RCC_CR_HSICAL_Pos)

/* PLLSRC: PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSI_DIV2  (0U << RCC_CFGR_PLLSRC_Pos)
#define RCC_CFGR_PLLSRC_HSE       (1U << RCC_CFGR_PLLSRC_Pos)

/* PLLXTPRE: HSE divider for PLL entry */
#define RCC_CFGR_PLLXTPRE_HSE     (0U << RCC_CFGR_PLLXTPRE_Pos)
#define RCC_CFGR_PLLXTPRE_HSE_DIV2 (1U << RCC_CFGR_PLLXTPRE_Pos)


/*====================*/
/* RCC_CFGR Register  */
/*====================*/

/* SW: System clock switch (2 bits) */
#define RCC_CFGR_SW_Pos         0
#define RCC_CFGR_SW_Msk         (0x3U << RCC_CFGR_SW_Pos)

/* SWS: System clock switch status (2 bits) */
#define RCC_CFGR_SWS_Pos        2
#define RCC_CFGR_SWS_Msk        (0x3U << RCC_CFGR_SWS_Pos)

/* HPRE: AHB prescaler (4 bits) */
#define RCC_CFGR_HPRE_Pos       4
#define RCC_CFGR_HPRE_Msk       (0xFU << RCC_CFGR_HPRE_Pos)

/* PPRE1: APB1 prescaler (3 bits) */
#define RCC_CFGR_PPRE1_Pos      8
#define RCC_CFGR_PPRE1_Msk      (0x7U << RCC_CFGR_PPRE1_Pos)

/* PPRE2: APB2 prescaler (3 bits) */
#define RCC_CFGR_PPRE2_Pos      11
#define RCC_CFGR_PPRE2_Msk      (0x7U << RCC_CFGR_PPRE2_Pos)

/* ADCPRE: ADC prescaler (2 bits) */
#define RCC_CFGR_ADCPRE_Pos     14
#define RCC_CFGR_ADCPRE_Msk     (0x3U << RCC_CFGR_ADCPRE_Pos)

/* PLLSRC: PLL entry clock source */
#define RCC_CFGR_PLLSRC_Pos     16
#define RCC_CFGR_PLLSRC_Msk     (1U << RCC_CFGR_PLLSRC_Pos)

/* PLLXTPRE: HSE divider for PLL entry */
#define RCC_CFGR_PLLXTPRE_Pos   17
#define RCC_CFGR_PLLXTPRE_Msk   (1U << RCC_CFGR_PLLXTPRE_Pos)

/* PLLMUL: PLL multiplication factor (4 bits) */
#define RCC_CFGR_PLLMUL_Pos     18
#define RCC_CFGR_PLLMUL_Msk     (0xFU << RCC_CFGR_PLLMUL_Pos)

/* USBPRE: USB prescaler */
#define RCC_CFGR_USBPRE_Pos     22
#define RCC_CFGR_USBPRE_Msk     (1U << RCC_CFGR_USBPRE_Pos)

/* MCO: Microcontroller clock output (3 bits) */
#define RCC_CFGR_MCO_Pos        24
#define RCC_CFGR_MCO_Msk        (0x7U << RCC_CFGR_MCO_Pos)

/* MCO source values */
#define RCC_CFGR_MCO_NONE       (0b000U << RCC_CFGR_MCO_Pos) // no clock
#define RCC_CFGR_MCO_SYSTEM     (0b100U << RCC_CFGR_MCO_Pos) // system clock
#define RCC_CFGR_MCO_HSI        (0b101U << RCC_CFGR_MCO_Pos) // HSI clock
#define RCC_CFGR_MCO_HSE        (0b110U << RCC_CFGR_MCO_Pos) // HSE clock
#define RCC_CFGR_MCO_PLL_DIV2   (0b111U << RCC_CFGR_MCO_Pos) // PLL clock divided by 2

/* System clock switch */
#define RCC_CFGR_SW_HSI         (0b00U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSE         (0b01U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_PLL         (0b10U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_NONE        (0b11U << RCC_CFGR_SW_Pos)

/* System clock switch status */
#define RCC_CFGR_SWS_HSI        (0b00U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSE        (0b01U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_PLL        (0b10U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_NONE       (0b11U << RCC_CFGR_SWS_Pos)

/* AHB prescaler values */
#define RCC_CFGR_HPRE_DIV1      (0b0000U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV2      (0b1000U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV4      (0b1001U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV8      (0b1010U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV16     (0b1011U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV64     (0b1100U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV128    (0b1101U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV256    (0b1110U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV512    (0b1111U << RCC_CFGR_HPRE_Pos)

/* APB1 prescaler values */
#define RCC_CFGR_PPRE1_DIV1     (0b000U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV2     (0b100U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV4     (0b101U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV8     (0b110U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV16    (0b111U << RCC_CFGR_PPRE1_Pos)

/* APB2 prescaler values */
#define RCC_CFGR_PPRE2_DIV1     (0b000U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV2     (0b100U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV4     (0b101U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV8     (0b110U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV16    (0b111U << RCC_CFGR_PPRE2_Pos)

/* ADC prescaler values */
#define RCC_CFGR_ADCPRE_DIV2    (0b00U << RCC_CFGR_ADCPRE_Pos)
#define RCC_CFGR_ADCPRE_DIV4    (0b01U << RCC_CFGR_ADCPRE_Pos)
#define RCC_CFGR_ADCPRE_DIV6    (0b10U << RCC_CFGR_ADCPRE_Pos)
#define RCC_CFGR_ADCPRE_DIV8    (0b11U << RCC_CFGR_ADCPRE_Pos)

/* PLL multiplication factor values */
#define RCC_CFGR_PLLMUL_X2      (0b0000U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X3      (0b0001U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X4      (0b0010U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X5      (0b0011U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X6      (0b0100U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X7      (0b0101U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X8      (0b0110U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X9      (0b0111U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X10     (0b1000U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X11     (0b1001U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X12     (0b1010U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X13     (0b1011U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X14     (0b1100U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X15     (0b1101U << RCC_CFGR_PLLMUL_Pos)
#define RCC_CFGR_PLLMUL_X16     (0b1110U << RCC_CFGR_PLLMUL_Pos)

/*====================*/
/* RCC_CIR Register   */
/*====================*/

/* LSIRDYF: LSI ready interrupt flag */
#define RCC_CIR_LSIRDYF_Pos     0
#define RCC_CIR_LSIRDYF_Msk     (1U << RCC_CIR_LSIRDYF_Pos)

/* LSERDYF: LSE ready interrupt flag */
#define RCC_CIR_LSERDYF_Pos     1
#define RCC_CIR_LSERDYF_Msk     (1U << RCC_CIR_LSERDYF_Pos)

/* HSIRDYF: HSI ready interrupt flag */
#define RCC_CIR_HSIRDYF_Pos     2
#define RCC_CIR_HSIRDYF_Msk     (1U << RCC_CIR_HSIRDYF_Pos)

/* HSERDYF: HSE ready interrupt flag */
#define RCC_CIR_HSERDYF_Pos     3
#define RCC_CIR_HSERDYF_Msk     (1U << RCC_CIR_HSERDYF_Pos)

/* PLLRDYF: PLL ready interrupt flag */
#define RCC_CIR_PLLRDYF_Pos     4
#define RCC_CIR_PLLRDYF_Msk     (1U << RCC_CIR_PLLRDYF_Pos)

/* CSSF: Clock security system interrupt flag */
#define RCC_CIR_CSSF_Pos        7
#define RCC_CIR_CSSF_Msk        (1U << RCC_CIR_CSSF_Pos)

/* LSIRDYIE: LSI ready interrupt enable */
#define RCC_CIR_LSIRDYIE_Pos    8
#define RCC_CIR_LSIRDYIE_Msk    (1U << RCC_CIR_LSIRDYIE_Pos)

/* LSERDYIE: LSE ready interrupt enable */
#define RCC_CIR_LSERDYIE_Pos    9
#define RCC_CIR_LSERDYIE_Msk    (1U << RCC_CIR_LSERDYIE_Pos)

/* HSIRDYIE: HSI ready interrupt enable */
#define RCC_CIR_HSIRDYIE_Pos    10
#define RCC_CIR_HSIRDYIE_Msk    (1U << RCC_CIR_HSIRDYIE_Pos)

/* HSERDYIE: HSE ready interrupt enable */
#define RCC_CIR_HSERDYIE_Pos    11
#define RCC_CIR_HSERDYIE_Msk    (1U << RCC_CIR_HSERDYIE_Pos)

/* PLLRDYIE: PLL ready interrupt enable */
#define RCC_CIR_PLLRDYIE_Pos    12
#define RCC_CIR_PLLRDYIE_Msk    (1U << RCC_CIR_PLLRDYIE_Pos)

/* LSIRDYC: LSI ready interrupt clear */
#define RCC_CIR_LSIRDYC_Pos     16
#define RCC_CIR_LSIRDYC_Msk     (1U << RCC_CIR_LSIRDYC_Pos)

/* LSERDYC: LSE ready interrupt clear */
#define RCC_CIR_LSERDYC_Pos     17
#define RCC_CIR_LSERDYC_Msk     (1U << RCC_CIR_LSERDYC_Pos)

/* HSIRDYC: HSI ready interrupt clear */
#define RCC_CIR_HSIRDYC_Pos     18
#define RCC_CIR_HSIRDYC_Msk     (1U << RCC_CIR_HSIRDYC_Pos)

/* HSERDYC: HSE ready interrupt clear */
#define RCC_CIR_HSERDYC_Pos     19
#define RCC_CIR_HSERDYC_Msk     (1U << RCC_CIR_HSERDYC_Pos)

/* PLLRDYC: PLL ready interrupt clear */
#define RCC_CIR_PLLRDYC_Pos     20
#define RCC_CIR_PLLRDYC_Msk     (1U << RCC_CIR_PLLRDYC_Pos)

/* CSSC: Clock security system interrupt clear */
#define RCC_CIR_CSSC_Pos        23
#define RCC_CIR_CSSC_Msk        (1U << RCC_CIR_CSSC_Pos)


/*====================*/
/* RCC_APB2RSTR Register */
/*====================*/

/* AFIORST: Alternate function I/O reset */
#define RCC_APB2RSTR_AFIORST_Pos    0
#define RCC_APB2RSTR_AFIORST_Msk    (1U << RCC_APB2RSTR_AFIORST_Pos)

/* IOPARST: I/O port A reset */
#define RCC_APB2RSTR_IOPARST_Pos    2
#define RCC_APB2RSTR_IOPARST_Msk    (1U << RCC_APB2RSTR_IOPARST_Pos)

/* IOPBRST: I/O port B reset */
#define RCC_APB2RSTR_IOPBRST_Pos    3
#define RCC_APB2RSTR_IOPBRST_Msk    (1U << RCC_APB2RSTR_IOPBRST_Pos)

/* IOPCRST: I/O port C reset */
#define RCC_APB2RSTR_IOPCRST_Pos    4
#define RCC_APB2RSTR_IOPCRST_Msk    (1U << RCC_APB2RSTR_IOPCRST_Pos)

/* IOPDRST: I/O port D reset */
#define RCC_APB2RSTR_IOPDRST_Pos    5
#define RCC_APB2RSTR_IOPDRST_Msk    (1U << RCC_APB2RSTR_IOPDRST_Pos)

/* IOPERST: I/O port E reset */
#define RCC_APB2RSTR_IOPERST_Pos    6
#define RCC_APB2RSTR_IOPERST_Msk    (1U << RCC_APB2RSTR_IOPERST_Pos)

/* IOPFRST: I/O port F reset */
#define RCC_APB2RSTR_IOPFRST_Pos    7
#define RCC_APB2RSTR_IOPFRST_Msk    (1U << RCC_APB2RSTR_IOPFRST_Pos)

/* IOPGRST: I/O port G reset */
#define RCC_APB2RSTR_IOPGRST_Pos    8
#define RCC_APB2RSTR_IOPGRST_Msk    (1U << RCC_APB2RSTR_IOPGRST_Pos)

/* ADCRST: ADC 1 interface reset */
#define RCC_APB2RSTR_ADCRST_Pos     9
#define RCC_APB2RSTR_ADCRST_Msk     (1U << RCC_APB2RSTR_ADCRST_Pos)

/* TIM1RST: TIM1 timer reset */
#define RCC_APB2RSTR_TIM1RST_Pos    11
#define RCC_APB2RSTR_TIM1RST_Msk    (1U << RCC_APB2RSTR_TIM1RST_Pos)

/* SPI1RST: SPI 1 reset */
#define RCC_APB2RSTR_SPI1RST_Pos    12
#define RCC_APB2RSTR_SPI1RST_Msk    (1U << RCC_APB2RSTR_SPI1RST_Pos)

/* TIM8RST: TIM8 timer reset */
#define RCC_APB2RSTR_TIM8RST_Pos    13
#define RCC_APB2RSTR_TIM8RST_Msk    (1U << RCC_APB2RSTR_TIM8RST_Pos)

/* USART1RST: USART 1 reset */
#define RCC_APB2RSTR_USART1RST_Pos  14
#define RCC_APB2RSTR_USART1RST_Msk  (1U << RCC_APB2RSTR_USART1RST_Pos)

/* ADC2RST: ADC 2 interface reset */
#define RCC_APB2RSTR_ADC2RST_Pos    10
#define RCC_APB2RSTR_ADC2RST_Msk    (1U << RCC_APB2RSTR_ADC2RST_Pos)


/*====================*/
/* RCC_APB1RSTR Register */
/*====================*/

/* TIM2RST: Timer 2 reset */
#define RCC_APB1RSTR_TIM2RST_Pos    0
#define RCC_APB1RSTR_TIM2RST_Msk    (1U << RCC_APB1RSTR_TIM2RST_Pos)

/* TIM3RST: Timer 3 reset */
#define RCC_APB1RSTR_TIM3RST_Pos    1
#define RCC_APB1RSTR_TIM3RST_Msk    (1U << RCC_APB1RSTR_TIM3RST_Pos)

/* TIM4RST: Timer 4 reset */
#define RCC_APB1RSTR_TIM4RST_Pos    2
#define RCC_APB1RSTR_TIM4RST_Msk    (1U << RCC_APB1RSTR_TIM4RST_Pos)

/* TIM5RST: Timer 5 reset */
#define RCC_APB1RSTR_TIM5RST_Pos    3
#define RCC_APB1RSTR_TIM5RST_Msk    (1U << RCC_APB1RSTR_TIM5RST_Pos)

/* TIM6RST: Timer 6 reset */
#define RCC_APB1RSTR_TIM6RST_Pos    4
#define RCC_APB1RSTR_TIM6RST_Msk    (1U << RCC_APB1RSTR_TIM6RST_Pos)

/* TIM7RST: Timer 7 reset */
#define RCC_APB1RSTR_TIM7RST_Pos    5
#define RCC_APB1RSTR_TIM7RST_Msk    (1U << RCC_APB1RSTR_TIM7RST_Pos)

/* TIM12RST: Timer 12 reset */
#define RCC_APB1RSTR_TIM12RST_Pos   6
#define RCC_APB1RSTR_TIM12RST_Msk   (1U << RCC_APB1RSTR_TIM12RST_Pos)

/* TIM13RST: Timer 13 reset */
#define RCC_APB1RSTR_TIM13RST_Pos   7
#define RCC_APB1RSTR_TIM13RST_Msk   (1U << RCC_APB1RSTR_TIM13RST_Pos)

/* TIM14RST: Timer 14 reset */
#define RCC_APB1RSTR_TIM14RST_Pos   8
#define RCC_APB1RSTR_TIM14RST_Msk   (1U << RCC_APB1RSTR_TIM14RST_Pos)

/* WWDGRST: Window watchdog reset */
#define RCC_APB1RSTR_WWDGRST_Pos    11
#define RCC_APB1RSTR_WWDGRST_Msk    (1U << RCC_APB1RSTR_WWDGRST_Pos)

/* SPI2RST: SPI 2 reset */
#define RCC_APB1RSTR_SPI2RST_Pos    14
#define RCC_APB1RSTR_SPI2RST_Msk    (1U << RCC_APB1RSTR_SPI2RST_Pos)

/* SPI3RST: SPI 3 reset */
#define RCC_APB1RSTR_SPI3RST_Pos    15
#define RCC_APB1RSTR_SPI3RST_Msk    (1U << RCC_APB1RSTR_SPI3RST_Pos)

/* USART2RST: USART 2 reset */
#define RCC_APB1RSTR_USART2RST_Pos  17
#define RCC_APB1RSTR_USART2RST_Msk  (1U << RCC_APB1RSTR_USART2RST_Pos)

/* USART3RST: USART 3 reset */
#define RCC_APB1RSTR_USART3RST_Pos  18
#define RCC_APB1RSTR_USART3RST_Msk  (1U << RCC_APB1RSTR_USART3RST_Pos)

/* UART4RST: UART 4 reset */
#define RCC_APB1RSTR_UART4RST_Pos   19
#define RCC_APB1RSTR_UART4RST_Msk   (1U << RCC_APB1RSTR_UART4RST_Pos)

/* UART5RST: UART 5 reset */
#define RCC_APB1RSTR_UART5RST_Pos   20
#define RCC_APB1RSTR_UART5RST_Msk   (1U << RCC_APB1RSTR_UART5RST_Pos)

/* I2C1RST: I2C 1 reset */
#define RCC_APB1RSTR_I2C1RST_Pos    21
#define RCC_APB1RSTR_I2C1RST_Msk    (1U << RCC_APB1RSTR_I2C1RST_Pos)

/* I2C2RST: I2C 2 reset */
#define RCC_APB1RSTR_I2C2RST_Pos    22
#define RCC_APB1RSTR_I2C2RST_Msk    (1U << RCC_APB1RSTR_I2C2RST_Pos)

/* USBRST: USB reset */
#define RCC_APB1RSTR_USBRST_Pos     23
#define RCC_APB1RSTR_USBRST_Msk     (1U << RCC_APB1RSTR_USBRST_Pos)

/* CANRST: CAN reset */
#define RCC_APB1RSTR_CANRST_Pos     25
#define RCC_APB1RSTR_CANRST_Msk     (1U << RCC_APB1RSTR_CANRST_Pos)

/* BKPRST: Backup interface reset */
#define RCC_APB1RSTR_BKPRST_Pos     27
#define RCC_APB1RSTR_BKPRST_Msk     (1U << RCC_APB1RSTR_BKPRST_Pos)

/* PWRRST: Power interface reset */
#define RCC_APB1RSTR_PWRRST_Pos     28
#define RCC_APB1RSTR_PWRRST_Msk     (1U << RCC_APB1RSTR_PWRRST_Pos)

/* DACRST: DAC interface reset */
#define RCC_APB1RSTR_DACRST_Pos     29
#define RCC_APB1RSTR_DACRST_Msk     (1U << RCC_APB1RSTR_DACRST_Pos)


/*====================*/
/* RCC_AHBENR Register */
/*====================*/

/* DMA1EN: DMA1 clock enable */
#define RCC_AHBENR_DMA1EN_Pos       0
#define RCC_AHBENR_DMA1EN_Msk       (1U << RCC_AHBENR_DMA1EN_Pos)

/* DMA2EN: DMA2 clock enable */
#define RCC_AHBENR_DMA2EN_Pos       1
#define RCC_AHBENR_DMA2EN_Msk       (1U << RCC_AHBENR_DMA2EN_Pos)

/* SRAMEN: SRAM interface clock enable */
#define RCC_AHBENR_SRAMEN_Pos       2
#define RCC_AHBENR_SRAMEN_Msk       (1U << RCC_AHBENR_SRAMEN_Pos)

/* FLITFEN: FLITF clock enable */
#define RCC_AHBENR_FLITFEN_Pos      4
#define RCC_AHBENR_FLITFEN_Msk      (1U << RCC_AHBENR_FLITFEN_Pos)

/* CRCEN: CRC clock enable */
#define RCC_AHBENR_CRCEN_Pos        6
#define RCC_AHBENR_CRCEN_Msk        (1U << RCC_AHBENR_CRCEN_Pos)

/* FSMCEN: FSMC clock enable */
#define RCC_AHBENR_FSMCEN_Pos       8
#define RCC_AHBENR_FSMCEN_Msk       (1U << RCC_AHBENR_FSMCEN_Pos)

/* SDIOEN: SDIO clock enable */
#define RCC_AHBENR_SDIOEN_Pos       10
#define RCC_AHBENR_SDIOEN_Msk       (1U << RCC_AHBENR_SDIOEN_Pos)


/*====================*/
/* RCC_APB2ENR Register */
/*====================*/

/* AFIOEN: Alternate function I/O clock enable */
#define RCC_APB2ENR_AFIOEN_Pos      0
#define RCC_APB2ENR_AFIOEN_Msk      (1U << RCC_APB2ENR_AFIOEN_Pos)

/* IOPAEN: I/O port A clock enable */
#define RCC_APB2ENR_IOPAEN_Pos      2
#define RCC_APB2ENR_IOPAEN_Msk      (1U << RCC_APB2ENR_IOPAEN_Pos)

/* IOPBEN: I/O port B clock enable */
#define RCC_APB2ENR_IOPBEN_Pos      3
#define RCC_APB2ENR_IOPBEN_Msk      (1U << RCC_APB2ENR_IOPBEN_Pos)

/* IOPCEN: I/O port C clock enable */
#define RCC_APB2ENR_IOPCEN_Pos      4
#define RCC_APB2ENR_IOPCEN_Msk      (1U << RCC_APB2ENR_IOPCEN_Pos)

/* IOPDEN: I/O port D clock enable */
#define RCC_APB2ENR_IOPDEN_Pos      5
#define RCC_APB2ENR_IOPDEN_Msk      (1U << RCC_APB2ENR_IOPDEN_Pos)

/* IOPEEN: I/O port E clock enable */
#define RCC_APB2ENR_IOPEEN_Pos      6
#define RCC_APB2ENR_IOPEEN_Msk      (1U << RCC_APB2ENR_IOPEEN_Pos)

/* IOPFEN: I/O port F clock enable */
#define RCC_APB2ENR_IOPFEN_Pos      7
#define RCC_APB2ENR_IOPFEN_Msk      (1U << RCC_APB2ENR_IOPFEN_Pos)

/* IOPGEN: I/O port G clock enable */
#define RCC_APB2ENR_IOPGEN_Pos      8
#define RCC_APB2ENR_IOPGEN_Msk      (1U << RCC_APB2ENR_IOPGEN_Pos)

/* ADC1EN: ADC 1 interface clock enable */
#define RCC_APB2ENR_ADC1EN_Pos      9
#define RCC_APB2ENR_ADC1EN_Msk      (1U << RCC_APB2ENR_ADC1EN_Pos)

/* ADC2EN: ADC 2 interface clock enable */
#define RCC_APB2ENR_ADC2EN_Pos      10
#define RCC_APB2ENR_ADC2EN_Msk      (1U << RCC_APB2ENR_ADC2EN_Pos)

/* TIM1EN: TIM1 timer clock enable */
#define RCC_APB2ENR_TIM1EN_Pos      11
#define RCC_APB2ENR_TIM1EN_Msk      (1U << RCC_APB2ENR_TIM1EN_Pos)

/* SPI1EN: SPI 1 clock enable */
#define RCC_APB2ENR_SPI1EN_Pos      12
#define RCC_APB2ENR_SPI1EN_Msk      (1U << RCC_APB2ENR_SPI1EN_Pos)

/* TIM8EN: TIM8 timer clock enable */
#define RCC_APB2ENR_TIM8EN_Pos      13
#define RCC_APB2ENR_TIM8EN_Msk      (1U << RCC_APB2ENR_TIM8EN_Pos)

/* USART1EN: USART 1 clock enable */
#define RCC_APB2ENR_USART1EN_Pos    14
#define RCC_APB2ENR_USART1EN_Msk    (1U << RCC_APB2ENR_USART1EN_Pos)


/*====================*/
/* RCC_APB1ENR Register */
/*====================*/

/* TIM2EN: Timer 2 clock enable */
#define RCC_APB1ENR_TIM2EN_Pos      0
#define RCC_APB1ENR_TIM2EN_Msk      (1U << RCC_APB1ENR_TIM2EN_Pos)

/* TIM3EN: Timer 3 clock enable */
#define RCC_APB1ENR_TIM3EN_Pos      1
#define RCC_APB1ENR_TIM3EN_Msk      (1U << RCC_APB1ENR_TIM3EN_Pos)

/* TIM4EN: Timer 4 clock enable */
#define RCC_APB1ENR_TIM4EN_Pos      2
#define RCC_APB1ENR_TIM4EN_Msk      (1U << RCC_APB1ENR_TIM4EN_Pos)

/* TIM5EN: Timer 5 clock enable */
#define RCC_APB1ENR_TIM5EN_Pos      3
#define RCC_APB1ENR_TIM5EN_Msk      (1U << RCC_APB1ENR_TIM5EN_Pos)

/* TIM6EN: Timer 6 clock enable */
#define RCC_APB1ENR_TIM6EN_Pos      4
#define RCC_APB1ENR_TIM6EN_Msk      (1U << RCC_APB1ENR_TIM6EN_Pos)

/* TIM7EN: Timer 7 clock enable */
#define RCC_APB1ENR_TIM7EN_Pos      5
#define RCC_APB1ENR_TIM7EN_Msk      (1U << RCC_APB1ENR_TIM7EN_Pos)

/* TIM12EN: Timer 12 clock enable */
#define RCC_APB1ENR_TIM12EN_Pos     6
#define RCC_APB1ENR_TIM12EN_Msk     (1U << RCC_APB1ENR_TIM12EN_Pos)

/* TIM13EN: Timer 13 clock enable */
#define RCC_APB1ENR_TIM13EN_Pos     7
#define RCC_APB1ENR_TIM13EN_Msk     (1U << RCC_APB1ENR_TIM13EN_Pos)

/* TIM14EN: Timer 14 clock enable */
#define RCC_APB1ENR_TIM14EN_Pos     8
#define RCC_APB1ENR_TIM14EN_Msk     (1U << RCC_APB1ENR_TIM14EN_Pos)

/* WWDGEN: Window watchdog clock enable */
#define RCC_APB1ENR_WWDGEN_Pos      11
#define RCC_APB1ENR_WWDGEN_Msk      (1U << RCC_APB1ENR_WWDGEN_Pos)

/* SPI2EN: SPI 2 clock enable */
#define RCC_APB1ENR_SPI2EN_Pos      14
#define RCC_APB1ENR_SPI2EN_Msk      (1U << RCC_APB1ENR_SPI2EN_Pos)

/* SPI3EN: SPI 3 clock enable */
#define RCC_APB1ENR_SPI3EN_Pos      15
#define RCC_APB1ENR_SPI3EN_Msk      (1U << RCC_APB1ENR_SPI3EN_Pos)

/* USART2EN: USART 2 clock enable */
#define RCC_APB1ENR_USART2EN_Pos    17
#define RCC_APB1ENR_USART2EN_Msk    (1U << RCC_APB1ENR_USART2EN_Pos)

/* USART3EN: USART 3 clock enable */
#define RCC_APB1ENR_USART3EN_Pos    18
#define RCC_APB1ENR_USART3EN_Msk    (1U << RCC_APB1ENR_USART3EN_Pos)

/* UART4EN: UART 4 clock enable */
#define RCC_APB1ENR_UART4EN_Pos     19
#define RCC_APB1ENR_UART4EN_Msk     (1U << RCC_APB1ENR_UART4EN_Pos)

/* UART5EN: UART 5 clock enable */
#define RCC_APB1ENR_UART5EN_Pos     20
#define RCC_APB1ENR_UART5EN_Msk     (1U << RCC_APB1ENR_UART5EN_Pos)

/* I2C1EN: I2C 1 clock enable */
#define RCC_APB1ENR_I2C1EN_Pos      21
#define RCC_APB1ENR_I2C1EN_Msk      (1U << RCC_APB1ENR_I2C1EN_Pos)

/* I2C2EN: I2C 2 clock enable */
#define RCC_APB1ENR_I2C2EN_Pos      22
#define RCC_APB1ENR_I2C2EN_Msk      (1U << RCC_APB1ENR_I2C2EN_Pos)

/* USBEN: USB clock enable */
#define RCC_APB1ENR_USBEN_Pos       23
#define RCC_APB1ENR_USBEN_Msk       (1U << RCC_APB1ENR_USBEN_Pos)

/* CANEN: CAN clock enable */
#define RCC_APB1ENR_CANEN_Pos       25
#define RCC_APB1ENR_CANEN_Msk       (1U << RCC_APB1ENR_CANEN_Pos)

/* BKPEN: Backup interface clock enable */
#define RCC_APB1ENR_BKPEN_Pos       27
#define RCC_APB1ENR_BKPEN_Msk       (1U << RCC_APB1ENR_BKPEN_Pos)

/* PWREN: Power interface clock enable */
#define RCC_APB1ENR_PWREN_Pos       28
#define RCC_APB1ENR_PWREN_Msk       (1U << RCC_APB1ENR_PWREN_Pos)

/* DACEN: DAC interface clock enable */
#define RCC_APB1ENR_DACEN_Pos       29
#define RCC_APB1ENR_DACEN_Msk       (1U << RCC_APB1ENR_DACEN_Pos)


/*====================*/
/* RCC_BDCR Register  */
/*====================*/

/* LSEON: External low-speed oscillator enable */
#define RCC_BDCR_LSEON_Pos          0
#define RCC_BDCR_LSEON_Msk          (1U << RCC_BDCR_LSEON_Pos)

/* LSERDY: External low-speed oscillator ready */
#define RCC_BDCR_LSERDY_Pos         1
#define RCC_BDCR_LSERDY_Msk         (1U << RCC_BDCR_LSERDY_Pos)

/* LSEBYP: External low-speed oscillator bypass */
#define RCC_BDCR_LSEBYP_Pos         2
#define RCC_BDCR_LSEBYP_Msk         (1U << RCC_BDCR_LSEBYP_Pos)

/* RTCSEL: RTC clock source selection (2 bits) */
#define RCC_BDCR_RTCSEL_Pos         8
#define RCC_BDCR_RTCSEL_Msk         (0x3U << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL_NOCLOCK     (0b00U << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL_LSE         (0b01U << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL_LSI         (0b10U << RCC_BDCR_RTCSEL_Pos)
#define RCC_BDCR_RTCSEL_HSE_DIV32   (0b11U << RCC_BDCR_RTCSEL_Pos)

/* RTCEN: RTC clock enable */
#define RCC_BDCR_RTCEN_Pos          15
#define RCC_BDCR_RTCEN_Msk          (1U << RCC_BDCR_RTCEN_Pos)

/* BDRST: Backup domain software reset */
#define RCC_BDCR_BDRST_Pos          16
#define RCC_BDCR_BDRST_Msk          (1U << RCC_BDCR_BDRST_Pos)


/*====================*/
/* RCC_CSR Register   */
/*====================*/

/* LSION: Internal low-speed oscillator enable */
#define RCC_CSR_LSION_Pos           0
#define RCC_CSR_LSION_Msk           (1U << RCC_CSR_LSION_Pos)

/* LSIRDY: Internal low-speed oscillator ready */
#define RCC_CSR_LSIRDY_Pos          1
#define RCC_CSR_LSIRDY_Msk          (1U << RCC_CSR_LSIRDY_Pos)

/* RMVF: Remove reset flag */
#define RCC_CSR_RMVF_Pos            24
#define RCC_CSR_RMVF_Msk            (1U << RCC_CSR_RMVF_Pos)

/* PINRSTF: PIN reset flag */
#define RCC_CSR_PINRSTF_Pos         26
#define RCC_CSR_PINRSTF_Msk         (1U << RCC_CSR_PINRSTF_Pos)

/* PORRSTF: POR/PDR reset flag */
#define RCC_CSR_PORRSTF_Pos         27
#define RCC_CSR_PORRSTF_Msk         (1U << RCC_CSR_PORRSTF_Pos)

/* SFTRSTF: Software reset flag */
#define RCC_CSR_SFTRSTF_Pos         28
#define RCC_CSR_SFTRSTF_Msk         (1U << RCC_CSR_SFTRSTF_Pos)

/* IWDGRSTF: Independent watchdog reset flag */
#define RCC_CSR_IWDGRSTF_Pos        29
#define RCC_CSR_IWDGRSTF_Msk        (1U << RCC_CSR_IWDGRSTF_Pos)

/* WWDGRSTF: Window watchdog reset flag */
#define RCC_CSR_WWDGRSTF_Pos        30
#define RCC_CSR_WWDGRSTF_Msk        (1U << RCC_CSR_WWDGRSTF_Pos)

/* LPWRRSTF: Low-power reset flag */
#define RCC_CSR_LPWRRSTF_Pos        31
#define RCC_CSR_LPWRRSTF_Msk        (1U << RCC_CSR_LPWRRSTF_Pos)