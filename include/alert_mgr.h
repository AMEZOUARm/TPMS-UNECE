#ifndef ALERT_MGR_H
#define ALERT_MGR_H

#include "common_types.h"

/**
 * @brief Evaluate state machine output to trigger/dismiss alerts
 */
void Alert_Manager_Run(void);

/**
 * @brief Mute active audio/visual alerts upon user request
 */
void Alert_Manager_Mute(void);

#endif // ALERT_MGR_H