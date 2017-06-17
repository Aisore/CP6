CC = gcc
CFLAGS = -g -std=c99 -w -pipe -O3

all: execute

print:    io.o
	$(CC) $^ -o $@

execute:  io.o execute.o people.o
	$(CC) $^ -o $@

clean:
	rm -f *.o

generate_text: generate_text.o io.o
	$(CC) $^ -o $@

generate_bin: generate_bin.o io.o
	$(CC) $^ -o $@

cleanall:
	rm -f execute generate generate1 *.o