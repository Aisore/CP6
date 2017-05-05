#include <stdio.h>
#include <stdlib.h>

#include "people.h"
#include "io.h"


int People_read_txt(People *s, FILE *in)
{
    fscanf(in, "%s", &(s->surname));
    fscanf(in, "%s", &(s->initials));
    fscanf(in, "%s", &(s->weight));
    fscanf(in, "%s", &(s->quantity));
    fscanf(in, "%d", &(s->destination));
    fscanf(in, "%d", &(s->departure_time));
    fscanf(in, "%d", &(s->presence_of_transplants));
    fscanf(in, "%d", &(s->kids));

    return !feof(in);
}

void People_write_txt(People *s, FILE *file)
{
    fprintf(file, "%s ", s->surname);
    fprintf(file, "%s ", s->initials);
    fprintf(file, "%s ", s->weight);
    fprintf(file, "%s ", s->quantity);
    fprintf(file, "%d ", s->destination);
    fprintf(file, "%d ", s->departure_time);
    fprintf(file, "%d ", s->presence_of_transplants); 
    fprintf(file, "%d \n", s->kids);
}

int People_read_bin(People *s, FILE *in)
{
    fread(s->surname,  sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), STR_SIZE, in);
    fread(&(s->weight), sizeof(int), 1, in);
    fread(&(s->quantity), sizeof(int), 1, in);
    fread(&(s->destination), sizeof(char), STR_SIZE, in);
    fread(&(s->departure_time), sizeof(char), STR_SIZE, in);
    fread(&(s->presence_of_transplants), sizeof(char), STR_SIZE, in);
    fread(&(s->kids), sizeof(int), 1, in);


    return !feof(in);
}

void People_write_bin(People *s, FILE *out)
{
    fwrite(s->surname,  sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), STR_SIZE, out);
    fwrite(&(s->weight), sizeof(char), STR_SIZE, out);
    fwrite(&(s->quantity), sizeof(char), STR_SIZE, out);
    fwrite(&(s->destination), sizeof(int), 1, out);
    fwrite(&(s->departure_time), sizeof(int), 1, out);
    fwrite(&(s->presence_of_transplants), sizeof(int), 1, out);
    fwrite(&(s->kids), sizeof(int), 1, out);

}

void People_print(People *s)
{
    printf("Name: %s %s\n", s->surname, s->initials);
    printf("Weight: %s\n", s->weight);
    printf("Quantity: %s\n", s->quantity);
    printf("Destination: %d\n", s->destination);
    printf("Departure_time: %d\n", s->departure_time);
    printf("Presence of transplants: %d\n", s->presence_of_transplants);
    printf("Kids: %d\n", s->kids);


    printf("\n");
}