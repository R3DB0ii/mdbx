#ifndef UTILS_H
#define UTILS_H

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../res/options.h"

typedef void (*ActionFunc)();

typedef struct MenuNode {
    char *title;
    ActionFunc action;
    struct MenuNode **children;
    int child_count;
    struct MenuNode *parent;
} MenuNode;

int print_file_header(const char *filename, int max_lines);

void draw_menu(MenuNode *menu, int highlight);

#endif
