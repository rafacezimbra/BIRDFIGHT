//lista simplesmente encadeada (cada nó tem o conteudo e um ponteiro)
/*https://youtu.be/H7p2QZOVlD0*/
#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tp_item;


typedef struct tp_no{
    tp_item rodada;
    char nome[30];
    struct tp_no *prox; //ponteiro que aponta para outra struct dessa
}tp_listase;

tp_listase* iniciaListase(){  //envia um ponteiro do tipo listase
    return NULL;
}

int listaseVazia(tp_listase *lista){  //recebe o conteudo do ponteiro lista
    if(lista==NULL){
        return 1;
    }else{
        return 0;
    }
}


tp_listase * alocaListase(){
    tp_listase *novo_no;        //cria um nó e aloca espaço para ele e retorna o endereço de memoria
    novo_no = (tp_listase*) malloc(sizeof(tp_listase));
    return novo_no;
}

int insereListaseOrdenadaOLD(tp_listase **l, tp_item e, char nome[30]){
  tp_listase *novo_no, *atu;
  novo_no=alocaListase(); //Endereço de memoria do novo no, criado pelo aloca lista, para o novo no
  if(novo_no==NULL) return 0; // Não alocou memória
   novo_no->rodada = e; // atribuir os valores para o novo nó;
   novo_no->prox = NULL; //finaliza o encadeamento do nó
   strcpy(novo_no->nome, nome);

  if(listaseVazia(*l)){// se for o primeiro nó entra aqui
   *l=novo_no;
} else{

  atu = *l;
  while(atu->prox != NULL && atu->prox->rodada >= e){
    atu=atu->prox; //aponta para o ultimo nó
    }
  atu->prox=novo_no;
  }
  return 1;
  }

  int insereListaseOrdenada (tp_listase **lista, tp_item e, char nome[30]){
	tp_listase *novo;
	novo=alocaListase();
	int i =0;
	tp_listase *atu, *ant;
	atu = *lista;
	ant = NULL;

	if (!novo) return 0;

	novo->rodada = e;
    strcpy(novo->nome, nome);
	novo->prox = NULL;

	if ( listaseVazia(*lista) ){ //Se for o primeiro elemento da lista
	    *lista=novo;
	}
	else {
		while(atu->prox != NULL && atu->prox->rodada >= e){
			ant=atu;
			atu=atu->prox;
		}
            novo->prox = atu;
            ant->prox = novo;
	}
    
    atu->prox=novo;
	
	return 1;
}
  

void destroiListase(tp_listase **lista){
    tp_listase *atu;
    atu = *lista;
    while(atu!=NULL){
        *lista=atu->prox;
        free(atu);
        atu = *lista;
    }
    *lista = NULL;
}

int listaseIgual(tp_listase *l1, tp_listase *l2){
    tp_listase *atu1;
    tp_listase *atu2;
    
    atu1 = l1;
    atu2 = l2;
    
    if(tamanhoListase(l1)!=tamanhoListase(l2)) return 0;
    
    while(atu1!=NULL){
        if(atu1->rodada != atu2->rodada) return 0;
    
    atu1 = atu1->prox;
    atu2 = atu2->prox;
    }
    return 1;
}


void imprime_e_escreve_listase(tp_listase *lista){

    FILE *arquivo = fopen("ranking.txt", "r");
    tp_listase *atu;
    atu=lista;

    printf("--- RANKING ---");

    int pos = 1;

    while (atu!=NULL){
        fprintf(arquivo, "%s\n%d\n", atu->nome, atu->rodada);
        printf("%d. %s - %d rodada(s) \n", pos, atu->nome, atu->rodada);
        atu=atu->prox;

        
    }
}
#endif