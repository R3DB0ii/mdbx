#include <stdio.h>
#include <stdlib.h>

#include "errors.h"

void handle_error(int errCode) {
    switch (errCode) {
        case ERR_NONE: break;

        case ERR_S_LOGO_NOT_FOUND: fprintf(stderr, RED DIM "[!] Error while opening the logo_small file, make sure that it is present in resources/ and that is named 'logo_small' without an extension\n" RESET); break;

        case ERR_LOGO_NOT_FOUND: fprintf(stderr, RED DIM "[!] Error while opening the logo file, make sure that it is present in resources/ and that is named 'logo' without an extension\n" RESET); break;

        case WRN_INVALID_LOGO_SIZE: fprintf(stderr, YELLOW DIM "[!] Invalid logo size specified, setting to default=2 (small)...\n" RESET); break;

        case ERR_LOGO_CORRUPTED: fprintf(stderr, RED "[!] Logo file is unreadable or corrupted, skipping...\n" RESET); break;

        default: fprintf(stderr, RED BOLD "[!?] Error unknown\n" RESET);
    }
}
