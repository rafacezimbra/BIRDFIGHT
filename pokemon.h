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
    strcpy(poke[6].nome, "Ticoliro");
    strcpy(poke[6].tipo, "lutador");
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

}

//DECLARACAO DOS POKEMONS







//rolinha
tp_pokemon rolinha;
rolinha.nome = "Rolinha";
rolinha.vida = 180;
rolinha.atq = 30;
rolinha.def = 0.8;
rolinha.agil = 65;
rolinha.evolucao = 1;

inicializaFila(&rolinha.hab);
insereFila(&rolinha.hab bicada);
insereFila(&rolinha.hab rolar);
insereFila(&rolinha.hab golpeBaixo);
insereFila(&rolinha.hab rolada);


//Joao(Frango)
tp_pokemon joao;
joao.nome = "Joao Frango";
joao.vida = 300;
joao.atq = 25;
joao.def = 0.55;
joao.agil = 35;
joao.evolucao = 1

inicializaFila(&joao.hab);
insereFila(&joao.hab bicada);
insereFila(&joao.hab semear);
insereFila(&joao.hab enrolar);
insereFila(&joao.hab taDandoOnda);


//Canarinho sambista
tp_pokemon canarinhoS;
canarinhoS.nome = "Canarinho Sambista";
canarinhoS.vida = 180;
canarinhoS.atq = 25;
canarinhoS.def = 0.6;
canarinhoS.agil = 80;
canarinhoS.evolucao = 1

inicializaFila(&canarinhoS.hab);
insereFila(&canarinhoS.hab chute);
insereFila(&canarinhoS.hab sambar);
insereFila(&canarinhoS.hab festaEmIpanema);
insereFila(&canarinhoS.hab carnaval);


//Corvo Emo Gotico
tp_pokemon corvoEmoGotico;
corvoEmoGotico.nome = "Corvo emo gotico";
corvoEmoGotico.vida = 250;
corvoEmoGotico.atq = 30;
corvoEmoGotico.def = 0.8;
corvoEmoGotico.agil = 65;
corvoEmoGotico.evolucao = 1;

inicializaFila(&corvoEmoGotico.hab);
insereFila(&corvoEmoGotico.hab bicada);
insereFila(&corvoEmoGotico.hab amaldicoar);
insereFila(&corvoEmoGotico.hab noiteChuvosa);
insereFila(&corvoEmoGotico.hab evanescence);


//Papaleguas
tp_pokemon papaleguas;
papaleguas.nome = "Papaleguas";
papaleguas.vida = 250;
papaleguas.atq = 35;
papaleguas.def = 0.8;
papaleguas.agil = 95;
papaleguas.evolucao = 1;

inicializaFila(&papaleguas.hab);
insereFila(&papaleguas.hab chute);
insereFila(&papaleguas.hab choque);
insereFila(&papaleguas.hab acelerar);
insereFila(&papaleguas.hab beepBeep);


//Pica-Pau

tp_pokemon picaPau;
picaPau.nome = "Pica Pau";
picaPau.vida = 250;
picaPau.atq = 40;
picaPau.def = 0.65;
picaPau.agil = 65;
picaPau.evolucao = 1;

inicializaFila(&picaPau.hab);
insereFila(&picaPau.hab bicada);
insereFila(&picaPau.hab semear);
insereFila(&picaPau.hab boloDeMurango);
insereFila(&picaPau.hab eLaVamosNos);


//Pinguins de madagascar
tp_pokemon pinguins;
pinguins.nome = "Recruta";
pinguins.vida = 200;
pinguins.atq = 40;
pinguins.def = 0.6;
pinguins.agil = 50;
pinguins.evolucao = 1;

inicializaFila(&pinguins.hab);
insereFila(&pinguins.hab soco);
insereFila(&pinguins.hab encharcar);
insereFila(&pinguins.hab sorrirEAcenar);
insereFila(&pinguins.hab boom);


//kiwi
tp_pokemon kiwi;
kiwi.nome = "Kiwi";
kiwi.vida = 180;
kiwi.atq = 25;
kiwi.def = 0.65;
kiwi.agil = 50;
kiwi.evolucao = 1;

inicializaFila(&kiwi.hab);
insereFila(&kiwi.hab bicada);
insereFila(&kiwi.hab semear);
insereFila(&kiwi.hab camuflagem);
insereFila(&kiwi.hab explosaoDeKiwi);



#endif


//para que serve
//tantos códigos?
//se a vida
//não é programada
//e as melhores coisas
//não tem lógica
//johnsson, johnsson 2024

