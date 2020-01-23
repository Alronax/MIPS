#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "emulateur.h"
#include "memoire.h"
#include "registres.h"
#include "fonction.h"

int main(int argc, char* argv[]){
  liste_registres liste;
  registres registers = &liste;
  char memoire [TAILLEMAX][2];
  int nombreLigne;
  unsigned char* programmeDeci;

  printf("          **** MIPS EMULATOR ****\nCS351 - LAURENT Mathieu GABILLET Théo\n\n");
  printf("Assembling file : %s\noutput will be written in : testDecode.txt\n",argv[1]);

  translateToHexa(argv[1],"testDecode.txt");
  nombreLigne = donneNombreInstruction();
  programmeDeci = donnePointeurProgDeci();
  initialisationPile();
  writeProgram(nombreLigne,programmeDeci,memoire);
  resetRegisters(registers);
  registers->registres_principaux[8] = 11;
  registers->registres_principaux[6] = 16;
  execution (nombreLigne,registers,memoire);
  
  afficherRegistres(registers);
  afficherMem(nombreLigne,memoire);
  return 0;
}
