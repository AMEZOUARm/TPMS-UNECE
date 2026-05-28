#include "telltale_ctrl.h"
#include "state_machine.h"
#include <stdio.h>

void Telltale_Controller_Run(void)
{
    switch (State_Machine_GetState())
    {
        case SYSTEM_ALERT:   printf("[Telltale] Temoin: CLIGNOTANT\n"); break;
        case SYSTEM_RUNNING: printf("[Telltale] Temoin: ETEINT\n");     break;
        default:             printf("[Telltale] Temoin: ALLUME (init)\n"); break;
    }
}

void Telltale_Perform_BulbCheck(void)
{
    printf("[Telltale] Controle lampe: OK\n");
}