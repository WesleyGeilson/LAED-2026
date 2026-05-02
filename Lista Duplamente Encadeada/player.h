typedef struct lista Lista;

struct lista{
    char nome_da_musica[30];
    double tempo_de_duracao;
    struct lista *guarda;
    struct lista *retaguarda;
};

Lista *AlocarNo(char *nome_da_musica, double tempo_de_duracao);
Lista *EncadeamentoDuplo(Lista *p, char *nome_da_musica, double tempo_de_duracao);
void MostrarPlaylist(Lista *p);