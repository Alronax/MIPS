#ifndef __REGISTERS__
#define __REGISTERS__


typedef struct liste_registres liste_registres;

struct liste_registres {
unsigned long registres_principaux[32];
unsigned long hi;
unsigned long lo;
unsigned long pc;
};

typedef liste_registres* registres;



void resetRegisters(registres registers);
void writeInReg(int numberOfReg, int val, registres registers);
void writeInHI (int val, registres registers);
void writeInLO (int val, registres registers);
void writeInPC (int val, registres registers);
void incrementPC (registres registers);
void afficherRegistres(registres registers);

#endif
