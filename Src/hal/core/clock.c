#include "clock.h"


void CLOCK_init(void)
{
    // Initialize system clock(s)
    
    // HSE enable
    // MCO enable
}


void GenericClockConfig(void)
{
    // Set HSE as system clock, and use PLL as a multiplier

    // The multiplier of our clock (HSE, 8 MHz)
    PLL_enable();
    HSE_enable();
    
    PLL_SetMul(9); // 8 MHz * 9 = 72 MHz system clock

}

void MCO_enable(void)
{
    // Careful, the MCO should NOT exceed 50 MHz. (the maximum IO speed)
    if (CONFIG_USE_PLL)
        RCC->CFGR |= (111 << 24); // Set MCO to HSE after PLL (72 / 2 MHz)
    else if (CONFIG_USE_HSI)
        RCC->CFGR |= (101 << 24); // Set MCO to HSI after PLL (36 MHz)
    else if (CONFIG_USE_HSE)
        RCC->CFGR |= (110 << 24); // Set MCO to HSE  (72 MHz)
    else
        RCC->CFGR |= (100 << 24); // Set MCO to not use any clock
}

#pragma region PLL Control
void PLL_enable(void)
{
    // Enable PLL
    RCC->CR |= (1 << 24); // PLLON
}
void PLL_toggle(void)
{
    // Toggle PLL 
    RCC->CR ^= (1 << 24); // PLLON
}
void PLL_disable(void)
{
    // Disable PLL
    RCC->CR &= ~(1 << 24); // PLLON
}

void PLL_setMul(uint8_t speed)
{
    if (speed < 2)
        speed = 2; // PLL multiplier cannot be less than 2
    else if (speed > 16)
        speed = 16; // PLL multiplier cannot be more than 16

    RCC->CFGR &= ~(0xF << 18); // Clear PLL multiplier bits
    RCC->CFGR |= ((speed - 2) << 18); // Set PLL multiplier (speed - 2)
}


#pragma endregion

#pragma region HSE Control
void HSE_enable(void)
{
    // Enable HSE
    RCC->CR |= (1 << 16); // HSEON
}
void HSE_toggle(void)
{
    // Toggle HSE as the lowest speed
    RCC->CR ^= (1 << 16); // HSEON
}
void HSE_disable(void)
{
    // Disable HSE
    RCC->CR &= ~(1 << 16); // HSEON
}
#pragma endregion


#pragma region System Control

// 0 = HSI, 1 = HSE, 2 = PLL, 3 = None
void SYSTEM_setSystemClock(uint8_t source)
{
    // Set system clock source
    if (source == 0) // HSI
        RCC->CFGR &= ~0b11; // Clear SW bits to select HSI
    else if (source == 1) // HSE
        RCC->CFGR = (RCC->CFGR & ~0b11) | 0b01; // Set SW bits to select HSE
    else if (source == 2) // PLL
        RCC->CFGR = (RCC->CFGR & ~0b11) | 0b10; // Set SW bits to select PLL
    else // None
        RCC->CFGR |= 0b11; // Set SW bits to select no clock
}

#pragma endregion


#pragma region CRC Control
void CRC_enable(void)
{
    // Enable CRC clock
    RCC->AHBENR |= (1 << 6); // CRCEN
}
void CRC_toggle(void)
{
    // Toggle CRC clock
    RCC->AHBENR ^= (1 << 6); // CRCEN
}
void CRC_disable(void)
{
    // Disable CRC clock
    RCC->AHBENR &= ~(1 << 6); // CRCEN
}
#pragma endregion


#pragma region Timer Control

void TIM_enable(uint8_t timer)
{
    // Enable timer clock
    switch(timer)
    {
        case 1:
            RCC->APB2ENR |= (1 << 11); // TIM1EN
            break;
        case 2:
            RCC->APB1ENR |= (1 << 0); // TIM2EN
            break;
        case 3:
            RCC->APB1ENR |= (1 << 1); // TIM3EN
            break;
        case 4:
            RCC->APB1ENR |= (1 << 2); // TIM4EN
            break;
        case 5:
            RCC->APB1ENR |= (1 << 3); // TIM5EN
            break;
        case 6:
            RCC->APB1ENR |= (1 << 4); // TIM6EN
            break;
        case 7:
            RCC->APB1ENR |= (1 << 5); // TIM7EN
            break;
        case 8:
            RCC->APB2ENR |= (1 << 13); // TIM8EN
            break;
        case 9:
            RCC->APB2ENR |= (1 << 19); // TIM9EN
            break;
        case 10:
            RCC->APB2ENR |= (1 << 20); // TIM10EN
            break;
        case 11:
            RCC->APB2ENR |= (1 << 21); // TIM11EN
            break;
        case 12:
            RCC->APB1ENR |= (1 << 6); // TIM12EN
            break;
        case 13:
            RCC->APB1ENR |= (1 << 7); // TIM13EN
            break;
        case 14:
            RCC->APB1ENR |= (1 << 8); // TIM14EN
            break;
        default:
            // Invalid timer number, do nothing or handle error
            break;
    }
}

#pragma endregion

