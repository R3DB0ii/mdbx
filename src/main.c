/* H_FILES */

#include "lib/layout.h"     // The menu voices and its layouy
#include "lib/tools.h"      // All the functions of the tools
#include "lib/utils.h"      // Golbal type definitions, imports and functions
#include "res/options.h"    // Options file

// === Main ===

int main() {
    initscr();
    echo();
    cbreak();
    keypad(stdscr, TRUE);

    while (1) {
        draw_menu(current_menu, highlight);
        ch = getch();
        switch (ch) {
            case KEY_UP:
                highlight = (highlight - 1 + current_menu->child_count) % current_menu->child_count;
                break;
            case KEY_DOWN:
                highlight = (highlight + 1) % current_menu->child_count;
                break;
            case 10: { // Invio
                MenuNode *selected = current_menu->children[highlight];
                if (selected->action) {
                    selected->action();
                } else if (selected->child_count > 0) {
                    current_menu = selected;
                    highlight = 0;
                } else if (strcmp(selected->title, "Esci") == 0) {
                    endwin();
                    return 0;
                }
                break;
            }
            case KEY_BACKSPACE:
            case 27: // ESC per tornare indietro
                if (current_menu->parent) {
                    current_menu = current_menu->parent;
                    highlight = 0;
                }
                break;
        }
    }

    endwin();
    return 0;
}

