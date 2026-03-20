#pragma once

#include "../device/registers.h"

#pragma region Bit Manipulation Macros
#define SET_BIT(REG, BIT)       ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)     ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)      ((REG) & (BIT))

#define WRITE_REG(REG, VAL)     ((REG) = (VAL))
#define READ_REG(REG)           (REG)

#define MODIFY_REG(REG, CLEARMASK, SETMASK) \ ((REG) = (((REG) & ~(CLEARMASK)) | (SETMASK)))
#pragma endregion

	
typedef enum HAL_status
{
	HAL_OK = 0,
	HAL_ERROR,
	HAL_INVALID_PARAM,
	HAL_TIMEOUT,
} HAL_status; 

void HAL_Init(void);


