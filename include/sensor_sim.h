#ifndef SENSOR_SIM_H
#define SENSOR_SIM_H

#include "common_types.h"
#include <stdint.h>

void     Sensor_Simulator_Update(Scenario_t scenario);
void     Sensor_Simulator_Reset(void);
uint32_t Sensor_Simulator_GetTick(void);

#endif