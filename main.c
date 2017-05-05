#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "people.h"
#include "io.h"
#include "print.c"
#include "print.h"


#define STR_SIZE 80

int main(int argc, char *argv[])
{
    char input[STR_SIZE];

    if (argc != 2) {
        printf("```")
        exit(0);
    }

    for(;;) {
        scanf("%s", input);
        if (!strcmp(input, "Add")) {
            FILE *add = fopen(argv[1], "a");
            if (!add) {
                fprintf(stderr, "Error: can`t open file");
                exit(1);
            }
            People people;
            scanf("%s", &people.surname);
            scanf("%s", &people.initials);
            scanf("%d", &people.weight);
            scanf("%d", &people.quantity);
            scanf("%s", &people.destination);
            scanf("%s", &people.departure_time);
            scanf("%s", &people.presence_of_transplants);
            scanf("%d", &people.kids);
            people_write_txt(&people, add_file);
            fclose(add);
        } else if (!strcmp(input, "Remove")) {
            scanf("%s", &surname);
            scanf("%s", &initials);
            remove_p(argv[1], surname, initials);
        } else if (!strcmp(input, "Info")) {
            scanf("%s", &surname);
            scanf("%s", &initials);
            info(argv[1], surname, initials);
        } else if (!strcmp(input, "Exit")) {
            break;
        } else {
            fprintf(stderr, "Error: Invalid request\n");
            exit(2);
        }
    }
    
    return 0;
}