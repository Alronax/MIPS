#include<stdio.h>
#include<stdlib.h>

#include "memoire.h"

int global_nbLignes;

void writeProgram(int nombreLigne,unsigned char* programmeDeci, char memoire [TAILLEMAX][2]) {
  int i;
  int j;
  for(i=0;i<nombreLigne*4;i++){
    for(j=0;j<2;j++){
      memoire[i][j] = programmeDeci[2*i + j];
    }
  }
}

void afficherMem(int nombreLigne, char memoire [TAILLEMAX][2]){
  int i;
  int j;

  printf("\n*** Final memory state: ***\nAddress | Value\n");
  for(i=0;i<=60;i+=4){
    for(j=0;j<4;j++){
      printf("@%d: %x%x%x%x%x%x%x%x     ",i,memoire[i][0],memoire[i][1],memoire[i+1][1],memoire[i+1][0],memoire[i+2][1],memoire[i+2][0],memoire[i+3][1],memoire[i+3][0]);
      i+=4;
    }
    i-=4;
    printf("\n");
  }
}

void initialisationPile(){
  int i = 0;
  for(i=0;i<10;i++){
    pile[i] = 0;
  }
}

void empiler(int val){
  int i = 0;
  while(i < 10 && pile[i] != 0){
    i++;
  }
  if(i < 10){
    pile[i] = val;
  }
}

int depiler(){
  int i = 0;
  int val;
  if (pile[0] != 0){
    while(i < 10 && pile[i+1] != 0){
      i++;
    }
    if (i<10){
      val = pile[i];
      pile[i] = 0;
    }
  }
  else{
    val = 0;
  }
  return val;
}

void store (int val, int offset, int adresse, char memoire [TAILLEMAX][2]){
  if (adresse < TAILLEMAX-global_nbLignes){
    memoire[adresse+offset][0] = val>>4;
    memoire[adresse+offset][1] = val & 0x0f;
  }
  else{
    printf("memoire pas assez grande\n");
  }
}

unsigned char load (int adresse, char memoire [TAILLEMAX][2]){
  int val = 0;
  if(adresse < TAILLEMAX-global_nbLignes){
    val = memoire[adresse][0];
    val <<= 4;
    val += memoire[adresse][1];
  }
  else{
    printf("acces memoire impossible\n");
  }
  return val;
}
