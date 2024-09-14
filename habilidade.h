#ifndef habilidade_h
#define habilidade_h
#include <string.h>
#include <stdio.h>
#define MAX 100

typedef struct {

char nome[50];

char tipo[15];
//tipos: normal, eletrico, agua, dancarino, lutador, planta, sombrio, nenhum

int dano;

//efeitos especiais para certas habilidades serao adicionados em suas funcoes respectivas
//funcoes so serao adicionadas apos a criacao do sistema de batalha

} tp_hab;

// HABILIDADE 1
// habilidades na primeira posicao sao as mais basicas e nao tem tipo 


//TESTE DE FUNCAO
// Função para inicializar uma habilidade
void criarHabilidades(tp_hab hab[]) {
  
    //bicada
    strcpy(hab[0].nome, "Bicada");
    strcpy(hab[0].tipo, "nenhum");
    hab[0].dano = 30; 
}






// chute
tp_hab chute;
chute.nome = "Chute";
chute.tipo = "nenhum";
chute.dano = 30;

// soco
tp_hab soco;
soco.nome = "soco";
soco.tipo = "nenhum";
soco.dano = 30;

// HABILIDADE 2
// habilidades na segunda posicao geralmente sao ataques do tipo do pokemon
//choque
tp_hab choque;
choque.nome = "Choque";
choque.tipo = "eletrico";
choque.dano = 40;

//amaldicoar
tp_hab amaldicoar;
amaldicoar.nome = "Amaldicoar";
amaldicoar.tipo = "sombrio";
amaldicoar.dano = 35;

//encharcar
tp_hab encharcar;
encharcar.nome = "Encharcar";
encharcar.tipo = "agua";
encharcar.dano = 35;

//brigar
tp_hab brigar;
brigar.nome = "Brigar";
brigar.tipo = "lutador";
brigar.dano = 40;

//sambar
tp_hab sambar;
sambar.nome = "Sambar";
sambar.tipo = "dancarino";
sambar.dano = 40;

//semear
tp_hab semear;
semear.nome = "Semear";
semear.tipo = "planta";
semear.dano = 40;

//rolar
tp_hab rolar;
rolar.nome = "Rolar";
rolar.tipo = "normal";
rolar.dano = 40;

// HABILIDADE 3
// Habilidades da posicao 3 sao do tipo de status e geralmente causam efeitos, e nao dano.

tp_hab eletrizar;
eletrizar.nome = "Eletrizar!";
eletrizar.tipo = "eletrico";
eletrizar.dano = 0;

tp_hab petrificar;
petrificar.nome = "Petrificar";
petrificar.tipo = "sombrio";
petrificar.dano = 0;

tp_hab relaxar;
relaxar.nome = "Relaxar";
relaxar.tipo = "agua";
relaxar.dano = 0;

tp_hab tocarBerimbau;
tocarBerimbau.nome = "Tocar Berimbau";
tocarBerimbau.tipo = "dancarino";
tocarBerimbau.dano = 0;

tp_hab gritoDeGuerra;
gritoDeGuerra.nome = "Grito de Guerra";
gritoDeGuerra.tipo = "lutador";
gritoDeGuerra.dano = 0;

tp_hab botarSaia;
botarSaia.nome = "Botar Saia";
botarSaia.tipo = "dancarino";
botarSaia.dano = 0;

tp_hab chorar;
chorar.nome = "Chorar";
chorar.tipo = "normal";
chorar.dano = 0;

tp_hab hibernar;
hibernar.nome = "Hibernar";
hibernar.tipo = "normal";
hibernar.dano = 0;

tp_hab golpeBaixo;
golpeBaixo.nome = "Golpe Baixo";
golpeBaixo.tipo = "lutador";
golpeBaixo.dano = 25;

tp_hab enrolar;
enrolar.nome = "Enrolar";
enrolar.tipo = "planta";
enrolar.dano = 0;

tp_hab festaEmIpanema;
festaEmIpanema.nome = "Festa em Ipanema";
festaEmIpanema.tipo = "dancarino";
festaEmIpanema.dano = 0;

tp_hab noiteChuvosa;
noiteChuvosa.nome = "Noite Chuvosa";
noiteChuvosa.tipo = "Sombrio";
noiteChuvosa.dano = 0;

tp_hab acelerar;
acelerar.nome = "Acelerar!";
acelerar.tipo = "eletrico";
acelerar.dano = 0;

