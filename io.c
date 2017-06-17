#include <stdio.h>
#include <stdlib.h>

#include "people.h"
#include "io.h"


int people_read_txt(People *s, FILE *in)
{
    fscanf(in, "%s", s->surname);
    fscanf(in, "%s", s->initials);
    fscanf(in, "%d", &(s->weight));
    fscanf(in, "%d", &(s->quantity));
    fscanf(in, "%s", s->destination);
    fscanf(in, "%s", s->departure_time);
    fscanf(in, "%s", s->presence_of_transfers);
    fscanf(in, "%d", &(s->kids));

    return !feof(in);
}

void people_write_txt(People *s, FILE *file)
{
    fprintf(file, "%s ", s->surname);
    fprintf(file, "%s ", s->initials);
    fprintf(file, "%d ", s->weight);
    fprintf(file, "%d ", s->quantity);
    fprintf(file, "%s ", s->destination);
    fprintf(file, "%s ", s->departure_time);
    fprintf(file, "%s ", s->presence_of_transfers); 
    fprintf(file, "%d \n", s->kids);
}

int people_read_bin(People *s, FILE *in)
{
    fread(s->surname,  sizeof(char), STR_SIZE, in);
    fread(s->initials, sizeof(char), STR_SIZE, in);
    fread(&(s->weight), sizeof(int), 1, in);
    fread(&(s->quantity), sizeof(int), 1, in);
    fread(s->destination, sizeof(char), STR_SIZE, in);
    fread(s->departure_time, sizeof(char), STR_SIZE, in);
    fread(s->presence_of_transfers, sizeof(char), STR_SIZE, in);
    fread(&(s->kids), sizeof(int), 1, in);
    
    return !feof(in);
}

void people_write_bin(People *s, FILE *out)
{
    fwrite(s->surname,  sizeof(char), STR_SIZE, out);
    fwrite(s->initials, sizeof(char), STR_SIZE, out);
    fwrite(&(s->weight), sizeof(int), 1, out);
    fwrite(&(s->quantity), sizeof(int), 1, out);
    fwrite(s->destination, sizeof(char), STR_SIZE, out);
    fwrite(s->departure_time, sizeof(char), STR_SIZE, out);
    fwrite(s->presence_of_transfers, sizeof(char), STR_SIZE, out);
    fwrite(&(s->kids), sizeof(int), 1, out);
}