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
int capturarBirdmon(Birdmon *pokeInimigo, Inventory *inv) {
    // Procura a "Gaiola" no inventário do jogador
    for (int i = 0; i < 6; i++) {
        if (strcmp(inv->items[i].name, "Gaiola") == 0) {
            if (inv->items[i].quantity > 0) {
                // Reduz a quantidade de gaiolas no inventário
                inv->items[i].quantity--;

                // Calcula a chance de captura baseada no HP do inimigo
                int hpMaximo = pokeInimigo->hpMax;  // Supondo que hpMax seja o HP total do Birdmon
                int hpAtual = pokeInimigo->hpAtual; // HP atual do Birdmon

                // Calcula o percentual de vida restante
                float hpPercentual = ((float)hpAtual / hpMaximo) * 100;
                
                // A chance de captura aumenta quanto menor o hpPercentual
                int chanceDeCaptura = (int)(100 - hpPercentual); // Exemplo: 50% HP restante = 50% de chance

                // Gera um número aleatório para determinar o sucesso da captura
                srand(time(NULL));
                int resultado = rand() % 100;

                if (resultado < chanceDeCaptura) { // Sucesso se o número aleatório estiver abaixo da chance calculada
                    printf("Parabéns! Você capturou o Birdmon %s!\n", pokeInimigo->nome);
                    return 1; // Captura bem-sucedida
                } else {
                    printf("A tentativa de captura falhou! O Birdmon escapou.\n");
                    return 0; // Captura falhou
                }
            } else {
                printf("Você não tem gaiolas suficientes no inventário!\n");
                return -1; // Falha devido à falta de gaiolas
            }
        }
    }

    printf("Gaiola não encontrada no inventário!\n");
    return -1; // Falha devido à ausência de gaiola
}
#endif