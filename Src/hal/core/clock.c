#include "../hal/core/clock.h"
#include "core.h"



void CLOCK_init(void)
{
    // Initialize system clock(s)
    
    // HSE enable
    // MCO enable
}

HAL_status CLOCK_check_SYSCLK(void)
{
	HAL_status status = HAL_OK;

	// Current system clock frequency (in Hz)
	uint32_t systemClockFreq = 0;

	// Current system clock source
	uint32_t source = (RCC->CFGR & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos;
	
	switch (source)
	{
		// HSI used as system clock
		case 0:
		{
			// 8 MHZ
			bool HSI = 		(RCC->CR & RCC_CR_HSION_Msk) != 0;
			bool HSIRDY = 	(RCC->CR & RCC_CR_HSIRDY_Msk) != 0;

			systemClockFreq = 8000000; // HSI is always 8 MHz
		}
		// HSE used as system clock
		case 1:
		{
			// 8 MHZ
			bool HSE = 		(RCC->CR & RCC_CR_HSEON_Msk) != 0;
			bool HSERDY = 	(RCC->CR & RCC_CR_HSERDY_Msk) != 0;

			systemClockFreq = 8000000; // HSE is typically 8 MHz (depends on crystal)
		}
		// PLL used as system clock
		case 2:
		{
			// Clock Multiplier (x2-x16)
			bool PLL = 		(RCC->CR & RCC_CR_PLLON_Msk) != 0;
			bool PLLRDY = 	(RCC->CR & RCC_CR_PLLRDY_Msk) != 0;
		}
		// No clock used as system clock
		case 3:
		{
			status = HAL_ERROR; // No clock source selected
			break;
		}
		// Something bad happened :(
		default:
		{
			status = HAL_INVALID_PARAM; // Invalid clock source
			break;
		}
	}

	if (systemClockFreq > 72000000)
		status = HAL_ERROR; // System clock exceeds maximum frequency

	return status;
}

void MCO_enable(void)
{
	RCC->CFGR &= ~(0b111 << 24); // Clear MCO bits

    // Careful, the MCO should NOT exceed 50 MHz. (the maximum IO speed)
    if (CONFIG_USE_PLL)
        RCC->CFGR |= (0b111 << 24); // Set MCO to HSE after PLL (PLL / 2 MHz)
    else if (CONFIG_USE_HSI)
        RCC->CFGR |= (0b101 << 24); // Set MCO to HSI after PLL (HSI MHz)
    else if (CONFIG_USE_HSE)
        RCC->CFGR |= (0b110 << 24); // Set MCO to HSE  (HSE MHz)
    else
        RCC->CFGR |= (0b100 << 24); // Set MCO to not use any clock
}

#pragma region PLL Control
HAL_status PLL_enable(void)
{
	HAL_status status = HAL_OK;

	uint32_t timeout = 1000000; // Arbitrary timeout value to prevent infinite loop

	// First, confirm PLL is off
	if (RCC->CR & (1 << 24)) // Check if PLLON is set
		PLL_disable(); 

    // Enable PLL
	if (CONFIG_PLL_SOURCE_HSE)
		RCC->CFGR |= (1 << 16); // Set PLL source to HSE
	else
		RCC->CFGR &= ~(1 << 16); // Set PLL source to HSI / 2
	
	// Enable PLL
    RCC->CR |= (1 << 24); 
	// Wait for PLL to be ready
	while (!(RCC->CR & (1 << 25)) && timeout--); // Wait for PLLRDY

	if (timeout == 0)
		status = HAL_TIMEOUT; // PLL failed to stabilize within timeout
	
	return status;
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
	while (!(RCC->CR & (1 << 17))); // Wait for HSERDY
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
void TIM_disable(uint8_t timer)
{
    // Disable timer clock
    switch(timer)
    {
        case 1:
            RCC->APB2ENR &= ~(1 << 11); // TIM1EN
            break;
        case 2:
            RCC->APB1ENR &= ~(1 << 0); // TIM2EN
            break;
        case 3:
            RCC->APB1ENR &= ~(1 << 1); // TIM3EN
            break;
        case 4:
            RCC->APB1ENR &= ~(1 << 2); // TIM4EN
            break;
        case 5:
            RCC->APB1ENR &= ~(1 << 3); // TIM5EN
            break;
        case 6:
            RCC->APB1ENR &= ~(1 << 4); // TIM6EN
            break;
        case 7:
            RCC->APB1ENR &= ~(1 << 5); // TIM7EN
            break;
        case 8:
            RCC->APB2ENR &= ~(1 << 13); // TIM8EN
            break;
        case 9:
            RCC->APB2ENR &= ~(1 << 19); // TIM9EN
            break;
        case 10:
            RCC->APB2ENR &= ~(1 << 20); // TIM10EN
            break;
        case 11:
            RCC->APB2ENR &= ~(1 << 21); // TIM11EN
            break;
        case 12:
            RCC->APB1ENR &= ~(1 << 6); // TIM12EN
            break;
        case 13:
            RCC->APB1ENR &= ~(1 << 7); // TIM13EN
            break;
        case 14:
            RCC->APB1ENR &= ~(1 << 8); // TIM14EN
            break;
        default:
            // Invalid timer number, do nothing
            break;
    }
}

#pragma endregion

