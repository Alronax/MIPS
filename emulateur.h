#include "memoire.h"
#include "registres.h"
#include "fonction.h"

/*convertit du binaire au decimal un entier*/
int b2d(int binaire);

/*execute une instruction contenue dans la memoire en hexadecimal*/
void execution1Instr (registres registers, char memoire [TAILLEMAX][2]);

/*execute la suite de toutes les instructions en hexa*/
void execution (int nbLigne,registres registers, char memoire [TAILLEMAX][2]);
