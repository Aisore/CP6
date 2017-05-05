#include <stdio.h>
#include <stdlib.h>

#include "people.h"
#include "io.h"
#include "print.h"

int group_num_of_b(int *quantity, int index, People *people)
{
    for (int i = 0; i < index; i++) {
        if (!strcmp(people[i].quantity, quantity)) {
            return i;
        }
    }
    return index;
}

void info(char *file, char *surname, char *initials)
{
    FILE *in = fopen(file, "r");
        if (!in) {
            printf("Error: can't open file\n");
            exit(1);
        }
    People people;
    while (people_read_txt(&people, in)) {
        if (!strcmp(people.surname, surname)) {
            printf("Name: %s %s\n Weight: %d\n Quantity: %d\n Destination: %s\n Depurture time: %s\n Presence of transplants: %s\n Kids: %d\n", people.surname, people.initials, people.weight, people.quantity, people.destination, people.depurture_time, people.presence_of_transplants, people.kids);
        }
    }
    fclose(in);
}

