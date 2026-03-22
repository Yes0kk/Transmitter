#include "core.h"



HAL_status HAL_Init(void)
{
	HAL_status status = HAL_OK;

	// Init CLOCK
    status = CLOCK_init();
	if (status != HAL_OK)
		return status;

	return status;
}