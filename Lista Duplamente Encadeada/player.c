#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

Lista *AlocarNo(char *nome_da_musica, double tempo_de_duracao){
    Lista *novo_no = (Lista*) malloc(sizeof(Lista));
    novo_no->retaguarda = NULL;
    novo_no->guarda = NULL;
    strcpy(novo_no->nome_da_musica,nome_da_musica);
    novo_no->tempo_de_duracao = tempo_de_duracao;
    return novo_no;
}

Lista *EncadeamentoDuplo(Lista *p, char *nome_da_musica, double tempo_de_duracao){
    if (p == NULL){ // se esta vazia a lista
        p = AlocarNo(nome_da_musica,tempo_de_duracao);
        return p;
    }
    else{ // se houver elementos na lista
        Lista *no = AlocarNo(nome_da_musica, tempo_de_duracao);
        Lista *aux = p; // este auxiliar sera nosso meio de caminhar até o final, pois aqui em listas encadeadas duplamente, inserimos no final.
        while(aux->guarda != NULL ){
            aux = aux->guarda;
        }
        aux->guarda = no;
        no->retaguarda = aux;
    }
    return p;
}

void MostrarPlaylist(Lista *p){
    if (p == NULL){
        printf("Lista Vazia!");
        return;
    }
    else{
        Lista *aux = p;
        do{
            printf("%s  |  %.2f\n", aux->nome_da_musica, aux->tempo_de_duracao);
            aux = aux->guarda;
        }while(aux!= NULL);
        
            
        
    }
}