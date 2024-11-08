#ifndef MENUB_H
#define MENUB_H

#include <stdio.h>
#include <stdlib.h>
#include "batalha.h"
#include "loja.h"
#include "pokemon.h"
#include "habilidade.h"

// Função de troca de Birdmon
void trocarBirdmon(tp_pokemon pokeUsuario[], int totalBirdmons, tp_pokemon *pokeAtivo) {
    int escolha;
    printf("Escolha um Birdmon para a batalha:\n");
    for (int i = 0; i < totalBirdmons; i++) {
        printf("%d - %s (HP: %d/%d)\n", i + 1, pokeUsuario[i].nome, pokeUsuario[i].hp, pokeUsuario[i].hpMax);
    }
    printf("Escolha: ");
    scanf("%d", &escolha);
    if (escolha > 0 && escolha <= totalBirdmons) {
        *pokeAtivo = pokeUsuario[escolha - 1];
        printf("Você escolheu %s para a batalha!\n", pokeAtivo->nome);
    } else {
        printf("Escolha inválida.\n");
    }
}

// Função principal do menu de batalha
void menuBatalha(tp_pokemon *pokeAtivo, tp_pokemon *pokeInimigo, tp_pokemon *inv, tp_pokemon pokeUsuario[], int totalBirdmons) {
    int escolha;
    //tp_pokemon pokeUsuario[] = pokeAtivo; 
    // remove essa linha pois está a sobrescrever a variável que recebe os pokemon do utilizador
    // e está a criar um array com apenas 1 pokemon e o nome dele.

    while (pokeInimigo->hp > 0 && pokeAtivo->hp > 0) {
        printf("\n--- Menu de Batalha ---\n");
        printf("1. Atacar\n");
        printf("2. Inventário\n");
        printf("3. Birdmons\n");
        printf("4. Fugir\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                realizarAtaque(pokeAtivo, *pokeInimigo);
                if (pokeInimigo->hp <= 0) {
                    printf("%s foi derrotado!\n", pokeInimigo->nome);
                }
                break;

            case 2:
                displayInventory(inv);
                break;

            case 3:
                trocarBirdmon(pokeUsuario, totalBirdmons, pokeAtivo);
                break;

            case 4:
                printf("Você fugiu da batalha!\n");
                return;  // Sai da batalha

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
}
#endif