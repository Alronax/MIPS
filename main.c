#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "emulateur.h"
#include "memoire.h"
#include "registres.h"
#include "fonction.h"

int main(){
  liste_registres liste;
  registres registers = &liste;
  char memoire [TAILLEMAX][2];
  int nombreLigne;
  unsigned char* programmeDeci;

  translateToHexa("test.txt","testDecode.txt");


  nombreLigne = donneNombreInstruction();
  programmeDeci = donnePointeurProgDeci();

  initialisationPile();
  writeProgram(nombreLigne,programmeDeci,memoire);
  afficherMemProg(nombreLigne,memoire);

  resetRegisters(registers);
  registers->registres_principaux[2] = 4;
  registers->registres_principaux[3] = 6;
  execution (registers,memoire);
  printf("reg 1 = %d\n",registers->registres_principaux[1]);
  return 0;
}
