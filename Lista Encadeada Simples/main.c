// Lista encadeada simples da Amazon

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {

	int opcao;
	printf("Bem vindo a Amazon!\n\n");
	Compras *carrinho = NULL; // tecnicamente aqui seria a cabeC'a da nossa lista que inicia vazia - Lembre-se! Um novo item adicionado será sempre o primeiro

	while(opcao != 0) {
		printf("[1] Comprar Itens \n[2] Atividade Mayara,\n[3]Ver itens \n[4] Inserir no meio\n[5] Remover por codigo\n");
		scanf("%d", &opcao);
		switch(opcao) {
		case 1:
			int codigo = 0;
			char nome[50];
			float preco;
			printf("Digite o codigo do produto: ");
			scanf("%d", &codigo);
			printf("digite o nome dele: ");
			scanf("%s", nome);
			printf("digite o preco dele: ");
			scanf("%f", &preco);
			inserir_inicio(carrinho, codigo, nome, preco);
			break;
		case 2:
			carrinho = inserir_inicio(carrinho, 100, "bola", 150);
			carrinho = inserir_inicio(carrinho, 101, "arroz", 50);
			break;
		case 3:
			mostrarCarrinho(carrinho);
			break;
		case 4: 
		    carrinho = inserirNoMeio(carrinho, 105, "fone de ouvido", 300);
		    break;
		case 5:
		    int codigo_remover;
		    printf("qual elemento vc deseja remover, digite o codigo ");
		    scanf("%d", &codigo_remover);
		    remover(carrinho, codigo_remover);
		case 0:
			break;
		default:
			break;
		}
	}

	return 0;
}