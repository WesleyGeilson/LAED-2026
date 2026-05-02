// Implemente void bubbleSort(int v[], int n) para ordenar em ordem crescente. Use troca com variável
// temporária (swap).

#include <stdio.h>
#include <stdlib.h>

// Algoritmo de ordenação bubblesort com complexidade geral 0(n²)
void bubbleSort(int v[], int n) {
    int temp = 0;
    // int flag = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n-i-1; j++){
            if(v[j] > v[j+1]){
                temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
                //flag = 0;
            }
            // if(flag == 1){
            //     break;
            // }
        }
    }
}

// funcao que imprime o array, copiei e colei de uma tarefa que o professor nos ofereceu
static void print_array(const int v[], int n){
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", v[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]");
}

int main(){
   
    int vet[] = {9,5,23,44,12,6,1};
    bubbleSort(vet, 7);
    print_array(vet,7);

    return 0;
}