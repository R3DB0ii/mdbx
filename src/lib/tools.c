#include "tools.h"

char input[128];
char aux1[128];
char aux2[128];

double nbuff;
double nbuff_aux;

void dBu_to_dBV(void) {
    clear();
    printw("dBu: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    clear();
    printw("%s dBu = %.2f dBV\n\n", input, nbuff + 20 * log10(REF_VOLT_DBU / REF_VOLT_DBV));
    printw("Premi un tasto per continuare...\n");
    getch();
}

void dBV_to_dBu(void) {
    clear();
    printw("dBV: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    clear();
    printw("%s dBV = %.2f dBu\n\n", input, nbuff + 20 * log10(REF_VOLT_DBV / REF_VOLT_DBU));
    printw("Premi un tasto per continuare...\n");
    getch();
}

void dBu_to_dBm(void) {
    clear();
    printw("dBu: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    printw("\nOhm: ");
    refresh();
    getnstr(aux1, 127);
    nbuff_aux = strtod(aux1, NULL);
    clear();
    printw("%s dBu (%s Ohm) = %.2f dBm\n\n", input, aux1, 10 * log10((pow((REF_VOLT_DBU * pow(10, nbuff / 20.0)), 2) / nbuff_aux) / REF_PWR_DBM));
    printw("Premi un tasto per continuare...\n");
    getch();
}

void dBFS_to_V_RMS(void) {
    clear();
    printw("dBFS: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    clear();
    printw("%s dBFS = %.2f V RMS\n\n", input, pow(10, nbuff / 20.0));
    printw("Premi un tasto per continuare...\n");
    getch();
}

void V_RMS_to_dBFS(void) {
    clear();
    printw("V RMS: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    clear();
    printw("%s V RMS = %.2f dBFS\n\n", input, 20 * log10(nbuff));
    printw("Premi un tasto per continuare...\n");
    getch();
}

void Pa_to_dBSPL(void) {
    clear();
    printw("Pa: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    clear();
    printw("%s Pa = %.2f dBSPL\n\n", input, 20 * log10(nbuff / REF_PRESSURE_SPL));
    printw("Premi un tasto per continuare...\n");
    getch();
}

void dBSPL_to_Pa(void) {
    clear();
    printw("dBSPL: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    clear();
    printw("%s dBSPL = %.2f Pa\n\n", input, REF_PRESSURE_SPL * pow(10, nbuff / 20.0));
    printw("Premi un tasto per continuare...\n");
    getch();
}

void hz_to_note(void) {
    clear();
    printw("Hz: ");
    refresh();
    getnstr(input, 127);
    nbuff = strtod(input, NULL);
    clear();
    double n = 12.0 * log2(nbuff / REF_C0_FREQ);
    int noteIndex = (int)round(n);
    double nearestFreq = REF_C0_FREQ * pow(2.0, noteIndex / 12.0);

    int noteInOctave = noteIndex % 12;
    if (noteInOctave < 0) noteInOctave += 12;
    static const char *noteNames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    printw("%s Hz = %s%d +%.1f cents\n", input, noteNames[noteInOctave], noteIndex / 12, 1200.0 * log2(nbuff / nearestFreq));
    printw("Premi un tasto per continuare...\n");
    getch();
}
