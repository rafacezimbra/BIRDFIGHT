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

void criarPokemons(tp_pokemon poke[]){

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
insereFila(&poke[1].hab, bicada);
insereFila(&poke[1].hab, choque);
insereFila(&poke[1].hab, eletrizar);
insereFila(&poke[1].hab, bombardeioEletrico);
}

//DECLARACAO DOS POKEMONS




//leti aqui



//Cocatriz:
tp_pokemon cocatriz
cocatriz.nome = "Cocatriz";
cocatriz.vida = 300;
cocatriz.atq = 40;
cocatriz.def = 0.8;
cocatriz.agil = 50;
cocatriz.evolucao = 1;

inicializaFila(&cocatriz.hab);
insereFila(&cocatriz.hab, bicada);
insereFila(&cocatriz.hab amaldicoar);
insereFila(&cocatriz.hab petrificar);
insereFila(&cocatriz.hab paralizar);


//Pato do Clube:
tp_pokemon patoDoClube;
patoDoClube.nome = "Pato do Clube";
patoDoClube.vida = 300;
patoDoClube.atq = 50;
patoDoClube.def = 0.45;
patoDoClube.agil = 50;
patoDoClube.evolucao = 1;

inicializaFila(&patoDoClube.hab);
insereFila(&patoDoClube.hab bicada);
insereFila(&patoDoClube.hab encharcar);
insereFila(&patoDoClube.hab relaxar);
insereFila(&patoDoClube.hab aguaQuente);


//Flamingo Capoerista:
tp_pokemon flamingoC;
flamingoC.nome = "Flamingo Capoeirista";
flamingoC.vida = 250;
flamingoC.atq = 40;
flamingoC.def = 0.95;
flamingoC.agil = 80;
flamingoC.evolucao = 1;

inicializaFila(&flamingoC.hab);
insereFila(&flamingoC.hab chute);
insereFila(&flamingoC.hab brigar);
insereFila(&flamingoC.hab tocarBerimbau);
insereFila(&flamingoC.hab meiaLua);


//Galo Guerreiro:
tp_pokemon galoGuerreiro;
galoGuerreiro.nome = "Galo Guerreiro";
galoGuerreiro.vida = 300;
galoGuerreiro.atq = 45;
galoGuerreiro.def = 0.6;
galoGuerreiro.agil = 35;
galoGuerreiro.evolucao = 1;

inicializaFila(&galoGuerreiro.hab);
insereFila(&galoGuerreiro.hab soco);
insereFila(&galoGuerreiro.hab brigar);
insereFila(&galoGuerreiro.hab gritoDeGuerra);
insereFila(&galoGuerreiro.hab avancarComEscudo);


//Galinha Pintadinha:
tp_pokemon galinhaPintadinha;
galinhaPintadinha.vida = 300;
galinhaPintadinha.atq = 20;
galinhaPintadinha.def = 0.6;
galinhaPintadinha.agil = 80;
galinhaPintadinha.evolucao = 1

inicializaFila(&galinhaPintadinha.hab);
insereFila(&galinhaPintadinha.hab chute);
insereFila(&galinhaPintadinha.hab sambar);
insereFila(&galinhaPintadinha.hab botarSaia);
insereFila(&galinhaPintadinha.hab pintinhoAmarelinho);


//ticoliro
tp_pokemon ticoLiro;
ticoLiro.vida = 180;
ticoLiro.atq = 35;
ticoliro.def = 0.8;
ticoLiro.agil = 50;
ticoLiro.evolucao = 1;

inicializaFila(&ticoLiro.hab);
insereFila(&ticoLiro.hab soco);
insereFila(&ticoLiro.hab rolar);
insereFila(&ticoLiro.hab chorar);
insereFila(&ticoLiro.hab tacada);


//dôdo
tp_pokemon dodo;
dodo.vida = 150;
dodo.nome = "Dodo";
dodo.atq = 20;
dodo.def = 0.8;
dodo.agil = 50;
dodo.evolucao = 1;

inicializaFila(&dodo.hab);
insereFila(&dodo.hab bicada);
insereFila(&dodo.hab rolar);
insereFila(&dodo.hab hibernar);
insereFila(&dodo.hab extincao);


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

