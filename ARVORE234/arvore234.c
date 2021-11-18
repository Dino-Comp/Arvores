//UNIVERSIDADE FEDERAL DO AMAZONAS
//LAURA AGUIAR MARTINHO - 21952064
//AED2 - TRABALHO PRATICO ARVORES 2-3-4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXIMO 400
#include"arvore234.h"

//funcao para verificar se o no e uma raiz
int eRaiz(tipoNo** atual){
  //comparar no pai com nulo
  if((*atual)->pai ==NULL){
    return 1;
  }else{
    return 0;
  }
}


tipoNo* achaFolha(tipoNo** atual, int elemento){
  int tam = (*atual)->tamanho;

  if((*atual)->ponteiros[0] == NULL){//se for folha
    return 0;
  }else{
    int i=0;
    while( i<tam && elemento > (*atual)->chave[i] ) {
      i++;
    }
    return(*atual)->ponteiros[i];
  }
}


void buscaAux(tipoNo* raiz, int ele, int nivel){
  int i; int tam = raiz->tamanho;
  for(i=0; i<tam; i++){
    if(ele<raiz->chave[i]){
      break;
    }else{
      if(ele == raiz->chave[i]){
        printf("Chave %d estava no nivel %d da arvore e na posicao %d do no\n",ele, nivel,i);
        //remover aqui
        return;
      }
    }
  }
  if(!raiz->ponteiros[0]){
    printf(" o valor %d nao encontra-se na arvore.\n",ele);
  }else{
    if(i==tam){
     i--;
    }
    buscaAux(raiz->ponteiros[i], ele,nivel+1);
  }
}

void busca(Arv234 *arvore, int ele){
  buscaAux(arvore->raiz, ele, 0);
}


tipoNo *criarGalho(tipoNo* pai){
  tipoNo *galho = malloc(sizeof(tipoNo));
	for(int i=0;i<5;i++) galho->ponteiros[i] = NULL;
  for(int i=0; i<4; i++) galho->chave[i] = 0;
	galho->tamanho = 0;
	galho->pai = pai;
  return galho;
}

Arv234* criaArv(){
  Arv234* aux = malloc(sizeof(Arv234));
  aux->raiz = criarGalho(NULL);
  return aux;
}

void distribuiFilho(tipoNo *pai, tipoNo *filho){
  int i, j;
  i=0;
  while(pai->ponteiros[i]){//saber ultima posicao
    i++;
  }
  tipoNo *aux;
  //ordenar
  pai->ponteiros[i] = filho;
  int tam = i+1;
  for(i=0; i<tam-1; i++){
    int tami= pai->ponteiros[i]->tamanho-1;
    for(j=i+1; j<tam;j++){
      int tamj=pai->ponteiros[j]->tamanho-1;
      //verificar tamanho das chaves
      if(pai->ponteiros[j]->chave[tamj] < pai->ponteiros[i]->chave[tami]){
        aux=pai->ponteiros[j];
        pai->ponteiros[j]=pai->ponteiros[i];
        pai->ponteiros[i]=aux;
      }
    }
  }
}
 //famosa split
