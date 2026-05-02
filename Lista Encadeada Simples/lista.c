#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

struct compras { // estrutura de compras, aqui ainda não precisamos utilizar seu apelido
    int codigo;
    char nome[50];
    float preco;
    struct compras *prox;
};

Compras* inserir_inicio(Compras* lista, int codigo, char* nome, float preco){ // essa funcao inserir_inicio é o equivalente a ser uma funcoa 'comprar', precisamos sempre do nó anterior (primeiro parametro)para iniciar o proximo item da compra
    Compras* novo_produto = (Compras*) malloc(sizeof(Compras)); // alocando memoria para a nossa variavel (o produto que estamos colocando no carrinho) (que tem acesso a todos os metodos e atributos)
   
    novo_produto -> codigo = codigo; // ' -> ' serve para acessar metodos e atributos quando estamos manipulando um ponteiro 
    novo_produto -> preco = preco;
    strcpy(novo_produto -> nome, nome);
    
    novo_produto->prox = lista; // avançamos uma posicao na nossa lista DUVIDA AQUI, lista nasce com seu no vazio ? NULL ?
    return novo_produto;
    
}

Compras *mostrarCarrinho(Compras *lista){
    Compras *aux = lista; // estrutura auxiliar que ira nos ajudar
    while(aux != NULL){ // percorrendo nossa lista, enquanto o ponteiro que esta na lista nao for vazio, imprima...
            
            printf(" Item: %s\n", aux->nome); 
            printf(" O codigo: %d\n", aux->codigo);
            printf(" O preco: %.2f\n\n", aux->preco);
            
            // Avança o ponteiro
            aux = aux->prox; // lembre-se ! prox é o nosso no e ele tem a propriedade de conseguir sempre referenciar o proximo no da frente 
        }
}

Compras *inserirNoMeio(Compras *lista, int codigo, char* nome, float preco){
    int cont = 0;
    Compras *aux =  lista; // vamos achar o meio da lista usando uma lista 'auxiliar'
    while (aux != NULL){
        cont++;
        aux = aux->prox;
    }
    int cont_final = cont/2; // a ideia aqui é chegar no meio da lista encadeada, fazer com que o no que antecede o meio (no penul)apontar para o meu novo (novo no) no e esse novo no apontar para o proximo no normal
    
    aux = lista; // reseto aux para ir ate o inicio da lista de novo
    for (int i = 0; i < cont_final - 1; i++ ){
        aux = aux-> prox;
    }
    Compras *novo_produto = (Compras*) malloc(sizeof(Compras));
    
    novo_produto -> codigo = codigo; // estamos inserindo as informaçoes 
    novo_produto -> preco = preco;
    strcpy(novo_produto -> nome, nome);
    
    novo_produto->prox = aux->prox; // [A] -> [B] antes        Depois [A] -> [novo_produto] -> [B]
    aux->prox = novo_produto;
}

void remover(Compras *lista, int codigo){
    Compras *anterior = NULL;
    Compras *atual = lista;
    
    while(atual != NULL||atual->codigo == codigo){
        if(atual->codigo == codigo){
            anterior = atual;
        }
    if (anterior == NULL) {
        lista = atual->prox; 
    } else {
        anterior->prox = atual->prox; 
    }
        atual = atual->prox;        
    }
}