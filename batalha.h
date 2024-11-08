#ifndef BATALHA_H //if not define
#define BATALHA_H

#include "pokemon.h"
#include "sprites.h"
#include "apagartela.h"
#include "habilidade.h"
#include "fila.h"
#include "inventario.h"
#include "tipo.h"

#define deslocamentoDoOponente 80
#define deslocAtaque 25


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
    int centroDaTela = 50; //numero ajustavel, muda onde o RODADA vai ficar

    apagarTela();
    printf("%*c", centroDaTela, ' ');
    printf("RODADA %d\n", rodada);

    //printar o inimigo
    printarPokemon(*pokeInimigo, 1);
    
    //printar o pokemon do jogador
    printarPokemon(pokeUsuario[pokeAtivo], 0);
 


}

//versao alterada leticia do mato
//alterações: passando a fila por copia, loop while para retirar os intens da fila
void printarAtaque(tp_fila fila){
    tp_hab ataque;
    int num = 1;
    while(!filaVazia(&fila)){
	removeFila(&fila, &ataque);
    //insereFila(&fila, ataque);
   	printf("%d. %s", num, ataque.nome);
	   if(num == 1 || num == 3){
	   printf("%*c",deslocAtaque - strlen(ataque.nome), ' ');
	   }else{
	   printf("\n");
   	   }
	   num++;
	}
    printf("\n0 - para voltar\n");
}

void atacar(tp_pokemon *pokeAtacante, tp_pokemon *pokeAlvo, int numAtaque, tp_fila filahab){
    //pega a fila de habilidades do atacante como copia, entao pode desempilhar a vontade
    tp_hab ataque;
    for(int i = 0; i<numAtaque; i++){
        removeFila(&filahab, &ataque);
    }
    printf("%s usou %s...\n", pokeAtacante->nome, ataque.nome);

    //conferir se o alvo ira ou nao desviar do golpe
    int danoDeTipo = multiplicadorDeTipo(ataque.tipo, pokeAlvo->tipo);
    int dado = rand()%100;
    int chanceDeDesviar = pokeAlvo->agil/2;
    if(dado>chanceDeDesviar){ //ataque acertou
    pokeAlvo->vida = pokeAlvo->vida - ((ataque.dano + pokeAtacante->atq)*pokeAlvo->def)*(danoDeTipo/2);
   
    switch(danoDeTipo){
        case 1:
        printf("o ataque nao foi muito eficaz...");
        break;
        case 2:
        printf("o ataque acertou!");
        break;
        case 4:
        printf("o ataque foi super efetivo!");
        break; 
    }
    }else{ //ataque errou
    printf("%s desviou do golpe!", pokeAlvo->nome);
    }
}

// Função de troca de Birdmon
void trocarBirdmon(tp_pokemon pokeUsuario[], int *totalBirdmons, int *pokeAtivo) {
    apagarTela();
    int escolha;
    printf("Escolha um Birdmon para a batalha:\n");
    for (int i = 0; i < *totalBirdmons; i++) {
        printf("%d - %s (HP: %d/%d)\n", i + 1, pokeUsuario[i].nome, pokeUsuario[i].vida, pokeUsuario[i].vidamax);
    }
    printf("Escolha: ");
    scanf("%d", &escolha);
    if (escolha > 0 && escolha <= *totalBirdmons) {

        if(!pokeUsuario[escolha-1].vivo){
            printf("Este Birdmon foi derrotado! Reviva-o para chama-lo novamente!\n");
            sleep(5);
            return trocarBirdmon(pokeUsuario, totalBirdmons, pokeAtivo);

        }else{
        pokeUsuario[*pokeAtivo] = pokeUsuario[escolha - 1];
        printf("Você escolheu %s para a batalha!\n", pokeUsuario[*pokeAtivo].nome);
        }
        
    } else {
        printf("Escolha inválida.\n");
        sleep(5);
        return trocarBirdmon(pokeUsuario, totalBirdmons, pokeAtivo);
    }
}


