#include "state_machine.h"
#include "pressure_anz.h"
#include <stdio.h>

static SystemState_t current_state = SYSTEM_INIT;

void State_Machine_Run(void)
{
    switch (current_state)
    {
        case SYSTEM_INIT:
            printf("[State Machine] INIT -- VEILLE\n");
            current_state = SYSTEM_STANDBY;
            break;

        case SYSTEM_STANDBY:
            printf("[State Machine] VEILLE -- MARCHE\n");
            current_state = SYSTEM_RUNNING;
            break;

        case SYSTEM_RUNNING:
            if (Pressure_Analyzer_HasAlert())
            {
                printf("[State Machine] MARCHE -- ALERTE\n");
                current_state = SYSTEM_ALERT;
            }
            else
            {
                printf("[State Machine] MARCHE - tout nominal\n");
            }
            break;

        case SYSTEM_ALERT:
            if (!Pressure_Analyzer_HasAlert())
            {
                printf("[State Machine] ALERTE -- MARCHE (panne resolue)\n");
                current_state = SYSTEM_RUNNING;
            }
            else
            {
                printf("[State Machine] ALERTE - panne active\n");
            }
            break;

        default:
            break;
    }
}

SystemState_t State_Machine_GetState(void)
{
    return current_state;
}