#include <stdio.h>
#include <stdlib.h>
//#include 
//Найти пассажиров, имеющих более р вещей;
#define SIZE_SUN 30

typedef struct {
    char surname[SIZE_SUN];
    char initials[SIZE_SUN];
    int quantity;
} people;

int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "rb");

    if (argc != 2) { //2?
        printf("Need ()")
        exit(0);
    }
    if (!in) {
        fprintf(stderr, "Can`t open file");
        exit(1);
    }
    int quan_have = argv[2]; 
    while (people_read_bin(&people, in)) {
        people[people_qty++] = (PeopleStatistics) {quan_have, people.surname_init, people.initials};
    }
    fclose(in);
    //Печать массива имен 
    return 0;
}