#ifndef _people_h_
#define _people_h_

#define STR_SIZE 24

typedef struct {
    char surname[STR_SIZE];
    char initials[STR_SIZE];
    int weight;
    int quantity;
    char destination[STR_SIZE];
    char departure_time[STR_SIZE];
    char presence_of_transplants[STR_SIZE];
    int kids;
} people;

int  people_read_txt(people *s, FILE *in);
void people_write_bin(people *s, FILE *out);
void people_print(people *s);
void people_write_txt(people *s, FILE *file);

#endif