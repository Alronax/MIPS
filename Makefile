main: main.o fonction.o registres.o
	gcc -o main main.o fonction.o registres.o -lm -g

main.o: main.c fonction.h
	gcc -c main.c -Wall -ansi -pedantic -o main.o -g

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -Wall -ansi -pedantic -o fonction.o -g

registres.o: registres.c registres.h
	gcc -c registres.c -Wall -ansi -pedantic -o registres.o -g
