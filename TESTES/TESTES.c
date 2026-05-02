#include <stdio.h>
#include <stdlib.h>

// cria as estruturas do nó
typedef struct node {
    int val;
    struct node *next;
} Node;

//printa todos os elementos da lista
void print(Node *ptr_aux){
    if(ptr_aux == NULL){
        return;
    }
    printf("%d\n", ptr_aux->val);
    print(ptr_aux->next);
    
}

// Torna a lista inversa
Node *inversed_list(Node *ptr_aux){
    if(ptr_aux == NULL || ptr_aux->next == NULL){
        return ptr_aux;
    }
    Node *nova_cabeca = inversed_list(ptr_aux->next);
    ptr_aux->next->next = ptr_aux;
    ptr_aux->next = NULL;
    return nova_cabeca;
    
}

//Imprime os valores de tras pra frente
void print_inversed(Node *ptr_aux){
    Node *aux = ptr_aux;
    if(aux == NULL){
        return;
    }
    print_inversed(aux->next);
    printf("%d\n",aux->val);

}

int main(){

    Node *no1 = (Node*) malloc (sizeof(Node));
    Node *no2 = (Node*) malloc (sizeof(Node));
    Node *no3 = (Node*) malloc (sizeof(Node));
    
    no1->next = no2;
    no1->val = 10;
    
    no2->next = no3;
    no2->val = 20;
    
    no3->next = NULL;
    no3->val = 30;

    printf("Lista invertida (sem mudar de verdade apenas visualmente): deve aparecer 30, 20, 10 \n");
    print_inversed(no1);
    printf("Lista normal: deve aparecer 10,20, 30\n");
    print(no1);
    Node *head_invertida = inversed_list(no1);
    printf("Lista invertida (sem mudando de verdade a ordem dos elementos): deve aparecer 30, 20, 10\n");
    print(head_invertida);

    free(no1);
    free(no2);
    free(no3);

    return 0;
}



move_and_update(p, valuelocate, valueinsert) {
    ptr_aux = p
    
    Enquanto(ptr_aux != Nulo){
        Se(ptr_aux->val == valuelocate){
            ptr_value = ptr_aux
            ptr_value->val = valueinsert
            parar
        }
    }
    Se (ptr_aux == Nulo) retornar

    // 3. REMOVER O NÓ DA POSIÇÃO ATUAL (DESCONECTAR)
    // Se o nó não for o primeiro
    Se (ptr_aux->prev != Nulo) {
        ptr_aux->prev->next = ptr_aux->next
    } Caso contrário (é a cabeça da lista) {
        p = ptr_aux->next
    }
    
    // Se o nó não for o último
    Se (ptr_aux->next != Nulo) {
        ptr_aux->next->prev = ptr_aux->prev
    }

    // 4. RE-INSERIR NA POSIÇÃO CORRETA (BUSCA DA NOVA POSIÇÃO)
    // Se a lista ficou vazia ou o novo valor é menor que o da nova cabeça
    Se (p == Nulo ou valueinsert <= p->val) {
        ptr_aux->next = p
        ptr_aux->prev = Nulo
        Se (p != Nulo) p->prev = ptr_aux
        p = ptr_aux // Atualiza a cabeça
    } Senão {
        // Percorre para achar o ponto de inserção
        atual = p
        Enquanto (atual->next != Nulo e atual->next->val < valueinsert) {
            atual = atual->next
        }
        
        // Insere ptr_aux após o nó 'atual'
        ptr_aux->next = atual->next
        ptr_aux->prev = atual
        Se (atual->next != Nulo) {
            atual->next->prev = ptr_aux
        }
        atual->next = ptr_aux
    }
}


copy_odd(Node p){ // Node q = NULO , ptr_q = NULO
    Se(p == NULO){
        retorna q
    }
    Se(q == NULO){
        Se(p->prox %2 != 0){
            q = p
            q->prox = NULO
            copy_odd(p->prox)
        }
    }
    Se(p->pos %2 != 0){
        ptr_q-> prox = p
        ptr_q-> prox->prox = NULO
        ptr_q = ptr_q->prox
    }
    copy_odd(p->prox)
}