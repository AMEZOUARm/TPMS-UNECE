/* ============================================================
 * main_scheduler.c
 * Tire Pressure Monitoring System - Main Scheduler
 *
 * Owns the processing pipeline and tick sequencing.
 * The call order follows a strict data-flow dependency:
 *
 *   Simulator -> SensorMgr -> Analyzer -> StateMachine
 *             -> AlertMgr  -> Telltale
 *
 * Each layer only reads from the layer above it, never below.
 * ============================================================ */

#include "main_scheduler.h"
#include "sensor_sim.h"
#include "sensor_mgr.h"
#include "pressure_anz.h"
#include "state_machine.h"
#include "alert_mgr.h"
#include "telltale_ctrl.h"
#include <stdio.h>

/* Active scenario chosen by the user at startup */
static Scenario_t active_scenario = SCENARIO_NORMAL;

/* ----------------------------------------------------------------
 * Scheduler_Init
 * Initializes all modules in dependency order.
 * Called once at startup before the main loop.
 * ---------------------------------------------------------------- */
void Scheduler_Init(void)
{
    printf("\n========================================\n");
    printf("  TPMS System Initializing...\n");
    printf("========================================\n");

    /* Step 1: clear sensor buffers */
    Sensor_Manager_Init();

    /* Step 2: reset simulator tick counter */
    Sensor_Simulator_Reset();

    /* Step 3: UNECE R64 mandatory bulb-check */
    Telltale_Perform_BulbCheck();

    printf("[Scheduler] All modules initialized.\n\n");
}

/* ----------------------------------------------------------------
 * Scheduler_SetScenario
 * Stores the user-selected scenario and resets simulation state.
 * ---------------------------------------------------------------- */
void Scheduler_SetScenario(Scenario_t scenario)
{
    active_scenario = scenario;
    Sensor_Simulator_Reset();
    Pressure_Analyzer_Reset();
}

/* ----------------------------------------------------------------
 * Scheduler_Tick
 * Executes one full 100 ms processing cycle.
 * Called repeatedly by main().
 * ---------------------------------------------------------------- */
void Scheduler_Tick(void)
{
    uint32_t tick = Sensor_Simulator_GetTick();

    printf("\n--- Tick %02u (scenario=%d) ---\n", tick, (int)active_scenario);

    /* 1. Simulation layer: generate and ingest raw sensor data */
    Sensor_Simulator_Update(active_scenario);

    /* 2. Sensor manager: validate raw data and update clean cache */
    Sensor_Manager_Run();

    /* 3. Pressure analyzer: apply UNECE R64 thresholds */
    Pressure_Analyzer_Run();

    /* 4. State machine: evaluate alerts and drive system state */
    State_Machine_Run();

    /* 5. Alert manager: manage buzzer and lamp based on state */
    Alert_Manager_Run();

    /* 6. Telltale controller: drive dashboard LED pattern */
    Telltale_Controller_Run();
}

/* ----------------------------------------------------------------
 * Scheduler_Run  (blocking loop version â€” not used in main.c)
 * Kept as reference for an RTOS / hardware target where the
 * tick timing is managed by an OS timer or hardware interrupt.
 * ---------------------------------------------------------------- */
void Scheduler_Run(void)
{
    /* On bare-metal this would be: wait for SysTick interrupt */
    while (1)
    {
        Scheduler_Tick();
        /* HAL_Delay(SYSTEM_TICK_MS); */
    }
}
