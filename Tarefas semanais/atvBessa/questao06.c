// Implemente void selectionSort(int *V, int n) conforme a ideia de “selecionar o menor e colocar na
// posição correta”.

#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < n-1;i++){
        int menor = i;
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

    int vet[] = {9,5,23,44,12,6,1};
    selectionSort(vet, 7);
    imprimedados(vet,7);

    return 0;
}