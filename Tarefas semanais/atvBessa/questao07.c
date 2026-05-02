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
    int menor = 0;
    for (int i = 0; i < n-1;i++){
        menor = i;
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

    int vet[] = {64, 25, 12, 22, 11};
    selectionSortDEBUG(vet, 5);
    imprimedados(vet,5);

    return 0;
}