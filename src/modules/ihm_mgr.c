#include <stdio.h>
#include "ihm_mgr.h"

Scenario_t IHM_SelectScenario(void) {
    int choice;
    printf("\n--- TPMS Simulation Menu ---\n");
    printf("0: Normal\n1: Slow Leak\n2: Rapid Leak\n3: Overheat\n4: Sensor Fault\n");
    printf("Choose a scenario: ");
    scanf("%d", &choice);
    return (Scenario_t)choice;
}