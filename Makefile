main: main.o fonction.o
	gcc -o main main.o fonction.o -lm -g

main.o: main.c fonction.h
	gcc -c main.c -Wall -ansi -pedantic -o main.o -g

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -Wall -ansi -pedantic -o fonction.o -g
