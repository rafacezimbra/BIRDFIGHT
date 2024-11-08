#ifndef MENUB_H
#define MENUB_H

#include <stdio.h>
#include <stdlib.h>
#include "loja.h"
#include "pokemon.h"
#include "habilidade.h"

// Função de troca de Birdmon
void trocarBirdmon(tp_pokemon pokeUsuario[], int totalBirdmons, int *pokeAtivo) {
    int escolha;
    printf("Escolha um Birdmon para a batalha:\n");
    for (int i = 0; i < totalBirdmons; i++) {
        printf("%d - %s (HP: %d/%d)\n", i + 1, pokeUsuario[i].nome, pokeUsuario[i].vida, pokeUsuario[i].vidamax);
    }
    printf("Escolha: ");
    scanf("%d", &escolha);
    if (escolha > 0 && escolha <= totalBirdmons) {
        pokeUsuario[*pokeAtivo] = pokeUsuario[escolha - 1];
        printf("Você escolheu %s para a batalha!\n", pokeUsuario[*pokeAtivo].nome);
    } else {
        printf("Escolha inválida.\n");
    }
}

// Função principal do menu de batalha
void menuBatalha(int *pokeAtivo, tp_pokemon *pokeOponente, Inventory *inv, tp_pokemon pokeUsuario[], int totalBirdmons, int rodada) {
int escolha;

    printf("\n--- Menu de Batalha ---\n");
    printf("1. Atacar\n");
    printf("2. Inventário\n");
    printf("3. Birdmons\n");
    printf("4. Fugir\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:

            apagarTela();
            printarBatalha(pokeUsuario, pokeOponente, *pokeAtivo, rodada);
            printarAtaque(pokeUsuario->hab);
            /*
            realizarAtaque(pokeAtivo, *pokeInimigo);
            if (pokeInimigo->vida <= 0) {
                printf("%s foi derrotado!\n", pokeInimigo->nome);
                }
            */
            
            break;

        case 2:
            displayInventory(inv);
            break;

        case 3:
            trocarBirdmon(pokeUsuario, totalBirdmons, pokeAtivo);
            break;

        case 4:
          capturarBirdmon(pokeInimigo, inv);
            break;  // Sai da batalha

        default:
            printf("Opção inválida. Tente novamente.\n");
            return menuBatalha(pokeAtivo, pokeOponente, inv, pokeUsuario, totalBirdmons, rodada);
    }
    
}
#endif
