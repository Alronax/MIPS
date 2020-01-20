#include <stdio.h>

#define TAILLEMAX_M 1000 /*notre taille de mémoire physique est de 1000 octets*/

int pile [10];
char* memoirePhysique;

unsigned char* memoireProgramme;

void writeProgram(int nombreLigne,unsigned char* programmeDeci);
void reinitialiserProgram();
void initialisationPile();
void empiler(int val);
int depiler();
void reinitialisationMemoirePhys();
void afficherMemProg(int nombreLigne);
unsigned char load (int adresse);
void store (unsigned char val, int adresse);
