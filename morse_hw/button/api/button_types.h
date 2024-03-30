/******************************************************************************
 *brief: Button driver types header file
 *author: cF-embedded.pl
 ******************************************************************************/

#ifndef __BUTTON_TYPES_H
#define __BUTTON_TYPES_H

#include "stdint.h"
#include <stdbool.h>

typedef uint32_t system_time_t;

typedef enum
{
    BUTTON_STATUS_OK,
    BUTTON_STATUS_ERROR
} button_status_e_t;

typedef enum
{
    BUTTON_STATE_PRESSED,
    BUTTON_STATE_RELEASED
} button_state_e_t;

#endif /* __BUTTON_TYPES_H */