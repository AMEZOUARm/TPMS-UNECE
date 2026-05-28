#ifndef PRESSURE_ANZ_H
#define PRESSURE_ANZ_H

#include "common_types.h"

#define PRESSURE_THRESHOLD_BAR   1.8f
#define TEMP_THRESHOLD_CELSIUS   70.0f

void    Pressure_Analyzer_Run(void);
void    Pressure_Analyzer_Reset(void);
uint8_t Pressure_Analyzer_HasAlert(void);

#endif