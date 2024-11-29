#include <stdio.h>
#include <stdlib.h>

typedef struct{

char nome[30];
int rodada;

}ranked;

void colocarNoRanking(nome, rodada){

    int jogadorPosicionado = 0; //diz se o jogador ja foi colocado no ranking ou nao
    ranked novoJogador;
    strcmp(novoJogador.nome, nome); //atribui o nome
    novoJogador.rodada = rodada; //atribui a rodada

   FILE *arquivo = fopen(ranking.txt, "r+");

    if(arquivo == NULL) printf("\nERRO AO ABRIR ARQUIVO\n");

    char rodadaString[50];

    int posAnterior = ftell(arquivo);
    int posAtual = ftell(arquivo);

    while(fgets(nome, 50, arquivo)){ //pega o nome de alguem ate nao terem mais jogadores

    fgets(rodadaString, 50, arquivo); //pega a rodada desse alguem

        posAtual = ftell(arquivo);

        rodada = atoi(rodadaString); //transforma a rodada, lida como string, em inteiro

        if(novoJogador.rodada >= rodada){

            fseek(arquivo, posAnterior, SEEK_SET); //volta para a posicao antes
            fprintf(arquivo, "%s\n", novoJogador.nome);
            fprintf(arquivo, "%d\n", novoJogador.rodada);
            jogadorPosicionado = 1;
            break;
        }else{

            posAnterior = posAtual;

        }
        
        if(!jogadorPosicionado){ //botar no final
            fseek(arquivo, 0, SEEK_END);
            fprintf(arquivo, "%s\n", novoJogador.nome);
            fprintf(arquivo, "%d\n", novoJogador.rodada);
        }

        fclose(arquivo);
    }
}
