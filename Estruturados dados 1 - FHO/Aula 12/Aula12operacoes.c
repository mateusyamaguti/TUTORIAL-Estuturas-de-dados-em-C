#include <stdio.h>
#include <stdlib.h>

#include "Aula12header.h"

// inicializando a lista (mover NULL para o ponteiro inicio lá do main
void inicializaLista (No **lista){
	*lista = NULL;
}

// testar se a lista está vazia
// retorna 1 se a lista estiver vazia
int listaEstaVazia (No *lista){
	if (lista == NULL)
	    return 1;
	    
	return 0;	
}

// funcao que exibe todo o conteúdo da lista
void imprimeLista (No *lista){
	No *aux = lista;
	
	if (listaEstaVazia(lista) ){	
		printf("A lista esta vazia!!!\n");
		return;
	}
	
	printf("Lista: [");
	
	// loop percorrendo do primeiro ao último nó da lista
	while(aux != NULL){
		printf("%d ", aux->id);
		aux = aux->proximo;
	}
	
	printf("]\n");
}


// operação de inserção de um nó no início da lista
void insereInicio (No **lista, int novoid){
	
	No *novo;
	
	// cria o novo nó a ser incluído na lista
	novo = (No*) malloc(sizeof(No));
	novo->id = novoid;
	
	// testar se a lista está vazia
	if (listaEstaVazia(*lista) == 1)
		novo->proximo = NULL;
		
	// caso contrário, o novo nó deve apontar para quem era o primeiro
	// nó da lista
	else
		novo->proximo = *lista;
		
	*lista = novo;
	
}


void insereFinal (No **lista, int novoid){
	No *novo;
	No *aux = *lista;
	
	novo = (No*) malloc(sizeof(No));	
	novo->id = novoid;
	novo->proximo = NULL;
	
	// se a lista estivber vazia, basta fazer o início apontar para o novo nó
	if(listaEstaVazia(*lista)){
		*lista = novo;
		return;
	}
	
	// caso a lista não estiver vazia
	// encontrar o último nó
	while (aux->proximo != NULL)
		aux = aux->proximo;
		
	aux->proximo = novo;	
}



void removeInicio (No **lista){
	
	No *aux = *lista;
	
	if(listaEstaVazia(*lista))
		return;
		
	// fazer o início apontar para o segundo nó da estrutura
	*lista = aux->proximo;
	
	// devolver o uso da memória para o sistema operacional
	free(aux);	
}

void removeFinal (No **lista){
	No *aux = *lista;
	No *anterior = *lista;
	
	if(listaEstaVazia(*lista))
		return;
		
	// caminhar até o final da lista
	while(aux->proximo != NULL){
		anterior = aux;
		aux = aux->proximo;
	}
	
	// se existir apenas um no na lista, inicializar a lista
	if(aux == *lista)
		*lista = NULL;
		
	// caso contrário, remover o último elemento da lista
	else
		anterior->proximo = NULL;
		
	// libera a memória do elemento removido
	free(aux);

}












