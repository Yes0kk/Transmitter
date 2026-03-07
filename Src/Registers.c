#define REG32(loc) (*(volatile uint32_t *)(loc))

/* Peripheral */
#define PERIPH_BASE     (0x40000000UL)

/* Buses */
#define AHB_BASE       (PERIPH_BASE + 0x00018000UL)
#define APB2_BASE      (PERIPH_BASE + 0x00010000UL)
#define APB1_BASE      (PERIPH_BASE + 0x00000000UL)

/* 
    AHB Peripherals 
*/
    /* Reset and Clock Control RCC */
    #define RCC_BASE        (AHB_BASE + 0x0000A000UL)

/*
    APB1 Peripherals
*/
    /* Timers */
    #define TIM11_BASE      (APB1_BASE + 0x00005400UL)
    #define TIM10_BASE      (APB1_BASE + 0x00005000UL)
    #define TIM9_BASE       (APB1_BASE + 0x00004C00UL)
    #define TIM8_BASE       (APB1_BASE + 0x00003400UL)
    #define TIM1_BASE       (APB1_BASE + 0x00002C00UL)
    /* GPIO Ports */
    #define GPIOG_BASE      (APB1_BASE + 0x00002000UL)
    #define GPIOF_BASE      (APB1_BASE + 0x00001C00UL)
    #define GPIOE_BASE      (APB1_BASE + 0x00001800UL)
    #define GPIOD_BASE      (APB1_BASE + 0x00001400UL)
    #define GPIOC_BASE      (APB1_BASE + 0x00001000UL)
    #define GPIOB_BASE      (APB1_BASE + 0x00000C00UL)
    #define GPIOA_BASE      (APB1_BASE + 0x00000800UL)
    /* ADC */
    #define ADC3_BASE       (APB1_BASE + 0x00003C00UL)
    #define ADC2_BASE       (APB1_BASE + 0x00002800UL)
    #define ADC1_BASE       (APB1_BASE + 0x00002400UL)
    /* USART */
    #define USART1_BASE     (APB1_BASE + 0x00003800UL)
    /* SPI */
    #define SPI1_BASE       (APB1_BASE + 0x00003000UL)
    /* EXTI */
    #define EXTI_BASE       (APB1_BASE + 0x00000400UL)
    /* AFIO */
    #define AFIO_BASE       (APB1_BASE + 0x00000000UL)

/*
    APB2 Peripherals
*/
    /* Timers */
    #define TIM14_BASE      (APB2_BASE + 0x00002000UL)
    #define TIM13_BASE      (APB2_BASE + 0x00001C00UL)
    #define TIM12_BASE      (APB2_BASE + 0x00001800UL)
    #define TIM7_BASE       (APB2_BASE + 0x00001400UL)
    #define TIM6_BASE       (APB2_BASE + 0x00001000UL)
    #define TIM5_BASE       (APB2_BASE + 0x00000C00UL)
    #define TIM4_BASE       (APB2_BASE + 0x00000800UL)
    #define TIM3_BASE       (APB2_BASE + 0x00000400UL)
    #define TIM2_BASE       (APB2_BASE + 0x00000000UL)
    /* Watchdog */
    #define IWDG_BASE       (APB2_BASE + 0x00003000UL)
    #define WWDG_BASE       (APB2_BASE + 0x00002C00UL)
    /* RTC */
    #define RTC_BASE        (APB2_BASE + 0x00002800UL)
    /* SPI */
    #define SPI3_BASE       (APB2_BASE + 0x00003C00UL)
    #define SPI2_BASE       (APB2_BASE + 0x00003800UL)
    /* USART */
    #define UART5_BASE      (APB2_BASE + 0x00005000UL)
    #define UART4_BASE      (APB2_BASE + 0x00004C00UL)
    #define USART3_BASE     (APB2_BASE + 0x00004800UL)
    #define USART2_BASE     (APB2_BASE + 0x00004400UL)
    /* I2C */
    #define I2C1_BASE       (APB2_BASE + 0x00005400UL)
    #define I2C2_BASE       (APB2_BASE + 0x00005800UL)
    /* USB Device FS Registers */
    #define USB_BASE        (APB2_BASE + 0x00005C00UL)
    /* CAN */
    #define CAN2_BASE       (APB2_BASE + 0x00006800UL)
    #define CAN1_BASE       (APB2_BASE + 0x00006400UL)
    /* Backup Registers */
    #define BKP_BASE        (APB2_BASE + 0x00006C00UL)
    /* Power Control PWR */
    #define PWR_BASE        (APB2_BASE + 0x00007000UL)
    /* Digital to Analog Converter */
    #define DAC_BASE        (APB2_BASE + 0x00007400UL)
    