#ifndef LOJA_H
#define LOJA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"
#include "apagartela.h"
#include "listase.h"

#define ANSI_COLOR_1 "\x1b[93m"
#define ANSI_COLOR_2 "\x1b[97m"

typedef struct {
    char nome[50];
    int preco;
    char descricao[100];
} ItemLoja;

Item criarItem(char* nome, int preco, char* descricao) {
    ItemLoja* novoItem = (ItemLoja*)malloc(sizeof(ItemLoja));
    strcpy(novoItem->nome, nome);
    novoItem->preco = preco;
    strcpy(novoItem->descricao, descricao);
    return novoItem;
}

void liberarItem(Item item) {
    free(item);
}

void liberarLista(tp_listase* lista, tp_listase* temp) {
    while (lista != NULL) {
        temp = lista;        
        lista = lista->prox; 
        liberarItem(temp->info);
        free(temp);        
    }
}

void loja(Inventory *inv, int *BirdCoin) {
    apagarTela();

    tp_listase* itens = iniciaListase(); // Inicializando a lista encadeada
    insereListase(&itens, criarItem("Soro", 300, "Retira status negativos do Birdmon ativo."));
    insereListase(&itens, criarItem("Biscoito", 500, "Revive um Birdmon com metade do HP."));
    insereListase(&itens, criarItem("Capacete", 300, "Aumenta a defesa do Birdmon ativo temporariamente."));
    insereListase(&itens, criarItem("Melao", 300, "Aumenta o ataque do Birdmon ativo temporariamente."));
    insereListase(&itens, criarItem("Gaiola", 150, "Captura o Birdmon adversario"));
    insereListase(&itens, criarItem("Alpiste", 250, "Restaura 30 HP do Birdmon ativo."));

    printf("\n");

    int escolha;
    printf("|| ***      ******   ********   ****   ||\n");
    printf("|| ***     **    **     **    ***  *** ||\n");
    printf("|| ***     *      *     **    **    ** ||\n");
    printf("|| ***     *      *  *  **    ******** ||\n");
    printf("|| ******  **    **  *  **    **    ** ||\n");
    printf("|| ******   ******   *****    **    ** ||\n");
    printf("Bem-vindo a Loja!\n");
    printf("Voce tem %d BirdCoins.\n\n", *BirdCoin);

    tp_listase* atual = itens;
    int index = 0;
    while (atual != NULL) {
        ItemLoja* item = (ItemLoja*)atual->info; // Cast para ItemLoja
        switch (index - 1) {
            case 0: // Soro
                printf("  ___   \n");
                printf(" |   |  \n");
                printf(" _| |_  \n");
                printf("|_____|             %d - %s (Preco: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("|_____| \n");
                printf("|_____| \n\n");
                break;

            case 1: // Biscoito
                printf("    *******       \n");
                printf("  ***  @   ****   \n");
                printf(" ** @    @   ***  \n");
                printf(" *    @    @  **    %d - %s (Preço: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf(" *  @        ***  \n");
                printf(" **     @   ***   \n");
                printf("   **********     \n\n");
                break;

            case 2: // Capacete
                printf(" #######  \n");
                printf("##      # \n"); 
                printf("#    ####           %d - %s (Preço: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("#   ##  | \n");
                printf("#   #___| \n");
                printf(" ####     \n\n");
                break;

            case 3:
                printf("          --MM \n");
                printf("      MM##MM:: \n");
                printf("    MMMM####++ \n");
                printf("    ####MM@@++      %d - %s (Preço: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("  MM##MM##  ## \n");
                printf("@@--      MM   \n"); 
                printf("  ########     \n\n");    
                break;

            case 4: // Gaiola
                printf("xxxxxxxxxxxxx \n");
                printf("x  x  x  x  x \n");
                printf("x  x  x  x  x \n");
                printf("x  x  x  x  x       %d - %s (Preço: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("x  x  x  x  x \n");
                printf("x  x  x  x  x \n");
                printf("xxxxxxxxxxxxx \n\n");
                break;

            case 5: // Alpiste
                printf("|-------------| \n");
                printf("|   ALPISTE   | \n");
                printf("|-------------| \n");
                printf("|:::::::::::::|     %d - %s (Preço: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                printf("|:::::::::::::| \n");
                printf("|:::::::::::::| \n");
                printf("|-------------| \n\n");
                break;
        }
        atual = atual->prox;
        index++;
    }

    printf("Escolha um item pelo numero (ou 0 para sair): ");
    scanf("%d", &escolha);

    if (escolha > 0 && escolha < index) {
        atual = itens;
        for (int i = 1; i < escolha; i++) {
            atual = atual->prox;
        }

        if (atual != NULL) {
            ItemLoja* item = (ItemLoja*)atual->info; // Cast para ItemLoja
            if (*BirdCoin >= item->preco) {
                char confirmacao;
                printf("Voce selecionou %s por %d BirdCoins. Deseja confirmar a compra? (s/n): ", item->nome, item->preco);
                scanf(" %c", &confirmacao); // O espaço antes de %c é para ignorar qualquer espaço em branco

                if (confirmacao == 's' || confirmacao == 'S') {
                    *BirdCoin -= item->preco;
                    adicionarAoInventario(inv, item->nome); // Função para adicionar o item ao inventário
                    printf("Voce comprou %s por %d BirdCoins.\n", item->nome, item->preco);
                    printf("BirdCoins restantes: %d\n", *BirdCoin);
                } else {
                    printf("Compra cancelada.\n");
                }
            } else {
                printf("Voce nao tem BirdCoins suficientes para comprar %s.\n", item->nome);
            }
        }
    } else if (escolha != 0) {
        printf("Escolha invalida. Tente novamente.\n");
    }

    printf("Saindo da loja...\n");
    liberarLista(itens);
}

#endif
