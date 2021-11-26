//ESTRUTURAS
typedef struct NO{
  struct NO *pai;
  struct NO *ponteiros[5];
  int chave[4];
  int tamanho;
}tipoNo;

typedef struct arvore234{
  tipoNo *raiz;
}Arv234;

//PROTÓTIPOS
void ordena(int[],int);
void busca(Arv234*, int);
void inserir(Arv234*,int);
void insereValor(tipoNo**, int, Arv234*);
void imprimir_Aux(tipoNo*, int);
void imprimir(Arv234 *);
void dividir(tipoNo **, Arv234*);
tipoNo* achaFolha(tipoNo**, int);
int eRaiz(tipoNo**);


void remover(tipoNo*, int);
int procura(tipoNo*, int);
tipoNo* sucessor(tipoNo*, int);
int rotacao(tipoNo*);
void remova(tipoNo*, int);
