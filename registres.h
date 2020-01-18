typedef struct liste_registres liste_registres;

struct liste_registres {
int registres_principaux[32];
int hi;
int lo;
int pc;
};

typedef liste_registres* registres;

registres registers;

void resetRegisters();
void writeInReg(int numberOfReg, int val);
void writeInHI (int val);
void writeInLO (int val);
void writeInPC (int val);
void incrementPC ();
