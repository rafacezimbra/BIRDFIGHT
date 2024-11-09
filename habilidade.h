#ifndef HABILIDADE_H
#define HABILIDADE_H
#include <string.h>
#include <stdio.h>
#define MAX 100
#define numHab 42
typedef struct {

char nome[50];

char tipo[15];
//tipos: normal, eletrico, agua, dancarino, lutador, planta, sombrio, nenhum

int dano;

int temEfeito;
int efDefOp;
int efDefAl;
int efAtkOp;
int efAtkAl;
int efAgilOp;
int efAgilAl;


//efeitos especiais para certas habilidades serao adicionados em suas funcoes respectivas
//funcoes so serao adicionadas apos a criacao do sistema de batalha

} tp_hab;

// HABILIDADE 1
// habilidades na primeira posicao sao as mais basicas e nao tem tipo 


//TESTE DE FUNCAO
// Função para inicializar uma habilidade
void criarHabilidades(tp_hab hab[]) {
  /*
  for(int i=0; i<numHab; i++){

    hab[i].temEfeito = 0;
    hab[i].efDefOp = 0;
    hab[i].efDefAl = 0;
    hab[i].efAtkOp = 0;
    hab[i].efAtkAl = 0;
    hab[i].efAgilOp = 0;
    hab[i].efAgilAl = 0;
  
  }
  */
  //HABILIDADE 1:
    strcpy(hab[0].nome, "Bicada");
    strcpy(hab[0].tipo, "nenhum");
    hab[0].dano = 30; 
    
    strcpy(hab[1].nome, "Chute");
    strcpy(hab[1].tipo, "nenhum");
    hab[1].dano = 30;
    
    strcpy(hab[2].nome, "Soco");
    strcpy(hab[2].tipo, "nenhum");
    hab[2].dano = 30;

  //HABILIDADE 2:
    strcpy(hab[3].nome, "Choque");
    strcpy(hab[3].tipo, "eletrico");
    hab[3].dano = 40;
    
    strcpy(hab[4].nome, "Amaldicoar");
    strcpy(hab[4].tipo, "sombrio");
    hab[4].temEfeito = 1;
    hab[4].efDefOp = 1;
    hab[4].efDefAl = 0;
    hab[4].efAtkOp = 0;
    hab[4].efAtkAl = 0;
    hab[4].efAgilOp = 0;
    hab[4].efAgilAl = 0;
    hab[4].dano = 35;
    
    strcpy(hab[5].nome, "Encharcar");
    strcpy(hab[5].tipo, "agua");
    hab[5].dano = 35;
    
    strcpy(hab[6].nome, "Brigar");
    strcpy(hab[6].tipo, "lutador");
    hab[6].dano = 40;
    
    strcpy(hab[7].nome, "Sambar");
    strcpy(hab[7].tipo, "dancarino");
    hab[7].dano = 40;
    
    strcpy(hab[8].nome, "Semear");
    strcpy(hab[8].tipo, "planta");
    hab[8].dano = 40;
    
    strcpy(hab[9].nome, "Rolar");
    strcpy(hab[9].tipo, "normal");
    hab[9].dano = 40;
    
  //HABILIDADE 3:
    strcpy(hab[10].nome, "Eletrizar");
    strcpy(hab[10].tipo, "eletrico");
    hab[10].temEfeito = 1;
    hab[10].efDefOp = 0;
    hab[10].efDefAl = 0;
    hab[10].efAtkOp = 0;
    hab[10].efAtkAl = 0;
    hab[10].efAgilOp = 0;
    hab[10].efAgilAl = 1;
    hab[10].dano = 0;

    strcpy(hab[11].nome, "Petrificar");
    strcpy(hab[11].tipo, "sombrio");
    hab[11].temEfeito = 1;
    hab[11].efDefOp = 0;
    hab[11].efDefAl = 0;
    hab[11].efAtkOp = 0;
    hab[11].efAtkAl = 0;
    hab[11].efAgilOp = 1;
    hab[11].efAgilAl = 0;
    hab[11].dano = 0; 

    strcpy(hab[12].nome, "Relaxar");
    strcpy(hab[12].tipo, "agua");
    hab[12].temEfeito = 1;
    hab[12].efDefOp = 1;
    hab[12].efDefAl = 0;
    hab[12].efAtkOp = 0;
    hab[12].efAtkAl = 0;
    hab[12].efAgilOp = 0;
    hab[12].efAgilAl = 0;
    hab[12].dano = 0; 

    strcpy(hab[13].nome, "Tocar Berimbau");
    strcpy(hab[13].tipo, "dancarino");
    hab[13].temEfeito = 1;
    hab[13].efDefOp = 0;
    hab[13].efDefAl = 0;
    hab[13].efAtkOp = 0;
    hab[13].efAtkAl = 1;
    hab[13].efAgilOp = 0;
    hab[13].efAgilAl = 1;
    hab[13].dano = 0; 

    strcpy(hab[14].nome, "Grito de Guerra");
    strcpy(hab[14].tipo, "lutador");
    hab[14].temEfeito = 1;
    hab[14].efDefOp = 0;
    hab[14].efDefAl = 0;
    hab[14].efAtkOp = 0;
    hab[14].efAtkAl = 1;
    hab[14].efAgilOp = 0;
    hab[14].efAgilAl = 0;
    hab[14].dano = 0;
    
    strcpy(hab[15].nome, "Botar Saia");
    strcpy(hab[15].tipo, "dancarino");
    hab[15].temEfeito = 1;
    hab[15].efDefOp = 1;
    hab[15].efDefAl = 0;
    hab[15].efAtkOp = 0;
    hab[15].efAtkAl = 1;
    hab[15].efAgilOp = 0;
    hab[15].efAgilAl = 1;
    hab[15].dano = 0;
    
    strcpy(hab[16].nome, "Chorar");
    strcpy(hab[16].tipo, "normal");
    hab[16].temEfeito = 1;
    hab[16].efDefOp = 1;
    hab[16].efDefAl = 0;
    hab[16].efAtkOp = 0;
    hab[16].efAtkAl = 0;
    hab[16].efAgilOp = 0;
    hab[16].efAgilAl = 0;
    hab[16].dano = 0;
    
    strcpy(hab[17].nome, "Hibernar");
    strcpy(hab[17].tipo, "normal");
    hab[17].temEfeito = 1;
    hab[17].efDefOp = 0;
    hab[17].efDefAl = 0;
    hab[17].efAtkOp = 0;
    hab[17].efAtkAl = 0;
    hab[17].efAgilOp = 0;
    hab[17].efAgilAl = 1;
    hab[17].dano = 0;
    
    strcpy(hab[18].nome, "Golpe Baixo");
    strcpy(hab[18].tipo, "lutador");
    hab[18].temEfeito = 1;
    hab[18].efDefOp = 1;
    hab[18].efDefAl = 0;
    hab[18].efAtkOp = 0;
    hab[18].efAtkAl = 0;
    hab[18].efAgilOp = 0;
    hab[18].efAgilAl = 0;  
    hab[18].dano = 25;
    
    strcpy(hab[19].nome, "Enrolar");
    strcpy(hab[19].tipo, "planta");
    hab[19].temEfeito = 1;
    hab[19].efDefOp = 0;
    hab[19].efDefAl = 1;
    hab[19].efAtkOp = 0;
    hab[19].efAtkAl = 0;
    hab[19].efAgilOp = 0;
    hab[19].efAgilAl = 0;
    hab[19].dano = 0;
    
    strcpy(hab[20].nome, "Festa em Ipanema");
    strcpy(hab[20].tipo, "dancarino");
    hab[20].temEfeito = 1;
    hab[20].efDefOp = 1;
    hab[20].efDefAl = 1;
    hab[20].efAtkOp = 0;
    hab[20].efAtkAl = 0;
    hab[20].efAgilOp = 1;
    hab[20].efAgilAl = 1;
    hab[20].dano = 0;
    
    strcpy(hab[21].nome, "Noite Chuvosa");
    strcpy(hab[21].tipo, "Sombrio");
    hab[21].temEfeito = 1;
    hab[21].efDefOp = 0;
    hab[21].efDefAl = 0;
    hab[21].efAtkOp = 0;
    hab[21].efAtkAl = 1;
    hab[21].efAgilOp = 0;
    hab[21].efAgilAl = 0;
    hab[21].dano = 0;
    
    strcpy(hab[22].nome, "Acelerar!");
    strcpy(hab[22].tipo, "eletrico");
    hab[22].temEfeito = 1;
    hab[22].efDefOp = 0;
    hab[22].efDefAl = 1;
    hab[22].efAtkOp = 0;
    hab[22].efAtkAl = 1;
    hab[22].efAgilOp = 0;
    hab[22].efAgilAl = 1;
    hab[22].dano = 0;
    
    strcpy(hab[23].nome, "Bolo de Morango");
    strcpy(hab[23].tipo, "normal");
    hab[23].temEfeito = 1;
    hab[23].efDefOp = 0;
    hab[23].efDefAl = 0;
    hab[23].efAtkOp = 0;
    hab[23].efAtkAl = 0;
    hab[23].efAgilOp = 0;
    hab[23].efAgilAl = 1;
    hab[23].dano = 0;
    
    strcpy(hab[24].nome, "Sorrir e Acenar");
    strcpy(hab[24].tipo, "dancarino");
    hab[24].temEfeito = 1;
    hab[24].efDefOp = 0;
    hab[24].efDefAl = 1;
    hab[24].efAtkOp = 0;
    hab[24].efAtkAl = 0;
    hab[24].efAgilOp = 0;
    hab[24].efAgilAl = 0;
    hab[24].dano = 0;
    
    strcpy(hab[25].nome, "Camuflagem");
    strcpy(hab[25].tipo, "planta");
    hab[25].temEfeito = 1;
    hab[25].efDefOp = 0;
    hab[25].efDefAl = 0;
    hab[25].efAtkOp = 0;
    hab[25].efAtkAl = 0;
    hab[25].efAgilOp = 0;
    hab[25].efAgilAl = 1;
    hab[25].dano = 0;

  //HABILIDADE 4:
    strcpy(hab[26].nome, "Bombardeio Eletrico");
    strcpy(hab[26].tipo, "eletrico");
    hab[26].dano = 80;
    
    strcpy(hab[27].nome, "Paralizar");
    strcpy(hab[27].tipo, "sombrio");
    hab[27].temEfeito = 1;
    hab[27].efDefOp = 0;
    hab[27].efDefAl = 0;
    hab[27].efAtkOp = 0;
    hab[27].efAtkAl = 0;
    hab[27].efAgilOp = 1;
    hab[27].efAgilAl = 0;
    hab[27].dano = 50;
    
    strcpy(hab[28].nome, "Agua Quente");
    strcpy(hab[28].tipo, "agua");
    hab[28].temEfeito = 1;
    hab[28].efDefOp = 1;
    hab[28].efDefAl = 0;
    hab[28].efAtkOp = 0;
    hab[28].efAtkAl = 0;
    hab[28].efAgilOp = 0;
    hab[28].efAgilAl = 0;
    hab[28].dano = 55;
    
    strcpy(hab[29].nome, "Meia Lua");
    strcpy(hab[29].tipo, "lutador");
    hab[29].dano = 55;
    
    strcpy(hab[30].nome, "Avancar com Escudo");
    strcpy(hab[30].tipo, "lutador");
    hab[30].temEfeito = 1;
    hab[30].efDefOp = 0;
    hab[30].efDefAl = 1;
    hab[30].efAtkOp = 0;
    hab[30].efAtkAl = 0;
    hab[30].efAgilOp = 0;
    hab[30].efAgilAl = 0;
    hab[30].dano = 60;
    
    strcpy(hab[31].nome, "Pintinho Amarelinho");
    strcpy(hab[31].tipo, "dancarino");
    hab[31].temEfeito = 1;
    hab[31].efDefOp = 0;
    hab[31].efDefAl = 1;
    hab[31].efAtkOp = 0;
    hab[31].efAtkAl = 0;
    hab[31].efAgilOp = 1;//diminui
    hab[31].efAgilAl = 1;//aumenta
    hab[31].dano = 0;
    
    strcpy(hab[32].nome, "Tacada");
    strcpy(hab[32].tipo, "normal");
    hab[32].temEfeito = 1;
    hab[32].efDefOp = 1;//diminui
    hab[32].efDefAl = 0;
    hab[32].efAtkOp = 1;//diminui
    hab[32].efAtkAl = 0;
    hab[32].efAgilOp = 1;//diminui
    hab[32].efAgilAl = 0;
    hab[32].dano = 60;
    
    strcpy(hab[33].nome, "Extincao");
    strcpy(hab[33].tipo, "normal");
    hab[33].dano = 999;
    
    strcpy(hab[34].nome, "Rolada");
    strcpy(hab[34].tipo, "normal");
    hab[34].temEfeito = 1;
    hab[34].efDefOp = 0;
    hab[34].efDefAl = 0;
    hab[34].efAtkOp = 0;
    hab[34].efAtkAl = 0;
    hab[34].efAgilOp = 0;
    hab[34].efAgilAl = 1;//aumenta
    hab[34].dano = 65;
    
    strcpy(hab[35].nome, "Ta Dando Onda");
    strcpy(hab[35].tipo, "planta");
    hab[35].temEfeito = 1;
    hab[35].efDefOp = 1;//diminui
    hab[35].efDefAl = 0;
    hab[35].efAtkOp = 0;
    hab[35].efAtkAl = 0;
    hab[35].efAgilOp = 0;
    hab[35].efAgilAl = 0;
    hab[35].dano = 55;
    
    strcpy(hab[36].nome, "Carnaval");
    strcpy(hab[36].tipo, "dancarino");
    hab[36].temEfeito = 1;
    hab[36].efDefOp = 1;//diminui
    hab[36].efDefAl = 1;//diminui
    hab[36].efAtkOp = 0;
    hab[36].efAtkAl = 0;
    hab[36].efAgilOp = 0;
    hab[36].efAgilAl = 1;//diminui
    hab[36].dano = 85;
    
    strcpy(hab[37].nome, "Evanescence");
    strcpy(hab[37].tipo, "sombrio");
    hab[37].temEfeito = 1;
    hab[37].efDefOp = 1;
    hab[37].efDefAl = 0;
    hab[37].efAtkOp = 0;
    hab[37].efAtkAl = 0;
    hab[37].efAgilOp = 0;
    hab[37].efAgilAl = 0;
    hab[37].dano = 35;
    
    strcpy(hab[38].nome, "Beep Beep!");
    strcpy(hab[38].tipo, "planta");
    hab[38].temEfeito = 1;
    hab[38].efDefOp = 0;
    hab[38].efDefAl = 0;
    hab[38].efAtkOp = 0;
    hab[38].efAtkAl = 1;
    hab[38].efAgilOp = 0;
    hab[38].efAgilAl = 1;
    hab[38].dano = 50;
    
    strcpy(hab[39].nome, "E la vamos nos!");
    strcpy(hab[39].tipo, "planta");
    hab[39].temEfeito = 1;
    hab[39].efDefOp = 0;
    hab[39].efDefAl = 0;
    hab[39].efAtkOp = 0;
    hab[39].efAtkAl = 0;
    hab[39].efAgilOp = 0;
    hab[39].efAgilAl = 1;
    hab[39].dano = 55;
    
    strcpy(hab[40].nome, "boom?");
    strcpy(hab[40].tipo, "agua");
    hab[40].temEfeito = 0;
    hab[40].efDefOp = 0;
    hab[40].efDefAl = 0;
    hab[40].efAtkOp = 0;
    hab[40].efAtkAl = 0;
    hab[40].efAgilOp = 0;
    hab[40].efAgilAl = 0;
    hab[40].dano = 90;
    
    strcpy(hab[41].nome, "Explosao de Kiwi");
    strcpy(hab[41].tipo, "planta");
    hab[41].temEfeito = 0;
    hab[41].efDefOp = 0;
    hab[41].efDefAl = 0;
    hab[41].efAtkOp = 0;
    hab[41].efAtkAl = 0;
    hab[41].efAgilOp = 0;
    hab[41].efAgilAl = 0;
    hab[41].dano = 60;
}


#endif
