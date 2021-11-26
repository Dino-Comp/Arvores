/*UNIVERSIDADE FEDERAL DO AMAZONAS
LAURA AGUIAR MARTINHO
21952064
ALGORITMOS E ESTRUTURAS DE DADOS II
PROF EDSON NASCIMENTO
ARVORE PATRICIA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvP.h"

int main(int argc, char** argv) {

	FILE *file;
	if((file = fopen (argv[1],"r"))==NULL){
		printf ("\nSem arquivo");
  }

  tipoPAT raiz = NULL;	int linha = 1;

	while(!feof(file)){

		String palavra = malloc(sizeof(char)*21);
		String frase = malloc(sizeof(char)*100);
    char caractere[21];
		frase = fgets(frase, 100, file);

    //definir um separador que quando surgir na string ela é dividida
		String letras = strtok(frase, " ");

		while(letras!=NULL){
      //funcao da biblioteca string strcpy copia caractere no lugar da letras
			strcpy(caractere, letras);
      //percorre o vetor char
			for(int i=0; i<=strlen(caractere); i++){
        //is upper funcao da ctype, checar se e maiuscula (uppercase)
				if(isupper(caractere[i])) caractere[i] = tolower(caractere[i]);//islower para transformar em minuscula (lowercase)
				if(!isalpha(caractere[i])) ignoraSimbolo(caractere, i);//isalpha checa se e letras do alfabeto, se nao, ignorar caracteres
			}strcpy(letras, caractere);

      //apenas palavras com mais de 3 letrass
			if(strlen(letras)>=3) raiz = Insere(letras, raiz, linha);
			letras = strtok(NULL, " ");
		}
		linha++;//contador de linhas
	}
  fclose(file);
  Ordena(raiz);
	return 0;

}
