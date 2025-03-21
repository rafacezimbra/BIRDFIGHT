#ifndef RANDOMPOKEMON_H
#define RANDOMPOKEMON_H
#include <stdio.h>
#include <stdlib.h> //aonde se encontra srand e rand
#include <time.h> //necessario para pegar o tempo do computador e utilizar de seed
#include "pokemon.h"
#include "pilha.h"
#define QTDPOKEMONS 16

void sortearPokemons(tp_pilha *pokeOponentes, tp_pokemon pokeUsuario[], tp_pokemon poke[]){

    
    srand(time(NULL)); 
    int vetor[QTDPOKEMONS-3+1];
    int vetorembaralhado[QTDPOKEMONS-3];
    int j = 1;
    
    //coloca os numeros de cada pokemon dentro do vetor que vai sortea-los (tirando os numeros dos pokemons escolhidos)
    for(int i=0; i<QTDPOKEMONS-3; i++){
         
        vetor[i] = j;
        while(j == pokeUsuario[0].num || j == pokeUsuario[1].num || j == pokeUsuario[2].num){
            j++;
        }
        vetor[i] = j;
        j++;
    }

    //momento pra embaralhar de fato
    for(int i=0; i<QTDPOKEMONS-3; i++){
         
        int aleatorio = rand()%13;
        int aux;

        aux = vetor[i];
        vetor[i] = vetor[aleatorio];
        vetor[aleatorio] = aux;
    }

    for(int i=0; i<QTDPOKEMONS-3; i++){
        push(pokeOponentes, poke[vetor[i]]);

    }
}

#endif
