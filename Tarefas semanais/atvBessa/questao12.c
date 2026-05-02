// 11) Insertion Sort (implementação base) (1 valor)
// Implemente void insertionSort(int *V, int n) usando:
// • chave = V[i]
// • deslocamentos enquanto j > 0 && chave < V[j-1]
// • inserção final da chave na posição correta.

#include <stdio.h>

void imprimedados(int dados[],int n){
    for(int i = 0; i < n; i++){
        printf("%d ", dados[i]);
    }
    printf("\n");
}

void InsertionSortDEBUG(int *v, int n){
    int i,j, chave;
    for (i = 1; i < n; i++){
        chave = v[i];
        j = i;
        while( j > 0 && chave < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = chave;
        imprimedados(v,n);
    }
}

int main(){

    int vet[] = {5, 3, 4, 1, 2};
    InsertionSortDEBUG(vet, 5);

    return 0;
}