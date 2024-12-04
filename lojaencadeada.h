#ifndef LOJA_H
#define LOJA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"
#include "apagartela.h"
#include "listase.h"

#define YEL "\e[0;33m"
#define ANSI_COLOR_1 "\x1b[93m"
#define ANSI_COLOR_2 "\x1b[97m"
#define WHT "\e[0;37m"
#define BHRED "\e[1;91m" //vermelho
#define BHMAG "\e[1;95m" //rosinha
#define BHBLU "\e[1;94m" //azul
#define BHCYN "\e[1;96m" //ciano
#define BHGRN "\e[1;92m" //verde
#define BHBLK "\e[1;90m" //preto

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

void liberarLista(tp_listase* lista) {
    tp_listase* temp;
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
    insereListase(&itens, criarItem("Alpiste", 250, "Restaura 60 HP do Birdmon ativo."));

    printf("\n");

    int escolha;

    while(1){
        apagarTela();
        printf(YEL);
        printf("|| ***      ******   ********   ****   ||\n");
        printf("|| ***     **    **     **    ***  *** ||\n");
        printf("|| ***     *      *     **    **    ** ||\n");
        printf("|| ***     *      *  *  **    ******** ||\n");
        printf("|| ******  **    **  *  **    **    ** ||\n");
        printf("|| ******   ******   *****    **    ** ||\n");
        printf("Bem-vindo a Loja!\n");
        printf("Voce tem %d BirdCoins.\n\n", *BirdCoin);
        printf(WHT);

        tp_listase* atual = itens;
        int index = 1;
        while (atual != NULL) {
            ItemLoja* item = (ItemLoja*)atual->info; // Cast para ItemLoja
            switch (index - 1) {
                case 0: // Soro
                    printf(BHBLU);
                    printf("  ___   \n");
                    printf(" |   |  \n");
                    printf(" _| |_  \n");
                    printf("|_____|             %d - %s (Valor: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                    printf(WHT);
                    printf("|_____| \n");
                    printf(BHBLU);
                    printf("|_____| \n\n");
                    printf(WHT);
                    break;

                case 1: // Biscoito
                    printf(BHMAG);
                    printf("    *******       \n");
                    printf("  ***  @   ****   \n");
                    printf(" ** @    @   ***  \n");
                    printf(" *    @    @  **    %d - %s (Valor: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                    printf(" *  @        ***  \n");
                    printf(" **     @   ***   \n");
                    printf("   **********     \n\n");
                    printf(WHT);
                    break;

                case 2: // Capacete
                    printf(BHRED);
                    printf(" #######  \n");
                    printf("##      # \n"); 
                    printf("#    ####           %d - %s (Valor: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                    printf("#   ##  | \n");
                    printf("#   #___| \n");
                    printf(" ####     \n\n");
                    printf(WHT);
                    break;

                case 3:
                    printf(YEL);
                    printf("          --MM \n");
                    printf("      MM##MM:: \n");
                    printf("    MMMM####++ \n");
                    printf("    ####MM@@++      %d - %s (Valor: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                    printf("  MM##MM##  ## \n");
                    printf("@@--      MM   \n"); 
                    printf("  ########     \n\n");   
                    printf(WHT); 
                    break;

                case 4: // Gaiola
                    printf(BHBLK);
                    printf("xxxxxxxxxxxxx \n");
                    printf("x  x  x  x  x \n");
                    printf("x  x  x  x  x \n");
                    printf("x  x  x  x  x       %d - %s (Valor: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                    printf("x  x  x  x  x \n");
                    printf("x  x  x  x  x \n");
                    printf("xxxxxxxxxxxxx \n\n");
                    printf(WHT);
                    break;

                case 5: // Alpiste
                    printf(BHGRN);
                    printf("|-------------| \n");
                    printf("|   ALPISTE   | \n");
                    printf("|-------------| \n");
                    printf(BHBLU);
                    printf("|:::::::::::::|     %d - %s (Valor: %d BirdCoins): %s\n", index, item->nome, item->preco, item->descricao);
                    printf("|:::::::::::::| \n");
                    printf("|:::::::::::::| \n");
                    printf("|-------------| \n\n");
                    printf(WHT);
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
                        continue;
                    } else {
                        printf("Compra cancelada.\n");
                        continue;
                    }
                } else {
                    printf("Voce nao tem BirdCoins suficientes para comprar %s.\n", item->nome);
                    printf("Preco: %d BirdCoins. Voce tem apenas: %d BirdCoins.\n", item->preco, *BirdCoin);
                    continue;
                }
            }
        } else if (escolha != 0) {
            printf("Escolha invalida. Tente novamente.\n");
        } else{
            break;
        }
        apagarTela();
    }
    printf("Saindo da loja...\n");
    liberarLista(itens);
    
}
#endif