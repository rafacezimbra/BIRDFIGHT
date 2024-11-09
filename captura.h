#ifndef CAPTURA_H
#define CAPTURA_H
#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inventario.h"
#include "pokemon.h"
#include "batalha.h"


// Função para tentar capturar o Birdmon inimigo usando uma gaiola
int capturarBirdmon(tp_pokemon *pokeInimigo, Inventory *inv, tp_pokemon pokeUsuario[6], int *quantidadePokemons) {
    // Verifica se o jogador já possui 6 pokémons
    if (*quantidadePokemons >= 6) {
        printf("Seu time está cheio! Você não pode capturar mais Pokémons.\n");
        return -1; // Falha devido à capacidade máxima de Pokémons
    }

    for (int i = 0; i < 6; i++) {
        if (strcmp(inv->items[i].name, "Gaiola") == 0) {
            if (inv->items[i].quantity > 0) {
                // Reduz a quantidade de gaiolas no inventário
                inv->items[i].quantity--;

                // Calcula a chance de captura baseada no HP do inimigo
                int hpMaximo = pokeInimigo->vidamax;  // Supondo que hpMax seja o HP total do Birdmon
                int hpAtual = pokeInimigo->vida; // HP atual do Birdmon

                // Calcula o percentual de vida restante
                float hpPercentual = ((float)hpAtual / hpMaximo) * 100;
                
                // A chance de captura aumenta quanto menor o hpPercentual
                int chanceDeCaptura = (int)(100 - hpPercentual); // Exemplo: 50% HP restante = 50% de chance

                // Gera um número aleatório para determinar o sucesso da captura
                srand(time(NULL));
                int resultado = rand() % 100;

                if (resultado < chanceDeCaptura) { // Sucesso se o número aleatório estiver abaixo da chance calculada
                    printf("Parabens! Voce capturou o Birdmon %s!\n", pokeInimigo->nome);
                    pokeUsuario[*quantidadePokemons] = *pokeInimigo;
                    (*quantidadePokemons)++;
                    pokeInimigo->vida = 0;
                    return 1; // Captura bem-sucedida
                } else {
                    printf("A tentativa de captura falhou! O Birdmon escapou.\n");
                    return 0; // Captura falhou
                }
            } else {
                printf("Voce nao tem gaiolas suficientes no inventario!\n");
                return -1; // Falha devido à falta de gaiolas
            }
        }
    }

    printf("Gaiola não encontrada no inventário!\n");
    return -1; // Falha devido à ausência de gaiola
}
#endif