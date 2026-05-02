typedef struct listas Listas;

struct listas{
  int valor;
  struct listas *prox;
};

Listas *alocarNo(int valor);
Listas *inserirCircular(Listas *p, int valor);
Listas *Buscar (Listas *p, int valor);
Listas *Remover (Listas *p, int valor);
void Liberar(Listas *p);
void VisualizarCircular(Listas *p);
Listas *InserirNoMeio (Listas *p, int valor);