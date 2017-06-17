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
    char presence_of_transfers[STR_SIZE];
    int kids;
} People;

#endif