#include<stdio.h>
#include<stdlib.h>

#include "memoire.h"

int global_nbLignes;

void writeProgram(int nombreLigne,unsigned char* programmeDeci) {
  int i;
  memoireProgramme = malloc((sizeof(char)*nombreLigne*4));
  for(i=0;i<nombreLigne*4;i++){
    memoireProgramme[i] = (programmeDeci[2*i] << 4) + programmeDeci[2*i + 1];
  }
}

void reinitialiserProgram(){
  free (memoireProgramme);
}

void afficherMemProg(int nombreLigne){
  int i;
  for(i=0;i<nombreLigne*4;i++){
    printf("%x\n",memoireProgramme[i]);
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

void reinitialisationMemoirePhys(int nombreLigne){
  int i;
  global_nbLignes = nombreLigne;
  for(i=0;i < 1000 - nombreLigne;i++){
    memoirePhysique[i] = 0;
  }
}

void store (unsigned char val, int adresse){
  if (adresse < 1000-global_nbLignes){
    memoirePhysique[adresse] = val;
  }
  else{
    printf("memoire pas assez grande\n");
  }
}

unsigned char load (int adresse){
  unsigned char val = 0;
  if(adresse < 1000-global_nbLignes){
    val = memoirePhysique[adresse];
  }
  else{
    printf("acces memoire impossible\n");
  }
  return val;
}
