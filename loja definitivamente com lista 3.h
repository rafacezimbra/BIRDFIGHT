#ifndef LOJA_H
#define LOJA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"
#include "apagartela.h"
#include "listase.h" // Incluindo a biblioteca de lista encadeada

#define ANSI_COLOR_1 "\x1b[93m"
#define ANSI_COLOR_2 "\x1b[97m"

typedef struct {
    char nome[50];
    int preco;
    char descricao[100];
} ItemLoja;

tp_item criarItem(char* nome, int preco, char* descricao) {
    ItemLoja* novoItem = (ItemLoja*)malloc(sizeof(ItemLoja));
    strcpy(novoItem->nome, nome);
    novoItem->preco = preco;
    strcpy(novoItem->descricao, descricao);
    return novoItem;
}

void liberarItem(tp_item item) {
    free(item);
}

void loja(Inventory *inv, int *BirdCoin) {
    apagarTela();

    tp_listase* itens = iniciaListase(); // Inicializando a lista encadeada
    insereListase(&itens, criarItem("Soro", 300, "Retira status negativos do Birdmon ativo."));
    insereListase(&itens, criarItem("Biscoito", 500, "Revive um Birdmon com metade do HP."));
    insereListase(&itens, criarItem("Capacete", 300, "Aumenta a defesa do Birdmon ativo temporariamente."));
    insereListase(&itens, criarItem("Melão", 300, "Aumenta o ataque do Birdmon ativo temporariamente."));
    insereListase(&itens, criarItem("Gaiola", 150, "Captura o Birdmon adversário"));
    insereListase(&itens, criarItem("Alpiste", 250, "Restaura 30 HP do Birdmon ativo."));

    printf("\n");

    int escolha;
    printf("|| ***      ******   ********   ****   ||\n");
    printf("|| ***     **    **     **    ***  *** ||\n");
    printf("|| ***     *      *     **    **    ** ||\n");
    printf("|| ***     *      *  *  **    ******** ||\n");
    printf("|| ******  **    **  *  **    **    ** ||\n");
    printf("|| ******   ******   *****    **    ** ||\n");
    printf("Bem-vindo à Loja!\n");
    printf("Você tem %d BirdCoins.\n", *BirdCoin);

    tp_listase* atual = itens;
    int index = 1;
    while (atual != NULL) {
        ItemLoja* item = (ItemLoja*)atual->info; // Cast para ItemLoja
        switch (index - 1) {
            case 0: // Alpiste
                printf("|-------------| \n");
                printf("|   ALPISTE   | \n");
                printf("|-------------| \n");
                printf("|:::::::::::::|     %d - %s (Preco: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("|:::::::::::::| \n");
                printf("|:::::::::::::| \n");
                printf("|-------------| \n\n");
                break;

            case 1: // Melão
                printf("          --MM \n");
                printf("      MM##MM:: \n");
                printf("    MMMM####++ \n");
                printf("    ####MM@@++      %d - %s (Preco: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("  MM##MM##  ## \n");
                printf("@@--      MM   \n"); 
                printf("  ########     \n\n");    
                break;

            case 2: // Gaiola
                printf("xxxxxxxxxxxxx \n");
                printf("x  x  x  x  x \n");
                printf("x  x  x  x  x \n");
                printf("x  x  x  x  x       %d - %s (Preco: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("x  x  x  x  x \n");
                printf("x  x  x  x  x \n");
                printf("xxxxxxxxxxxxx \n\n");
                break;

            case 3: // Soro
                printf("  ___   \n");
                printf(" |   |  \n");
                printf(" _| |_  \n");
                printf("|_____|             %d - %s (Preco: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("|_____| \n");
                printf("|_____| \n\n");
                break;

            case 4: // Biscoito
                printf("    *******       \n");
                printf("  ***  @   ****   \n");
                printf(" ** @    @   ***  \n");
                printf(" *    @    @  **    %d - %s (Preco: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf(" *  @        ***  \n");
                printf(" **     @   ***   \n");
                printf("   **********     \n\n");
                break;

            case 5: // Capacete
                printf(" #######  \n");
                printf("##      # \n"); 
                printf("#    ####           %d - %s (Preco: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("#   ##  | \n");
                printf("#   #___| \n");
                printf(" ####     \n\n");
                break;
        }
        atual = atual->prox;
        index++;
    }

    printf("Escolha um item pelo número (ou 0 para sair): ");
    scanf("%d", &escolha);

    if (escolha > 0 && escolha < index) {
        atual = itens;
        for (int i = 1; i < escolha; i++) {
            atual = atual->prox;
        }

        ItemLoja* item = (ItemLoja*)atual->info; // Cast para ItemLoja
        if (*BirdCoin >= item->preco) {
            *BirdCoin -= item->preco;
            adicionarAoInventario(inv, *item); // Função para adicionar o item ao inventário
            printf("Você comprou %s por %d BirdCoins.\n", item->nome, item->preco);
        } else {
            printf("Você não tem BirdCoins suficientes para comprar %s.\n", item->nome);
        }
    } else if (escolha == 0) {
        printf("Saindo da loja...\n");
    } else {
        printf("Escolha inválida.\n");
    }

    liberarLista(itens); // Liberando a lista ao final
}

#endif // LOJA_H