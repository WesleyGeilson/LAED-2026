#include <stdio.h>

int particiona (int *V, int inicio, int final) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while (esq < dir) {
        while (esq <= final && V[esq] <= pivo ){
            esq++;
        }
        while (dir >= 0 && pivo <= V[dir]){
            dir--;
        }
        if (esq < dir) {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quickSort(int *V, int inicio, int fim) {
    int pivo;
    if (fim > inicio) {
        pivo = particiona (V, inicio,fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

void imprimirVetor(int v[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    
}

int main(){
    
    int vet[] = {42, 23, 16, 15, 8, 4};
    printf("Vetor antes de ordenar com quicksort:");
    imprimirVetor(vet, 6);

    printf("Vetor DEPOIS de ordenar com quicksort:");
    quickSort(vet, 0, 5);
    imprimirVetor(vet, 6);






    return 0;
}