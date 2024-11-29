#ifndef POKEMON_H
#define POKEMON_H
#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "habilidade.h"
#define QTDPOKEMONS 16
#define aumentolvl 0.1

typedef struct tp_pokemon{

    int num;
    int vida, vidamax, atq, atqO, agil, agilO, evolucao, nivel, vivo;
    float def, defO;
    
    int exp, expO, expMax;
    char nome[35];
    char tipo[10];

    //habilidades
    tp_fila hab;
} tp_pokemon;

void criarPokemons(tp_pokemon poke[], tp_hab hab[]){

    //coloca para todos os pokemons comecarem com experiencia = 0.
    for(int i=0; i<=QTDPOKEMONS; i++){

    poke[i].exp = 0;
    poke[i].expO = 0;
    poke[i].expMax = 100;
    poke[i].nivel = 1; //mudar para 1
    poke[i].vivo = 1;

    }

    //BIRDMON NULO - SERVE APENAS PARA FINS DE LOGICA
    strcpy(poke[0].nome, "NULO");
    strcpy(poke[0].tipo, "NULO");
    poke[1].num = 0;
    poke[1].vida = 0;
    poke[1].vidamax = 0;
    poke[1].atqO = 0;
    poke[1].atq = 0;
    poke[1].defO = 0;
    poke[1].def = 0;
    poke[1].agil = 0;
    poke[1].agilO = 0;
    poke[1].evolucao = 1;

    //Pikapombo
    strcpy(poke[1].nome, "Pikapombo");
    strcpy(poke[1].tipo, "eletrico");
    poke[1].num = 1;
    poke[1].vida = 250;
    poke[1].vidamax = 250;
    poke[1].atqO = 30;
    poke[1].atq = 30;
    poke[1].defO = 0.6;
    poke[1].def = 0.6;
    poke[1].agilO = 50;
    poke[1].agil = 50;
    poke[1].evolucao = 1;

    inicializaFila(&poke[1].hab);
    insereFila(&poke[1].hab, hab[0] /*bicada*/);
    insereFila(&poke[1].hab, hab[3] /*soco*/);
    insereFila(&poke[1].hab, hab[10] /*eletrizar*/);
    insereFila(&poke[1].hab, hab[26] /*Bombardeio Eletrico*/);


    //Cocatriz:
    strcpy(poke[2].nome, "Cocatriz");
    strcpy(poke[2].tipo, "sombrio");
    poke[2].num = 2;
    poke[2].vida = 300;
    poke[2].vidamax = 300;
    poke[2].atqO = 40;
    poke[2].atq = 40;
    poke[2].defO = 0.8;
    poke[2].def = 0.8;
    poke[2].agilO = 50;
    poke[2].agil = 50;
    poke[2].evolucao = 1;

    inicializaFila(&poke[2].hab);
    insereFila(&poke[2].hab, hab[0] /*bicada*/);
    insereFila(&poke[2].hab, hab[4] /*amaldicoar*/);
    insereFila(&poke[2].hab, hab[11] /*petrificar*/);
    insereFila(&poke[2].hab, hab[27] /*paralizar*/);


    //Pato do Clube:
    strcpy(poke[3].nome, "Pato do Clube");
    strcpy(poke[3].tipo, "agua");
    poke[3].num = 3;
    poke[3].vida = 300;
    poke[3].vidamax = 300;
    poke[3].atqO = 50;
    poke[3].atq = 50;
    poke[3].defO = 0.45;
    poke[3].def = 0.45;
    poke[3].agilO = 50;
    poke[3].agil = 50;
    poke[3].evolucao = 1;

    inicializaFila(&poke[3].hab);
    insereFila(&poke[3].hab, hab[0] /*bicada*/);
    insereFila(&poke[3].hab, hab[5] /*encharcar*/);
    insereFila(&poke[3].hab, hab[12] /*relaxar*/);
    insereFila(&poke[3].hab, hab[28] /*agua quente*/);


    //Flamingo Capoerista:
    strcpy(poke[4].nome, "Flamingo Capoeirista");
    strcpy(poke[4].tipo, "lutador");
    poke[4].num = 4;
    poke[4].vida = 250;
    poke[4].vidamax = 250;
    poke[4].atqO = 40;
    poke[4].atq = 40;
    poke[4].defO = 0.95;
    poke[4].def = 0.95;
    poke[4].agilO = 80;
    poke[4].agil = 80;
    poke[4].evolucao = 1;

    inicializaFila(&poke[4].hab);
    insereFila(&poke[4].hab, hab[1] /*chute*/);
    insereFila(&poke[4].hab, hab[6] /*brigar*/);
    insereFila(&poke[4].hab, hab[13] /*tocarBerimbau*/);
    insereFila(&poke[4].hab, hab[29] /*Meia-Lua*/);


    //Galo Guerreiro:
    strcpy(poke[5].nome, "Galo Guerreiro");
    strcpy(poke[5].tipo, "lutador");
    poke[5].num = 5;
    poke[5].vida = 300;
    poke[5].vidamax = 300;
    poke[5].atqO = 45;
    poke[5].atq = 45;
    poke[5].defO = 0.6;
    poke[5].def = 0.6;
    poke[5].agilO = 35;
    poke[5].agil = 35;
    poke[5].evolucao = 1;

    inicializaFila(&poke[5].hab);
    insereFila(&poke[5].hab, hab[2] /*soco*/);
    insereFila(&poke[5].hab, hab[6] /*brigar*/);
    insereFila(&poke[5].hab, hab[14] /*grito de guerra*/);
    insereFila(&poke[5].hab, hab[30] /*Avancar com Escudo*/);

    //Galinha Pintadinha:
    strcpy(poke[6].nome, "Galinha Pintadinha");
    strcpy(poke[6].tipo, "dancarino");
    poke[6].num = 6;
    poke[6].vida = 300;
    poke[6].vidamax = 300;
    poke[6].atqO = 20;
    poke[6].atq = 20;
    poke[6].defO = 0.6;
    poke[6].def = 0.6;
    poke[6].agilO = 80;
    poke[6].agil = 80;
    poke[6].evolucao = 1;

    inicializaFila(&poke[6].hab);
    insereFila(&poke[6].hab, hab[1] /*chute*/);
    insereFila(&poke[6].hab, hab[7] /*sambar*/);
    insereFila(&poke[6].hab, hab[15] /*botar saia*/);
    insereFila(&poke[6].hab, hab[31] /*Pintinho Amarelinho*/);


    //ticoliro
    strcpy(poke[7].nome, "Ticoliro");
    strcpy(poke[7].tipo, "lutador");
    poke[7].num = 7;
    poke[7].vida = 180;
    poke[7].vidamax = 180;
    poke[7].atqO = 35;
    poke[7].atq = 35;
    poke[7].defO = 0.8;
    poke[7].def = 0.8;
    poke[7].agilO = 50;
    poke[7].agil = 50;
    poke[7].evolucao = 1;

    inicializaFila(&poke[7].hab);
    insereFila(&poke[7].hab, hab[2] /*soco*/);
    insereFila(&poke[7].hab, hab[9] /*rolar*/);
    insereFila(&poke[7].hab, hab[16] /*chorar*/);
    insereFila(&poke[7].hab, hab[32] /*tacada*/);


    //dodo
    strcpy(poke[8].nome, "Dodo");
    strcpy(poke[8].tipo, "normal");
    poke[8].num = 8;
    poke[8].vida = 150;
    poke[8].vidamax = 150;
    poke[8].atqO = 20;
    poke[8].atq = 20;
    poke[8].defO = 0.8;
    poke[8].def = 0.8;
    poke[8].agilO = 50;
    poke[8].agil = 50;
    poke[8].evolucao = 1;

    inicializaFila(&poke[8].hab);
    insereFila(&poke[8].hab, hab[0] /*bicada*/);
    insereFila(&poke[8].hab, hab[9] /*rolar*/);
    insereFila(&poke[8].hab, hab[17] /*hibernar*/);
    insereFila(&poke[8].hab, hab[33] /*Extincao*/);


    //rolinha
    strcpy(poke[9].nome, "Rolinha");
    strcpy(poke[9].tipo, "normal");
    poke[9].num = 9;
    poke[9].vida = 180;
    poke[9].vidamax = 180;
    poke[9].atqO = 30;
    poke[9].atq = 30;
    poke[9].defO = 0.8;
    poke[9].def = 0.8;
    poke[9].agilO = 65;
    poke[9].agil = 65;
    poke[9].evolucao = 1;

    inicializaFila(&poke[9].hab);
    insereFila(&poke[9].hab, hab[0] /*bicada*/);
    insereFila(&poke[9].hab, hab[9] /*rolar*/);
    insereFila(&poke[9].hab, hab[18] /*golpe baixo*/);
    insereFila(&poke[9].hab, hab[34] /*rolada*/);


    //Joao Frango 
    strcpy(poke[10].nome, "Joao Frango");
    strcpy(poke[10].tipo, "planta");
    poke[10].num = 10;
    poke[10].vida = 300;
    poke[10].vidamax = 300;
    poke[10].atqO = 25;
    poke[10].atq = 25;
    poke[10].defO = 0.55;
    poke[10].def = 0.55;
    poke[10].agilO = 35;
    poke[10].agil = 35;
    poke[10].evolucao = 1;

    inicializaFila(&poke[10].hab);
    insereFila(&poke[10].hab, hab[0] /*bicada*/);
    insereFila(&poke[10].hab, hab[8] /*semear*/);
    insereFila(&poke[10].hab, hab[19] /*enrolar*/);
    insereFila(&poke[10].hab, hab[35] /*Ta dando onda!*/);


    //Canarinho sambista
    strcpy(poke[11].nome, "Canarinho sambista");
    strcpy(poke[11].tipo, "dancarino");
    poke[11].num = 11;
    poke[11].vida = 180;
    poke[11].vidamax = 180;
    poke[11].atqO = 25;
    poke[11].atq = 25;
    poke[11].defO = 0.6;
    poke[11].def = 0.6;
    poke[11].agilO = 80;
    poke[11].agil = 80;
    poke[11].evolucao = 1;

    inicializaFila(&poke[11].hab);
    insereFila(&poke[11].hab, hab[1] /*chute*/);
    insereFila(&poke[11].hab, hab[7] /*sambar*/);
    insereFila(&poke[11].hab, hab[20] /*Festa em Ipanema*/);
    insereFila(&poke[11].hab, hab[36] /*Carnaval!*/);


    //Corvo Emo Gotico
    strcpy(poke[12].nome, "Corvo emo gotico");
    strcpy(poke[12].tipo, "sombrio");
    poke[12].num = 12;
    poke[12].vida = 250;
    poke[12].vidamax = 250;
    poke[12].atqO = 30;
    poke[12].atq = 30;
    poke[12].defO = 0.8;
    poke[12].def = 0.8;
    poke[12].agilO = 65;
    poke[12].agil = 65;
    poke[12].evolucao = 1;

    inicializaFila(&poke[12].hab);
    insereFila(&poke[12].hab, hab[0] /*bicada*/);
    insereFila(&poke[12].hab, hab[4] /*amaldicoar*/);
    insereFila(&poke[12].hab, hab[21] /*Noite Chuvosa*/);
    insereFila(&poke[12].hab, hab[37] /*evanescence*/);


    //Papaleguas
    strcpy(poke[13].nome, "Papaleguas");
    strcpy(poke[13].tipo, "eletrico");
    poke[13].num = 13;
    poke[13].vida = 250;
    poke[13].vidamax = 250;
    poke[13].atqO = 35;
    poke[13].atq = 35;
    poke[13].defO = 0.8;
    poke[13].def = 0.8;
    poke[13].agilO = 95;
    poke[13].agil = 95;
    poke[13].evolucao = 1;

    inicializaFila(&poke[13].hab);
    insereFila(&poke[13].hab, hab[1] /*chute*/);
    insereFila(&poke[13].hab, hab[3] /*soco*/);
    insereFila(&poke[13].hab, hab[22] /*Acelerar!*/);
    insereFila(&poke[13].hab, hab[38] /*Beep Beep!*/);


    //Pica-Pau
    strcpy(poke[14].nome, "Pica-Pau");
    strcpy(poke[14].tipo, "planta");
    poke[14].num = 14;
    poke[14].vida = 250;
    poke[14].vidamax = 250;
    poke[14].atqO = 40;
    poke[14].atq = 40;
    poke[14].defO = 0.65;
    poke[14].def = 0.65;
    poke[14].agilO = 65;
    poke[14].agil = 65;
    poke[14].evolucao = 1;

    inicializaFila(&poke[14].hab);
    insereFila(&poke[14].hab, hab[0] /*bicada*/);
    insereFila(&poke[14].hab, hab[8] /*semear*/);
    insereFila(&poke[14].hab, hab[23] /*Bolo de Morango*/);
    insereFila(&poke[14].hab, hab[39] /*E la vamos nos!*/);


    //Pinguins de madagascar (recruta)
    strcpy(poke[15].nome, "Recruta");
    strcpy(poke[15].tipo, "agua");
    poke[15].num = 15;
    poke[15].vida = 200;
    poke[15].vidamax = 200;
    poke[15].atqO = 40;
    poke[15].atq = 40;
    poke[15].defO = 0.6;
    poke[15].def = 0.6;
    poke[15].agilO = 50;
    poke[15].agil = 50;
    poke[15].evolucao = 1;

    inicializaFila(&poke[15].hab);
    insereFila(&poke[15].hab, hab[2] /*soco*/);
    insereFila(&poke[15].hab, hab[5] /*encharcar*/);
    insereFila(&poke[15].hab, hab[24] /*Sorrir e Acenar*/);
    insereFila(&poke[15].hab, hab[40] /*boom?*/);

    //Kiwi
    strcpy(poke[16].nome, "Kiwi");
    strcpy(poke[16].tipo, "planta");
    poke[16].num = 16;
    poke[16].vida = 180;
    poke[16].vidamax = 180;
    poke[16].atqO = 25;
    poke[16].atq = 25;
    poke[16].defO = 0.65;
    poke[16].def = 0.65;
    poke[16].agilO = 50;
    poke[16].agil = 50;
    poke[16].evolucao = 1;

    inicializaFila(&poke[16].hab);
    insereFila(&poke[16].hab, hab[0] /*bicada*/);
    insereFila(&poke[16].hab, hab[8] /*semear*/);
    insereFila(&poke[16].hab, hab[25] /*camuflagem*/);
    insereFila(&poke[16].hab, hab[41] /*Explosao de Kiwi*/);

}

//para que serve
//tantos códigos?
//se a vida
//não é programada
//e as melhores coisas
//não tem lógica
//johnsson, johnsson 2024

#endif
