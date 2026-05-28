#include <stdio.h>
#include "ihm_mgr.h"
#include "main_scheduler.h"

int main(void)
{
    printf("========================================\n");
    printf("  TPMS - Surveillance Pression Pneus\n");
    printf("========================================\n");

    Scheduler_Init();

    Scenario_t scenario = IHM_SelectScenario();
    Scheduler_SetScenario(scenario);

    printf("\n[Main] Demarrage simulation: %d ticks x %d ms\n\n",
           SIMULATION_TICKS, SYSTEM_TICK_MS);

    for (int tick = 0; tick < SIMULATION_TICKS; tick++)
    {
        Scheduler_Tick();
    }

    printf("\n========================================\n");
    printf("  Simulation terminee (%d ticks).\n", SIMULATION_TICKS);
    printf("========================================\n");

    return 0;
}