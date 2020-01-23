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
	int inter = 0;
	for (i=1;i<=32;i++){
		inter = 0;
		inter = (binaire / pow(10,32-i));
		resultat = resultat * 2 + inter%2;
	}
	return resultat;
}

int sb2d(int binaire){
	binaire = b2d(binaire);
	if (binaire >= 131072 /*2^17*/){
		binaire -= 262144;
	}
	return binaire;
}

void execution1Instr (registres registers, char memoire [TAILLEMAX][2]){
	unsigned long pc = registers->pc;
	unsigned long lo = registers->lo;
	unsigned long hi = registers->hi;
	unsigned long reg[32] ;
	int target, i,s = 0, t = 0, d = 0, immediate = 0, index = 0, sa = 0, intermediaire;


	for(i=0;i<32;i++){
		reg[i] = registers->registres_principaux[i];
	}
	intermediaire = memoire[pc][1];

	s = s + (intermediaire % 4)*8;
	index = index + intermediaire * 16777216;

	intermediaire = memoire[pc+1][0];
	s = s + (intermediaire / 2);
	t = t + (intermediaire % 2)*16;
	index = index + intermediaire * 1048576;

	intermediaire = memoire[pc+1][1];

	t = t + intermediaire;
	index = index + intermediaire * 65536;


	intermediaire = memoire[pc+2][0];

	d = d + intermediaire * 2;
	immediate = immediate + intermediaire * 4096;
	index = index + intermediaire * 4096;


	intermediaire = memoire[pc+2][1];

	d = d + (intermediaire / 8);
	immediate = immediate + intermediaire * 256;
	index = index + intermediaire * 256;
	sa = sa + (intermediaire % 8)*4;


	intermediaire = memoire[pc+3][0];

	immediate = immediate + intermediaire * 16;
	index = index + intermediaire * 16;
	sa = sa + (intermediaire / 4);

	intermediaire = memoire[pc+3][1];

	immediate = immediate + intermediaire;
	index = index + intermediaire;

	/* if (immediate >= 32728){  */


	if (memoire[pc][0] == 0){

		if (memoire[pc][1] > 7){
			/* J et JAL */
			target = b2d(d2b(index) << 2);
			if (memoire[pc][1] > 0xb){
				/* JAL */
				reg[31] = pc + 4;
			}
			pc = (pc / 268435456 ) * 268435456 + target;
		}
		else if (memoire[pc+3][1] == 4){
			/* AND */
			reg[d] = b2d(d2b(reg[s]) & d2b(reg[t]));               /* conversion ok ?*/
		}
		else if (memoire[pc+3][1] == 5){
			/* OR */
			reg[d] = b2d(d2b(reg[s]) | d2b(reg[t]));                /* conversion ok ?*/
		}
		else if (memoire[pc+3][1] == 0xc){
			/* SYSCALL */
		}
		else if (memoire[pc+3][1] == 6){
			/* XOR */
			reg[d] = b2d(d2b(reg[s]) ^ d2b(reg[t]));                 /* conversion ok ?*/
		}
		else if (memoire[pc+3][1] == 8){
			if (memoire[pc+3][0] == 1){
				/* MULT */
				hi = (reg[s] * reg[t]) / 4294967296;
				lo = (reg[s] * reg[t]) % 4294967296;
			}
			else{
				/* JR */
				pc = reg[s] - 4;
			}
		}
		else if (memoire[pc+3][1] == 0xa){
			if (memoire[pc+3][0] == 1){
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
		else if (memoire[pc+3][1] == 0){
			if (memoire[pc+3][0] == 1){
				/* MFHI */
				reg[d] = hi;
			}
			else if (memoire[pc+3][0] == 2){
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
		else if (memoire[pc+3][1] == 2){
			if (memoire[pc+3][0] == 1){
				/* MFLO */
				reg[d] = lo;
			}
			else if (memoire[pc+3][0] == 2){
				/* SUB */
				reg[d] = reg[s] - reg[t];
			}
			else{
				if (memoire[pc+1][0] < 2){
					/* SRL */
					reg[d] = b2d(d2b(reg[t]) >> sa);                        /* conversion ok ?*/
				}
				else{
					/* ROTR */
					reg[d] = b2d(d2b(reg[t]) >> sa) + b2d(d2b(reg[t]) << (32-sa));    /* addition bit à bit, ou conversion à faire */   /* conversion ok ?*/
				}
			}
		}
	}
	else if (memoire[pc][0] == 2){

		/* ADDI */
		reg[t] = reg[s] + immediate;
	}
	else if (memoire[pc][0] == 3){
		/* LUI */
		reg[t] = b2d(d2b(immediate) << 16);                                      /* conversion ok ?*/
	}
	else if (memoire[pc][0] == 8){
		/* LW */
	}
	else if (memoire[pc][0] == 0xa){
		/* SW */
	}
	else{
		if (memoire[pc][1] < 4){
			/* BEQ */
			if (reg[s] == reg[t]){
				/* branchement */
			}
		}
		else if (memoire[pc][1] < 8){
			/* BNE */
			if (reg[s] != reg[t]){
				/* branchement */
			}
		}
		else if (memoire[pc][1] < 0xc){
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

	for(i=0;i<32;i++){
		writeInReg(i, reg[i],registers);
	}
	writeInHI (hi, registers);
	writeInLO (lo,registers);
	writeInPC (pc,registers);
	incrementPC (registers);
}

void execution (int nbLigne,registres registers, char memoire [TAILLEMAX][2]){
	int i = 0;
	for(i=0;i<nbLigne;i++){
		execution1Instr(registers, memoire );
	}
}
