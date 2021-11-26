/*
ATIVIDADE 1 - ARVORES BINARIAS
LAURA AGUIAR MARTINHO - 21952064
ALGORITMOS E ESTRUTURAS DE DADOS 2
*/

#include <stdio.h>
#include <stdlib.h>

//declaracao para os nos da arvore
//variavel x para valor atribuido aos nos
//filhos direito e esquerdo
typedef struct No{
	int dado;
	struct No *esquerdo;
	struct No *direito;
}tipoNo;
//definir ponteiro  para tipo arvore composto da strutura No
typedef struct No *ArvBin;
//deixa mais claro e poupa usar dois ponteiros tipoNo ao longo do codigo

//funcao que aloca espaco para nova entrada de elementomento
//(ela cria uma arvore onde serao inseridos posteriormente elementomentos)
ArvBin *cria_AB(){
  ArvBin *raiz = (ArvBin *)malloc(sizeof(ArvBin));
  if(raiz!=NULL){
    *raiz = NULL;
  }
  return raiz;
}

//funcao auxiliar que aloca novo no com dados tipo inteiro e espacos para direito ou esquerdo
tipoNo *noInt(int dado){
  tipoNo *novo = (tipoNo *)malloc(sizeof(tipoNo));
  novo->dado = dado;
  novo->esquerdo = NULL;
  novo->direito = NULL;
  return novo;
}

//funcao para inserir valores
void insere(ArvBin *raiz, int valor){
  if(*raiz == NULL){
    tipoNo *novo = noInt(valor);
    *raiz = novo;
    return;
  }
  if(valor == (*raiz)->dado){
    return;
  }
  if(valor < (*raiz)->dado){
    insere(&(*raiz)->esquerdo, valor);
  }else if(valor > (*raiz)->dado){
    insere(&(*raiz)->direito, valor);
  }
}

//funcoes auxiliares para fila que sera necessaria
/*#################################################*/
typedef struct elemento tipoEle;
struct elemento{
	void *informacao;
	tipoEle *prox;
};
typedef struct filaneutra tipoFN;
struct filaneutra{
	tipoEle *primeiro;
	tipoEle *ult;
};
tipoEle *criaElemento(void *informacao){
		tipoEle *e = malloc(sizeof(tipoEle));
		e->informacao = informacao;
		e->prox = NULL;
		return e;
}
tipoFN *criarfilaneutra(){
	tipoFN *filaneutra = malloc(sizeof(tipoFN));
	filaneutra->primeiro = NULL;
	filaneutra->ult = NULL;
	return filaneutra;
}
void enfileirar(tipoFN *filaneutra, void *novo){
	tipoEle *elemento = criaElemento(novo);
	if(filaneutra->primeiro == NULL){
		filaneutra->primeiro = elemento;
		filaneutra->ult=elemento;
	}else{
		tipoEle* ultimo = filaneutra->ult;
		ultimo->prox = elemento;
		filaneutra->ult= elemento;
	}
}
tipoEle *desenfileirar(tipoFN *filaneutra){
	tipoEle* primeiro = filaneutra->primeiro;
	if (primeiro != NULL){
		void *informacao = primeiro->informacao;
		if(filaneutra->primeiro == filaneutra->ult){
			filaneutra->primeiro=NULL;
			filaneutra->ult = NULL;
		}else{// caso geral
			filaneutra->primeiro = primeiro->prox;
		}
		return primeiro;
	}

}
/*#################################################*/


/*----------------- EXERCICIO 1 -----------------*/
/*
a) Escreva uma função que realiza um percurso em largura na árvore. Você pode usar uma filaneutra auxiliar.
  void largura(No* Raiz);
*/
void largura(ArvBin *raiz){
    if(*raiz==NULL) return;

    tipoFN *filaneutra = criarfilaneutra();
    tipoNo* no_aux;
    tipoEle* elementomento;

    enfileirar(filaneutra, *raiz);// inserindo o primeiro da arvore

    while(filaneutra->primeiro!=NULL){ //enquanto existir elementomentos na filaneutra...
        elementomento = desenfileirar(filaneutra);
        if(elementomento->informacao!=NULL){
            no_aux = (tipoNo*) elementomento->informacao;
            printf("%d ", no_aux->dado);

            if(no_aux->esquerdo!=NULL) enfileirar(filaneutra, no_aux->esquerdo);
            if(no_aux->direito!=NULL) enfileirar(filaneutra, no_aux->direito);
        }
    }
}


/*
b) Escreva uma função recursiva que conta o número de folhas em uma árvore binária.
  int conta folhas(No* Raiz);
*/
int contaFolhas(ArvBin raiz){
   if(raiz == NULL)
        return 0;
   if(raiz->esquerdo == NULL && raiz->direito == NULL)
        return 1;
   return contaFolhas(raiz->esquerdo) + contaFolhas(raiz->direito);
}


