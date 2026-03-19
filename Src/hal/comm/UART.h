#pragma once

#include "../device/base_addresses.h"


/* USART */
#define USART1_BASE     (APB2_BASE + 0x00003800UL)
#define USART2_BASE     (APB1_BASE + 0x00004400UL)
#define USART3_BASE     (APB1_BASE + 0x00004800UL)
#define UART4_BASE      (APB1_BASE + 0x00004C00UL)
#define UART5_BASE      (APB1_BASE + 0x00005000UL)


/*====================*/
// Struct Definition  //
/*====================*/

/* UNIVERSAL SYNCHRONOUS/ASYNCHRONOUS RECIEVER TRANSMITTER */
typedef struct UART_TypeDef
{
	volatile uint32_t SR;		// 0x00
	volatile uint32_t DR;		// 0x04
	volatile uint32_t BRR;		// 0x08
	volatile uint32_t CR1;		// 0x0C
	volatile uint32_t CR2;		// 0x10
	volatile uint32_t CR3;		// 0x14
	volatile uint32_t GTPR;		// 0x18
} UART_TypeDef;

// USART
#define USART1 ((UART_TypeDef *) USART1_BASE)
#define USART2 ((UART_TypeDef *) USART2_BASE)
#define USART3 ((UART_TypeDef *) USART3_BASE)
#define UART4  ((UART_TypeDef *) UART4_BASE)
#define UART5  ((UART_TypeDef *) UART5_BASE)
