
#include <stdio.h>
#include <stdlib.h>
#include "../../src/libs/separate.h"

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Error: Amount of arguments invalid\n");
        return 1;
    }

    char** list_expected;
    list_expected = (char**) malloc(1);
    list_expected[0] = (char*) malloc(1);

    int i = 0;
    int j = 0;
    int z = 0;
    while (argv[2][z] != '\0') {
    
        if (argv[2][z] == ',') {

            i++;
            list_expected[j] = (char*) realloc(list_expected[j], i+1);
            list_expected[j][i] = '\0';
            j++;
            i = 0;
            list_expected = (char**) realloc(list_expected, j+1);
        } else {

            i++;
            list_expected[j] = (char*) realloc(list_expected[j], i+1);
            list_expected[j][i] = argv[2][z];
        }

        z++;

    }

    char** list_strings;

    list_strings = (char**) malloc(2);
    list_strings[0] = (char*) malloc(5);
    list_strings[1] = (char*) malloc(5);

    list_strings[0] = "test";
    list_strings[1] = "test";

    /* separate_text(argv[1], list_strings); */

    i = 0;
    j = 0;
    while (list_strings[j] != NULL) {
    
        if (list_strings[j][i] != list_expected[j][i]) {

            printf("%s != %s\n", list_strings[j], list_expected[j]);
            return 1;

        }

        i++;
        if (list_strings[j][i] == '\0' && list_expected[j][i] == '\0') {

            j++;
            i = 0;
        } else {
            printf("maybe an error\n");
            return 1;
        }


    }
    
    free(list_expected);
    free(list_strings);

    return 0;

}

