//FILA ADAPTADA PARA CABER HABILIDADES

#ifndef FILA_H //if not define
#define FILA_H
#include <stdio.h>
#include "habilidade.h"
#define MAX 100

typedef tp_hab
tp_item;

typedef struct {
int ini, fim;
//outro caminho - int tam

tp_item item[MAX];
} tp_fila;

void inicializaFila(tp_fila *f){
f->ini = f->fim = MAX-1;
}

int filaVazia(tp_fila *f){
if(f->ini == f->fim) return 1;
return 0;
}

int proximo (int pos){
if(pos == MAX-1) return 0; //chegou na ultima posicao, volta para o zero
pos++;
return pos;
}

int filaCheia (tp_fila *f){
if(proximo(f->fim)==f->ini)
return 1;
return 0;

}

int insereFila (tp_fila *f, tp_item e){
if(filaCheia(f))
return 0; //Nao foi possivel adicionar o elemento a fila

f->fim = proximo(f->fim);
f->item[f->fim]=e;
//f->tam++ caso houvesse contador
return 1;
}

int removeFila(tp_fila *f, tp_item *e){
if(filaVazia(f))
return 0; //nao foi possivel remover da fila
f->ini = proximo(f->ini);
*e = f->item[f->ini];
//f->tam-- caso houvesse contador
return 1;

}

void imprime_fila (tp_fila f){
tp_item e;

while(!filaVazia(&f)){
removeFila(&f, &e);
printf("\n%d", e);

}
}

int tamanhoFila(tp_fila *f){
if(filaVazia(f)) return 0;
if(f->ini < f->fim) return f->fim - f->ini;
return MAX - 1 - f->ini +f->fim + 1;
}
#endif //fim do ifndef (necessario)