#ifndef BATALHA_H //if not define
#define BATALHA_H

#include "pokemon.h"

//checa se o jogador esta vivo
int playerVivo(int pokeUsuarioQtd, tp_pokemon pokeUsuario[]){ //procura um pokemon do jogador que esteja vivo. Se nao houver, o jogador perdeu
    for(int i=0; i<pokeUsuarioQtd; i++){
        if(pokeUsuario[i].vivo) return 1;
    }
    return 0;
}

void perdeu(){
    printf("\n Voce perdeu!\n");
	printf("\n digite qualquer valor para encerrar o programa\n");
	char lixo;
	scanf(" %c", &lixo);
}

void printarBatalha(tp_pokemon pokeUsuario[], tp_pokemon pokeInimigo, int pokeAtivo){ //printa o estado da batalha

    //printf("")

}

void batalha(int rodada, int *pokeUsuarioQtd, tp_pokemon pokeUsuario[], tp_pilha *pokeOponentes){

    apagarTela();

    int pokeAtivo = 0; //posicao do pokemon do jogador ativo no vetor pokeUsuario

    tp_pokemon pokeInimigo = pokeOponentes.top(); //o inimigo atual da batalha
    pokeOponentes.pop();



}

#endif