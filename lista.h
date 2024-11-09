//lista simplesmente encadeada (cada nó tem o conteudo e um ponteiro)
/*https://youtu.be/H7p2QZOVlD0*/
#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>

typedef void* tp_item;

typedef struct tp_no{
    tp_item info;
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

int insereListase(tp_listase **l, tp_item e){
  tp_listase *novo_no, *atu;
  novo_no=alocaListase(); //Endereço de memoria do novo no, criado pelo aloca lista, para o novo no
  if(novo_no==NULL) return 0; // Não alocou memória
   novo_no->info = e; // atribuir os valores para o novo nó;
   novo_no->prox = NULL; //finaliza o encadeamento do nó

  if(listaseVazia(*l)){// se for o primeiro nó entra aqui
   *l=novo_no;
} else{
  atu = *l;
  while(atu->prox != NULL){
    atu=atu->prox; //aponta para o ultimo nó
    }
  atu->prox=novo_no;
  }
  return 1;
  }
  
  
void printListase(tp_listase *lista){
    tp_listase *atu;
    atu = lista;
    while(atu!=NULL){
        printf("%p ", atu->info);
        atu = atu->prox;
    }
}

int removeListase(tp_listase **l, tp_item e){
    tp_listase *atu, *ant;
    
    ant = NULL;
    atu = *l; //aponta pro primeiro (main)
    
    while((atu!=NULL)&&(atu->info != e)){ //enquanto nao for o ultimo elemento e nao for o elemento que eu quero
        ant = atu;                          //anterior passa a ser o atual
        atu = atu->prox;                    //atual passa a ser o proximo
    }   
    if(atu==NULL){                          //Não achou o elemento
        return 0;
    }
    if(ant==NULL){                          //se for retirado o primeiro elemento
        *l = atu->prox;                     //o *l da main, passa a ser o proximo, ja que o primeiro nao existe mais
    }else{
        ant->prox = atu->prox;              //caso contrario, o anterior vai ligar para o proximo, pulando o que vai ser excluido
    }
    free(atu);                              //desvincula o no que foi excluido
    atu = NULL;
    return 1;
    
}

tp_listase *buscaListase(tp_listase *lista, tp_item e){
    tp_listase *atu;
    atu = lista;
    while((atu!=NULL)&&(atu->info != e)){
        atu = atu->prox;
    }
    return atu;
}

int tamanhoListase(tp_listase *lista){
    int cont = 0;
    tp_listase *atu;
    atu = lista;
    while(atu!=NULL){
        cont ++;
        atu=atu->prox;
    }
    return cont;
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
        if(atu1->info != atu2->info) return 0;
    
    atu1 = atu1->prox;
    atu2 = atu2->prox;
    }
    return 1;
}
#endif