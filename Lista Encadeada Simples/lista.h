typedef struct compras Compras; // aqui criamos a nossa estrutura que sera nosso alicerce, ela está apelidada em todas as ocasiões de 'Compras'

Compras* inserir_inicio(Compras* lista, int codigo, char* nome, float preco); // Inseri no inicio da lista

Compras* mostrarCarrinho(Compras *lista); // Mostra toda nossa corrente de lista

Compras* inserirNoMeio(Compras *lista, int codigo, char* nome, float preco); // Insere no meio da lista, percorrendo todos os seus elementos e dividindo por 2

void liberar(Compras *lista);

void remover(Compras *lista, int codigo);




