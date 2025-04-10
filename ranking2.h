#ifndef RANKING_H //if not define
#define RANKING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogadorNoRank{

char nome[30];
int rodada;

}ranked;



//parte que importa e funciona

void colocarNoRanking(char nome[], int rodada) {
    int jogadorPosicionado = 0; // Diz se o jogador já foi colocado no ranking ou não
    ranked novoJogador;
    strcpy(novoJogador.nome, nome); // Atribui o nome
    novoJogador.rodada = rodada;   // Atribui a rodada

    FILE *arquivo = fopen("ranking.txt", "r");
    FILE *temp = fopen("temp_ranking.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("\nERRO AO ABRIR ARQUIVO\n");
        return;
    }

    char linhaNome[50];
    char linhaRodada[50];

    // Processa o arquivo original
    while (fgets(linhaNome, sizeof(linhaNome), arquivo)) {
        linhaNome[strcspn(linhaNome, "\n")] = '\0'; // Remove o '\n'
        fgets(linhaRodada, sizeof(linhaRodada), arquivo);
        int rodadaAtual = atoi(linhaRodada);

        // Insere o novo jogador na posição correta
        if (!jogadorPosicionado && novoJogador.rodada >= rodadaAtual) {
            fprintf(temp, "%s\n", novoJogador.nome);
            fprintf(temp, "%d\n", novoJogador.rodada);
            jogadorPosicionado = 1;
        }

        // Escreve o jogador atual do ranking no arquivo temporário
        fprintf(temp, "%s\n", linhaNome);
        fprintf(temp, "%d\n", rodadaAtual);
    }

    // Se o novo jogador ainda não foi inserido, adiciona no final
    if (!jogadorPosicionado) {
        fprintf(temp, "%s\n", novoJogador.nome);
        fprintf(temp, "%d\n", novoJogador.rodada);
    }

    fclose(arquivo);
    fclose(temp);

    // Substitui o arquivo original pelo temporário
    remove("ranking.txt");
    rename("temp_ranking.txt", "ranking.txt");
}

int imprimeRank(){
    printf("--- RANKING ---\n");
    char registro[50];
    int pos = 1;
    FILE *arquivo = fopen("ranking.txt", "r+");
    if (!arquivo) return 0;
    while(fgets(registro, sizeof(registro), arquivo)){
        registro[strcspn(registro, "\n")] = '\0';
        printf("%d. ", pos);
        printf("%s ", registro);
        fgets(registro, sizeof(registro), arquivo);
        printf("- %s", registro);
        pos++;
    }
    fclose(arquivo);
    return 1;
}

//funcoes aposentadas - nao funcionam

/*
int ordenaRank(char nome[30], int rodada, tp_listase_rank *lista){

  
    char rodadaString[50];
    char nomeAtual[50];

    FILE *arquivo = fopen("ranking.txt", "r+");
	if (!arquivo){
        printf("\nERRO AO ABRIR O ARQUIVO DE RANKING\n");
        sleep(5);
        return 0;
    } 
    while(fgets(nome, 50, arquivo)){ //pega o nome de alguem ate nao terem mais jogadores

    fgets(rodadaString, 50, arquivo); //pega a rodada desse alguem
    int rodadaAtual = atoi(rodadaString);
    
    insereListaseOrdenada(lista, rodadaAtual, nomeAtual); //insere esse jogador na lista encadeada de forma ordenada
    }

    insereListaseOrdenada(lista, rodada, nome);

    fclose(arquivo);

    return 1;
}

int imprimeRankOLD(){
    printf("RANKING\n");
	char registro[50];
    int pos = 1;
	FILE *arquivo = fopen("ranking.txt", "r+");
	if (!arquivo) return 0;
	while(fgets(registro, sizeof(registro), arquivo)){
        printf("%d. ", pos);
		printf("%s", registro);
        pos++;
	}
	fclose(arquivo);
	return 1;
}


void colocarNoRankingOLD(char nome[], int rodada){

    int jogadorPosicionado = 0; //diz se o jogador ja foi colocado no ranking ou nao
    ranked novoJogador;
    strcpy(novoJogador.nome, nome); //atribui o nome
    novoJogador.rodada = rodada; //atribui a rodada

   FILE *arquivo = fopen("ranking.txt", "r+");

    if(arquivo == NULL) printf("\nERRO AO ABRIR ARQUIVO\n");

    char rodadaString[50];

    int posAnterior = ftell(arquivo);
    int posAtual = ftell(arquivo);

    while(fgets(nome, 50, arquivo)){ //pega o nome de alguem ate nao terem mais jogadores

    fgets(rodadaString, 50, arquivo); //pega a rodada desse alguem

        posAtual = ftell(arquivo);

        rodada = atoi(rodadaString); //transforma a rodada, lida como string, em inteiro

        if(novoJogador.rodada >= rodada){
            
            char rodadaEmString[12];
            itoa(novoJogador.rodada, rodadaEmString, 10); //transforma o numero de rodadas em uma string

            fseek(arquivo, posAnterior, SEEK_SET); //volta para a posicao antes
            fputs(novoJogador.nome, arquivo);
            fputs(rodadaEmString, arquivo);
            jogadorPosicionado = 1;
            break;
        }else{

            posAnterior = posAtual;

        }
    }
        
        if(!jogadorPosicionado){ //botar no final
            fseek(arquivo, 0, SEEK_END);
            fprintf(arquivo, "%s\n", novoJogador.nome);
            fprintf(arquivo, "%d\n", novoJogador.rodada);
        }

        fclose(arquivo);
    
}

*/

#endif