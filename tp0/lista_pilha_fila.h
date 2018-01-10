typedef int t_chave;

typedef struct{
    t_chave chave;
} t_item;

typedef struct celula *t_apontador;

typedef struct celula{
    t_item item;
    t_apontador prox;
} t_celula;


//LISTA-------------------------------------
typedef struct {
    t_apontador primeiro, ultimo;
} t_lista;

void lista_FazVazia(t_lista *lista);
int lista_TestaVazia(t_lista lista);
void lista_InsereFinal(t_item x, t_lista *lista);
void lista_InsereP(t_item x, t_lista *lista, t_apontador p);
void lista_RetiraP(t_apontador p, t_lista *L, t_item *item);
void lista_Imprime(t_lista lista);


//PILHA-------------------------------------
typedef struct{
    t_apontador fundo;
    t_apontador topo;
    int tamanho;
} t_pilha;

void pilha_FazVazia(t_pilha *pilha);
int pilha_TestaVazia(t_pilha *pilha);
void pilha_empilha(t_item x, t_pilha *pilha);
void pilha_desempilha(t_pilha *pilha, t_item *item);
int pilha_tamanho(t_pilha *pilha);


//FILA--------------------------------------
typedef struct{
    t_apontador frente;
    t_apontador tras;
} t_fila;

void fila_FazVazia(t_fila *fila);
int fila_TestaVazia(t_fila *fila);
void fila_enfileira(t_item x, t_fila *fila);
void fila_desenfileira(t_fila *fila, t_item *item);