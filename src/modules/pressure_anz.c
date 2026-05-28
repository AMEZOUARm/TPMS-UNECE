#include "pressure_anz.h"
#include "sensor_mgr.h"
#include <stdio.h>

static uint8_t alert_flag = 0;

void Pressure_Analyzer_Run(void)
{
    uint8_t i;
    alert_flag = 0;

    for (i = 0; i < 4; i++)
    {
        TelemetryData_t data = Sensor_Manager_GetCleanData(i);

        if (data.fault_code == 2)
        {
            printf("[Analyzer] Roue %d: PANNE CAPTEUR DETECTEE\n", i);
            alert_flag = 1;
            continue;
        }

        if (data.pressure < PRESSURE_THRESHOLD_BAR)
        {
            printf("[Analyzer] Roue %d: ALERTE! Pression basse (%.2f bar)\n", i, data.pressure);
            alert_flag = 1;
        }

        if (data.temperature > TEMP_THRESHOLD_CELSIUS)
        {
            printf("[Analyzer] Roue %d: AVERTISSEMENT! Surchauffe (%.2f C)\n", i, data.temperature);
            alert_flag = 1;
        }
    }
}

void Pressure_Analyzer_Reset(void)
{
    alert_flag = 0;
}

uint8_t Pressure_Analyzer_HasAlert(void)
{
    return alert_flag;
}