void dividir(tipoNo **esquerdo, Arv234 *arv){
  int i, dir, esq;
  tipoNo *aux, *pai, *direito;
  //onde divide  o esquerdo - dir
  int mediana = (*esquerdo)->chave[1];
  //redefinicoes
  (*esquerdo)->tamanho = 1;
  (*esquerdo)->chave[1]=0;
  //se esquerdo nao tiver pai
  if(!(*esquerdo)->pai){
    //cria um galho e passa a raiz pro pai
    pai = criarGalho((*esquerdo)->pai);
    arv->raiz = pai;
    pai->ponteiros[0] = *esquerdo;
  } else {
    //se nao, este e o pai
    pai = (*esquerdo)->pai;
  }
  (*esquerdo)->pai = pai;
  //cria galho pro direito e insira seus valores
  direito = criarGalho(pai);
  insereValor(&direito, (*esquerdo)->chave[2],arv);
  insereValor(&direito, (*esquerdo)->chave[3],arv);
  //redefinicoes
  (*esquerdo)->chave[2]=0;
  (*esquerdo)->chave[3]=0;
  //distribua seus filhos ao pai e insira
  distribuiFilho(pai, direito);
  insereValor(&pai, mediana, arv);

  i=0;
  esq = 0;
  dir = 0;
  aux = (*esquerdo)->ponteiros[i];
  //enquanto esqurdo tiver filhos
  while (i < 5 && aux) {
    //trocas
    (*esquerdo)->ponteiros[i] = NULL;
    if(aux->chave[(aux->tamanho)-1] > mediana) {
      direito->ponteiros[dir] = aux;
      dir++;
    } else { //se folha
      (*esquerdo)->ponteiros[esq] = aux;
      esq++;
    }
    i++;
    aux = (*esquerdo)->ponteiros[i];
  }

}

//funcao auxiliar
void insereValor(tipoNo **atual, int elemento, Arv234 *arv){
  int tam = (*atual)->tamanho;
  (*atual)->chave[tam] = elemento;
  (*atual)->tamanho++;
  ordena((*atual)->chave, (*atual)->tamanho);
  //inseriu e ordenou, testar limites:
  if((*atual)->tamanho==4){
    dividir(atual, arv);
  }
}

//funcao inserir valores
void inserir(Arv234* arv, int elemento){
  tipoNo *noAtual = arv->raiz;
  tipoNo *noAnterior;
  int i=0;
  do{//nao e folha
    noAnterior = noAtual;
    noAtual = achaFolha(&noAnterior, elemento);
  } while(noAtual);
  //e folha
  insereValor(&noAnterior, elemento,arv);
}

//ordena vetor simples
void ordena(int vetor[], int tam){
  int aux;
  int i, j;
  for(i=0; i<tam-1; i++){
    for(j=i+1; j<tam;j++){
      if(vetor[j]<vetor[i]){
        aux=vetor[j];
        vetor[j]=vetor[i];
        vetor[i]=aux;
      }
    }
  }
}

//imprimir
void imprimir(Arv234 *arvore) {
  imprimir_Aux(arvore->raiz, 0);
}

void imprimir_Aux(tipoNo *atual, int nivel){
    int tam = atual->tamanho;
    int i;
    for(i= 0; i<tam;i++){
      printf("%d | %d | %d\n", nivel, i, atual->chave[i]);
    }
    i=0;
    while (i < 4 && atual->ponteiros[i]) {
      imprimir_Aux(atual->ponteiros[i], nivel + 1);
      i++;
    }
}


//achar o anterior quando remover o no
tipoNo* sucessor(tipoNo* atual, int elemento){
  Arv234 *arv;
  if(!((atual)->ponteiros[0] == NULL)){
    for(int i = 0; i<atual->tamanho;i++){
      if (atual->chave[i] == elemento) {
        atual = atual->ponteiros[i+1];
        break;
      }
    }
  }
  while(!((atual)->ponteiros[0] == NULL)){
    atual = atual->ponteiros[0];
  }
  return atual;
}

//excluir auxiliar
void remova(tipoNo *atual, int elemento){
  int posicao;
  for(int i=0;i<atual->tamanho;i++){
    if(atual->chave[i]==elemento){
      posicao=i;
    }
  }
  for(int j=posicao; j<atual->tamanho-1; j++)
    atual->chave[j]=atual->chave[j+1];

  atual->tamanho--;
}

