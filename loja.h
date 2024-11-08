#ifndef LOJA_H
#define LOJA_H
#include <stdio.h>
#include <string.h>
#include "inventario.h"
#define MAX 100
//teoricamente é p funcionar
// Estrutura de item da loja
typedef struct {
    char nome[50];
    int preco;
    char descricao[100];
} ItemLoja;

// Função para exibir a loja e permitir a compra de itens
void loja(Inventory *inv, int *BirdCoin) {
    ItemLoja itens[6] = {
        {"Alpiste", 250, "Restaura 30 HP do Birdmon ativo."},
        {"Gaiola", 150, "Captura o Birdmon adversário"},
        {"Melao", 300, "Aumenta o ataque do Birdmon ativo temporariamente."},
        {"Capacete", 300, "Aumenta a defesa do Birdmon ativo temporariamente."},
        {"Biscoito", 500, "Revive um Birdmon com metade do HP."},
        {"Soro", 300, "Retira status negativos do Birdmon ativo."}
    };

    int escolha;
    printf("\nBem-vindo a Loja!\n");
    printf("Você tem %d BirdCoins.\n", *BirdCoin);

    for (int i = 0; i < 6; i++) {
        printf("%d - %s (Preço: %d BirdCoins): %s\n", i + 1, itens[i].nome, itens[i].preco, itens[i].descricao);
    }
    printf("Escolha um item para comprar (ou 0 para sair): ");
    scanf("%d", &escolha);

    while (escolha != 0) {
        if (escolha >= 1 && escolha <= 6) {
            int itemIndex = escolha - 1;
            if (*BirdCoin >= itens[itemIndex].preco) {
                *BirdCoin -= itens[itemIndex].preco;
                adicionarAoInventario(inv, itens[itemIndex].nome);
                printf("BirdCoins restantes: %d\n", *BirdCoin);
            } else {
                printf("BirdCoins insuficientes para comprar este item.\n");
            }
        } else {
            printf("Escolha inválida. Tente novamente.\n");
        }

        printf("\nEscolha outro item para comprar ou 0 para sair: ");
        scanf("%d", &escolha);
    }

    printf("Obrigado por visitar a loja!\n");
}

#endif