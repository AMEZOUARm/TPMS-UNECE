#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <stdint.h>

/**
 * @brief Global system operational states
 */
typedef enum {
    SYSTEM_INIT,
    SYSTEM_STANDBY,
    SYSTEM_RUNNING,
    SYSTEM_ALERT
} SystemState_t;

/**
 * @brief Simulation scenarios
 */
typedef enum {
    SCENARIO_NORMAL,
    SCENARIO_SLOW_LEAK,
    SCENARIO_RAPID_LEAK,
    SCENARIO_OVERHEAT,
    SCENARIO_SENSOR_FAULT
} Scenario_t;

/**
 * @brief Raw data structure (Input from Simulator)
 */
typedef struct {
    float raw_pressure;
    float raw_temperature;
} RawData_t;

/**
 * @brief Normalized telemetry data structure (Internal system data)
 */
typedef struct {
    uint8_t wheel_id;
    float pressure;
    float temperature;
    uint8_t fault_code; // 0: OK, 1: Low Pressure, 2: Sensor Fault
} TelemetryData_t;

#endif // COMMON_TYPES_H