#include "sensor_sim.h"
#include "sensor_mgr.h"

static uint32_t sim_tick = 0;

void Sensor_Simulator_Update(Scenario_t scenario)
{
    uint8_t i;
    for (i = 0; i < 4; i++)
    {
        RawData_t raw;
        raw.raw_pressure    = 2.5f;
        raw.raw_temperature = 45.0f;

        if (i == 0)
        {
            switch (scenario)
            {
                case SCENARIO_NORMAL:
                    break;
                case SCENARIO_SLOW_LEAK:
                    raw.raw_pressure = 2.5f - ((float)sim_tick * 0.05f);
                    if (raw.raw_pressure < 0.5f) raw.raw_pressure = 0.5f;
                    break;
                case SCENARIO_RAPID_LEAK:
                    raw.raw_pressure = 2.5f - ((float)sim_tick * 0.30f);
                    if (raw.raw_pressure < 0.5f) raw.raw_pressure = 0.5f;
                    break;
                case SCENARIO_OVERHEAT:
                    raw.raw_temperature = 45.0f + ((float)sim_tick * 3.0f);
                    break;
                case SCENARIO_SENSOR_FAULT:
                    raw.raw_pressure = 0.1f;
                    break;
                default:
                    break;
            }
        }
        Sensor_Manager_Ingest(i, raw);
    }
    sim_tick++;
}

void Sensor_Simulator_Reset(void)
{
    sim_tick = 0;
}

uint32_t Sensor_Simulator_GetTick(void)
{
    return sim_tick;
}