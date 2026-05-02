// Lista circular:

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    
    printf("Lista Circular:\n");
    Listas *listaCircular = NULL;
    listaCircular = inserirCircular(listaCircular,10);
    listaCircular = inserirCircular(listaCircular,20);
    listaCircular = inserirCircular(listaCircular,30);
    VisualizarCircular(listaCircular);
    Buscar(listaCircular,20);
    listaCircular = Remover(listaCircular,10);
    VisualizarCircular(listaCircular);
    Liberar(listaCircular);
    return 0;
}