#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "fonction.h"

char TopCode [][10] = {"ADD","ADDI","AND","BEQ","BGTZ","BLEZ","BNE","DIV","J","JAL","JR","LUI","LW","MFHI","MFLO","MULT","NOP","OR","ROTR","SLL","SLT","SRL","SUB","SW","SYSCALL","XOR"};
char Tequivalent [][32] = {"000000ssssstttttddddd00000100000","001000ssssstttttiiiiiiiiiiiiiiii","000000ssssstttttddddd00000100100","000100ssssstttttoooooooooooooooo","000111sssss00000oooooooooooooooo","000110sssss00000oooooooooooooooo"};/*arret a BLEZ*/

int programmeDeci [800] = {0};
int global_nombreLigne = 0;

/*recupere une instruction d'une ligne dans fichierSource et l'ecrit telle qu'elle dans tab*/
int recupInstruction(char tab[],FILE* fichierSource){
  int i = 0;
  int flag = 1;

  while(tab[i-1] != '\n' && !feof(fichierSource)) {/*enregistre une instruction entiere dans tab*/
    fscanf(fichierSource, "%c", &tab[i]);
    i++;
  }
  tab[i+1] = '\0';
  if(feof(fichierSource)){
    flag = 0;
  }
  return flag;
}

/*parcours tab pour obtenir opcode*/
void selectOpCode(char tab[],char opCode[], int* i){
  while (tab[*i] != ' '){
    opCode[*i] = tab[*i];
    *i = *i + 1;
  }
}

/*traduit du decimal au binaire*/
int d2b (int ent){
	int reste;
	int resultat = 0;
  int i = 0;

	while (ent != 0){
		reste = ent%2;
		ent = ent/2;
		resultat += reste * pow(10,i);
    i++;
	}
    return resultat;
}

/*recupere un nombre dans le tableau et le met dans le registre*/
int recupNb( char registre[], char tab[], int* i){
  int l = 0;
  int flag = 0;
  int r;

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
    r = atoi(registre); /*transforme en int le string*/
    r = d2b(r);
    return r;
  }


/*remplace dans instructionBinaire les caractere letter en partant de la derniere occurence de la lettre et va au debut
 jusqu'a ce que nb n'ait plus de nombres a mettre*/
void replace(int nb, int lastLetter, char letter,char instructionBinaire[]){
  int compteur = 0;
  char operande[16] = {""};

  sprintf(operande , "%d" , nb);

  while ((operande[compteur]!='\0') && (instructionBinaire[lastLetter - compteur] == letter)){
    instructionBinaire[lastLetter-compteur] = operande[strlen(operande)-1 -compteur];
    printf("j'ecris %x a l emplacement %d\n",operande[strlen(operande)-1 -compteur]-'0',lastLetter-compteur);
    compteur ++;
  }
  if(instructionBinaire[lastLetter-compteur] == letter){
    while(instructionBinaire[lastLetter-compteur] == letter){
      instructionBinaire[lastLetter-compteur] = '0';
      compteur ++;
    }
  }
}

/*ecrit une instruction decimal de 8 caracteres dans programmeDeci*/
void writeInTab (int* tab){
  int compteur = 0;
  while (compteur < 8){
    programmeDeci[global_nombreLigne*8 + compteur] = tab[compteur];
    compteur ++;
  }

}



