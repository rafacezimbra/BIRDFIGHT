#ifndef POKEMON_H
#define POKEMON_H
#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "habilidade.h"
#define QTDPOKEMONS 16


typedef struct {

    int vida, atq, agil, evolucao;
    float def;
   
    int exp;
    char nome[35];
    char tipo[10];

    //habilidades
    tp_fila hab;
} tp_pokemon;

void criarPokemons(tp_pokemon poke[], tp_hab hab[]){

    //coloca para todos os pokemons comecarem com experiencia = 0.
    for(int i=1; i<=QTDPOKEMONS; i++){

    poke[i].exp = 0;

    }

    //Pikapombo
    strcpy(poke[1].nome, "Pikapombo");
    strcpy(poke[1].tipo, "eletrico");
    poke[1].vida = 250;
    poke[1].atq = 30;
    poke[1].def = 0.6;
    poke[1].agil = 50;
    poke[1].evolucao = 1;

    inicializaFila(&poke[1].hab);
    insereFila(&poke[1].hab, hab[1]); //bicada
    insereFila(&poke[1].hab, choque); //choque
    insereFila(&poke[1].hab, eletrizar); //eletrizar
    insereFila(&poke[1].hab, bombardeioEletrico); //bombardeioEletrico


    //Cocatriz:
    strcpy(poke[2].nome, "Cocatriz");
    strcpy(poke[1].tipo, "sombrio");
    poke[2].vida = 300;
    poke[2].atq = 40;
    poke[2].def = 0.8;
    poke[2].agil = 50;
    poke[2].evolucao = 1;

    inicializaFila(&poke[2].hab);
    insereFila(&poke[2].hab, bicada); //bicada
    insereFila(&poke[2].hab amaldicoar); //amaldicoar
    insereFila(&poke[2].hab petrificar); //petrificar
    insereFila(&poke[2].hab paralizar); //paralizar


    //Pato do Clube:
    strcpy(poke[3].nome, "Pato do Clube");
    strcpy(poke[1].tipo, "agua");
    poke[3].vida = 300;
    poke[3].atq = 50;
    poke[3].def = 0.45;
    poke[3].agil = 50;
    poke[3].evolucao = 1;

    inicializaFila(&poke[3].hab);
    insereFila(&poke[3].hab bicada);
    insereFila(&poke[3].hab encharcar);
    insereFila(&poke[3].hab relaxar);
    insereFila(&poke[3].hab aguaQuente);


    //Flamingo Capoerista:
    strcpy(poke[4].nome, "Flamingo Capoeirista");
    strcpy(poke[4].tipo, "lutador");
    poke[4].vida = 250;
    poke[4].atq = 40;
    poke[4].def = 0.95;
    poke[4].agil = 80;
    poke[4].evolucao = 1;

    inicializaFila(&poke[4].hab);
    insereFila(&poke[4].hab chute);
    insereFila(&poke[4].hab brigar);
    insereFila(&poke[4].hab tocarBerimbau);
    insereFila(&poke[4].hab meiaLua);


    //Galo Guerreiro:
    strcpy(poke[5].nome, "Flamingo Capoeirista");
    strcpy(poke[5].tipo, "lutador");
    poke[5].vida = 300;
    poke[5].atq = 45;
    poke[5].def = 0.6;
    poke[5].agil = 35;
    poke[5].evolucao = 1;

    inicializaFila(&poke[5].hab);
    insereFila(&poke[5].hab soco);
    insereFila(&poke[5].hab brigar);
    insereFila(&poke[5].hab gritoDeGuerra);
    insereFila(&poke[5].hab avancarComEscudo);

    //Galinha Pintadinha:
    strcpy(poke[6].nome, "Galinha Pintadinha");
    strcpy(poke[6].tipo, "dancarino");
    poke[6].vida = 300;
    poke[6].atq = 20;
    poke[6].def = 0.6;
    poke[6].agil = 80;
    poke[6].evolucao = 1;

    inicializaFila(&poke[6].hab);
    insereFila(&poke[6].hab chute);
    insereFila(&poke[6].hab sambar);
    insereFila(&poke[6].hab botarSaia);
    insereFila(&poke[6].hab pintinhoAmarelinho);


    //ticoliro
    strcpy(poke[7].nome, "Ticoliro");
    strcpy(poke[7].tipo, "lutador");
    poke[7].vida = 180;
    poke[7].atq = 35;
    poke[7].def = 0.8;
    poke[7].agil = 50;
    poke[7].evolucao = 1;

    inicializaFila(&poke[7].hab);
    insereFila(&poke[7].hab soco);
    insereFila(&poke[7].hab rolar);
    insereFila(&poke[7].hab chorar);
    insereFila(&poke[7].hab tacada);


    //dodo
    strcpy(poke[8].nome, "Dodo");
    strcpy(poke[8].tipo, "normal");
    poke[8].vida = 150;
    poke[8].atq = 20;
    poke[8].def = 0.8;
    poke[8].agil = 50;
    poke[8].evolucao = 1;

    inicializaFila(&poke[8].hab);
    insereFila(&poke[8].hab bicada);
    insereFila(&poke[8].hab rolar);
    insereFila(&poke[8].hab hibernar);
    insereFila(&poke[8].hab extincao);


    //rolinha
    poke[9].vida = 180;
    poke[9].atq = 30;
    poke[9].def = 0.8;
    poke[9].agil = 65;
    poke[9].evolucao = 1;

    inicializaFila(&poke[9].hab);
    insereFila(&poke[9].hab bicada);
    insereFila(&poke[9].hab rolar);
    insereFila(&poke[9].hab golpeBaixo);
    insereFila(&poke[9].hab rolada);


    //Joao Frango 
    strcpy(poke[10].nome, "Joao Frango");
    strcpy(poke[10].tipo, "planta");
    poke[10].vida = 300;
    poke[10].atq = 25;
    poke[10].def = 0.55;
    poke[10].agil = 35;
    poke[10].evolucao = 1;

    inicializaFila(&poke[10].hab);
    insereFila(&poke[10].hab bicada);
    insereFila(&poke[10].hab semear);
    insereFila(&poke[10].hab enrolar);
    insereFila(&poke[10].hab taDandoOnda);


    //Canarinho sambista
    strcpy(poke[11].nome, "Canarinho sambista");
    strcpy(poke[11].tipo, "dancarino");
    poke[11].vida = 180;
    poke[11].atq = 25;
    poke[11].def = 0.6;
    poke[11].agil = 80;
    poke[11].evolucao = 1;

    inicializaFila(&poke[11].hab);
    insereFila(&poke[11].hab chute);
    insereFila(&poke[11].hab sambar);
    insereFila(&poke[11].hab festaEmIpanema);
    insereFila(&poke[11].hab carnaval);


    //Corvo Emo Gotico
    strcpy(poke[12].nome, "Corvo emo gotico");
    strcpy(poke[12].tipo, "sombrio");
    poke[12].vida = 250;
    poke[12].atq = 30;
    poke[12].def = 0.8;
    poke[12].agil = 65;
    poke[12].evolucao = 1;

    inicializaFila(&poke[12].hab);
    insereFila(&poke[12].hab bicada);
    insereFila(&poke[12].hab amaldicoar);
    insereFila(&poke[12].hab noiteChuvosa);
    insereFila(&poke[12].hab evanescence);


    //Papaleguas
    strcpy(poke[13].nome, "Papaleguas");
    strcpy(poke[13].tipo, "eletrico");
    poke[13].vida = 250;
    poke[13].atq = 35;
    poke[13].def = 0.8;
    poke[13].agil = 95;
    poke[13].evolucao = 1;

    inicializaFila(&poke[13].hab);
    insereFila(&poke[13].hab chute);
    insereFila(&poke[13].hab choque);
    insereFila(&poke[13].hab acelerar);
    insereFila(&poke[13].hab beepBeep);


    //Pica-Pau
    strcpy(poke[14].nome, "Pica-Pau");
    strcpy(poke[14].tipo, "planta");
    poke[14].vida = 250;
    poke[14].atq = 40;
    poke[14].def = 0.65;
    poke[14].agil = 65;
    poke[14].evolucao = 1;

    inicializaFila(&poke[14].hab);
    insereFila(&poke[14].hab bicada);
    insereFila(&poke[14].hab semear);
    insereFila(&poke[14].hab boloDeMurango);
    insereFila(&poke[14].hab eLaVamosNos);


    //Pinguins de madagascar (recruta)
    strcpy(poke[15].nome, "Recruta");
    strcpy(poke[15].tipo, "agua");
    poke[15].vida = 200;
    poke[15].atq = 40;
    poke[15].def = 0.6;
    poke[15].agil = 50;
    poke[15].evolucao = 1;

    inicializaFila(&poke[15].hab);
    insereFila(&poke[15].hab soco);
    insereFila(&poke[15].hab encharcar);
    insereFila(&poke[15].hab sorrirEAcenar);
    insereFila(&poke[15].hab boom);

    //Kiwi
    strcpy(poke[16].nome, "Kiwi");
    strcpy(poke[16].tipo, "planta");
    poke[16].vida = 180;
    poke[16].atq = 25;
    poke[16].def = 0.65;
    poke[16].agil = 50;
    poke[16].evolucao = 1;

    inicializaFila(&poke[16].hab);
    insereFila(&poke[16].hab bicada);
    insereFila(&poke[16].hab semear);
    insereFila(&poke[16].hab camuflagem);
    insereFila(&poke[16].hab explosaoDeKiwi);

    }

#endif

//para que serve
//tantos códigos?
//se a vida
//não é programada
//e as melhores coisas
//não tem lógica
//johnsson, johnsson 2024

