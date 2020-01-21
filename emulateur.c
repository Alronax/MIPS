#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "emulateur.h"
#include "memoire.h"
#include "registres.h"
#include "fonction.h"

int b2d(int binaire){
	int i;
	int resultat = 0;
	for (i=0;i<8;i++){
		resultat += binaire%2 << i;
		binaire >>= 1;
	}
	return resultat;
}

void execution (registres registers, char memoire [TAILLEMAX][2]){
	int pc = registers->pc;
	int lo = registers->lo;
	int hi = registers->hi;
	char reg[32] ;
	int i,d,s,t,sa,immediate;

	for(i=0;i++;i=31){
		reg[i] = registers->registres_principaux[i];
	}
	/* int s = 0, t = 0, d = 0, immediate = 0;
	if (memoire[pc][1] <= '9'){
		s = s + (memoire[pc][1] mod 4)*8;
	}
	else if( */
	if (memoire[pc][0] == '0'){
		if (memoire[pc][1] > '7'){
			/* J et JAL */
		}
		else if (memoire[pc+3][1] == '4'){
			/* AND */
			reg[d] = b2d(d2b(reg[s]) & d2b(reg[t]));               /* conversion ok ?*/
		}
		else if (memoire[pc+3][1] == '5'){
			/* OR */
			reg[d] = b2d(d2b(reg[s]) | d2b(reg[t]));                /* conversion ok ?*/
		}
		else if (memoire[pc+3][1] == 'c'){
			/* SYSCALL */
		}
		else if (memoire[pc+3][1] == '6'){
			/* XOR */
			reg[d] = b2d(d2b(reg[s]) ^ d2b(reg[t]));                 /* conversion ok ?*/
		}
		else if (memoire[pc+3][1] == '8'){
			if (memoire[pc+3][0] == '1'){
				/* MULT */
				hi = (reg[s] * reg[t]) / 4294967296;
				lo = (reg[s] * reg[t]) % 4294967296;
			}
			else{
				/* JR */
				pc = reg[s] - 4;
			}
		}
		else if (memoire[pc+3][1] == 'a'){
			if (memoire[pc+3][0] == '1'){
				/* DIV */
				lo = reg[s] / reg[t];
				hi = reg[s] % reg[t];
			}
			else{
				/* SLT */
				if (reg[s] < reg[t]){
					reg[d] = 1;
				}
				else{
					reg[d] = 0;
				}
			}
		}
		else if (memoire[pc+3][1] == '0'){
			if (memoire[pc+3][0] == '1'){
				/* MFHI */
				reg[d] = hi;
			}
			else if (memoire[pc+3][0] == '2'){
				/* ADD */
				reg[d] = reg[s] + reg[t];
			}
			else{
				if (strcmp(memoire[pc+1],"00") == 0 || strcmp(memoire[pc+2],"00") == 0 || strcmp(memoire[pc+3],"00") == 0){
					/* SLL */
					reg[d] = b2d(d2b(reg[t]) << sa);                       /* conversion ok ?*/
				}
				else{
					/* NOP */
				}
			}
		}
		else if (memoire[pc+3][1] == '2'){
			if (memoire[pc+3][0] == '1'){
				/* MFLO */
				reg[d] = lo;
			}
			else if (memoire[pc+3][0] == '2'){
				/* SUB */
				reg[d] = reg[s] - reg[t];
			}
			else{
				if (memoire[pc+1][0] < '2'){
					/* SRL */
					reg[d] = b2d(d2b(reg[t]) >> sa);                        /* conversion ok ?*/
				}
				else{
					/* ROTR */
					reg[d] = b2d(d2b(reg[t]) >> sa) + b2d(d2b(reg[t]) << (32-sa));    /* addition bit à bit, ou conversion à faire */   /* conversion ok ?*/
				}
			}
		}
	else if (memoire[pc][0] == '2'){
		/* ADDI */
		reg[t] = reg[s] + immediate;
	}
	else if (memoire[pc][0] == '3'){
		/* LUI */
		reg[t] = b2d(d2b(immediate) << 16);                                      /* conversion ok ?*/
	}
	else if (memoire[pc][0] == '8'){
		/* LW */
	}
	else if (memoire[pc][0] == 'a'){
		/* SW */
	}
	else{
		if (memoire[pc][1] < '4'){
			/* BEQ */
			if (reg[s] == reg[t]){
				/* branchement */
			}
		}
		else if (memoire[pc][1] < '8'){
			/* BNE */
			if (reg[s] != reg[t]){
				/* branchement */
			}
		}
		else if (memoire[pc][1] < 'c'){
			/* BLEZ */
			if (reg[s] <= 0){
				/* branchement */
			}
		}
		else{
			/* BGTZ */
			if (reg[s] > 0){
				/* branchement */
			}
		}
	}
}
	for(i=0;i++;i=31){
		writeInReg(i, reg[i],registers);
	}
	writeInHI (hi, registers);
	writeInLO (lo,registers);
	writeInPC (pc,registers);
	incrementPC (registers);
}







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
