# TPMS — Tire Pressure Monitoring System
**Version 1.0.0** | Simulation PC | Langage C | UNECE R64

## Scénarios simulés
| ID | Scénario       | Effet                          |
|----|----------------|-------------------------------|
| 0  | Normal         | Tout nominal                  |
| 1  | Slow Leak      | -0.05 bar/tick (~tick 14)     |
| 2  | Rapid Leak     | -0.30 bar/tick (~tick 3)      |
| 3  | Overheat       | +3°C/tick (~tick 9)           |
| 4  | Sensor Fault   | Capteur hors plage [0.5;5.0]  |

## Compilation
```bash
gcc -Wall -Wextra -I include src/main.c src/modules/*.c src/scheduler/main_scheduler.c -o tpms_sim.exe
```

## Lancement
```bash
.\tpms_sim.exe
```