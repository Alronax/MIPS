#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "emulateur.h"
#include "memoire.h"
#include "registres.h"
#include "fonction.h"

int main(){
  int nombreLigne;
  unsigned char* programmeDeci;

  translateToHexa("test.txt","testDecode.txt");

  nombreLigne = donneNombreInstruction();
  programmeDeci = donnePointeurProgDeci();

  reinitialisationMemoirePhys();
  writeProgram(nombreLigne,programmeDeci);
  afficherMemProg(nombreLigne);
  reinitialiserProgram();
  return 0;
}
