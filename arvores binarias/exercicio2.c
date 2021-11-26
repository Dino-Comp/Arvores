/*
ATIVIDADE 1 - ARVORES BINARIAS
LAURA AGUIAR MARTINHO - 21952064
ALGORITMOS E ESTRUTURAS DE DADOS 2
*/

#include <stdio.h>
#include <stdlib.h>


//declaracao para os nos da arvore
//variavel char para caractere atribuido aos nos
//filhos direito e esquerdo

typedef struct no* ArvBin;
typedef struct no tipoNo;

struct no{
    char dado;
    tipoNo *esquerda;
    tipoNo *direita;
};


ArvBin *criaArvBin(){
	ArvBin *raiz = malloc(sizeof(ArvBin));
	if(raiz!=NULL) {
    *raiz = NULL;
  }
	return raiz;
}


tipoNo *criaChar(char dado){
    tipoNo *no = malloc(sizeof(tipoNo));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

void printPosOrd(ArvBin *raiz){
	if(*raiz==NULL) return;

	if(*raiz!=NULL){
		printPosOrd(&((*raiz)->esquerda));
		printPosOrd(&((*raiz)->direita));
		printf("%c ", (*raiz)->dado);
	}
}

void printPreOrd(ArvBin *raiz){
	if(*raiz==NULL) return;

	if(*raiz!=NULL){
		printf("%c ", (*raiz)->dado);
		printPreOrd(&((*raiz)->esquerda));
		printPreOrd(&((*raiz)->direita));
	}
}

// verifica se letra valida
int letra(tipoNo *no){
  if(no!=NULL){
      if(no->dado >= 97 && no->dado <= 122) return 1;
  }
  return 0;
}

// verifica operador
int operador(tipoNo *no){
  int operadores[5] = {42,43,45,47,94};
  if(no!=NULL)
      for(int i=0; i<5; i++)
          if(operadores[i]==no->dado) return 1;
return 0;
}

// verifica no com letra e operador
int verificaNo(tipoNo *no){
  if(no!=NULL){
      if(no->esquerda == NULL && no->direita == NULL) // folha
          return letra(no);
      else if(no->esquerda != NULL && no->direita !=NULL) // raiz
          return operador(no);
      else return 0;
  }
  return 0;
}

/*---------------- EXERCICIO 2 -----------------*/
/*
a. Em uma árvore de expressão, um nó que é um operando (uma letra entre a e z) não deve ter filhos e um nó que é um operador (+, -, * ou /, **) deve ter duas sub-árvores não vazias que correspondem a duas expressões válidas. Escreva uma função que verifica se uma árvore de expressão é válida, considerando também que uma árvore vazia é inválida e que a presença de quaisquer outros caracteres, exceto os parênteses, também tornam uma árvore inválida.
  int expr_valida(arv *Raiz);
*/
int expr_valida(ArvBin *raiz){
    if(!verificaNo(*raiz)) return 0;
    if(!verificaNo((*raiz)->esquerda)) return 0;
    if(!verificaNo((*raiz)->direita)) return 0;

    return 1;
    return (expr_valida(&((*raiz)->esquerda)) && expr_valida(&((*raiz)->direita)));


}

void criar_expr_errada(ArvBin *raiz){
    *raiz = criaChar('+');
    (*raiz)->esquerda = criaChar('-');
    (*raiz)->direita = criaChar('?');
    ((*raiz)->esquerda)->esquerda = criaChar('a');
    ((*raiz)->esquerda)->direita = criaChar('b');
    ((*raiz)->direita)->esquerda = criaChar('3');
    ((*raiz)->direita)->direita = criaChar('d');
}

void criar_expr1(ArvBin *raiz){
    *raiz = criaChar('+');
    (*raiz)->esquerda = criaChar('-');
    (*raiz)->direita = criaChar('*');
    ((*raiz)->esquerda)->esquerda = criaChar('a');
    ((*raiz)->esquerda)->direita = criaChar('b');
    ((*raiz)->direita)->esquerda = criaChar('c');
    ((*raiz)->direita)->direita = criaChar('d');
}

/*
b. Escreva a árvore binária correspondente à seguinte expressão: (a+b) * (c−d)−e * f. Escreva os elementos da árvore considerando os seguintes percursos pré-ordem e pós-ordem.
*/
void criar_expr2(ArvBin *raiz){
    *raiz = criaChar('-');
    (*raiz)->esquerda = criaChar('*');
    (*raiz)->direita = criaChar('*');
    ((*raiz)->esquerda)->esquerda = criaChar('+');
    ((*raiz)->esquerda)->direita = criaChar('-');
    ((*raiz)->direita)->esquerda = criaChar('e');
    ((*raiz)->direita)->direita = criaChar('f');
    (((*raiz)->esquerda)->esquerda)->esquerda = criaChar('a');
    (((*raiz)->esquerda)->esquerda)->direita = criaChar('b');
    (((*raiz)->esquerda)->direita)->esquerda = criaChar('c');
    (((*raiz)->esquerda)->direita)->direita = criaChar('d');

}

int main(){
  ArvBin *raiz = criaArvBin();
    criar_expr2(raiz);
    printf("\n\nEXERCICIO2\n");
    printf("exercicio a)\n");

    printf("Arvore de Expressao\n(a + b) * (c - d) - e * f\neh Valida?\n");
    if(expr_valida(raiz)){
      printf("R: Arvore de Expressao Valida");
    }else{printf("Arvore Expressao Invalida");}


    printf("\nPercurso em Pre-Ordem: ");
    printPreOrd(raiz);

    printf("\nPercurso em Pos-Ordem: ");
    printPosOrd(raiz);

    printf("\n\nexercicio b)\n");

    ArvBin *raiz2 = criaArvBin();
    criar_expr1(raiz2);
    printf("Uma arvore para teste: (a - b) + (c * d) : ");
    if(expr_valida(raiz2))
        printf("Arvore de expressao Valida");
    else
        printf("Arvore de expressao Invalida");

    ArvBin *raiz3 = criaArvBin();
    criar_expr_errada(raiz3);
    printf("\nOutra arvore para teste: (a - b) + (3 ? d) : ");
    if(expr_valida(raiz3))
        printf("Arvore de expressao Valida");
    else
        printf("Arvore de expressao Invalida");
}
