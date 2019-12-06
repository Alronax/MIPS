#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "fonction.h"

char TopCode [][10] = {"ADD","ADDI","AND","BEQ","BGTZ","BLEZ","BNE","DIV","J","JAL","JR","LUI","LW","MFHI","MFLO","MULT","NOP","OR","ROTR","SLL","SLT","SRL","SUB","SW","SYSCALL","XOR"};
char Tequivalent [][32] = {"000000ssssstttttddddd00000100000","001000ssssstttttiiiiiiiiiiiiiiii","000000ssssstttttddddd00000100100","000100ssssstttttoooooooooooooooo","000111sssss00000oooooooooooooooo","000110sssss00000oooooooooooooooo"};/*arret a BLEZ*/


void selectOpCode(char tab[],char opCode[], int* i){
  while (tab[*i] != ' '){/*parcours tab pour obtenir opcode*/
    opCode[*i] = tab[*i];
    *i = *i + 1;
  }
}

int d2b (int ent,int* ptaille){/*prend pas en compte taille*/
	int reste;
	int resultat = 0;
  int i = 0;

	while (ent != 0){
		reste = ent%2;
		ent = ent/2;
		resultat += reste * pow(10,i);
    i++;
    *ptaille = *ptaille + 1;
	}
    return resultat;
}

void recupInstruction(char tab[],FILE* fichierSource){
  int i = 0;
  while(tab[i-1] != '\n') {/*enregistre une instruction entiere dans tab*/
    fscanf(fichierSource, "%c", &tab[i]);
    i++;
  }
  tab[i+1] = '\0';
}

void recupNb(int *r, char registre[], char tab[], int* i,int* ptaille){
  int l = 0;
  int flag = 0;

  while ((tab[*i] != ',' && tab[*i] != '\n') ){/*parcours tab pour prendre le prochain nombre*/
    if(tab[*i] == '#'){
      flag = 1;
    }

    if(flag == 0 && tab[*i] != '$' && tab[*i] != ' '){
        registre[l] = tab[*i];
        l++;
    }
    *i = *i + 1;
  }
    *r = atoi(registre);/*transforme en int le string*//*!!marche pas*/
    *r = d2b(*r,ptaille);/*!!! changer taille*/
  }

void translateToHexaLine(FILE* fichierSource){
  char tab[100] = {0};
  int i = 0;
  int j = 0;
  int numopCode;
  char opCode[10] = {0};
  char registre[10] = {0};
  int r1 = -1;
  int r2 = -1;
  int r3 = -1;
  int taille = 0;

  recupInstruction(tab,fichierSource);

  selectOpCode(tab,opCode,&i);

  while (strcmp(opCode,TopCode[j]) != 0){/*trouve opCode dans tableau opcode*/
	j++;
  }
  numopCode = j;

  while (tab[i] != '\0'){/*enregistre les nombre dans les registres 1,2 et 3*/
    if(r1 == -1){recupNb(&r1,registre,tab,&i,&taille);}

    else if(r2 == -1){recupNb(&r2,registre,tab,&i,&taille);}
    else if(r3 == -1) {recupNb(&r3,registre,tab,&i,&taille);}
    i++;
  }

  letterToNumber(r1,r2,r3,j,&taille);

}

void translateToHexa(char nomFichierSource[],char nomFichierCible[]){
  FILE* fichierSource = NULL;

  fichierSource = fopen(nomFichierSource, "r+");
  if(fichierSource == NULL) {
    perror("Probleme ouverture fichier");
    exit(1);
  }
  translateToHexaLine(fichierSource);

  fclose (fichierSource);
}

void replace(int nb, int* ptaille,int lastLetter, char letter,char* instructionBinaire[]){
  int compteur = 0;
  char operande[16] = "-1";

  sprintf(operande , "%d" , nb);

  while((*instructionBinaire[lastLetter-compteur] == letter) && (compteur <= *ptaille)){
    *instructionBinaire[lastLetter-compteur] = operande[compteur];
    compteur ++;
  }
  if(*instructionBinaire[lastLetter-compteur] == letter){
    while(*instructionBinaire[lastLetter-compteur] == letter){
      *instructionBinaire[lastLetter-compteur] = '0';
    }
  }
}

void letterToNumber(int r1, int r2, int r3,int index, int* ptaille){
  char* instructionBinaire[40];
  int compteur = 0;
  *instructionBinaire = "";

  if(Tequivalent[index][6] == 's'){
    if(Tequivalent[index][11] == 't'){
      if(Tequivalent[index][16] == 'd'){
        strcpy(*instructionBinaire,Tequivalent[index]);/*probleme*/

        printf("1\n");
        replace(r2,ptaille,10,'s',instructionBinaire);
        replace(r3,ptaille,15,'t',instructionBinaire);
        replace(r1,ptaille,20,'d',instructionBinaire);
      }
      if(Tequivalent[index][16] == 'i' || Tequivalent[index][16] == 'o'){
        /*replace*/
      }
      else{
        /*remplacer*/
      }
    }
    else{
      if(Tequivalent[index][16] == 'o'){
        /*replace*/
      }
      else{
        /*jR (hint)*/
      }
    }
  }
  else{/*pas s*/
    if(Tequivalent[index][11] == 't'){
      if(Tequivalent[index][16] == 'd'){
        /*replace t d sa*/
      }
      if(Tequivalent[index][16] == 'o'){
        /*replace offset base*/
      }
      else{
        /*replace immediate*/
      }
    }
    if(Tequivalent[index][16] == 'd'){
      /*replace*/
    }
    if(Tequivalent[index][4] == '1'){/*instruction j ou jAL*/
      /*replace*/
    }
    if(Tequivalent[index][28] == '0'){/*instruction NOP*/
      /*replace*/
    }
    else{/*instruction SYSCALL*/
      /*replace*/
    }
  }
}
