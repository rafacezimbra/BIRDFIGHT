#ifndef BATALHA_H //if not define
#define BATALHA_H

#include "pokemon.h"
#include "sprites.h"
#include "apagartela.h"
#include "habilidade.h"
#include "fila.h"
#include "inventario.h"
#include "tipo.h"
#include "captura.h"

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
void xpBatalha(int *pokeAtivo, tp_pokemon pokeUsuario[]) {
    // Gera experiência aleatória entre 10 e 50
    int exp_ganha = (rand() % 41) + 10;
    printf("%s ganhou %d de EXP na batalha!\n", pokeUsuario[*pokeAtivo].nome, exp_ganha);

    // Atualiza a experiência do Pokémon
    pokeUsuario[*pokeAtivo].exp += exp_ganha;

    // Verifica se o Pokémon alcançou ou excedeu a experiência necessária para subir de nível
    if (pokeUsuario[*pokeAtivo].exp >= pokeUsuario[*pokeAtivo].expMax) {
        // Sobe de nível
        pokeUsuario[*pokeAtivo].nivel += 1;
        printf("%s subiu para o nível %d!\n", pokeUsuario[*pokeAtivo].nome,pokeUsuario[*pokeAtivo].nivel);

        // Reseta a experiência atual e aumenta o limite de experiência para o próximo nível
        pokeUsuario[*pokeAtivo].exp = pokeUsuario[*pokeAtivo].expO;
        pokeUsuario[*pokeAtivo].expMax += 20;
    }
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


void efeito(tp_pokemon *pokeAtacante, tp_pokemon *pokeAlvo, tp_hab ataque, tp_fila filahab){
	if(ataque.efAgilAl==1 && ataque.efAtkAl==1 && ataque.efDefAl==-1){
		pokeAtacante->agil = pokeAtacante->agil*1.1; //aumenta a agil em 10% do poke atacante
		pokeAtacante->atq = pokeAtacante->atq*1.1; //aumenta a atk em 10% do poke atacante
		pokeAtacante->def = pokeAtacante->def*0.9; //aumenta a def em 10% do poke atacante
	} else if (ataque.efAtkAl==-1 && ataque.efDefAl==-1){
		pokeAtacante->agil = pokeAtacante->agil*0.9; //aumenta a atk em 10% do poke atacante
		pokeAtacante->def = pokeAtacante->def*0.9; //aumenta a def em 10% do poke atacante
		pokeAlvo->agil = pokeAlvo->agil*0.8; //reduz a atk em 20% do poke alvo
		pokeAlvo->def = pokeAlvo->def*0.8; //reduz a def em 20% do poke alvo
	} else 	if(ataque.efAgilAl==1 && ataque.efAtkAl==1){
		pokeAtacante->agil = pokeAtacante->agil*1.1; //aumenta a agil em 10% do poke atacante
		pokeAtacante->atq = pokeAtacante->atq*1.1; //aumenta a atk em 10% do poke atacante
	} else if (ataque.efDefOp==1 && ataque.efAgilOp==1 && ataque.efAtkOp==1){
		pokeAlvo->def = pokeAlvo->def*0.9; //reduz a def em 10% do poke alvo
		pokeAlvo->atq = pokeAlvo->atq*0.9; //reduz a atk em 10% do poke alvo
		pokeAlvo->agil = pokeAlvo->agil*0.9; //reduz a agil em 10% do poke alvo
	} else if(ataque.efAgilAl==1){
		pokeAtacante->agil = pokeAtacante->agil*1.1; //aumenta a agil em 10% do poke atacante
	} else if (ataque.efAtkAl==1){
		pokeAtacante->atq = pokeAtacante->atq*1.1; //aumenta a atk em 10% do poke atacante
	} else if (ataque.efDefAl==1){
		pokeAtacante->def = pokeAtacante->def*1.1; //aumenta a def em 10% do poke atacante
	} else if(ataque.efAgilOp==1){
		pokeAlvo->agil = pokeAlvo->agil*0.9; //reduz a agil em 10% do poke alvo
	} else if (ataque.efAtkOp==1){
		pokeAlvo->atq = pokeAlvo->atq*0.9; //reduz a atk em 10% do poke alvo
	} else if (ataque.efDefOp==1){
		pokeAlvo->def = pokeAlvo->def*0.9; //reduz a def em 10% do poke alvo
	}
}

void atacar(tp_pokemon *pokeAtacante, tp_pokemon *pokeAlvo, int numAtaque, tp_fila filahab){
    //pega a fila de habilidades do atacante como copia, entao pode desempilhar a vontade
    tp_hab ataque;
    for(int i = 0; i<numAtaque; i++){
        removeFila(&filahab, &ataque);
    }
    printf("%s usou %s...\n", pokeAtacante->nome, ataque.nome);

    //conferir se o alvo ira ou nao desviar do golpe
    efeito(pokeAtacante, pokeAlvo, ataque, filahab);
    float danoDeTipo = multiplicadorDeTipo(ataque.tipo, pokeAlvo->tipo);
    int dado = rand()%100;
    int chanceDeDesviar = pokeAlvo->agil/3;
    if(dado>chanceDeDesviar){ //ataque acertou
        pokeAlvo->vida = pokeAlvo->vida - (float)(((float)ataque.dano + (float)pokeAtacante->atq)*(float)pokeAlvo->def)*(float)(danoDeTipo);
    
        if(danoDeTipo == 0.5) printf("o ataque nao foi muito eficaz...");
        else if(danoDeTipo == 1) printf("o ataque acertou!");
        else if(danoDeTipo == 2) printf("o ataque foi super efetivo!");
    

    }else{ //ataque errou
    printf("%s desviou do golpe!", pokeAlvo->nome);
    }
}

// Função de troca de Birdmon
int trocarBirdmon(tp_pokemon pokeUsuario[], int *totalBirdmons, int *pokeAtivo) {
    apagarTela();
    int escolha;
    printf("Escolha um Birdmon para a batalha:\n");
    for (int i = 0; i < *totalBirdmons; i++) {
        printf("%d - %s (HP: %d/%d)\n", i + 1, pokeUsuario[i].nome, pokeUsuario[i].vida, pokeUsuario[i].vidamax);
    }
    printf("Escolha: ");
    scanf("%d", &escolha);

    if(escolha == 0) return 0;
    if (escolha > 0 && escolha <= *totalBirdmons) {

        if(!pokeUsuario[escolha-1].vivo){
            printf("Este Birdmon foi derrotado! Reviva-o para chama-lo novamente!\n");
            sleep(5);
            return trocarBirdmon(pokeUsuario, totalBirdmons, pokeAtivo);

        }else{
        tp_pokemon pokeAux;
        pokeAux = pokeUsuario[*pokeAtivo];
        pokeUsuario[*pokeAtivo] = pokeUsuario[escolha - 1];
        pokeUsuario[escolha - 1] = pokeAux;
        printf("Voce escolheu %s para a batalha!\n", pokeUsuario[*pokeAtivo].nome);
        return 1;
        }
        
    } else {
        printf("Escolha invalida.\n");
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
    printf("4. Capturar Birdmon\n");
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
            printf("digite o numero do item (0 para retornar):\n");
            int item;
            while(1){
            scanf("%d", &item);
            if(item == 0){ //retornar
                apagarTela();
                printarBatalha(pokeUsuario, pokeInimigo, *pokeAtivo, rodada);
                return  menuBatalha(pokeAtivo, pokeInimigo, inv, pokeUsuario, pokeUsuarioQtd, rodada);
                break;
            }
		    if(aplicarEfeito(item, &pokeUsuario[*pokeAtivo])) break;
            }
        break;

        case 3:
            if(trocarBirdmon(pokeUsuario, pokeUsuarioQtd, pokeAtivo)==0){
            //voltar
            apagarTela();
            printarBatalha(pokeUsuario, pokeInimigo, *pokeAtivo, rodada);
            return  menuBatalha(pokeAtivo, pokeInimigo, inv, pokeUsuario, pokeUsuarioQtd, rodada);
            }
        break;

        
        case 4:
          capturarBirdmon(pokeInimigo, inv, pokeUsuario, pokeUsuarioQtd);
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

int verificarVivos(int *pokeAtivo, tp_pokemon *pokeInimigo, tp_pokemon pokeUsuario[], int rodada, int pokeUsuarioQtd, Inventory *inv){
    //return 0: todo mundo ta de boa, ninguem morreu nesse turno
    //return 1: inimigo perdeu
    //return 2: pokemon ativo do jogador foi derrotado
    //return 3: todos os pokemons do jogador foram derrotados

    //checa se algum pokemon esta alem da vida maxima
    if(pokeInimigo->vida > pokeInimigo->vidamax) pokeInimigo-> vida = pokeInimigo->vidamax;
    if(pokeUsuario[*pokeAtivo].vida > pokeUsuario[*pokeAtivo].vidamax) pokeUsuario[*pokeAtivo].vida = pokeUsuario[*pokeAtivo].vidamax;

    if(pokeInimigo->vida <= 0){
        pokeInimigo->vivo = 0;
        printf("O %s selvagem foi derrotado!\n", pokeInimigo->nome);
       	int moedasGanhas = rand() % 451 + 150;
    	inv->items[6].quantity += moedasGanhas; //adicionando nas birdcoins do jogador
        xpBatalha(pokeAtivo, pokeUsuario);
	
	

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
        situacao = verificarVivos(pokeAtivo, &pokeInimigo, pokeUsuario, rodada, *pokeUsuarioQtd, inventario);
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
        situacao = verificarVivos(pokeAtivo, &pokeInimigo, pokeUsuario, rodada, *pokeUsuarioQtd, inventario);
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
