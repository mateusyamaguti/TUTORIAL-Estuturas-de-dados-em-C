#include <stdio.h>
#include "Aula10_header.h"

void inicializaLista(No **lista){
	*lista = NULL;	
}


int listaEstaVazia(No *lista){
	if(lista==NULL)
	    return 1;
		
	return 0;	
}


void imprimeLista(No *lista){
	No *aux = lista;
	
	if(listaEstaVazia(lista) == 1){
//	if(listaEstaVazia(lista)){
		printf("A lista estah vazia!!!\n");
		return;
	}
	
	printf("Lista: [");
	
	while(aux != NULL){
		printf("%d ", aux->id);
		aux = aux->proximo;
	}
	
	printf("]\n");
	
}
