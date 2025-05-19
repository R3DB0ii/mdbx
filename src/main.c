#include <stdio.h>
#include <stdlib.h>

#include "lib/utils.h"
#include "lib/converters.h"

int main() {

    func_ptr mainSection = NULL;

    do{
        print_title(1);

        static callable_func converters_func = {
            "Converters",
            "a series of unit converters",
            &converters
        };

        mainSection = func_choose_exec(
            "mDbX main sections, select the desired field...",
            1,
            &converters_func
        );

        if(mainSection) {
            mainSection();
        }

    } while(mainSection);

    return 0;
}
