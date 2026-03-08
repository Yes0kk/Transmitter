#pragma once

#include <stdint.h>
#include <stdio.h>

// Peripheral Base Address
#define PERIPHERAL_BASE (0x40000000UL)

// Bus Base Addresses
#define AHB_BASE  (PERIPHERAL_BASE + 0x00018000UL)
#define APB2_BASE (PERIPHERAL_BASE + 0x00010000UL)
#define APB1_BASE (PERIPHERAL_BASE + 0x00000000UL)
