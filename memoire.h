#ifndef __MEMORY__
#define __MEMORY__

#include <stdio.h>

#define TAILLEMAX 429496 /*notre taille de mémoire physique est de 4294967296 octets (4Gio) mais pour eviter une erreur de segmentation on a du diviser par 10000*/

int pile [10];

/*ecrit le programme dans la memoire*/
void writeProgram(int nombreLigne,unsigned char* programmeDeci, char memoire [TAILLEMAX][2]);

/*initialise la pile qui servira a garder en memoire les valeures du PC lors d'un jump*/
void initialisationPile();
void empiler(int val);
int depiler();

/*affiche les 60 premiers emplacements memoire*/
void afficherMem(int nombreLigne, char memoire [TAILLEMAX][2]);

/*load un mot de 32 bits de la memoire dans un registre*/
unsigned char load (unsigned long adresse, int offset, char memoire [TAILLEMAX][2]);

/*store un mot de 32 bits dans la memoire*/
void store (unsigned long val, int offset, unsigned long adresse, char memoire [TAILLEMAX][2]);

#endif
