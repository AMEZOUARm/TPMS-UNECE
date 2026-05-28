#include "alert_mgr.h"
#include "state_machine.h"
#include <stdio.h>

void Alert_Manager_Run(void)
{
    if (State_Machine_GetState() == SYSTEM_ALERT)
        printf("[Alert Manager] ALERTE - buzzer ON, lampe ON\n");
    else
        printf("[Alert Manager] Aucune alerte active\n");
}

void Alert_Manager_Mute(void) {}