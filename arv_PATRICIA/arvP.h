/*UNIVERSIDADE FEDERAL DO AMAZONAS
LAURA AGUIAR MARTINHO
21952064
ALGORITMOS E ESTRUTURAS DE DADOS II
PROF EDSON NASCIMENTO
ARVORE PATRICIA*/


/*****
Biblioteca PATRICIA - Estruturas e prototipos de funcoes
*****/

//declaraçao de  um tipo String
typedef  char* String;

//passando como parâmetro a enumeração dos tipos de NO para ser retornada em funcao futuramente
typedef enum{
  Pai, Folha //noPai (interno) possui filhos, noFolha (externo) sem filhos
}tipoNo;

//estruturas para Lista, usada na implementacao
typedef struct elemento{
	int dado;
	struct elemento *proximo;
}tipoEle;

typedef struct lista{
	tipoEle *primeiro;
	tipoEle *ultimo;
}tipoLista;

//estruturas da arvore e seus nos
typedef struct tNoPAT *tipoPAT;
typedef struct tNoPAT{
	tipoNo tipo;
  //declarar dentro de uma uniao: deixando todos os campos na mesma posição de memória
	union{
		struct{
			short Indice;
			char Caractere;
			tipoPAT Esquerdo, Direito;
		}noPai;
		String Dado;
	}NO;
	tipoLista *linhas; //Guarda as linhas que aparece Chave
}tNoPAT;

//prototipos das funcoes
char Digito(short, String);
int Comparou(char, char);
int EFolha(tipoPAT);
void Ordena(tipoPAT);
void ignoraSimbolo(String, int);
void inserirLista(tipoLista *, int);
void imprimirLista(tipoEle *);
void mostrarPalavra(tipoPAT);
tipoPAT criaPai(short, tipoPAT *,  tipoPAT *, char, int);
tipoPAT criaFolha(String, int);
tipoPAT Busca(String, tipoPAT);
tipoPAT InsereAux(String, tipoPAT, short, int);
tipoPAT Insere(String, tipoPAT, int);
tipoLista *criarLista();
