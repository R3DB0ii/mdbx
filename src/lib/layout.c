#include "layout.h"

MenuNode nodo_exit = {"Esci", NULL, NULL, 0, &main_menu};

// ======== FUNCTIONS ============================================================================

MenuNode nodo_dBu_to_dBV = {"dBu -> dbV", dBu_to_dBV, NULL, 0, &menu_dB_converters};
MenuNode nodo_dBV_to_dBu = {"dBV -> dBu", dBV_to_dBu, NULL, 0, &menu_dB_converters};
MenuNode nodo_dBu_to_dBm = {"dBu -> dBm", dBu_to_dBm, NULL, 0, &menu_dB_converters};
MenuNode nodo_dBFS_to_V_RMS = {"dBFS -> Volt RMS", dBFS_to_V_RMS, NULL, 0, &menu_dB_converters};
MenuNode nodo_V_RMS_to_dBFS = {"Volt RMS -> dBFS", V_RMS_to_dBFS, NULL, 0, &menu_dB_converters};
MenuNode nodo_Pa_to_dBSPL = {"Pa -> dBSPL", Pa_to_dBSPL, NULL, 0, &menu_dB_converters};
MenuNode nodo_dBSPL_to_Pa = {"dBSPL -> Pa", dBSPL_to_Pa, NULL, 0, &menu_dB_converters};

MenuNode nodo_hz_to_note = {"hz -> nota", hz_to_note, NULL, 0, &menu_waves_converters};
MenuNode nodo_note_to_hz = {"nota -> hz", note_to_hz, NULL, 0, &menu_waves_converters};

// ======== MENUS lv.2 ===========================================================================

MenuNode *dB_converters[] = {

    &nodo_dBu_to_dBV,
    &nodo_dBV_to_dBu,
    &nodo_dBu_to_dBm,
    &nodo_dBFS_to_V_RMS,
    &nodo_V_RMS_to_dBFS,
    &nodo_Pa_to_dBSPL,
    &nodo_dBSPL_to_Pa,
};

MenuNode menu_dB_converters = {"dB", NULL, dB_converters, 7, &menu_converters};


MenuNode *waves_converters[] = {

    &nodo_hz_to_note,
    &nodo_note_to_hz,

};

MenuNode menu_waves_converters = {"Onde", NULL, waves_converters, 2, &menu_converters};


// ======== MENUS lv.1 ===========================================================================

MenuNode *converters[] = {

    &menu_dB_converters,
    &menu_waves_converters,
};

MenuNode menu_converters = {"Conversioni", NULL, converters, 2, &main_menu};



// ======== MAIN (lv.0) ==========================================================================

MenuNode *main_children[] = {

    &menu_converters,
    &nodo_exit,
};

MenuNode main_menu = {"Menu Principale", NULL, main_children, 2, NULL};



// ======== SETTING UP... ========================================================================

MenuNode *current_menu = &main_menu;

int highlight = 0;

int ch;
