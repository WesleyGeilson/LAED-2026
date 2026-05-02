#define TAM 10  

typedef struct pilha Pilha;

struct pilha{
    int info[TAM];
    int topo;
};

void inicializar_pilha(Pilha *p);

int verificar_pilha_cheia(Pilha *p);

int verificar_pilha_vazia(Pilha *p);

int empilhar(Pilha *p, int valor);

int desempilhar(Pilha *p);

void imprimir(Pilha *p);