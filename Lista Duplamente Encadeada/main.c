#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

int main(){
    
    char nome_musica[30]; double tempo_musica;
    printf("Player music!\nDigite o nome de 03 musicas e seu tempo !\n");
    // fgets(nome_musica, sizeof(nome_musica), stdin);
    // scanf("%f", tempo_musica);
    
    Lista *playlist = NULL;
    playlist = EncadeamentoDuplo( playlist, "Shape of You", 3.53);
    playlist = EncadeamentoDuplo( playlist, "Billie Jean", 4.54);
    playlist = EncadeamentoDuplo( playlist, "Garota de Ipanema", 5.23);
    
    MostrarPlaylist(playlist);
    return 0;
}