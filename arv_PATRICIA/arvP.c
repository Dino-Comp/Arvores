/*UNIVERSIDADE FEDERAL DO AMAZONAS
LAURA AGUIAR MARTINHO
21952064
ALGORITMOS E ESTRUTURAS DE DADOS II
PROF EDSON NASCIMENTO
ARVORE PATRICIA*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvP.h"

//retorna o i-esimo digito do no a partir da esquerda
char Digito(short i, String no){
  if(i>strlen(no)){
    return 0;
  }else{
    return no[i];
  }
}

//auxiliar de comparacao simples p/ alfabeto, se for um menor ou igual
int Comparou(char a, char b){
  if(a == 0 || b == 0 ){
    return 0;
  }
  if(a <= b){
    return 1;
  }else{
    return 0;
  }
}

//verifica se no eh Folha
int eFolha(tipoPAT no){
  if(no->tipo == Folha){
    return 1;
  }else{
    return 0;
  }
}

//cria um novo no para cada tipo
//com filhos
tipoPAT criaPai(short i, tipoPAT *Esquerdo,  tipoPAT *Direito, char Caractere, int linha){
  tipoPAT no = (tipoPAT)malloc(sizeof(tNoPAT));
  no->tipo = Pai;
  no->NO.noPai.Esquerdo = *Esquerdo;
  no->NO.noPai.Direito = *Direito;
  no->NO.noPai.Indice = i;
  no->NO.noPai.Caractere = Caractere;
	no->linhas = criarLista();
	inserirLista(no->linhas, linha);//armnazena valor linha onde se encontra o ponteiro da palavra
  return no;
}
//sem filhos
tipoPAT criaFolha(String palavra, int linha){
  tipoPAT no;
  no = (tipoPAT)malloc(sizeof(tNoPAT));
  no->tipo = Folha;
  no->NO.Dado = palavra;
	no->linhas = criarLista();
	inserirLista(no->linhas, linha);
  return no;
}

//busca palavra e verifica se existe na arvore
tipoPAT Busca(String palavra, tipoPAT arv){
  if(eFolha(arv)){
    if(strncmp(palavra, arv->NO.Dado, strlen(palavra)) == 0){
      return arv;
    }else{
      return NULL;
    }
  }
  if (Comparou(Digito(arv->NO.noPai.Indice, palavra),arv->NO.noPai.Caractere)){
    return Busca(palavra, arv->NO.noPai.Esquerdo);
  }else{
    return Busca(palavra, arv->NO.noPai.Direito);
  }

}

//imprimir a palavra
void mostrarPalavra(tipoPAT no){
  if(no == NULL){
    printf("Sem palavras, vazio\n");
  }else if(no->tipo == Folha){
    printf("\n %s",no->NO.Dado);
		imprimirLista((no->linhas)->primeiro);//imprime as linhas tambem
  }
}

//funcao auxiliar insercao, inserir entre chaves
tipoPAT InsereAux(String palavra, tipoPAT arv, short i, int linha){
  tipoPAT no;
  char caractere;
  if (eFolha(arv) || i < arv->NO.noPai.Indice){
    if(eFolha(arv)){
      //se identificou folha, retorna o i-esimo digito do no
      caractere = Digito(i,arv->NO.Dado);
    }else{
      //se nao for folha se torna no com filhos
      caractere = arv->NO.noPai.Caractere;
    }
    //se indice for menor que o pai, cria folha nova
    no = criaFolha(palavra, linha);
    //quando confirma menor ou igual
    if (Comparou(Digito(i, palavra),caractere)){
      //cria espaco pra filhos no noh
      return (criaPai(i,&no, &arv,Digito(i, palavra), linha));
    }else{
      //se nao cria novo pai na arvore
      return (criaPai(i,&arv,&no,caractere, linha));
    }
  }else{
    //verificar comparacoes no pai e palavras
    if(Comparou(Digito((arv)->NO.noPai.Indice, palavra),(arv)->NO.noPai.Caractere)){
      (arv)->NO.noPai.Esquerdo = InsereAux(palavra,(arv)->NO.noPai.Esquerdo,i, linha);
    }else{
      (arv)->NO.noPai.Direito = InsereAux(palavra,(arv)->NO.noPai.Direito,i, linha);
    }
    return (arv);
  }
}

//funcao inserir valores
tipoPAT Insere(String palavra, tipoPAT arv, int linha){
  tipoPAT no;
  int i;
  if(arv == NULL){
    return (criaFolha(palavra, linha));
  }else{
    no = arv;//faz o no ser raiz da arv
    while (!eFolha(no)){
      if(Comparou(Digito(no->NO.noPai.Indice,palavra),no->NO.noPai.Caractere)){
        no = no->NO.noPai.Esquerdo;
      }else{
        no = no->NO.noPai.Direito;
      }
    }
    i = 0;
    //quando achar o primeiro caracter diferente
    if(strlen(palavra)>strlen(no->NO.Dado)){
      while ((i <= strlen(palavra)) && (Digito(i, palavra) == Digito(i, no->NO.Dado)))
        i++;
        if (i >= strlen(palavra)){
					inserirLista(no->linhas, linha);
          //inserir valorLinha na linha e retornar raiz
          return (arv);
        }else{
          //inserir palavra
          return (InsereAux(palavra, arv, i, linha));
        }
    }else{
      while((i <= strlen(no->NO.Dado)) && (Digito(i, palavra) == Digito(i, no->NO.Dado)))
        i++;
        if (i >= strlen(no->NO.Dado)){
					inserirLista(no->linhas, linha);
          return (arv);
        }else{
          return (InsereAux(palavra, arv, i, linha));
        }
      }
    }
}

//ordenar palavras em ordem alfabetica recursivamente
void Ordena(tipoPAT arv){
  if(arv == NULL){
    return;
  }
  if(!eFolha(arv)){
    Ordena(arv->NO.noPai.Esquerdo);
  }
  mostrarPalavra(arv);
  if(!eFolha(arv)){
    Ordena(arv->NO.noPai.Direito);
  }
}

//ignora caracteres simbolicos
void ignoraSimbolo(String palavra, int indice){
	for(int i=0; i<strlen(palavra); i++){
    if(i==indice){
      if((i+1) <= strlen(palavra)){
        palavra[i] = palavra[i+1];
      }
      indice = i+1;
    }
	}
}

//funcoes para lista usada no codigo para armazenar linhas contadas
//cria uma lista
tipoLista *criarLista(){
		tipoLista *aux = malloc(sizeof(tipoLista));
		aux->primeiro = NULL;
		aux->ultimo = NULL;
		return aux;
}
//insere valores na lista
void inserirLista(tipoLista *lista, int dado){
	if(lista->primeiro == NULL){
		tipoEle *aux = malloc(sizeof(tipoLista));
		aux->proximo = NULL;
		aux->dado = dado;
		lista->primeiro = aux;
	}else{
		tipoEle *temp = lista->primeiro;
		while(temp->proximo != NULL){
			temp = temp->proximo;
		}
		tipoEle *aux = malloc(sizeof(tipoEle));
		aux->dado = dado;
		aux->proximo = NULL;
		temp->proximo = aux;
		lista->ultimo = aux;
	}

}
//mostra linhas
void imprimirLista(tipoEle *primeiro){
	if(primeiro == NULL){
		return;
	}else{
		printf(" - na linha %d;", primeiro->dado);
		imprimirLista(primeiro->proximo);
	}
}
