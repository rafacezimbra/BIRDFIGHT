#ifndef LOJA_H
#define LOJA_H
#include <stdio.h>
#include <string.h>
#include <stdilb.h>
#include "inventario.h"
#include "apagartela.h"
#define MAX 100

typedef struct {
    char nome[50];
    int preco;
    char descricao[100];
} ItemLoja;

typedef struct {
    ItemLoja *itens;
    int quantidade; // to keep track of the number of items
} Loja;


void inicializarLoja(Loja *loja) {
    loja->quantidade = 6; // setting initial number of items
    loja->itens = (ItemLoja*) malloc(loja->quantidade * sizeof(ItemLoja));
    if (loja->itens == NULL) {
        printf("Erro ao alocar memória para os itens da loja!\n");
        exit(1);
    }
    
    // Adding items to the store
    strcpy(loja->itens[0].nome, "Alpiste");
    loja->itens[0].preco = 250;
    strcpy(loja->itens[0].descricao, "Restaura 30 HP do Birdmon ativo.");

    strcpy(loja->itens[1].nome, "Gaiola");
    loja->itens[1].preco = 150;
    strcpy(loja->itens[1].descricao, "Captura o Birdmon adversario");

    strcpy(loja->itens[2].nome, "Melao");
    loja->itens[2].preco = 300;
    strcpy(loja->itens[2].descricao, "Aumenta o ataque do Birdmon ativo temporariamente.");

    strcpy(loja->itens[3].nome, "Capacete");
    loja->itens[3].preco = 300;
    strcpy(loja->itens[3].descricao, "Aumenta a defesa do Birdmon ativo temporariamente.");

    strcpy(loja->itens[4].nome, "Biscoito");
    loja->itens[4].preco = 500;
    strcpy(loja->itens[4].descricao, "Revive um Birdmon com metade do HP.");

    strcpy(loja->itens[5].nome, "Soro");
    loja->itens[5].preco = 300;
    strcpy(loja->itens[5].descricao, "Retira status negativos do Birdmon ativo.");
}


void liberarLoja(Loja *loja) {
    free(loja->itens);
    loja->itens = NULL;
    loja->quantidade = 0;
}

void loja(Inventory *inv, int *BirdCoin){
    apagarTela();

    Loja loja;

    inicializarLoja(&loja);

    ItemLoja itens[6] = {
        {"Alpiste", 250, "Restaura 30 HP do Birdmon ativo."},
        {"Gaiola", 150, "Captura o Birdmon adversario"},
        {"Melao", 300, "Aumenta o ataque do Birdmon ativo temporariamente."},
        {"Capacete", 300, "Aumenta a defesa do Birdmon ativo temporariamente."},
        {"Biscoito", 500, "Revive um Birdmon com metade do HP."},
        {"Soro", 300, "Retira status negativos do Birdmon ativo."}
    };

printf("\n");

int escolha;
printf("|| ***      ******   ********   ****   ||\n");
printf("|| ***     **    **     **    ***  *** ||\n");
printf("|| ***     *      *     **    **    ** ||\n");
printf("|| ***     *      *  *  **    ******** ||\n");
printf("|| ******  **    **  *  **    **    ** ||\n");
printf("|| ******   ******   *****    **    ** ||\n");
printf("Bem-vindo a Loja!\n");
printf("Voce tem %d BirdCoins.\n", *BirdCoin);

printf("\n");
for (int i = 0; i < 6; i++) {

switch(i){
case 0:
printf("|-------------| \n");
printf("|   ALPISTE   | \n");
printf("|-------------| \n");
printf("|:::::::::::::|     %d - %s (Preco: %d BirdCoins): %s\n", i + 1, itens[i].nome, itens[i].preco, itens[i].descricao);
printf("|:::::::::::::| \n");
printf("|:::::::::::::| \n");
printf("|-------------| \n\n");
break;


//melão
case 1: 
printf("          --MM \n");
printf("      MM##MM:: \n");
printf("    MMMM####++ \n");
printf("    ####MM@@++      %d - %s (Preco: %d BirdCoins): %s\n", i + 1, itens[i].nome, itens[i].preco, itens[i].descricao);
printf("  MM##MM##  ## \n");
printf("@@--      MM   \n"); 
printf("  ########     \n\n");    
break;

//gaiola
case 2:
printf("xxxxxxxxxxxxx \n");
printf("x  x  x  x  x \n");
printf("x  x  x  x  x \n");
printf("x  x  x  x  x       %d - %s (Preco: %d BirdCoins): %s\n", i + 1, itens[i].nome, itens[i].preco, itens[i].descricao);
printf("x  x  x  x  x \n");
printf("x  x  x  x  x \n");
printf("xxxxxxxxxxxxx \n\n");
break;

//soro
case 3:
printf("  ___   \n");
printf(" |   |  \n");
printf(" _| |_  \n");
printf("|_____|             %d - %s (Preco: %d BirdCoins): %s\n", i + 1, itens[i].nome, itens[i].preco, itens[i].descricao);
printf("|_____| \n");
printf("|_____| \n\n");
break;

//biscoito
case 4:
printf("    *******       \n");
printf("  ***  @   ****   \n");
printf(" ** @    @   ***  \n");
printf(" *    @    @  **    %d - %s (Preco: %d BirdCoins): %s\n", i + 1, itens[i].nome, itens[i].preco, itens[i].descricao);
printf(" *  @        ***  \n");
printf(" **     @   ***   \n");
printf("   **********     \n\n");
break;

//capacete
case 5:
printf(" #######  \n");
printf("##      # \n"); 
printf("#    ####           %d - %s (Preco: %d BirdCoins): %s\n", i + 1, itens[i].nome, itens[i].preco, itens[i].descricao);
printf("#   ##  | \n");
printf("#   #___| \n");
printf(" ####     \n\n");
break;

}
}

printf("\nEscolha um item para comprar (ou 0 para sair): ");
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
            printf("Escolha invalida. Tente novamente.\n");
        }

        printf("\nEscolha outro item para comprar ou 0 para sair: ");
        scanf("%d", &escolha);
    }

    printf("Obrigado por visitar a loja!\n");
    liberarLoja(&loja);
}

#endif
