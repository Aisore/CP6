#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "people.h"


void remove_people(char *file, char *surname, char *initials) //\\ here i am
{
    FILE *in = fopen(file, "r");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    FILE *tmp = fopen("tmp", "w");
    People people;
    while (people_read_bin(&people, in)) {
        if (strcmp(people.surname, surname)) {
            people_write_bin(&people, tmp);
        } else if (strcmp(people.initials, initials)) {
            people_write_bin(&people, tmp);
        }
    }
    fclose(in);
    fclose(tmp);

    in = fopen(file, "w");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    tmp = fopen("tmp", "r");
    while (people_read_bin(&people, tmp)) {
        if (strcmp(people.surname, surname) != 0) {
            people_write_bin(&people, in);
        } else if (strcmp(people.initials, initials) != 0) {
            people_write_bin(&people, in);
        }
    }
    fclose(in);
    fclose(tmp);
    remove("tmp");
}

void result_people(FILE *in, int max_num)
{
    People pe;
    while (people_read_bin(&pe, in)) {
        if (pe.quantity > max_num) {
            printf("\n");
            printf("Имя: %s %s\nВес багажа: %d\nКол-во багажа: %d\nМесто назначения: %s\nВремя отлета: %s\nПересадки: %s\nКол-во детей: %d\n", pe.surname, pe.initials, pe.weight, pe.quantity, pe.destination, pe.departure_time, pe.presence_of_transfers, pe.kids);
            printf("\n");
        }
    }
}

void info_people(FILE *in, char *surname, char *initials)
{
    People pe;
    while (people_read_bin(&pe, in)) {
        if (!strcmp(pe.surname, surname) && !strcmp(pe.initials, initials)) {
            printf("\n");
            printf("Имя: %s %s\nВес багажа: %d\nКол-во багажа: %d\nМесто назначения: %s\nВремя отлета: %s\nПересадки: %s\nКол-во детей: %d\n", pe.surname, pe.initials, pe.weight, pe.quantity, pe.destination, pe.departure_time, pe.presence_of_transfers, pe.kids);
            printf("\n");
        }
    }
}

void add_people(FILE *add_file) ///\\\ here i am
{
    People people;
    memset(&people, 0, sizeof(People));
    fscanf(stdin, "%s", people.surname);
    if (feof(stdin)) {
        return;
    }
    fscanf(stdin, "%s", people.initials);
    if (feof(stdin)) {
        return;
    }
    fscanf(stdin, "%d", &people.weight);
    if (feof(stdin)) {
        return;
    }
    fscanf(stdin, "%d", &people.quantity);
    if (feof(stdin)) {
        return;
    }
    fscanf(stdin, "%s", people.destination);
    if (feof(stdin)) {
        return;
    }
    fscanf(stdin, "%s", people.departure_time);
    if (feof(stdin)) {
        return;
    }    
    fscanf(stdin, "%s", people.presence_of_transfers);
    if (feof(stdin)) {
        return;
    }    
    fscanf(stdin, "%d", &people.kids);
    if (feof(stdin)) {
        return;
    }
    people_write_bin(&people, add_file);
}