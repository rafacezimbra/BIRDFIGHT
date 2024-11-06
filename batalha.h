#ifndef BATALHA_H //if not define
#define BATALHA_H

#include "pokemon.h"
#include "sprites.h"
#include "apagartela.h"
#define deslocamentoDoOponente 40


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



void printarBatalha(tp_pokemon pokeUsuario[], tp_pokemon *pokeInimigo, int pokeAtivo, int rodada){ //printa o estado da batalha

    //tamanho da tela inicial: 134
    //tamanho do sprite do maior pokemon: 84

    //para printar varios espacos pode-se usar printf("%*c", quantidade-de-espacos, ' ');

    int qtdDeEspacos = deslocamentoDoOponente; //numero ajustavel
    int centroDaTela = 30; //numero ajustavel, muda onde o RODADA vai ficar

    apagarTela();
    printf("%*c", centroDaTela, ' ');
    printf("RODADA %d\n", rodada);

    //printar o inimigo
    printf("%*c", qtdDeEspacos, ' '); //printa uma certa quantidade de espacos pra deixar o oponente e seus status mais a direita
    printf("%s    Lvl: %d\n", pokeInimigo->nome, pokeInimigo->nivel);
    printf("%*c", qtdDeEspacos, ' ');
    printf("HP: %d/%d\n", pokeInimigo->vida, pokeInimigo->vidamax);
    printarPokemon(*pokeInimigo, 1);

    //printar o pokemon do jogador
    printarPokemon(pokeUsuario[pokeAtivo], 0);
    printf("%s   Lvl: %d \n", pokeUsuario[pokeAtivo].nome, pokeUsuario[pokeAtivo].nivel);
    printf("HP: %d \n", pokeUsuario[pokeAtivo].vida);


}

/*
void menuDeBatalha(BATALHA *batalha, tp_pokemon *pokeUsuario, tp_pokemon *pokeOponente) {
    int escolha;

    while (playerVivo(batalha->pokeUsuarioQtd, pokeUsuario) && pokeOponente->vivo) {
        printf("\nEscolha sua ação:\n");
        printf("1 - Acessar Inventário\n");
        printf("2 - Capturar Pokémon\n");
        printf("3 - Trocar Pokémon\n");
        printf("4 - Selecionar Ataque\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // fazer a função do inventario
                break;

            case 2:
                //fazer a função para capturar
                break;

            case 3:
                // fazer a função para trocar o pkm
               
                break;

            case 4:
                // fazer a função de selecionar atk
                break;

            default:
                printf("Escolha inválida. Tente novamente.\n");
                break;
        }
    }
}
*/

void batalha(int rodada, int *pokeUsuarioQtd, tp_pokemon pokeUsuario[], tp_pilha *pokeOponentes){

    apagarTela();

    //0 eh um valor placeholder
    int pokeAtivo = 0; //posicao do pokemon do jogador ativo no vetor pokeUsuario - mudar isso depois para o ultimo pokemon equipado

    tp_pokemon pokeInimigo;
    pop(pokeOponentes, &pokeInimigo); //pega o inimigo no topo da pilha e torna ele o atual da batalha
    pokeInimigo.nivel = rodada;

    printarBatalha(pokeUsuario, &pokeInimigo, pokeAtivo, rodada); 
    sleep (100); //placeholder


}



#endif