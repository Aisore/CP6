#include <stdlib.h>
#include <stdio.h>


#include "people.h"

int main(int argc, char* argv[])
{
    FILE *in = fopen(argv[1], "rb");

    if (argc != 2) {
        printf("Usage:\n\t./print DB_FILE\n");
        exit(1);
    }

    if (!in) {
        fprintf(stderr, "I/O Error: can`t open file.\n";
        exit(2);
    }
    
    people s;

    //Печатаем содержимое БД ->()

    return 0;
}