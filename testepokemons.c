#include <stdio.h>
#include "pilha.h"
#include "fila.h"
#include "pokemon.h"
//#include "habilidade.h"

int main(void){

    tp_pokemon pokemon[17];
    
    criarPokemons(pokemon);


    printf("%s", pokemon[1].nome);

    return 0;
}
