#ifndef __FONCTION__
#define __FONCTION__



int translateToHexaLine(FILE* fichierSource);
int recupNb(char registre[], char tab[], int* i);
int recupInstruction(char tab[],FILE* fichierSource);
void selectOpCode(char tab[],char opCode[],int*i);
void letterToNumber(int r1, int r2, int r3,int index);
int d2b (int ent);
void replace(int nb,int lastLetter, char letter,char instructionBinaire[]);
void translateToHexa(char nomFichierSource[],char nomFichierCible[]);
void writeInTab (int* tab);
int donneNombreInstruction();
unsigned char* donnePointeurProgDeci();

#endif
