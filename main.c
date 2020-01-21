#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "emulateur.h"
#include "memoire.h"
#include "registres.h"
#include "fonction.h"

int main(){
  registres registers;
  char memoire [TAILLEMAX][2];
  int nombreLigne;
  unsigned char* programmeDeci;
  unsigned char valeur = 0xa1;

/*
  translateToHexa("test.txt","testDecode.txt");

  nombreLigne = donneNombreInstruction();
  programmeDeci = donnePointeurProgDeci();

  reinitialisationMemoirePhys();
  writeProgram(nombreLigne,programmeDeci);
  afficherMemProg(nombreLigne);*/
  return 0;
}
