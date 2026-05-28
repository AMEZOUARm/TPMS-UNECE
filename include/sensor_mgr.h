#ifndef SENSOR_MGR_H
#define SENSOR_MGR_H

#include "common_types.h"

/**
 * @brief Initialize sensor buffers and state
 */
void Sensor_Manager_Init(void);

/**
 * @brief Ingest raw data from the simulator or hardware layer
 * @param wheel_id The ID of the wheel (0-3)
 * @param raw The raw data structure containing unprocessed values
 */
void Sensor_Manager_Ingest(uint8_t wheel_id, RawData_t raw);

/**
 * @brief Periodic task to filter and validate raw data into the cache
 */
void Sensor_Manager_Run(void);

/**
 * @brief Retrieve the latest validated telemetry for a specific wheel
 */
TelemetryData_t Sensor_Manager_GetCleanData(uint8_t wheel_id);

#endif // SENSOR_MGR_H