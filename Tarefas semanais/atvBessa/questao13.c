// Insertion Sort instrumentado (comparações e movimentações) (1.5 valor)
// Crie uma versão instrumentada que conte:
// • comparacoes: apenas avaliações da condição do tipo chave < V[j-1]
// • movimentacoes: atribuições no vetor V[...] = ... (inclui deslocamentos e a inserção final da chave)
// Teste com vetores: ordenado, reverso, aleatório (n=20). Explique os resultados observados, especialmente no
// caso “quase ordenado”.

#include <stdio.h>

typedef struct{
    int comparacoes;
    int trocas;
} Metrics;

void imprimedados(int dados[],int n){
    for(int i = 0; i < n; i++){
        printf("%d ", dados[i]);
    }
    printf("\n");
}

void imprimeMetricas(Metrics metrica){
    printf("Comparacoes:%d\n", metrica.comparacoes);
    printf("Trocas: %d\n", metrica.trocas);
}

void InsertionSort(int *v, int n){
    int i,j, chave;
    Metrics InsertionSortmetrics;
    InsertionSortmetrics.comparacoes = 0;
    InsertionSortmetrics.trocas = 0;
    imprimedados(v,n);
    for (i = 1; i < n; i++){
        chave = v[i];
        j = i;
        while( j > 0){
            InsertionSortmetrics.comparacoes++;
            if(chave < v[j-1]){
                v[j] = v[j-1];
                j--;
                InsertionSortmetrics.trocas++;
            }else{
                break;
            }
            if (j != i) { // só se a chave “andou”
            v[j] = chave;
            InsertionSortmetrics.trocas++; // escrita final (inserção real)
            }
        }
    }
    imprimeMetricas(InsertionSortmetrics);
}

int main(){

    int vetaleatorio[] = {5, 2, 4, 6, 1, 3};
    int vetordenado[] = {1, 2, 3, 4, 5};
    int vetreverso[] = {5, 4, 3, 2, 1};

    printf("Vetor aleatorio:\n");
    InsertionSort(vetaleatorio, 6);
    printf("\n");
    printf("Vetor ordenado:\n");
    InsertionSort(vetordenado, 5);
    printf("\n");
    printf("Vetor reverso:\n");
    InsertionSort(vetreverso, 5);

    return 0;
}