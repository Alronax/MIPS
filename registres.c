#include<stdio.h>
#include<stdlib.h>

#include "registres.h"

void resetRegisters(registres registers){
  int compteur;
  for(compteur = 0;compteur<32; compteur++){
    registers->registres_principaux[compteur] = 0;
  }
  registers->hi = 0;
  registers->lo = 0;
  registers->pc = 0;
}

void writeInReg(int numberOfReg,  unsigned long val, registres registers){
  registers->registres_principaux[numberOfReg] = val;
}

void writeInHI (unsigned long val, registres registers){
  registers->hi = val;
}

void writeInLO (unsigned long val, registres registers){
  registers->lo = val;
}

void writeInPC (unsigned long val,registres registers){
  registers->pc = val;
}

/*pc represente le debut d un octet donc comme une instructio est sur 32 bits on l'incrémente de 4 après chaque instruction*/
void incrementPC (registres registers){
  registers->pc += 4;
}

void afficherRegistres(registres registers){
  int i;

  printf("\n*** Final register states: ***\n");
  for(i=0;i<32;i+=4){
    printf("$%d: %lx      $%d: %lx      $%d: %lx      $%d: %lx\n",i,registers->registres_principaux[i],i+1,registers->registres_principaux[i+1],i+2,registers->registres_principaux[i+2],i+3,registers->registres_principaux[i+3]);
  }
  printf("HI : %lx\n",registers->hi);
  printf("LO : %lx\n",registers->lo);
}
