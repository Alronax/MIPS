#include<stdio.h>
#include<stdlib.h>

#include "registres.h"

void resetRegisters(){
  int compteur = 0;
  for(compteur = 0;compteur<32; compteur++){
    registers->registres_principaux[compteur] = 0;
  }
  registers->hi = 0;
  registers->lo = 0;
  registers->pc = 0;
}

void writeInReg(int numberOfReg, int val){
  registers->registres_principaux[numberOfReg] = val;
}

void writeInHI (int val){
  registers->hi = val;
}

void writeInLO (int val){
  registers->lo = val;
}

void writeInPC (int val){
  registers->pc = val;
}

/*pc represente le debut d un octet donc comme une instructio est sur 32 bits on l'incrémente de 4 après chaque instruction*/
void incrementPC (){
  registers->pc += 4;
}
