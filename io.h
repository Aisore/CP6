#ifndef _IO_H_
#define _IO_H_

#include "people.h"

int  people_read_txt(People *s, FILE *in);
void people_write_bin(People *s, FILE *out);
void people_print(People *s);
void people_write_txt(People *s, FILE *file);

#endif