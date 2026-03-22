#include "../hal/core/clock.h"
#include "clock/rcc.h"
#include "config.h"
#include "core.h"



void CLOCK_init(void)
{
    // Initialize system clock(s)
    
    // HSE enable
    // MCO enable
}

// Makes sure the the HSE is stable and ready to be used as a clock source
HAL_status CLOCK_confirm_HSE(void)
{
	if ((RCC->CR & RCC_CR_HSEON_Msk) == 0)
		return HAL_FALSE;

	uint32_t timeout = CONFIG_CLOCK_TIMEOUT; // Timeout loop
	while (((RCC->CR & RCC_CR_HSERDY_Msk) == 0) && timeout--); // Wait for HSE to stabilize
	if (timeout == 0)
		return HAL_TIMEOUT; // HSE failed to stabilize within timeout
	return HAL_OK;
}

// Makes sure the the HSI is stable and ready to be used as a clock source
HAL_status CLOCK_confirm_HSI(void)
{
	if (((RCC->CR & RCC_CR_HSION_Msk) == 0))
		return HAL_FALSE;

	uint32_t timeout = CONFIG_CLOCK_TIMEOUT; // Timeout loop
	while (((RCC->CR & RCC_CR_HSIRDY_Msk) == 0) && timeout--); // Wait for HSI to stabilize
	if (timeout == 0)
		return HAL_TIMEOUT; // HSI failed to stabilize within timeout
	return HAL_OK;
}

// Makes sure the PLL is stable and ready to be used as a clock source
HAL_status CLOCK_confirm_PLL(void)
{
	if (((RCC->CR & RCC_CR_PLLON_Msk) == 0))
		return HAL_FALSE;

	// 0 = HSI/2, 1 = HSE
	bool PLLSource = 	(RCC->CFGR & RCC_CFGR_PLLSRC_Msk) != 0;
	HAL_status tempStatus = PLLSource ? CLOCK_confirm_HSE() : CLOCK_confirm_HSI();
	if (tempStatus != HAL_OK)
		return tempStatus;

	uint32_t timeout = CONFIG_CLOCK_TIMEOUT; // Timeout loop
	while (((RCC->CR & RCC_CR_PLLRDY_Msk) == 0) && timeout--); // Wait for PLL to stabilize
	if (timeout == 0)
		return HAL_TIMEOUT; // PLL failed to stabilize within timeout
	return HAL_OK;
}

