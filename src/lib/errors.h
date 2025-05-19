#ifndef ERRORS_H
#define ERRORS_H

void handle_error(int errCode);

#define ERR_NONE                    0
#define ERR_S_LOGO_NOT_FOUND        1
#define ERR_LOGO_NOT_FOUND          2
#define WRN_INVALID_LOGO_SIZE       3
#define ERR_LOGO_CORRUPTED          4

/*
 * LIST OF ALL AVAILABLE ERROR CODES
 * =================================
 * ERR_NONE                     -> No errors
 * ERR_S_LOGO_NOT_FOUND         -> The small version of the logo is not found
 * ERR_LOGO_NOT_FOUND           -> The logo is not found
 * WRN_INVALID_LOGO_SIZE        -> Invalid argument in 'void print_title(int size)' function
 * ERR_LOGO_CORRUPTED           -> Logo file is unreadable for an unknown reason
 * */

/*
 * COLORS
 * ==== TYPE =========== CODE ==== */

#define RESET           "\x1b[0m"

#define BLACK           "\x1b[30m"
#define RED             "\x1b[31m"
#define GREEN           "\x1b[32m"
#define YELLOW          "\x1b[33m"
#define BLUE            "\x1b[34m"
#define MAGENTA         "\x1b[35m"
#define CYAN            "\x1b[36m"
#define WHITE           "\x1b[37m"

#define BRIGHT_BLACK    "\x1b[90m"
#define BRIGHT_RED      "\x1b[91m"
#define BRIGHT_GREEN    "\x1b[92m"
#define BRIGHT_YELLOW   "\x1b[93m"
#define BRIGHT_BLUE     "\x1b[94m"
#define BRIGHT_MAGENTA  "\x1b[95m"
#define BRIGHT_CYAN     "\x1b[96m"
#define BRIGHT_WHITE    "\x1b[97m"

#define BG_BLACK        "\x1b[40m"
#define BG_RED          "\x1b[41m"
#define BG_GREEN        "\x1b[42m"
#define BG_YELLOW       "\x1b[43m"
#define BG_BLUE         "\x1b[44m"
#define BG_MAGENTA      "\x1b[45m"
#define BG_CYAN         "\x1b[46m"
#define BG_WHITE        "\x1b[47m"

#define BOLD            "\x1b[1m"
#define DIM             "\x1b[2m"
#define UNDERLINE       "\x1b[4m"
#define BLINK           "\x1b[5m"
#define REVERSE         "\x1b[7m"
#define HIDDEN          "\x1b[8m"

#endif
