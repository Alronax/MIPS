void translateToHexaLine(FILE* fichierSource);
void recupNb(int *r, char registre[], char tab[], int* i,int* ptaille);
void recupInstruction(char tab[],FILE* fichierSource);
void selectOpCode(char tab[],char opCode[],int*i);
void letterToNumber(int r1, int r2, int r3,int index, int* ptaille);
int d2b (int ent,int* ptaille);
void replace(int nb, int* ptaille,int lastLetter, char letter,char instructionBinaire[]);
void translateToHexa(char nomFichierSource[],char nomFichierCible[]);
