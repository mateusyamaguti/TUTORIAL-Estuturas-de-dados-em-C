#include <stdio.h>
#include <stdlib.h>

#include "Aula12header.h"

// inicializando a lista (mover NULL para o ponteiro inicio l� do main
void inicializaLista (No **lista){
	*lista = NULL;
}

// testar se a lista est� vazia
// retorna 1 se a lista estiver vazia
int listaEstaVazia (No *lista){
	if (lista == NULL)
	    return 1;
	    
	return 0;	
}

// funcao que exibe todo o conte�do da lista
void imprimeLista (No *lista){
	No *aux = lista;
	
	if (listaEstaVazia(lista) ){	
		printf("A lista esta vazia!!!\n");
		return;
	}
	
	printf("Lista: [");
	
	// loop percorrendo do primeiro ao �ltimo n� da lista
	while(aux != NULL){
		printf("%d ", aux->id);
		aux = aux->proximo;
	}
	
	printf("]\n");
}


// opera��o de inser��o de um n� no in�cio da lista
void insereInicio (No **lista, int novoid){
	
	No *novo;
	
	// cria o novo n� a ser inclu�do na lista
	novo = (No*) malloc(sizeof(No));
	novo->id = novoid;
	
	// testar se a lista est� vazia
	if (listaEstaVazia(*lista) == 1)
		novo->proximo = NULL;
		
	// caso contr�rio, o novo n� deve apontar para quem era o primeiro
	// n� da lista
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
	
	// se a lista estivber vazia, basta fazer o in�cio apontar para o novo n�
	if(listaEstaVazia(*lista)){
		*lista = novo;
		return;
	}
	
	// caso a lista n�o estiver vazia
	// encontrar o �ltimo n�
	while (aux->proximo != NULL)
		aux = aux->proximo;
		
	aux->proximo = novo;	
}



void removeInicio (No **lista){
	
	No *aux = *lista;
	
	if(listaEstaVazia(*lista))
		return;
		
	// fazer o in�cio apontar para o segundo n� da estrutura
	*lista = aux->proximo;
	
	// devolver o uso da mem�ria para o sistema operacional
	free(aux);	
}

void removeFinal (No **lista){
	No *aux = *lista;
	No *anterior = *lista;
	
	if(listaEstaVazia(*lista))
		return;
		
	// caminhar at� o final da lista
	while(aux->proximo != NULL){
		anterior = aux;
		aux = aux->proximo;
	}
	
	// se existir apenas um no na lista, inicializar a lista
	if(aux == *lista)
		*lista = NULL;
		
	// caso contr�rio, remover o �ltimo elemento da lista
	else
		anterior->proximo = NULL;
		
	// libera a mem�ria do elemento removido
	free(aux);

}












