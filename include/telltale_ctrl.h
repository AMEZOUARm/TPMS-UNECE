#ifndef TELLTALE_CTRL_H
#define TELLTALE_CTRL_H

#include "common_types.h"

/**
 * @brief Control dashboard LED patterns (OFF, ON, BLINK)
 */
void Telltale_Controller_Run(void);

/**
 * @brief Force full LED test for Startup Bulb-Check
 */
void Telltale_Perform_BulbCheck(void);

#endif // TELLTALE_CTRL_H