// Função principal do menu de batalha
void menuBatalha(int *pokeAtivo, tp_pokemon *pokeInimigo, Inventory *inv, tp_pokemon pokeUsuario[], int *pokeUsuarioQtd, int rodada) {
    int escolha;
    tp_hab ataque;
    printf("\n--- Menu de Batalha ---\n");
    printf("1. Atacar\n");
    printf("2. Inventario\n");
    printf("3. Birdmons\n");
    //printf("4. Fugir\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    
	int numAtaque;
    switch (escolha) {
        case 1:

            apagarTela();
            printarBatalha(pokeUsuario, pokeInimigo, *pokeAtivo, rodada);
            printarAtaque(pokeUsuario->hab);
            scanf("%d", &numAtaque);
            if(numAtaque == 0){
            //voltar
            apagarTela();
            printarBatalha(pokeUsuario, pokeInimigo, *pokeAtivo, rodada);
            return  menuBatalha(pokeAtivo, pokeInimigo, inv, pokeUsuario, pokeUsuarioQtd, rodada);
            }else if(numAtaque > 0 && numAtaque <= 4){
                atacar(&pokeUsuario[*pokeAtivo], pokeInimigo, numAtaque, pokeUsuario[*pokeAtivo].hab);
                
            }else{
                printf("Opcao invalida. Tente novamente.\n");
	            //voltar
	            apagarTela();
	            printarBatalha(pokeUsuario, pokeInimigo, *pokeAtivo, rodada);
				return menuBatalha(pokeAtivo, pokeInimigo, inv, pokeUsuario, pokeUsuarioQtd, rodada);
				sleep(5);
				break;
           }

             /*
            realizarAtaque(pokeAtivo, *pokeInimigo);
            if (pokeInimigo->vida <= 0) {
                printf("%s foi derrotado!\n", pokeInimigo->nome);
                }
            */
        break;

        case 2:
            displayInventory(inv);
		aplicarEfeito(item, poke.vida, poke.atq, poke.def, poke.agil);
        break;

        case 3:
            trocarBirdmon(pokeUsuario, pokeUsuarioQtd, pokeAtivo);
        break;

        
        case 4:
          capturarBirdmon(pokeInimigo, inv);
            break;  // Sai da batalha
        
        default:
            printf("Opcao invalida. Tente novamente.\n");
            //voltar
            apagarTela();
            printarBatalha(pokeUsuario, pokeInimigo, *pokeAtivo, rodada);
            return  menuBatalha(pokeAtivo, pokeInimigo, inv, pokeUsuario, pokeUsuarioQtd, rodada);
            break;
        	
    }
   
}
/*
void menuDeBatalha(tp_pokemon pokeUsuario[], tp_pokemon *pokeOponente, int pokeAtivo, int rodada) {
    int escolha;

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
            apagarTela();
            printarBatalha(pokeUsuario, pokeOponente, pokeAtivo, rodada);
           
            printarAtaque(pokeUsuario->hab);
            

            //printar selecao de ataques
            
            
            break;

        default:
            printf("Escolha inválida. Tente novamente.\n");
            break;
    }
    
}
*/

void turnoDoInimigo(int *pokeAtivo, tp_pokemon *pokeInimigo, tp_pokemon pokeUsuario[]){
    //randomizar ataque do oponente
    int numAtaque = rand()%4 + 1;
    atacar(pokeInimigo, &pokeUsuario[*pokeAtivo], numAtaque, pokeInimigo->hab);
}

int verificarVivos(int *pokeAtivo, tp_pokemon *pokeInimigo, tp_pokemon pokeUsuario[], int rodada, int pokeUsuarioQtd){
    //return 0: todo mundo ta de boa, ninguem morreu nesse turno
    //return 1: inimigo perdeu
    //return 2: pokemon ativo do jogador foi derrotado
    //return 3: todos os pokemons do jogador foram derrotados

    if(pokeInimigo->vida <= 0){
        pokeInimigo->vivo = 0;
        printf("O %s selvagem foi derrotado!\n");
        return 1; //inimigo perdeu
    }

    int aliadosDerrotados = 0;
    if(pokeUsuario[*pokeAtivo].vida <= 0){ //se o pokemon ativo do jogador for derrotado:
        pokeUsuario[*pokeAtivo].vivo = 0;
        //printf("%s foi derrotado!\n");
        
        for(int i=0; i<pokeUsuarioQtd; i++){
            if(!pokeUsuario[i].vivo) aliadosDerrotados++;
        }
        if(aliadosDerrotados==pokeUsuarioQtd) return 3; //jogador perdeu
        else return 2; //o pokemon ativo do jogador perdeu, mas ele ainda tem outros pokemons vivos
    }else return 0; //ta todo mundo de boa, nada aconteceu nesse turno

}

int batalha(int rodada, int *pokeUsuarioQtd, tp_pokemon pokeUsuario[], tp_pilha *pokeOponentes, Inventory *inventario, int *pokeAtivo){

    apagarTela();

    int situacao;

    tp_pokemon pokeInimigo;
    pop(pokeOponentes, &pokeInimigo); //pega o inimigo no topo da pilha e torna ele o atual da batalha
    pokeInimigo.nivel = rodada;

    while(1){ //loop "infinito" - quebra apenas quando alguem morrer
        printarBatalha(pokeUsuario, &pokeInimigo, *pokeAtivo, rodada); 
        menuBatalha(pokeAtivo, &pokeInimigo, inventario, pokeUsuario, pokeUsuarioQtd, rodada);
        situacao = verificarVivos(pokeAtivo, &pokeInimigo, pokeUsuario, rodada, *pokeUsuarioQtd);
        sleep(5);
        switch(situacao){
            case 1: return 1; //inimigo perdeu, essa rodada acabou
            case 2: trocarBirdmon(pokeUsuario, pokeUsuarioQtd, pokeAtivo);
            break;
            case 3: return 0; //jogador perdeu, acabou o jogo
            default: break; //jogo continua
        }
        
       
        printarBatalha(pokeUsuario, &pokeInimigo, *pokeAtivo, rodada);
        turnoDoInimigo(pokeAtivo, &pokeInimigo, pokeUsuario);
        situacao = verificarVivos(pokeAtivo, &pokeInimigo, pokeUsuario, rodada, *pokeUsuarioQtd);
        sleep(5);
        switch(situacao){
            case 1: return 1; //inimigo perdeu, essa rodada acabou
            case 2: trocarBirdmon(pokeUsuario, pokeUsuarioQtd, pokeAtivo);
            break;
            case 3: return 0; //jogador perdeu, acabou o jogo
            default: break; //jogo continua
        }
    }

}







#endif
