#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#include "emulateur.h"

/*
unsigned char char2b (unsigned char ent){
	unsigned char reste;
	unsigned char resultat = 0;
  int i = 0;

	while (ent != 0){
		reste = ent%2;
		ent = ent/2;
		resultat += reste * pow(10,i);
    i++;
	}
    return resultat;
}


unsigned char b2char (unsigned char binaire){
  int i;
  int resultat = 0;
  for (i=0;i<8;i++){
    resultat += binaire%2 << i;
    binaire >>= 1;
  }
  return resultat;
}

unsigned char charToInverse (unsigned char octet){
  unsigned char resultat = 0;
  int i;
  octet = char2b(octet);
  for(i = 0;i < 8;i++){
    resultat += octet%2;
    octet <<= 1;
    resultat >>= 1;
  }
  resultat = b2char(resultat);
  return resultat;
}*/
