#ifndef __REGISTERS__
#define __REGISTERS__


typedef struct liste_registres liste_registres;

struct liste_registres {
int registres_principaux[32];
int hi;
int lo;
int pc;
};

typedef liste_registres* registres;



void resetRegisters(registres registers);
void writeInReg(int numberOfReg, int val, registres registers);
void writeInHI (int val, registres registers);
void writeInLO (int val, registres registers);
void writeInPC (int val, registres registers);
void incrementPC (registres registers);

#endif
