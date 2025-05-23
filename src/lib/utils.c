#include "utils.h"

int print_file_header(const char *filename, int max_lines) {
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        mvprintw(0, 0, "Errore: impossibile aprire %s", filename);
        return 1;
    }

    char buffer[512];
    int row = 0;
    while (fgets(buffer, sizeof(buffer), fp) && row < max_lines) {
        mvprintw(row, 0, "%s", buffer);
        row++;
    }

    fclose(fp);
    return row;
}

void draw_menu(MenuNode *menu, int highlight) {
    clear();
    
    int header_lines = print_file_header(OPT_BANNER_PATH, 10);
    mvprintw(header_lines, 0, "=== %s ===", menu->title);

    refresh();

    for (int i = 0; i < menu->child_count; i++) {
        if (i == highlight) attron(A_REVERSE);
        mvprintw(i + 7, 2, "%s", menu->children[i]->title);
        if (i == highlight) attroff(A_REVERSE);
    }
}