// Confirms the current system clock source and frequency, and checks if it is valid (not exceeding 72 MHz)
HAL_status CLOCK_confirm_SYSCLK(void)
{
	HAL_status status = HAL_OK;

	// Current system clock frequency (in Hz)
	uint32_t systemClockFreq = 0;

	// Current system clock source
	uint8_t source = (RCC->CFGR & RCC_CFGR_SWS_Msk) >> RCC_CFGR_SWS_Pos;
	
	switch (source)
	{
		// HSI used as system clock
		case 0:
		{
			// HSI is always 8 MHz
			systemClockFreq = SETTING_HSI_FREQ; 

			// Confirm HSI is stable and ready to be used as a clock source
			status = CLOCK_confirm_HSI();
			if (status != HAL_OK)
				return status; // Propagate HSI confirmation status

			break;
		}
		// HSE used as system clock
		case 1:
		{
			// HSE frequency is defined in config.h
			systemClockFreq = CONFIG_HSE_FREQ; 

			// Confirm HSE is stable and ready to be used as a clock source
			status = CLOCK_confirm_HSE();
			if (status != HAL_OK)
				return status; // Propagate HSE confirmation status
				
			break;
		}
		// PLL used as system clock
		case 2:
		{
			// 0 for HSI / 2, 1 for HSE
			bool PLLSource = 	(RCC->CFGR & RCC_CFGR_PLLSRC_Msk) != 0;
			
			// PLLMUL is encoded as (mul - 2)
			uint8_t mul = 		((RCC->CFGR & RCC_CFGR_PLLMUL_Msk) >> RCC_CFGR_PLLMUL_Pos) + 2;
			// HSE divider for PLL entry (1 or 2)
			uint8_t HSEDIV = 	((RCC->CFGR & RCC_CFGR_PLLXTPRE_Msk) != 0) ? 2 : 1; 

			// Calculate PLL frequency based on source and multiplier
			systemClockFreq = PLLSource ? ((CONFIG_HSE_FREQ / HSEDIV) * mul) : ((SETTING_HSI_FREQ / 2) * mul); 

			// Confirm PLL is stable and ready to be used as a clock source
			status = CLOCK_confirm_PLL();
			if (status != HAL_OK)
				return status; // Propagate PLL confirmation status
			break;
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

	// Confirm the system clock frequency does not exceed the maximum allowed frequency for the device
	if (systemClockFreq > SETTING_DEVICE_MAX_SYSCLK_FREQ)
		status = HAL_ERROR; // System clock exceeds maximum frequency

	return status;
}

// Returns the speed of the PLL output clock (in Hz) based on the current PLL registers
uint32_t CLOCK_get_PLL_freq(void)
{
	// 0 for HSI / 2, 1 for HSE
	bool source = 		(RCC->CFGR & RCC_CFGR_PLLSRC_Msk) != 0;
	// PLLMUL is encoded as (mul - 2)
	uint8_t mul = 		((RCC->CFGR & RCC_CFGR_PLLMUL_Msk) >> RCC_CFGR_PLLMUL_Pos) + 2;
	// HSE divider for PLL entry (1 or 2)
	uint8_t HSEDIV = 		((RCC->CFGR & RCC_CFGR_PLLXTPRE_Msk) != 0) ? 2 : 1; 

	// Calculate PLL frequency based on source and multiplier
	return source ? ((CONFIG_HSE_FREQ / HSEDIV) * mul) : ((SETTING_HSI_FREQ / 2) * mul); 
}

// Initial startup function for the MCO
HAL_status CLOCK_init_MCO(void)
{
	HAL_status status = HAL_OK;
	// Clear bits just in case
	RCC->CFGR &= ~(RCC_CFGR_MCO_Msk);

    switch (CONFIG_MCO_USE_CLOCK)
	{
		// Fastest case (PLL) -> could be over 72 MHz, we use a seperate MCO clock if it is
		case 0b100:
		{
			// Here the speed is PLL
			uint32_t PLLfreq = CLOCK_get_PLL_freq();
			if (PLLfreq > SETTING_DEVICE_MAX_MCO_FREQ)
			{
				status = HAL_PARTIAL_OK;
				// Fallthrough
			}
			else
			{
				// Set the MCO Clock to config
				RCC->CFGR |= (0b100 << RCC_CFGR_MCO_Pos);
				break;
			}
			// Continue to get a working clock
		}
		// Second fastest case (PLL/2) -> could be over 72MHz, we use a seperate MCO clock if it is
		case 0b111:
		{
			// Here the speed is PLL/2
			uint32_t PLLfreq = CLOCK_get_PLL_freq() / 2;
			if (PLLfreq > SETTING_DEVICE_MAX_MCO_FREQ)
			{
				status = HAL_PARTIAL_OK;
				// Fallthrough
			}
			else
			{
				// Set the MCO Clock to config
				RCC->CFGR |= (0b111 << RCC_CFGR_MCO_Pos);
				break;
			}
		}
		// Third fastest case (HSE) -> could be over 72MHz, we use a seperate MCO clock if it is
		case 0b110:
		{
			// Here the speed is HSE
			uint32_t HSEfreq = CONFIG_HSE_FREQ;
			if (HSEfreq > SETTING_DEVICE_MAX_MCO_FREQ)
			{
				status = HAL_PARTIAL_OK;
				// Fallthrough
			}
			else
			{
				// Set the MCO Clock to config
				RCC->CFGR |= (0b110 << RCC_CFGR_MCO_Pos);
				break;
			}
		}
		// Last and final case before an error is thrown
		case 0b101:
		{
			// Here the speed is HSI
			uint32_t HSIfreq = SETTING_HSI_FREQ;
			if (HSIfreq > SETTING_DEVICE_MAX_MCO_FREQ)
			{
				// We return error because this is the last case scenario.
				status = HAL_ERROR;
				// Fallthrough
			}
			else
			{
				// Set the MCO Clock to config
				RCC->CFGR |= (0b101 << RCC_CFGR_MCO_Pos);
				break;
			}
		}
		// Either no clock is selected, or none of the other clocks were in the acceptable speed range
		default:
		{
			return status;
		}
	}
	return status;
}

// TODO: Rework the functions below


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

