#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    
    Pilha pilha_principal;
    inicializar_pilha(&pilha_principal);
    
    empilhar(&pilha_principal, 101);
    empilhar(&pilha_principal, 19);
    empilhar(&pilha_principal, 20);
    empilhar(&pilha_principal, 30);
    empilhar(&pilha_principal, 80);
    
    imprimir(&pilha_principal);
    
    desempilhar(&pilha_principal);
    desempilhar(&pilha_principal);
    desempilhar(&pilha_principal);
    desempilhar(&pilha_principal);
    desempilhar(&pilha_principal);
   
    
    printf("\n\n");
    
    imprimir(&pilha_principal);
    
}