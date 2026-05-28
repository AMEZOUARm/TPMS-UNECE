#ifndef MAIN_SCHEDULER_H
#define MAIN_SCHEDULER_H

#include "common_types.h"

/** System tick period definition (100 ms in a real embedded target) */
#define SYSTEM_TICK_MS 100

/** Number of ticks to simulate per scenario in the PC simulation */
#define SIMULATION_TICKS 20

/**
 * @brief Initialize all modules in the correct dependency order.
 *        Call once before the simulation loop.
 */
void Scheduler_Init(void);

/**
 * @brief Store the active scenario and reset simulation state.
 * @param scenario Scenario chosen by the user.
 */
void Scheduler_SetScenario(Scenario_t scenario);

/**
 * @brief Execute one full 100 ms processing cycle.
 */
void Scheduler_Tick(void);

/**
 * @brief Blocking main loop — for RTOS / hardware targets.
 *        Not called on PC simulation (main.c drives the loop).
 */
void Scheduler_Run(void);

#endif /* MAIN_SCHEDULER_H */
