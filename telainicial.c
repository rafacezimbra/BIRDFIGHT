//atencao, para testar o codigo, sempre compile ele antes (clicando em run)
//e depois abra o .bat pela pasta do windows, nao por aqui.

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "pokemon.h"
#include "habilidade.h"
#include "pilha.h"
#include "sprites.h"
#include "randompokemon.h"
#include "batalha.h"
#include "loja.h"
#include "apagartela.h"
#include "inventario.h"

#define QTDPOKEMONS 16



void menu(char nomeUsuario[], int *pokeUsuarioQtd, tp_pokemon pokeUsuario[]){
	
	apagarTela();
	//textcolor(5);
	printf("|| *********    *******  *******       ********                ************* *******       *********   ***      *** *************** ||\n"); 
	printf("|| ***********   *****  **********    **     ***               *************  *****   ***************  ***      *** *************** ||\n");
	printf("|| **      ****   ***   **      **    **       ***             ***             ***    ************     ***      ***       ***       ||\n"); 
	printf("|| **       ***   ***   **   ****     **        ***            ***             ***   ****              ***      ***       ***       ||\n"); 
	printf("|| **        **   ***   **   ***      **         **            ***             ***   ****              ***      ***       ***       ||\n");
	printf("|| **       **    ***   *******       **         **   ******   ***********     ***   ***               ************       ***       ||\n");
	printf("|| **  ******     ***   ********      **         **   ******   ***********     ***   ***               ************       ***       ||\n");
	printf("|| **       **    ***   ***  ****     **         **            ***             ***   ***       *****   ***      ***       ***       ||\n");
	printf("|| **        **   ***   ***   ****    **         **            ***             ***   ***       ******  ***      ***       ***       ||\n");
	printf("|| **       ***   ***   ***    ****   **        ***            ***             ***    ***          *** ***      ***       ***       ||\n");
	printf("|| **    *****    ***   ***     ***   **       ***             ***             ***     *****      **** ***      ***       ***       ||\n");
	printf("|| **********    *****  ***      ***  **     *****             ***            *****     *************  ***      ***       ***       ||\n");
	printf("|| ********     ******* ***      ***   *********               ***           *******      *********    ***      ***       ***       ||\n");
	printf("||                                                                                                                                  ||\n");
 	printf("||                                               SELECIONE SEUS TRES BIRDMONS:                                                      ||\n");
	printf("||                                                                                                                                  ||\n");
	printf("||                      1- Pikapombo              |  2- Cocatriz              |  3- Pato do Clube                                   ||\n");
	printf("||                      4- Flamingo Capoeirista   |  5- Galo Guerreiro        |  6- Galinha Pintadinha                              ||\n");
	printf("||                      7- Ticoliro               |  8- Dodo                  |  9- Rolinha                                         ||\n");
	printf("||                      10- Joao                  |  11- Canarinho Sambista   |  12- Corvo Emo Gotico                               ||\n");
	printf("||                      13- Papaleguas            |  14- Pica-Pau             |  15- Recruta                                        ||\n");
	printf("||                                                |  16- Kiwi                 |                                                     ||\n");
	printf("||                                                                                                                                  ||\n");
	printf("||                                                                                                                                  ||\n");

	if(*pokeUsuarioQtd>0){
	printf("                                                   EQUIPE DE %s                                                                      \n", nomeUsuario);
	printf("                                                 * %s                                                                                \n", pokeUsuario[0].nome);
	if(*pokeUsuarioQtd>1){
	printf("                                                 * %s                                                                                \n", pokeUsuario[1].nome);
	if(*pokeUsuarioQtd>2){
	printf("                                                 * %s                                                                                \n", pokeUsuario[2].nome);
	}
	}
	}
}

int checarSePokeJaFoiEscolhido(int *pokeUsuarioQtd, tp_pokemon poke[], tp_pokemon pokeUsuario[], int pokeEscolhido){

	for(int i=0; i<*pokeUsuarioQtd; i++){

		if(pokeUsuario[i].num == poke[pokeEscolhido].num){
			return 1;
		}
	}
	return 0;
}

