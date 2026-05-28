#include "sensor_mgr.h"
#include <string.h>

static TelemetryData_t clean_cache[4];
static RawData_t raw_buffer[4];

void Sensor_Manager_Init(void) {
    memset(clean_cache, 0, sizeof(clean_cache));
    memset(raw_buffer, 0, sizeof(raw_buffer));
}

void Sensor_Manager_Ingest(uint8_t wheel_id, RawData_t raw) {
    if (wheel_id < 4) {
        raw_buffer[wheel_id] = raw;
    }
}

void Sensor_Manager_Run(void) {
    for (uint8_t i = 0; i < 4; i++) {
        // Validation Logic (Filtering)
        if (raw_buffer[i].raw_pressure < 0.5f || raw_buffer[i].raw_pressure > 5.0f) {
            clean_cache[i].fault_code = 2; // Sensor Fault
        } else {
            clean_cache[i].pressure = raw_buffer[i].raw_pressure;
            clean_cache[i].temperature = raw_buffer[i].raw_temperature;
            clean_cache[i].fault_code = 0; // OK
        }
    }
}

TelemetryData_t Sensor_Manager_GetCleanData(uint8_t wheel_id) {
    return (wheel_id < 4) ? clean_cache[wheel_id] : (TelemetryData_t){0};
}