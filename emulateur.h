#include "memoire.h"
#include "registres.h"
#include "fonction.h"

void execution1Instr (registres registers, char memoire [TAILLEMAX][2]);
void execution (int nbLigne,registres registers, char memoire [TAILLEMAX][2]);
int b2d(int binaire);
