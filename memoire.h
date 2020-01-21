#include <stdio.h>

#define TAILLEMAX 4294967296 /*notre taille de mémoire physique est de 4294967296 octets*/

int pile [10];

void writeProgram(int nombreLigne,unsigned char* programmeDeci, char memoire [TAILLEMAX][2]);
void initialisationPile();
void empiler(int val);
int depiler();
void afficherMemProg(int nombreLigne, char memoire [TAILLEMAX][2]);
unsigned char load (int adresse, char memoire [TAILLEMAX][2]);
void store (int val, int offset, int adresse, char memoire [TAILLEMAX][2]);
