
#pragma region APB1_Peripherals
/*
    APB1 Peripherals
*/
#pragma endregion

#pragma region APB2_Peripherals
/*
    APB2 Peripherals
*/
    /* RTC */
    #define RTC_BASE        (APB2_BASE + 0x00002800UL)
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

