// Implemente Bubble Sort com:
// • comparacoes++ a cada comparação
// • trocas++ a cada swap
// Imprima comparacoes e trocas ao final.
// OBS: utilizei o mesmo codigo da questao 02, no final adicionei o comentario breve

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
    int dados[] = {64, 34, 25, 57, 22, 11, 62};
    int dados2[] = {64, 34, 25, 57, 22, 11, 62};
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
   
    printf("\nNota-se que embora o haja o mesmo numero de trocas, nossas comparacoes podem aumentar bastante, isso quer dizer que em algum momento, o vetor passou a estar ordenado, porem como estamos lidando com o bubble sort sem flag, ele obrigatoriamente deve percorrer o vetor varias vezes mesmo ja estando ordenado, fazendo uma parte do custo computacional se tornar desnecessario");
    return 0;
}