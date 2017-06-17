#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "people.h"
#include "io.h"

int main(int argc, char *argv[])
{
    int index_qty = 0;
    char what_do[STR_SIZE];

    if (argc != 2) {
        printf("Usage:\n\t./execute DB_FILE\n");
        exit(0);
    }
    printf("Введите запрос\n");
    while (!feof(stdin)) {
        fscanf(stdin, "%s", what_do);
        if (feof(stdin)) {
            break;
        }
        if (!strcmp(what_do, "result")) {
            FILE *in = fopen(argv[1], "r");
            if (!in) {
                printf("I/O Error: can't open file.\n");
                exit(1);
            }
            int max_num;
            fscanf(stdin, "%d", &max_num);
            if (feof(stdin)) {
                break;
            }
            result_people(in, max_num);
            fclose(in);
        } else if (!strcmp(what_do, "add")) {
            FILE *add_file = fopen(argv[1], "a");
            if (!add_file) {
            printf("I/O Error: can't open file.\n");
                exit(1);
            }
            if (feof(stdin)) {
                fclose(add_file);
                break;
            }
            add_people(add_file);
            fclose(add_file);
        } else if (!strcmp(what_do, "remove")) {
            char surname[STR_SIZE];
            char initials[STR_SIZE];
            fscanf(stdin, "%s", surname);
            if (feof(stdin)) {
                break;
            }
            fscanf(stdin, "%s", initials);
            remove_people(argv[1], surname, initials);
            if (feof(stdin)) {
                break;
            }
        } else if (!strcmp(what_do, "close") || !strcmp(what_do, "exit")) {
            break;
        } else if (!strcmp(what_do, "info")) {
            FILE *in = fopen(argv[1], "r");
            if (!in) {
                printf("I/O Error: can't open file.\n");
                exit(1);
            }
            char surname[STR_SIZE];
            char initials[3];
            scanf("%s", &surname);
            if (feof(stdin)) {
                break;
            }
            scanf("%s", &initials);
            if (feof(stdin)) {
                fclose(in);
                break;
            }
            info_people(in, surname, initials);
            fclose(in);
        } else if (!strcmp(what_do, "help")) {
            printf("\tresult - вывод результата\n");
            printf("\tadd    [фамилия] [инициалы] [вес багажа] [кол-во багажа] [пункт назначения] [время вылета] [пересадки] [кол-во детей] - добавить студента\n");
            printf("\tremove    [фамилия] [инициалы] - удалить человека\n");
            printf("\tinfo    [фамилия] [инициалы] - информация о человеке\n");
            printf("\texit - завершение программы\n");
        } else {
        }
    }
    int pos = 0;

    return 0;
}