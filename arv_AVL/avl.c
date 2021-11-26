#include <stdio.h>
#include <stdlib.h>
/*
Uma árvore binária balanceada é aquela em que, para
qualquer nó, suas sub-árvores esquerda e direita têm
a mesma altura
*/
//estrutura tipo No que compoe a AVL
typedef struct No{
  int info, altura;
  struct No *esquerdo;
  struct No *direito;
}tipoAVL;
//cria novo No
tipoAVL *criaAVL(int x){
  tipoAVL *novo = malloc(sizeof(tipoAVL));
  novo->altura=0;
  novo->info = x;
  novo->esquerdo = NULL;
  novo->direito = NULL;
  return novo;
}
//funcao altura no auxiliar
int altura(tipoAVL *raiz){
  int alt_esq, alt_dir;
  if(raiz == NULL){
    return 0;
  }
  if(raiz->esquerdo == NULL){
    alt_esq = 0;
  }else{
    alt_esq = 1 + raiz -> esquerdo -> altura;
  }
  if(raiz->direito == NULL){
    alt_dir = 0;
  }else{
    alt_dir = 1 + raiz->direito -> altura;
  }
  if(alt_esq > alt_dir){
    return alt_esq;
  }
  return alt_dir;
}
//implementacoes das rotações simples e duplas para etapa de rebalanceamento
//rotacoes simples: no desbalanceado (pai), seu filho e o seu neto estão todos no mesmo sentido de inclinação
//rotacao simples direita
tipoAVL *rotaDir(tipoAVL *raiz){
  tipoAVL *aux = raiz->esquerdo;//inserindo na sub-árvore da esquerda do filho esq
  //no desbalanceado
  //rotacoes a esquerda
  raiz->esquerdo = aux->direito;
  aux->direito = raiz;
  raiz->altura = altura(raiz);
  aux->altura = altura(aux);
  printf("Rotacao a direita: ");
  printf("troca de %d por %d\n",raiz->info,aux->info);
  return aux;
}
//rotacao simples esquerda
tipoAVL *rotaEsq(tipoAVL *raiz){
  tipoAVL *aux = raiz->direito;
  raiz->direito = aux->esquerdo;
  aux->esquerdo = raiz;
  raiz->altura = altura(raiz);
  aux->altura = altura(aux);
  printf("Rotacao a esquerda: ");
  printf("troca de %d por %d\n",raiz->info,aux->info);
  return aux;
}
//rotacos duplas: no desbalanceado (pai) e seu filho estão inclinados no sentido inverso ao neto - equivale a duas rotações simples.
//rotacao dupla direita
tipoAVL *rotaDDir(tipoAVL *raiz){
  raiz = rotaEsq(raiz);
  return raiz;
}
//rotacao dupla esquerda
tipoAVL *rotaDEsq(tipoAVL *raiz){
  raiz = rotaDir(raiz);
  return raiz;
}
//rotacao esq-direita
tipoAVL *rotaEsqDir(tipoAVL *raiz){
  raiz -> esquerdo = rotaEsq(raiz->esquerdo);
  raiz = rotaDir(raiz);
  return raiz;
}
//rota dir-esq
tipoAVL *rotaDirEsq(tipoAVL *raiz){
  raiz->direito = rotaDir(raiz->direito);
  raiz = rotaEsq(raiz);
  return raiz;
}
//calcula fatorBal
/*
FB(n) = altura(sub arvore dir) – altura(sub arvor esq)
se FB(n) = 0, as duas sub-árvores têm a mesma
altura
se FB(n) = -1, a sub-árvore esquerda é mais alta que
a direita em 1
se FB(n) = +1, a sub-árvore direita é mais alta que a
esquerda em 1
*/
int fatorBal(tipoAVL *raiz){
  int alt_esq, alt_dir;
  if(raiz==NULL){
    return 0;
  }
  if (raiz->esquerdo == NULL){
    alt_esq = 0;
  }else{
    alt_esq = 1+raiz->esquerdo->altura;
  }
  if(raiz->direito == NULL){
    alt_dir = 0;
  }else{
    alt_dir = 1+raiz->direito->altura;
  }
  return (alt_esq - alt_dir);
}

//insercao elementos na avl
tipoAVL *insere(tipoAVL *raiz, int x){
  if(raiz == NULL){ raiz = criaAVL(x); }
  else{
    if(x > raiz->info){
      raiz->direito = insere(raiz->direito, x);
      if(fatorBal(raiz) == -2){
        if(x > raiz->direito->info){ raiz = rotaDDir(raiz); }
        else{ raiz = rotaDirEsq(raiz); }
      }
    }
    else{
      if(x < raiz->info){
        raiz -> esquerdo = insere(raiz->esquerdo, x);
        if(fatorBal(raiz) == 2){
          if(x < raiz->esquerdo->info){ raiz = rotaDEsq(raiz); }
          else{ raiz = rotaEsqDir(raiz); }
        }
      }
    }
  }
  raiz -> altura = altura(raiz);
  return raiz;
}
void inOrdem(tipoAVL *raiz){
  if(raiz != NULL){
    inOrdem(raiz->esquerdo);
    printf(" %d (%d)\n", raiz->info, fatorBal(raiz));
    inOrdem(raiz->direito);
  }
}

//##################################################

/*---------- EXERCICIO 1 ----------*/
/*
a) Mostrar as rotações necessárias para a construção da seguinte árvore AVL: 5, 4, 3, 6, 7 e 8
*/
int main(){
  printf("\n-------------------------------");
  printf("\nAtividade Árvores Binárias AVL");
  printf("\n-------------------------------\n");

//##################################################

  printf(">> EXERCICIO 1\n");

//##################################################

  printf("a) Mostrar as rotações necessárias para a construção da seguinte árvore AVL: 5, 4, 3, 6, 7 e 8\n");

 printf("\nALV: 5 4 3 6 7 8");
  printf("\n\n");
  tipoAVL *raiz = NULL;
  raiz = insere(raiz, 5);
  raiz = insere(raiz, 4);
  raiz = insere(raiz, 3);
  raiz = insere(raiz, 6);
  raiz = insere(raiz, 7);
  raiz = insere(raiz, 8);

//##################################################

  printf("\nb) Defina em C uma estrutura de dados que possa representar uma árvore AVL\n");

  printf("\ntypedef struct No{\n\tint info, altura;\n\tstruct No *esquerdo;\n\tstruct No *direito;\n}tipoAVL;\n");
//##################################################

printf("\nc) Implemente procedimento para calcular FB;\n(consta no codigo)\n");
//##################################################

  printf("\nd) Implemente procedimento que percorra a árvore e imprima o fator de balanceamento de cada nó em uma ordem infixada com o seguinte formato:\nn(FB), onde n é uma raiz de subárvore e FB o fator de balanceamento.\n");
  printf("\nExemplo com a arvore 5 4 3 6 7 8\n n(FB):\n----------\n");
   inOrdem(raiz);
 //##################################################

  printf("\nf) Implemente os procedimentos de rotação simples (direita e esquerda)\n(consta no codigo)\n");
  return 0;
}
