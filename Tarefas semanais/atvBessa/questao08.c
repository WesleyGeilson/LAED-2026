// Instrumente o Selection Sort com:
// • comparacoes++ a cada comparação entre elementos
// • trocas++ somente quando ocorrer troca real (quando menor != i)
// Execute em (i) ordenado, (ii) reverso, (iii) aleatório, com n=20. Compare os resultados e explique por que o
// número de operações tende a ser “mais constante” que no Bubble.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int comparacoes;
    int trocas;
} Metrics;

void imprimeMetricas(Metrics metrica){
    printf("Comparacoes:%d\n", metrica.comparacoes);
    printf("Trocas: %d\n", metrica.trocas);
}

void swap(int *n, int *m){
    int troca = *n;
    *n = *m;
    *m = troca;
}

void imprimedados(int dados[],int n){
    for(int i = 0; i < n; i++){
        printf("%d ", dados[i]);
    }
    printf("\n");
}

void selectionSort(int v[], int n){
    Metrics metricaSelectionSort;
    metricaSelectionSort.comparacoes = 0;
    metricaSelectionSort.trocas = 0;
    int menor = 0;
    for (int i = 0; i < n-1;i++){
        menor = i;
        for (int j = i+1; j < n; j++){
            metricaSelectionSort.comparacoes++;
            if (v[menor] > v[j]){
                menor = j;
            }
        }
        if(i != menor){
            swap(&v[i],&v[menor]);
            metricaSelectionSort.trocas++;
        }
    }imprimeMetricas(metricaSelectionSort);
}

void selectionSortDEBUG(int v[], int n){
    int menor = 0;
    for (int i = 0; i < n-1;i++){
        imprimedados(v,5);
        for (int j = i+1; j < n; j++){
            if (v[menor] > v[j]){
                menor = j;
            }
        }
        if(i != menor){
            swap(&v[i],&v[menor]);
        }
    }
}

int main(){

    // Execute em (i) ordenado, (ii) reverso, (iii) aleatório, com n=20
    int vet_ordenado[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int vet_reverso[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int vet_aleatorio[] = {64, 25, 12, 22, 11, 90, 87, 45, 33, 78, 56, 23, 67, 89, 10, 44, 77, 33, 55, 22};

    selectionSort(vet_ordenado,20);
    selectionSort(vet_aleatorio,20);
    selectionSort(vet_reverso,20);

    printf("As comparações tendem a ser menores porque estamos limitando melhor o escopo de acesso,e mantem a ordem relativa de elementos iguais ");
    return(0);
}