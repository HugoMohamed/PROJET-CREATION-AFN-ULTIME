CC = gcc
OPTIONS = -Wall

afd : ensemble.o afn.o pile.o main.o
	$(CC) $(OPTIONS) ensemble.o afn.o pile.o main.o -o afd

ensemble.o : ensemble.c ensemble.h
	$(CC) $(OPTIONS) -c ensemble.c

afn.o : afn.c afn.h
	$(CC) $(OPTIONS) -c afn.c

pile.o : pile.c pile.h
	$(CC) $(OPTIONS) -c pile.c

main.o : main.c
	$(CC) $(OPTIONS) -c main.c

clean :
	rm -rf *.o *.~ afd