void escolha(char nomeUsuario[], tp_pokemon pokeUsuario[], tp_pokemon poke[], int *pokeUsuarioQtd){
    char resp;
    int birdmonUsuario; //numero q a pessoa vai digitar

    while(*pokeUsuarioQtd!=3){




    	printf("%d Birdmon: ", *pokeUsuarioQtd+1);
	    scanf(" %d", &birdmonUsuario); //escaneia o numero q o usuario digitou

			if(birdmonUsuario > QTDPOKEMONS || birdmonUsuario < 1){ //checar se o valor eh um numero de um passaro
				printf("Este valor nao eh valido!");
				sleep(3);
				menu(nomeUsuario, pokeUsuarioQtd, pokeUsuario);

			}else if(checarSePokeJaFoiEscolhido(pokeUsuarioQtd, poke, pokeUsuario, birdmonUsuario)){ //checar se o passaro ja foi escolhido
				printf("Este passaro ja foi escolhido!");
				sleep(3);
				menu(nomeUsuario, pokeUsuarioQtd, pokeUsuario);
				
		}else{
	 	apagarTela();

		printarPokemon(poke[birdmonUsuario], -1);
		printf("%s:\n", poke[birdmonUsuario].nome);
	    printf("Tipo: %s\n", poke[birdmonUsuario].tipo);
	    printf("Vida: %d\n", poke[birdmonUsuario].vida); 
	    printf("Ataque: %d\n", poke[birdmonUsuario].atq);
	    printf("Defesa: %.2f\n", poke[birdmonUsuario].def);
	    printf("Agilidade: %d\n", poke[birdmonUsuario].agil); 
		printf("\n");
		printf("Habilidades:"); 
		imprimeFila(poke[birdmonUsuario].hab);
		
	    printf("\n\n");

	    printf("Voce deseja manter %s no seu time? (s/n) ", poke[birdmonUsuario].nome);
	    scanf(" %c", &resp); 
	    switch(resp){

				case 'S':
				case 's':pokeUsuario[*pokeUsuarioQtd] = poke[birdmonUsuario]; //copia o pokemon do numero escolhido para os pokemons do jogador
						(*pokeUsuarioQtd)++; 
						menu(nomeUsuario, pokeUsuarioQtd, pokeUsuario);
						break;
					
				case'N':
				case 'n':menu(nomeUsuario, pokeUsuarioQtd, pokeUsuario);
						break;
						
							
				default:printf("\nOpcao invalida");
						break;
			}	

			if(*pokeUsuarioQtd == 3){

				printf("\nVoce deseja ficar com esses tres Birdmons? ");
				scanf(" %c", &resp); 
				switch(resp){

				case 'S':
				case 's': break;
						
					
				case'N':
				case 'n':*pokeUsuarioQtd = 0;
						menu(nomeUsuario, pokeUsuarioQtd, pokeUsuario);

						break;
						
							
				default:printf("\nOpcao invalida");
						break;
				}
			}
		}
	}	
}



int main (void) {
    tp_hab hab[50]; //declaracao das habilidades
    char nomeUsuario[30];
    int birdmonUsuario1, birdmonUsuario2, birdmonUsuario3; //se for usar pilha, talvez nn precise tmb

 
	tp_pokemon poke[QTDPOKEMONS + 1]; //declara todos os pokemons
	tp_pokemon pokeUsuario[6]; //pokemons do usuario
	tp_pilha pokeOponentes; //pilha de pokemons inimigos
	Inventory inventario;
	int pokeUsuarioQtd = 0; //quantidade de pokemons q o usuario tem

    inicializaPilha(&pokeOponentes);
	initializeInventory(&inventario);
    
    //criarHabilidades(hab);
    criarPokemons(poke, hab);

	printf("POR FAVOR COLOQUE A JANELA EM TELA CHEIA\n\n");
    sleep (1);
    printf("O mundo dos Birdmon eh um mundo cheio de misterios...\n");
    sleep (1);
    printf("Voce acaba de se mudar para a cidade de Xique-Xique, Bahia.\n");
    sleep (1);
    printf("Qual o seu nome? ");
    scanf(" %[^\n]s", nomeUsuario);
    printf("%s, que belo nome. Seja bem-vindo(a) ao BirdFight!\n", nomeUsuario);
    sleep (4);

    printf("\n");
    printf("\n");

    // LIMPAR TELA
	apagarTela();


    menu(nomeUsuario, &pokeUsuarioQtd, pokeUsuario); //printa o menu

    // ESCOLHA DO BIRDMON 
    escolha(nomeUsuario, pokeUsuario, poke, &pokeUsuarioQtd); 

	//SORTEIO DO RESTO DOS POKEMONS

	sortearPokemons(&pokeOponentes, pokeUsuario, poke);


	


	//LOOP DE BATALHA-LOJA
	int rodada = 0;
	int pokeAtivo = 0;
	while(1){
		rodada++;

		if(batalha(rodada, &pokeUsuarioQtd, pokeUsuario, &pokeOponentes, &inventario, &pokeAtivo) == 0){
			perdeu();
			return 0;
		}else{
			//loja() alguem bota a loja ai namoral
		}
	}
	

	//final do codigo antigo (acho que pode remover ja)
	printf("\n digite qualquer valor para encerrar o programa\n");
	char lixo;
	scanf(" %c", &lixo);

	return 0;
}

















