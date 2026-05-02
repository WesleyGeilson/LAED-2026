// 10) Selection Sort crescente/decrescente (0.5 valor)
// Adapte o Selection Sort para receber ordem (1 crescente, -1 decrescente). Mostre os testes com o mesmo vetor nas duas
// ordens e valide a saída.

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

void selectionSort(int v[], int n, int choise){
    Metrics metricaSelectionSort;
    metricaSelectionSort.comparacoes = 0;
    metricaSelectionSort.trocas = 0;
    int menor = 0;
    if(choise == 1){
        for (int i = 0; i < n-1;i++){
            menor = i;
            imprimedados(v,5);
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

    else if(choise == -1){
        for (int i = 0; i < n-1;i++){
            menor = i;
            imprimedados(v,5);
            for (int j = i+1; j < n; j++){
                metricaSelectionSort.comparacoes++;
                if (v[menor] < v[j]){
                    menor = j;
                }
            }
            if(i != menor){
                swap(&v[i],&v[menor]);
                metricaSelectionSort.trocas++;
            }
        }imprimeMetricas(metricaSelectionSort);    
    }
}

int main(){
    int vet[] = {64, 25, 12, 22, 11};

    printf("\n====================================\n");
    selectionSort(vet, 5, 1);
    printf("\n====================================\n");
    selectionSort(vet, 5, -1);

    return(0);

}