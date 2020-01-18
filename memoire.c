#include<stdio.h>
#include<stdlib.h>

#include "memoire.h"


void initialisationMemoire(){
  int i = 0;
  for(i=0;i<500;i++){
    memoire[i] = 0;
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
