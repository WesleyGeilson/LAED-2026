// Implemente Bubble Sort com:
// • comparacoes++ a cada comparação
// • trocas++ a cada swap
// Imprima comparacoes e trocas ao final.
// OBS: aqui eu ja havia feito um desafio em sala com a atividade do professor, bastou apenas modificar pequenas coisas e entao implementar

#include <stdio.h>

typedef struct{
    int comparacoes;
    int trocas;
} Metrics;

void imprimeMetricas(Metrics metrica){
    printf("Comparacoes:%d\n", metrica.comparacoes);
    printf("Trocas: %d\n", metrica.trocas);
}

void bubbleSortNOFLAG(int v[], int n) {
    Metrics bubbleNoFlagMetrics;
    bubbleNoFlagMetrics.comparacoes = 0;
    bubbleNoFlagMetrics.trocas = 0;
    int temp = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n-i-1; j++){
            bubbleNoFlagMetrics.comparacoes++;
            if(v[j] > v[j+1]){
                temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
                bubbleNoFlagMetrics.trocas++;
            }
        }
    }imprimeMetricas(bubbleNoFlagMetrics);
}
void bubbleSortFLAG(int v[], int n) {
    int temp = 0;
    int flag;
    Metrics bubbleFlagMetrics;
    bubbleFlagMetrics.comparacoes = 0;
    bubbleFlagMetrics.trocas = 0;

    for (int i = 0; i < n - 1; i++){
        flag = 0;
        for (int j = 0; j < n-i-1; j++){
            bubbleFlagMetrics.comparacoes++;
            if(v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                bubbleFlagMetrics.trocas++;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }imprimeMetricas(bubbleFlagMetrics);
}
 
void imprimirVetor(int v[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    
}


int main() {
    int dados[] = {64, 34, 25, 12, 22, 11, 90};
    int dados2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    printf("Vetor original: ");
    imprimirVetor(dados, n);
    printf("\n");

    printf("Vetor ordenado (com flag no bubble):\n");
    bubbleSortFLAG(dados, n);
    imprimirVetor(dados, n);
    printf("\n");

    printf("Vetor ordenado (sem flag no bubble):\n");
    bubbleSortNOFLAG(dados2,n);
    imprimirVetor(dados2, n);
   
    return 0;
}