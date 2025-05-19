#include <stdio.h>
#include <math.h>
#include <string.h>

#include "utils.h"
#include "converters.h"


#define REF_VOLT_DBU        0.775
#define REF_VOLT_DBV        1.0
#define REF_PWR_DBM         0.001 // 1 mW
#define REF_PRESSURE_SPL    0.00002 // 20 µPa, soglia uditiva


void decibel_converter(void) {

    int scelta;
    double input, output;

    while(1) {

        printf("\n===== dB CONVERTER =====\n");
        printf("1. dBu → dBV\n");
        printf("2. dBV → dBu\n");
        printf("3. dBu → dBm (600Ω)\n");
        printf("4. dBFS → Volt (rms, ref peak = 1.0)\n");
        printf("5. Volt → dBFS (rms, ref peak = 1.0)\n");
        printf("6. Pa → dBSPL\n");
        printf("7. dBSPL → Pa\n");
        printf("0. Esci\n");
        printf("Scelta: ");

        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Inserisci valore in dBu: ");
                scanf("%lf", &input);
                output = input + 20 * log10(REF_VOLT_DBU / REF_VOLT_DBV);
                printf("Risultato: %.2f dBV\n", output);
                break;
            case 2:
                printf("Inserisci valore in dBV: ");
                scanf("%lf", &input);
                output = input + 20 * log10(REF_VOLT_DBV / REF_VOLT_DBU);
                printf("Risultato: %.2f dBu\n", output);
                break;
            case 3:
                printf("Inserisci valore in dBu: ");
                scanf("%lf", &input);
                double voltage = REF_VOLT_DBU * pow(10, input / 20.0);
                double power = (voltage * voltage) / 600.0; // P = V²/R
                output = 10 * log10(power / REF_PWR_DBM);
                printf("Risultato: %.2f dBm\n", output);
                break;
            case 4:
                printf("Inserisci valore in dBFS: ");
                scanf("%lf", &input);
                output = pow(10, input / 20.0);
                printf("Risultato: %.6f V RMS (su ref=1.0)\n", output);
                break;
            case 5:
                printf("Inserisci valore in Volt RMS: ");
                scanf("%lf", &input);
                output = 20 * log10(input);
                printf("Risultato: %.2f dBFS (su ref=1.0)\n", output);
                break;
            case 6:
                printf("Inserisci pressione acustica in Pascal: ");
                scanf("%lf", &input);
                output = 20 * log10(input / REF_PRESSURE_SPL);
                printf("Risultato: %.2f dBSPL\n", output);
                break;
            case 7:
                printf("Inserisci valore in dBSPL: ");
                scanf("%lf", &input);
                output = REF_PRESSURE_SPL * pow(10, input / 20.0);
                printf("Risultato: %.6f Pa\n", output);
                break;
            case 0:
                printf("Uscita dal programma.\n");
                return;
            default:
                printf("Scelta non valida.\n");
        }

    }
}


void converters(void){
    print_title(2);

    static callable_func decibel_converter_func = {
        "Decibel converter",
        "convert between different dB scales",
        &decibel_converter
    };

    func_ptr tool = func_choose_exec(
        "mDbX main sections, select the desired field...",
        1,
        &decibel_converter_func
    );

    if(tool) {
        tool();
    }
}
