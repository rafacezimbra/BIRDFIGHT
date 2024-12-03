//� importante difernciar as estruturas nesta biblioteca. Temos dois dados estruturados: a descritor e o n� da lista

#ifndef LISTADE_H
#define LISTADE_H
#include <stdio.h>
#include <stdlib.h>
typedef int tp_itemLDE;
//dados estruturado que representa o descritor
typedef struct tp_no_aux {
	struct tp_no_aux *ant;
	tp_itemLDE info;
	struct tp_no_aux *prox;
} tp_no;
//dado estruturado que representa a lista
typedef struct {
	tp_no *ini;
	tp_no *fim;
	// int tamanho;
} tp_listad;
//aloca-se mem�ria para o descritor (explicado no �nicio deste arquivo) e faz o seus ponteiros apontarem para o Nulo

tp_listad *inicializa_listad(){
	tp_listad *lista=(tp_listad*) malloc(sizeof(tp_listad));
	lista->ini = NULL;
	lista->fim = NULL;
	// lista->tamanho = 0;
	return lista;
}
int listad_vazia(tp_listad *lista) {
	if ( (lista->ini == NULL) )
	return 1;
	return 0;
}
//Aloca um n� da lista
tp_no *aloca() {
	tp_no* pt;
	pt=(tp_no*) malloc(sizeof(tp_no));
	return pt;
}
//insere um novo n� na lista
int insere_listad_no_fim (tp_listad *lista, tp_itemLDE e){
	tp_no *novo;
	novo=aloca();
	if (!novo) return 0;
	novo->info = e;
	novo->prox = NULL;
	if ( listad_vazia(lista) ){ //Se for o primeiro elemento da lista
		novo->ant = NULL;
		lista->ini = lista->fim = novo;
	} else {
		novo->ant = lista->fim;
		lista->fim->prox = novo;
		lista->fim = novo;
	}
	//lista->tamanho++;
	return 1;
}



int insere_listad_no_inicio (tp_listad *lista, tp_itemLDE e){
	tp_no *novo;
	novo=aloca();
	if (!novo) return 0;
	novo->info = e;
	novo->prox = NULL;
	novo->ant = NULL;
	novo->prox= lista->ini;
	lista->ini = novo;
}

//imprime os conte�dos da lista
void imprime_listad(tp_listad *lista) {
	if (lista==NULL)
	printf("Lista n�o inicializada");
	else {
		tp_no *atu;
		atu = lista->ini;
		while (atu != NULL) {
			printf("%d ", atu->info);
			atu=atu->prox;
		}
	}
	printf("\n");
}

int tam_listad(tp_listad *lista) {
	int tam=0;
	tp_no *atu;
	atu=lista->ini;
	if ( listad_vazia(lista) ){
		return 0;
	} else {
		
		while (atu != NULL) {
			atu=atu->prox;
			tam+=1;
		}
	}

	return tam;
}

//remove um elemento da lista
int remove_listad (tp_listad *lista, tp_itemLDE e){
	tp_no *atu;
	atu = lista->ini;
	while ( (atu != NULL) && (atu->info != e) ) {
		atu=atu->prox;
	}
	if ( atu == NULL) return 0;
	if (lista->ini == lista->fim) { //Se o for o unico elemento da lista
		lista->ini = lista->fim = NULL; 
	} else {
		if (lista->ini == atu) { //Se for o primeiro elemento da lista
			lista->ini = atu->prox;
			atu->prox->ant = NULL;
		} else {
		if (lista->fim == atu) { // se for o �ltimo n� da lista
			lista->fim = atu->ant;
			atu->ant->prox = NULL;
		} else {
			atu->prox->ant = atu->ant;
			atu->ant->prox = atu->prox;
			}
		}
	}
	free(atu);
	//lista->tamanho--;
	return 1;
}

//Com base em um conte�do, retorna-se o endere�o do n� que cont�m o conte�do
tp_no * busca_listade (tp_listad *lista, tp_itemLDE e){
	tp_no *atu;
	atu = lista->ini;
	while ( (atu != NULL) && (atu->info != e) ) {
		atu=atu->prox;
	}
	return atu;
}
//Retira da mem�ria todos os n�s da lista e tamb�m o descritor
tp_listad * Destroi_listad (tp_listad *lista){tp_no *atu;
	atu = lista->ini;
	while (atu != NULL) {
		lista->ini = atu->prox;
		free(atu);
		atu=lista->ini;
	}
	free(lista);
	return NULL;
}
#endif