/*traduite en hexa une instruction et l'ecrit dans programmeDeci*/
int translateToHexaLine(FILE* fichierSource){
  char tab[100] = {0};
  int i = 0;
  int j = 0;
  char opCode[10] = {0};
  char registre[10] = {0};
  int r1 = -1;
  int r2 = -1;
  int r3 = -1;
  int flag;
  int instructionDeci[8] = {0};
  char instructionBinaire[32] = {"00000000000000000000000000000000"};
  int index;
  int compteur;

  flag = recupInstruction(tab,fichierSource);
  if (flag == 1){
    selectOpCode(tab,opCode,&i);

    while (strcmp(opCode,TopCode[j]) != 0){/*trouve opCode dans tableau opcode*/
  	j++;
    }

    while (tab[i] != '\0'){/*enregistre les nombre dans les registres 1,2 et 3*/
      if(r1 == -1){r1 = recupNb(registre,tab,&i);}

      else if(r2 == -1){r2 = recupNb(registre,tab,&i);}

      else if(r3 == -1) {r3 = recupNb(registre,tab,&i);}

      i++;
    }

    index = j;
    compteur = 0;

        if(Tequivalent[index][6] == 's'){
          if(Tequivalent[index][11] == 't'){
            if(Tequivalent[index][16] == 'd'){
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r2,10,'s',instructionBinaire);
              replace(r3,15,'t',instructionBinaire);
              replace(r1,20,'d',instructionBinaire);/*normalement instruction binaire est ok*/


            }

            else if(Tequivalent[index][16] == 'i' || Tequivalent[index][16] == 'o'){
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r2,10,'s',instructionBinaire);
              replace(r1,15,'t',instructionBinaire);
    		  /* gérer offset ou immediate*/
            }

            else{
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r2,10,'s',instructionBinaire);
              replace(r1,15,'t',instructionBinaire);
            }
          }
          else{/*pas de t*/
            if(Tequivalent[index][16] == 'o'){
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r1,10,'s',instructionBinaire);
    		  /* gérer offset */
            }
            else{
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r1,10,'s',instructionBinaire);
    		  /* gérer hint*/
            }
          }
        }
        else{/*pas s*/
          if(Tequivalent[index][11] == 't'){
            if(Tequivalent[index][16] == 'd'){
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r2,10,'t',instructionBinaire);
              replace(r1,15,'d',instructionBinaire);
              replace(r3,20,'a',instructionBinaire);
            }
            else if(Tequivalent[index][16] == 'o'){
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r2,10,'t',instructionBinaire);
    		  /* gérer offset et base */
            }
            else{
              strcpy(instructionBinaire,Tequivalent[index]);
              replace(r2,10,'t',instructionBinaire);
    		  /* gérer immediate */
            }
          }
          else if(Tequivalent[index][16] == 'd'){
            strcpy(instructionBinaire,Tequivalent[index]);
              replace(r1,15,'d',instructionBinaire);
          }
          else if(Tequivalent[index][4] == '1'){/*instruction J ou JAL*/
            /* gérer inst_index */
          }
          else if(Tequivalent[index][28] == '0'){/*instruction NOP*/
          }
          else{/*instruction SYSCALL*/
            /*gérer code*/
          }
        }
        
    compteur = 0;

    while(compteur < 8){
      instructionDeci[compteur] = (instructionBinaire[compteur*4] - '0')*8 + (instructionBinaire[compteur*4 +1] - '0')*4 + (instructionBinaire[compteur*4+2] - '0')*2 +(instructionBinaire[compteur*4+3] - '0');
      compteur ++;
    }
    writeInTab(instructionDeci);
  }
  return flag;
}

/*traduit en hexa toutes les instructions
les stocke dans programmeDeci et les ecrit dans le fichierCible*/
void translateToHexa(char nomFichierSource[],char nomFichierCible[]){
  FILE* fichierSource = NULL;
  FILE* fichierDestination = NULL;
  int flag = 1;
  int compteur = 0;
  int compteur2 = 0;

  fichierSource = fopen(nomFichierSource, "r+");
  if(fichierSource == NULL) {
    perror("Probleme ouverture fichier");
    exit(1);
  }

  fichierDestination = fopen(nomFichierCible, "w");
  if(fichierDestination == NULL) {
    perror("Probleme ouverture fichier");
    exit(1);
  }

  while(flag){
    flag = translateToHexaLine(fichierSource);
    global_nombreLigne ++;
  }
  global_nombreLigne --;


  while(compteur<global_nombreLigne){
    compteur2 = 0;
    while (compteur2 < 8){
      fprintf(fichierDestination,"%x",programmeDeci[compteur*8 + compteur2]);
      compteur2 ++;
    }
    fprintf(fichierDestination,"\n");
    compteur ++;
  }

  fclose (fichierSource);
  fclose(fichierDestination);
}
