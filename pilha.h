#ifndef PILHA_H //if not define
#define PILHA_H
#include <stdio.h>
#include "pilha.h"
#define MAX 100

//pilha adaptada para caber pokemons
typedef tp_pokemon
tp_item_p;

typedef struct {
int topo;
tp_item_p item[MAX];
} tp_pilha;

void inicializaPilha(tp_pilha *p){
p->topo = -1;
}

int pilhaVazia(tp_pilha *p){
if (p->topo == -1) return 1; //verdadeiro, pilha esta vazia
return 0; //falso, pilha nao esta vazia
}

int pilhaCheia(tp_pilha *p){
if(p->topo == MAX-1) {
return 1;
} else {
return 0;
}
}

int push(tp_pilha *p, tp_item_p e){
if(pilhaCheia(p)==1) return 0; //testa se a pilha esteja cheia, aborta a funcao caso esteja
p->topo++; //aumenta o topo
p->item[p->topo] = e; //guarda o elemento no vetor na posicao topo
return 1;
}

int pop(tp_pilha *p, tp_item_p *e){
if (pilhaVazia(p)) return 0; //retorna 0 caso a pilha estiver vazia
*e = p->item[p->topo]; //joga o item para a variavel e (que deve ser criada na main)
p->topo--;
return 1;
}

int top(tp_pilha *p, tp_item_p *e){ //incompleta

if(pilhaVazia(p))
return 0;

*e = p->item[p->topo];
return 1;

}

void imprimePilha(tp_pilha p){
tp_item_p e;
printf("\n");
while (!pilhaVazia(&p)){
pop(&p, &e);
printf("%s", e.nome);
printf("\n");
}

}

int alturaPilha(tp_pilha *p){
return p->topo+1;
}

#endif //fim do ifndef (necessario)