#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "errors.h"

#include "utils.h"


void print_title(int size) {

    /*
     * FUNCTION: print_title
     * =====================
     * Print the mdbx logo in various sizes
     *
     * PARAMETERS:
     * size - 1 or 2, these are the available sizes for the logo
     *
     * RETURNS: void function, but returns printed text on screen
     * */

    printf("\033[2J\033[H"); // Clear screen w ANSI (works on most terminal)

    const char* logo_path_relative = "./resources/logo";
    const char* logo_small_path_relative = "./resources/logo_small";

    FILE *fp = NULL;

    if(size == 1) {
        fp = fopen(logo_path_relative, "r");
        if(fp == NULL) {
            handle_error(ERR_LOGO_NOT_FOUND);
            return;
        }
    } else if(size == 2) {
        fp = fopen(logo_small_path_relative, "r");
        if(fp == NULL) {
            handle_error(ERR_S_LOGO_NOT_FOUND);
            return;
        }
    } else {
        handle_error(WRN_INVALID_LOGO_SIZE);
        fp = fopen(logo_small_path_relative, "r");
        if(fp == NULL) {
            handle_error(ERR_S_LOGO_NOT_FOUND);
        }
    }

    char buffer[1024];
    printf(BLINK DIM BRIGHT_MAGENTA);
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    printf(RESET);

    if (ferror(fp)) {
        handle_error(ERR_LOGO_CORRUPTED);
    }

    fclose(fp);
}

func_ptr func_choose_exec(const char* menuTitle, int count, ...) {

    /*
     * FUNCTION: func_choose_exec
     * ==========================
     * Takes in input an x number of functions and prints a menu from where
     * you can choose one and execute it.
     *
     * PARAMETERS:
     * menuTitle - Name of the menu
     * count - Number of choosable functions
     * ... - Functions to be choosed
     *
     * RETURNS: choosed function
     */

    va_list args;
    va_start(args, count);

    // Allocate array to store function entries
    callable_func** entries = malloc(count * sizeof(callable_func*));
    
    if (!entries) {
        perror("malloc failed");
    }

    // Read all function entries from varargs
    for (int i = 0; i < count; i++) {
        entries[i] = va_arg(args, callable_func*);
    }
    va_end(args);

    int choice = 0;
    int valid_choice = 0;

    do {

        // Display title
        printf("=== %s ===\n\n", menuTitle);

        // Display functions entries
        for (int i = 0; i < count; i++) {
            printf("%d. %s - %s\n", i + 1, entries[i]->name, entries[i]->description);
        }
        printf("%d. Exit\n\n", count + 1);

        // Get user input
        printf("Enter your choice (1-%d): ", count + 1);
        scanf("%d", &choice);

        // Validate choice
        if (choice >= 1 && choice <= count) {
            valid_choice = 1;

            // Print small title header and return selected
            print_title(2);

            return entries[choice - 1]->func;
        }
        else if (choice == count + 1) {
            // Exit option
            valid_choice = 1;
            printf("Exiting menu.\n");
        }
        else {
            printf("Invalid choice. Press Enter to try again...");
            getchar(); // Consume the newline from previous scanf
            getchar(); // Wait for user to press Enter
        }

    } while (choice != count + 1);

    // Clean up
    if (entries) free(entries);
    return NULL;
}
