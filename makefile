CC=gcc
CFLAGS=-Wall

gol: gol.c main.c
	$(CC) gol.c main.c -o game $(CFLAGS)