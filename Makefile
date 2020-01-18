main: main.o fonction.o registres.o memoire.o emulateur.o
	gcc -o main main.o fonction.o registres.o memoire.o emulateur.o -lm -g

main.o: main.c fonction.h registres.h memoire.h emulateur.h
	gcc -c main.c -Wall -ansi -pedantic -o main.o -g

fonction.o: fonction.c fonction.h
	gcc -c fonction.c -Wall -ansi -pedantic -o fonction.o -g

registres.o: registres.c registres.h
	gcc -c registres.c -Wall -ansi -pedantic -o registres.o -g

memoire.o: memoire.c memoire.h
	gcc -c memoire.c -Wall -ansi -pedantic -o memoire.o -g

emulateur.o: emulateur.c emulateur.h
	gcc -c emulateur.c -Wall -ansi -pedantic -o emulateur.o -g