tp_hab boloDeMorango;
boloDeMorango.nome = "Bolo de Morango";
boloDeMorango.tipo = "normal";
boloDeMorango.dano = 0;

tp_hab sorrirEAcenar;
sorrirEAcenar.nome = "Sorrir e Acenar";
sorriEAcenar.tipo = "dancarino";
sorrirEAcenar.dano = 0;

tp_hab camuflagem;
camuflagem.nome = "Camuflagem";
camuflagem.tipo = "planta";
camuflagem.dano = 0;


// HABILIDADE 4
// habilidades na posicao 4 sao habilidades especiais, unicas de cada passaro e com efeitos especiais

//Bombardeio eletrico
tp_hab bombardeioEletrico;
bombardeioEletrico.nome = "Bombardeio Eletrico";
bombardeioEletrico.tipo = "eletrico";
bombardeioEletrico.dano = 80;

//Paralizar
tp_hab paralizar
paralizar.nome = "Paralizar";
paralizar.tipo = "sombrio";
paralizar.dano = 50;
// paralizar.efeitoNoOponente = Chance do oponente nao atacar no prox turno;

//agua quente
tp_hab aguaQuente
aguaQuente.nome = "Agua Quente";
aguaQuente.tipo = "agua";
aguaQuente.dano = 55;
// aguaQuente.efeitoNoOponente = Chance de causar queimadura

//meia-lua
tp_hab meiaLua;
meiaLua.nome = "Agua Quente";
aguaQuente.tipo = "agua";
aguaQuente.dano = 55;

//avancarComEscudo
tp_hab avancarComEscudo
avancarComEscudo.nome = "Avancar com Escudo";
avancarComEscudo.tipo = "lutador";
avancarComEscudo.dano = 60;
//avancarComEscudo.efeitoNoUsuario = aumenta def

//Pintinho amarelinho
tp_hab pintinhoAmarelinho;
pintinhoAmarelinho.nome = "Pintinho Amarelinho";
pintinhoAmarelinho.tipo = "dancarino";
pintinhoAmarelinho.dano = 0;
//pintinhoAmarelinho.efeitoNoUsuario = aumenta agi
//pintinhoAmarelinho.efeitoNoOponente = diminui agi 


//Tacada
tp_hab tacada;
tacada.nome = "Tacada";
tacada.tipo = "normal";
tacada.dano = 60;
//tacada.efeitoNoOponente = chance de causar confusão

//Extinção
tp_hab extincao;
extincao.nome = "Extincao";
extincao.tipo = "normal";
extincao.dano = 999;
//elimina o oponente e a si mesmo instantaneamente

//Rolada
tp_hab rolada;
rolada.nome = "Rolada";
rolada.tipo = "normal";
rolada.dano = 65;
//rolada.efeitoNoUsuario = aumenta agi

//Ta dando onda
tp_hab taDandoOnda;
taDandoOnda.nome = "Ta Dando Onda";
taDandoOnda.tipo = "planta";
taDandoOnda.dano = 55;
//taDandoOnda.efeitoNoOponente = causa confusão

//Carnaval
tp_hab carnaval;
carnaval.nome = "Carnaval"
carnaval.tipo = "dancarino";
carnaval.dano = 85;
//carnaval.efeitoNoOponente = causa confusão
//carnaval.efeitoNoUsuario = causa confusão

//evanescence
tp_hab evanescence;
tp.nome = "Evanescence";
evanescence.tipo = "sombrio";
evanescence.dano = 35;
//evanescence.efeitoNoOponente = diminui def

//Beep Beep
tp_hab beepBeep;
beepBeep.nome = "Beep Beep!";
eLaVamosNos.tipo = "planta";
beepBeep.dano = 50;

//beepBeep.efeitoNoUsuario = chance de atk 2x

//E lá vamos nós
tp_hab eLaVamosNos;
eLaVamosNos.nome = "E la vamos nos!";
eLaVamosNos.tipo = "planta";
eLaVamosNos.dano = 55;

//eLaVamosNos.efeitoNoUsuario = chance de escolher outra habilidade para utilizar(round em dobro yeepee)

//Boom?
tp_hab boom;
boom.dano = "boom?";
boom.tipo = "agua";
boom.dano = 90;

//boom.efeitoNoUsuario = -40 hp


// Explosão de Kiwi

tp_hab explosaoDeKiwi;
explosaoDeKiwi.nome = "Explosao de Kiwi";
explosaoDeKiwi.tipo = "planta";
explosaoDeKiwi.dano = 60;
#endif
