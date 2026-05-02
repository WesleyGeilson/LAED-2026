#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int verificar_pilha_cheia(Pilha *p){
    if (p->topo >= TAM - 1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int verificar_pilha_vazia(Pilha *p){
    if (p-> topo != -1){
        return 0;
    }
    return 1;
}

int empilhar(Pilha *p, int valor){
    if (!verificar_pilha_cheia(p)){
        p->topo++;
        p->info[p->topo] = valor;
        return 1;
    }
    return 0;
}

int desempilhar(Pilha *p){
    int valor = 0;
    if(!verificar_pilha_vazia(p)){
        valor = p->info[p-> topo];
        p->topo--;
    }
    else {
        exit(1);
    }
    return valor;
}

void imprimir(Pilha *p){
    if (verificar_pilha_vazia(p)){
        printf("pilha vazia");
        return;
    }
    else{
        printf("Elementos listados desde o topo a base: \n\n");
        for(int i = p->topo; i>=0; i--){
            printf("Info: %d\n", p->info[i]);
        }
    }
}