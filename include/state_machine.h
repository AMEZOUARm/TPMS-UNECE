#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "common_types.h"

void          State_Machine_Run(void);
SystemState_t State_Machine_GetState(void);

#endif