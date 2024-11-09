/******************************************************************************
construa uma função que recebe como parametro, 
uma lista encadeada e um numero inteiro n e retorne o numero de nós da lista 
que possuem um campo info com valores maiores do que n.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"  // Incluindo o arquivo de lista simplesmente encadeada

// Estrutura para armazenar informações do item
typedef struct {
    char nome[50];
    float preco;
    char descricao[100];
} Item;

// Função para adicionar item à lista encadeada
void adicionarItem(tp_listase **lista, char* nome, int preco, char* descricao) {
    Item *novoItem = (Item*) malloc(sizeof(Item));
    if (novoItem == NULL) {
        printf("Erro ao alocar memória para o item!\n");
        exit(1);
    }
    strcpy(novoItem->nome, nome);
    novoItem->preco = preco;
    strcpy(novoItem->descricao, descricao);
    
    // Inserindo o item na lista
    insereListase(lista, (tp_item)novoItem);  // Passando o ponteiro do novoItem para a lista
}

// Função para exibir os itens disponíveis na loja
void exibirLoja(tp_listase *lista) {
    printf("\nItens disponíveis na loja:\n");
    tp_listase *atu = lista;
    int i = 1;
    while(atu != NULL) {
        Item *item = (Item*) atu->info;  // Convertendo o ponteiro genérico para ponteiro do tipo Item
        printf("%d - %s\n", i++, item->nome);
        atu = atu->prox;
    }
    printf("0 - Sair\n");
}

// Função para exibir detalhes de um item específico
void exibirDetalhes(tp_listase *lista, int indice) {
    tp_listase *atu = lista;
    int i = 1;
    while(atu != NULL) {
        if (i == indice) {
            Item *item = (Item*) atu->info;  // Convertendo o ponteiro genérico para ponteiro do tipo Item
    
            printf("Nome: %s\n", item->nome);
            printf("Preço: R$ %.2f\n", item->preco);
            printf("Quantidade disponível: %d\n", item->quantidade);
            printf("---------------------------\n");
            return;
        }
        atu = atu->prox;
        i++;
    }
    printf("Item não encontrado!\n");
}


// Função para contar o número de itens na lista
int contarItens(tp_listase *lista) {
    int count = 0;
    tp_listase *atu = lista;
    while (atu != NULL) {
        count++;
        atu = atu->prox;
    }
    return count;
}

int main() {
    tp_listase *listaItens = iniciaListase();  // Iniciando a lista encadeada
    int opcao;

    // Adicionando itens na lista
    adicionarItem(&listaItens, "Camisa", 49.99, 10);
    adicionarItem(&listaItens, "Calça", 89.99, 5);
    adicionarItem(&listaItens, "Tênis", 129.99, 8);
    adicionarItem(&listaItens, "Chapéu", 29.99, 15);
    adicionarItem(&listaItens, "Mochila", 99.99, 4);
    adicionarItem(&listaItens, "Relógio", 199.99, 2);

    // Loop para permitir ao usuário escolher um item ou sair
    do {
        exibirLoja(listaItens);
        printf("\nSelecione um item pelo número (ou 0 para sair): ");
        scanf("%d", &opcao);

        if (opcao > 0 && opcao <= contarItens(listaItens)) {
            exibirDetalhes(listaItens, opcao);
        } else if (opcao != 0) {
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    printf("Encerrando o sistema...\n");

    // Liberar a memória alocada
    destroiListase(&listaItens);

    return 0;
}