//
int rotacao(tipoNo *atual){
  Arv234 *arv;
  int posicao;
  tipoNo *paiNo = atual->pai;
  tipoNo *irmao;
  if(!eRaiz(&atual)){
    for(int i = 0; i<=paiNo->tamanho;i++)
      if(paiNo->ponteiros[i]==atual){
        posicao=i;
        break;
      }

    int tamIrmao;
    if(posicao>0){
      irmao = paiNo->ponteiros[posicao-1];
      tamIrmao = irmao->tamanho;
      if(irmao->tamanho>1){
        insereValor(&atual, paiNo->chave[posicao-1],arv);
        paiNo->chave[posicao-1] = irmao->chave[tamIrmao-1];
        remova(irmao, irmao->chave[tamIrmao-1]);
        return 1;
      }
    }

    if(posicao<paiNo->tamanho){
      irmao = paiNo->ponteiros[posicao+1];
      if(irmao->tamanho>1){
        insereValor(&atual, paiNo->chave[posicao],arv);
        paiNo->chave[posicao] = irmao->chave[0];
        remova(irmao, irmao->chave[0]);
        return 1;
      }
    }
  }
  return 0;
}




//remove aplicando rotacao
void remover(tipoNo* raiz, int elemento){
  tipoNo *atual;// = busca(raiz, elemento);
  tipoNo *aux;
  int trocado;
Arv234 *arv;
  if(atual!=NULL){
    //acha folha com sucessor mais proximo do valor
    if(!((atual)->ponteiros[0] == NULL)){
      for(int i=0; i<atual->tamanho;i++){
        if(atual->chave[i]==elemento){
          aux=sucessor(atual,elemento);
          atual->chave[i]=aux->chave[0];
          trocado=atual->chave[i];
          break;
        }
      }
      atual=aux;
    //  atual sera a folha que contem o trocado
      remova(atual,trocado);
      //remove trocado do atual
    }else{
      //remove atual do no
      remova(atual,elemento);
    }
  }
  while(1){
    if(atual->tamanho!=0){
      return ;
      //no caso de nao haver um irmao de no com chaves entao nao executa
    }else if(rotacao(atual)){
      return;
    }else{
      tipoNo *paiNo  = atual->pai;
      if (paiNo->tamanho==1){
        if(paiNo->ponteiros[0]!=atual)
          insereValor(&paiNo, (paiNo->ponteiros[0])->chave[0],arv);
        if(paiNo->ponteiros[1]!=atual)
          insereValor(&paiNo, (paiNo->ponteiros[1])->chave[0],arv);
        atual = paiNo;
        //libera memoria
        atual->ponteiros[0]=0;
        return;
      }else{
        int posicao;
        tipoNo *irmao;
        //procura em qual posição de filho está o atual.
        for(int i=0; i<=paiNo->tamanho;i++){
          if(paiNo->ponteiros[i]==atual){
            posicao=i;
            break;
          }
        }//se não for a ultima posição rota para a direita
        if(posicao<paiNo->tamanho){
          irmao = paiNo->ponteiros[posicao+1];
          insereValor(&atual, paiNo->chave[posicao],arv);
          insereValor(&atual, irmao->chave[0],arv);
          remova(paiNo, paiNo->chave[posicao]);
          for(int i = posicao+1; i<paiNo->tamanho+1; i++){
            paiNo->ponteiros[i]=paiNo->ponteiros[i+1];
          }
          return;
          	//senão rota para a esquerda
        }else{
          irmao=paiNo->ponteiros[posicao-1];
          insereValor(&atual, paiNo->chave[posicao-1],arv);
          insereValor(&atual, irmao->chave[0],arv);
          paiNo->ponteiros[posicao-1]=atual;
          remova(paiNo, paiNo->chave[posicao-1]);
          return;
        }
      }
    }
  }
}

int main(){

   srand((unsigned)time(NULL));
  //
  Arv234 *arvore = criaArv();



	int numero;

	// Insere 300 numeros
  for(int i=0; i<300; i++){
		numero = rand()% MAXIMO;
    inserir(arvore, numero);
	}
  imprimir(arvore);


  //
	//Gerando chaves random e verificando se está na Árvore 234
	for(int i=0; i<80; i++){
	  numero = rand()% MAXIMO;
    busca(arvore, numero);
  }



  return 0;
}
