//lista simplesmente encadeada (cada nó tem o conteudo e um ponteiro)
/*https://youtu.be/H7p2QZOVlD0*/
#ifndef LISTASERANK_H
#define LISTASERANK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tp_rank;


typedef struct tp_no_rank{
    tp_rank rodada;
    char nome[30];
    struct tp_no_rank *prox; //ponteiro que aponta para outra struct dessa
}tp_listase_rank;

tp_listase_rank* iniciaListaseRank(){  //envia um ponteiro do tipo listase
    return NULL;
}

int listaseVaziaRank(tp_listase_rank *lista){  //recebe o conteudo do ponteiro lista
    if(lista==NULL){
        return 1;
    }else{
        return 0;
    }
}


tp_listase_rank * alocaListaseRank(){
    tp_listase_rank *novo_no;        //cria um nó e aloca espaço para ele e retorna o endereço de memoria
    novo_no = (tp_listase_rank*) malloc(sizeof(tp_listase_rank));
    return novo_no;
}

int insereListaseOrdenadaOLD(tp_listase_rank **l, tp_rank e, char nome[30]){
  tp_listase_rank *novo_no, *atu;
  novo_no=alocaListaseRank(); //Endereço de memoria do novo no, criado pelo aloca lista, para o novo no
  if(novo_no==NULL) return 0; // Não alocou memória
   novo_no->rodada = e; // atribuir os valores para o novo nó;
   novo_no->prox = NULL; //finaliza o encadeamento do nó
   strcpy(novo_no->nome, nome);

  if(listaseVaziaRank(*l)){// se for o primeiro nó entra aqui
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

  int insereListaseOrdenada (tp_listase_rank *l, tp_rank rodada, char nome[30]){
	tp_listase_rank *novo_no, *atu, *ant;
	novo_no=alocaListaseRank();
	if(novo_no==NULL) return 0;
	novo_no->rodada = rodada;
	strcpy(novo_no->nome, nome);
	novo_no->prox = NULL;
	if(listaseVaziaRank(l)){
		l=novo_no;
	} else {
		atu = l;
		ant = NULL;
		int r = atu->rodada;
		while(r>novo_no->rodada){
			ant=atu;
			atu=atu->prox;
			r = atu->rodada;
		}
		ant->prox=novo_no;
		novo_no->prox=atu->prox;
	
	return 1;
	}
}
  

void destroiListaseRank(tp_listase_rank **lista){
    tp_listase_rank *atu;
    atu = *lista;
    while(atu!=NULL){
        *lista=atu->prox;
        free(atu);
        atu = *lista;
    }
    *lista = NULL;
}


void imprime_e_escreve_listase(tp_listase_rank *lista){

    FILE *arquivo = fopen("ranking.txt", "r");
    tp_listase_rank *atu;
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
