main: main.o fonction.o
	gcc -o main main.o fonction.o -lm

main.o: main.c fonction.h
	gcc -c main.c -Wall -ansi -pedantic -o main.o -lm

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -Wall -ansi -pedantic -o fonction.o -lm
/*aaa*/
