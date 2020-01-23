#ifndef __MEMORY__
#define __MEMORY__


#include <stdio.h>

#define TAILLEMAX 429496 /*notre taille de mémoire physique est de 4294967296 octets (4Gio) mais pour eviter une erreur de segmentation on a du diviser par 1000*/

int pile [10];

void writeProgram(int nombreLigne,unsigned char* programmeDeci, char memoire [TAILLEMAX][2]);
void initialisationPile();
void empiler(int val);
int depiler();
void afficherMem(int nombreLigne, char memoire [TAILLEMAX][2]);
unsigned char load (int adresse, char memoire [TAILLEMAX][2]);
void store (int val, int offset, int adresse, char memoire [TAILLEMAX][2]);

#endif
