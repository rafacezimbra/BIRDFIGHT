#ifndef RANDOMPOKEMONA_H
#define RANDOMPOKEMONA_H
#include <stdio.h>
#include <stdlib.h> //aonde se encontra srand e rand
#include <time.h> //necessario para pegar o tempo do computador e utilizar de seed
#include "pokemon.h"
#include "pilha.h"

#define QTDPOKEMONS 16

int checarPokemonsNaPilha(int birdmonSorteado, int qtdNumSorteados, int pokeOponente[]){

    for(int j = 0; j < qtdNumSorteados; j++) {
        if (birdmonSorteado == pokeOponente[j]){return 1;}
        printf("testeforJ"); //apagar
        }
        return 0;
}

void sortearPokemons(tp_pilha *pokeOponentes, tp_pokemon pokeUsuario[], tp_pokemon poke[]){
int pokeOponente[QTDPOKEMONS-3], birdmonSorteado = 0, qtdNumSorteados=0;

srand(time(NULL)); //necessario apenas no comeco do codigo. Cria a seed da aleatoriedade baseada no tempo do pc.

for(int i = 0; i < 13; i++){
birdmonSorteado = rand()%16 + 1; //roda valores de 1 a 16 -- altere o 16 para mudar o maior numero. altere o 1 para mudar qual o menor numero

    while (checarPokemonsNaPilha(birdmonSorteado, qtdNumSorteados, pokeOponente)==1 || birdmonSorteado == pokeUsuario[0].num || birdmonSorteado == pokeUsuario[1].num || birdmonSorteado == pokeUsuario[2].num) {
        birdmonSorteado = rand() % 16 + 1;  
        }

            pokeOponente[i] = birdmonSorteado;

            // pilha
            push(pokeOponentes, poke[birdmonSorteado]);
            qtdNumSorteados++;

        }
}


#endif

