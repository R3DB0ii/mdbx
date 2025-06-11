#ifndef OPTIONS_H
#define OPTIONS_H

#include <math.h>

#define OPT_BANNER_PATH     "src/res/banner"

#define REF_A4_FREQ         440.0
#define REF_C0_FREQ         (REF_A4_FREQ * pow(2.0, -4.75))
#define REF_SOUND_SPEED     343.0                               // m/s 20°C
#define REF_VOLT_DBU        0.775
#define REF_VOLT_DBV        1.0
#define REF_PWR_DBM         0.001                               // 1 mW
#define REF_PRESSURE_SPL    0.00002                             // 20 µPa, soglia uditiva

#endif
