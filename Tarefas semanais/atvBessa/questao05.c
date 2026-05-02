// Implemente void bubbleSortOrdem(int v[], int n, int ordem):
// • ordem = 1 crescente
// • ordem = -1 decrescente
// Teste com: n=0, n=1, repetidos, mistura de positivos/negativos.
#include <stdio.h>

typedef struct{
    int comparacoes;
    int trocas;
} Metrics;

void bubbleSortFLAG(int v[], int n, int s) {
    int temp = 0;
    int flag = 0;
    Metrics bubbleFlagMetrics;
    bubbleFlagMetrics.comparacoes = 0;
    bubbleFlagMetrics.trocas = 0;
    if(s == 1){
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n-i-1; j++){
                bubbleFlagMetrics.comparacoes++;
                if(v[j] > v[j+1]){
                    temp = v[j+1];
                    v[j+1] = v[j];
                    v[j] = temp;
                    bubbleFlagMetrics.trocas++;
                    flag = 1;
                }
                if(flag == 1){
                    break;
                }
            }
        }
    }

    else if (s == -1){
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n-i-1; j++){
                bubbleFlagMetrics.comparacoes++;
                if(v[j] < v[j+1]){
                    temp = v[j+1];
                    v[j+1] = v[j];
                    v[j] = temp;
                    bubbleFlagMetrics.trocas++;
                    flag = 0;
                }
                if(flag == 1){
                    break;
                }
            }
        }
    }
}

void imprimedados(int dados[],int n){
    for(int i = 0; i < n; i++){
        printf("%d ", dados[i]);
    }
    printf("\n");
}
int main(){
    
    int dados[] = {64, 34, 25, 12, 22, 11, 90};
    int dadosmisturados[] = {-5, 10, -1, 8, 0, -3, 6};
    int n = 7;

    bubbleSortFLAG(dados, n, 1);
    printf("Vetor ordenado em ordem crescente: ");
    imprimedados(dados,7);

    bubbleSortFLAG(dados, n, -1);
    printf("Vetor ordenado em ordem decrescente: ");
    imprimedados(dados,7);

    bubbleSortFLAG(dadosmisturados, n, 1);
    printf("Vetor misturado ordenado em ordem crescente: ");
    imprimedados(dadosmisturados,7);

    bubbleSortFLAG(dadosmisturados, n, -1);
    printf("Vetor misturado ordenado em ordem decrescente: ");
    imprimedados(dadosmisturados,7);

    return 0;
}