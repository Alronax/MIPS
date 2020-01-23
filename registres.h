#ifndef __REGISTERS__
#define __REGISTERS__


typedef struct liste_registres liste_registres;

/*structure des registres*/
struct liste_registres {
unsigned long registres_principaux[32];
unsigned long hi;
unsigned long lo;
unsigned long pc;
};

typedef liste_registres* registres;

/*met tous les registres a 0*/
void resetRegisters(registres registers);

/*ecrit une valeur val dans un registre numberOfReg des registres principaux de registers*/
void writeInReg(int numberOfReg, unsigned long val, registres registers);

/*ecrit une valeur val dans un registre HI de registers*/
void writeInHI (unsigned long val, registres registers);

/*ecrit une valeur val dans un registre LO de registers*/
void writeInLO (unsigned long val, registres registers);

/*ecrit une valeur val dans un registre PC de registers*/
void writeInPC (unsigned long val, registres registers);

/*incremente le pc pour qu'il pointe vers la prochaine instruction*/
void incrementPC (registres registers);

/*affiche tous les registres*/
void afficherRegistres(registres registers);

#endif
