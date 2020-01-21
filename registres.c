#include<stdio.h>
#include<stdlib.h>

#include "registres.h"

void resetRegisters(registres registers){
  int compteur = 0;
  for(compteur = 0;compteur<32; compteur++){
    registers->registres_principaux[compteur] = 0;
  }
  registers->hi = 0;
  registers->lo = 0;
  registers->pc = 0;
}

void writeInReg(int numberOfReg, int val, registres registers){
  registers->registres_principaux[numberOfReg] = val;
}

void writeInHI (int val, registres registers){
  registers->hi = val;
}

void writeInLO (int val, registres registers){
  registers->lo = val;
}

void writeInPC (int val, registres registers){
  registers->pc = val;
}

/*pc represente le debut d un octet donc comme une instructio est sur 32 bits on l'incrémente de 4 après chaque instruction*/
void incrementPC (registres registers){
  registers->pc += 4;
}