/*
c) Escreva uma função recursiva que verifica se um valor (Valor) está presente na árvore (Raiz) (considere que não há nenhuma garantia a respeito da ordem dos valores na árvore).
  int busca(No* Raiz, int Valor);
*/
int Busca(ArvBin raiz, int valor){
  if(raiz!=NULL){
    if(raiz->dado == valor){
      return 1;
    }else if(Busca(raiz->esquerdo, valor)){
      return 1;
    }else{
      return Busca(raiz->direito, valor);
    }
  }
  return 0;
}

/*
d) Escreva uma função espelho(Raiz) que retorna uma nova árvore Raiz, mas com as sub-árvores esquerdo e direito de todos os nós trocadas. A árvore original não deve ser alterada.
  No* espelho(No* Raiz);
*/
tipoNo *espelho(ArvBin raiz){
  if (raiz!=NULL){
    tipoNo *aux;
    // espelha sub arvores
    espelho(raiz->esquerdo);
    espelho(raiz->direito);
    // troca ponteiros
    aux = raiz->esquerdo;
    raiz->esquerdo = raiz->direito;
    raiz->direito = aux;
  }
  return raiz;
}

/*----------------- EXERCICIO 3 -----------------*/
/*
a) Escreva uma função não-recursiva que recebe uma árvore binária de busca Raiz como parâmetro e retorna o apontador para o nó cuja chave possui o valor mínimo ou NULL caso árvore esteja vazia.
  No* minimo(No* Raiz);
*/
int minimo(ArvBin raiz){
  ArvBin atual = raiz;
  while (atual->esquerdo != NULL) {
    atual = atual->esquerdo;
  }
  return(atual->dado);
}


/*
b) Escreva uma função não-recursiva que verifica a existência de algum elementomento com chave negativa na árvore.
  int existe chave negativa(No* Raiz);
*/
int existe_chave_negativa(ArvBin raiz){
  if(raiz!=NULL){
    if(raiz->dado < 0){
      return 1;
    }else if(existe_chave_negativa(raiz->esquerdo)){
      return 1;
    }else{
      return existe_chave_negativa(raiz->direito);
    }
  }
return 0;
}


/*
c) Escreva uma função que verifica se uma árvore de busca é válida.
  int verifica busca(No* Raiz);
*/
//funcao auxiliar
int maximo(ArvBin raiz){
  ArvBin atual = raiz;
  while (atual->direito != NULL) {
    atual = atual->direito;
  }
  return(atual->dado);
}

int verificaBusca(ArvBin raiz){
  if (raiz==NULL) {
    return 1;
  }
 // se o min da esquerdo for > no
  if (raiz->esquerdo!=NULL && minimo(raiz->esquerdo) > raiz->dado){
    return 0;
  }
 // se o max da esquerdo for <= no
  if (raiz->direito!=NULL && maximo(raiz->direito) <= raiz->dado){
    return 0 ;
  }
 //se nenhum for avore de busca
  if (!verificaBusca(raiz->esquerdo) || !verificaBusca(raiz->direito)){
    return 0 ;
  }
 return 1;
}

//funcao printar em ordem
void printOrd(ArvBin *raiz)
{
	if (raiz == NULL)
		return;

	if (*raiz != NULL)
	{
		printOrd(&((*raiz)->esquerdo));
		printf("%d ", (*raiz)->dado);
		printOrd(&((*raiz)->direito));
	}
}

int main(){
  ArvBin *raiz = cria_AB();
  int entrada; int buscado;
  printf("Digite os elementos inteiros da arvore, excluindo o zero (0)\n(numero zero condicao de parada da leitura):");

  scanf("%d", &entrada);
  while (entrada != 0){
    insere(raiz, entrada);
    scanf("%d", &entrada);
  }

   printf("Digite um numero pra verificar se ele existe na sua arvore:");
  scanf("%d", &buscado);

printf("\n\nEXERCICIO 1\n\n");
printf("------------------------------------\n");
printf("letra a)");
 printf("percorrer em largura:\n");
 largura(raiz);
 printf("\n");

printf("------------------------------------\n");
printf("letra b)");
printf("Num folhas:");
  printf("%d\n",contaFolhas(*raiz));

printf("------------------------------------\n");
printf("letrac)");
printf("é arvore de busca?:\n");
  if(verificaBusca(*raiz)){
    printf("SIM\n");
  }else{
    printf("NAO\n");
  }

printf("------------------------------------\n");
printf("letra d)");

  printf("espelho:\n");
  espelho(*raiz);
  printOrd(raiz);
  printf("\n");

printf("------------------------------------\n");
printf("\n\nEXERCICIO 3\n\n");
printf("------------------------------------\n");
printf("letra a)");
  printf("elementomento minimo:\n");
  printf("%d\n",minimo(*raiz));

printf("------------------------------------\n");
printf("letra b)");
 printf("Existe negativo?:\n");
  if(existe_chave_negativa(*raiz)){
    printf("SIM\n");
  }else{
    printf("NAO\n");
  }

printf("------------------------------------\n");
printf("letra c)");
  printf("Tem o numero %d?:\n", buscado);
  if(Busca(*raiz, buscado)){
    printf("SIM\n");
  }else{
    printf("NAO\n");
  }

printf("------------------------------------\n");




  return 0;

  }
