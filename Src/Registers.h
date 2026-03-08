
#pragma region APB1_Peripherals
/*
    APB1 Peripherals
*/
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
#pragma endregion

#pragma region APB2_Peripherals
/*
    APB2 Peripherals
*/
    /* Watchdog */
    #define IWDG_BASE       (APB2_BASE + 0x00003000UL)
    #define WWDG_BASE       (APB2_BASE + 0x00002C00UL)
    /* RTC */
    #define RTC_BASE        (APB2_BASE + 0x00002800UL)
    /* SPI */
    #define SPI3_BASE       (APB2_BASE + 0x00003C00UL)
    #define SPI2_BASE       (APB2_BASE + 0x00003800UL)
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
#pragma endregion

