#include <stdio.h>
#include "pokemon.h"
#include "habilidade.h"

void pergunta(tp_pokemon poke[]){

    int birdmonUsuario1;

    printf("Primeiro Birdmon: ");
    scanf("%d", &birdmonUsuario1);
    printf("%s:\n", poke[birdmonUsuario1].nome);
}

int main(void){
    

    tp_pokemon poke[17];
    tp_hab hab[50];

    criarHabilidades(hab);
    criarPokemons(poke, hab);

    pergunta(poke);

      sleep (10);
      
    return 0;
}