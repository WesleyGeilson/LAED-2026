#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

Listas *alocarNo(int valor){ // cria se um no solto
    Listas *novo_no = (Listas*) malloc(sizeof(Listas));
    novo_no->prox  = NULL;
    novo_no->valor = valor;
return novo_no;
}

Listas *inserirCircular(Listas *p, int valor){
    Listas *novo = alocarNo(valor);
    if( p == NULL){
        novo->prox = novo; // fazemos o nosso nó da main apontar para si mesmo
        p = novo;
    }
    else{
        novo->prox = p->prox; // a ideia é que p é o cara principal, ele sempre esta para o ultimo elemento, portanto fazer a estrutura nova apontar sempre apontar para p nos garante que ela seja circular 
        p->prox = novo;
        p = novo;
    }
return p;
}

void VisualizarCircular(Listas *p){
    if(p == NULL){
        printf("\nLista vazia!\n");
        return;
    }
    
    Listas *PrimeiroNo = p->prox; // o primeiro no da lista é o ponteiro que o ultimo aponta, afinal é uma lista circular! Pergunta... nao precisamos alocar memoria para este e nem para o proximo?
    Listas *aux = PrimeiroNo;
    do{
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }while(aux != PrimeiroNo);    
}

void Liberar(Listas *p){
    free(p);
}

Listas *Buscar (Listas *p, int valor){
    int num_found = valor;
    bool flag = false;
    Listas *PrimeiroNo = p->prox;
    Listas *aux = PrimeiroNo;
    do{
        if(aux-> valor == num_found){
            printf("Valor Encontrado !");
            flag = true;
            break;
        }
        aux = aux->prox;
    }while(aux != PrimeiroNo);
    if (flag == false){
        printf("Valor nao Encontrado !");
    }
    return 0;
}

Listas *Remover (Listas *p, int valor){
    if(p == NULL){
        printf("Lista vazia");
        return NULL;
    }
    else{
        int num_found = valor;
        Listas *anterior = p;
        Listas *atual = p->prox;
        do{
            if(atual-> valor == num_found){
                anterior->prox = atual->prox;
                printf("\nValor Removido!\n\n");
                if(atual == p){
                    p = anterior;
                }
                Liberar(atual);
                return p;

            }
            anterior = anterior->prox;
            atual = atual->prox;
        }while(atual != anterior);

        printf("Valor nao Encontrado !");
    }
    return p;
}