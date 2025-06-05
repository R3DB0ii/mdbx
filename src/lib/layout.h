#ifndef LAYOUT_H
#define LAYOUT_H

#include "utils.h"
#include "tools.h"

// === FUNCTIONS ===
extern MenuNode nodo_dBu_to_dBV;
extern MenuNode nodo_dBV_to_dBu;
extern MenuNode nodo_dBu_to_dBm;
extern MenuNode nodo_dBFS_to_V_RMS;
extern MenuNode nodo_V_RMS_to_dBFS;
extern MenuNode nodo_Pa_to_dBSPL;
extern MenuNode nodo_dBSPL_to_Pa;
extern MenuNode nodo_hz_to_note;
extern MenuNode nodo_exit;

// === MENUS lv.2 ===
extern MenuNode menu_dB_converters;
extern MenuNode menu_waves_converters;

// === MENUS lv.1 ===
extern MenuNode menu_converters;

// === MAIN (lv.0) ==
extern MenuNode main_menu;

// Navigation variables
extern MenuNode *current_menu;
extern int highlight;
extern int ch;

#endif
