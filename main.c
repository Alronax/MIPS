#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "emulateur.h"
#include "memoire.h"
#include "registres.h"
#include "fonction.h"

int main(){
  unsigned char valeur;
  valeur = 0xac;
  valeur = charToInverse(valeur);
  translateToHexa("test.txt","testDecode.txt");
  printf("%x",valeur);
  return 0;
}
