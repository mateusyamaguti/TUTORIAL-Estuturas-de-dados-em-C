/* ********************************************* */
/* **** operações - arquivo A12operacoes.c  **** */
/* ********************************************* */
#include <stdio.h>
#include <stdlib.h>
#include "Aula12header.h"

/* funcao que inicializa a lista ------------- */
void inicializaLista (No **lista) {

    *lista = NULL;

} /* fim da funcao inicializaLista */

/* funcao que verifica se a lista esta vazia - */
int listaEstaVazia (No *lista) {

    if (lista == NULL)
        return 1;

    return 0;
} /* fim da funcao listaVazia */

/* funcao que imprime o conteudo da lista ----- */
void imprimeLista (No *lista) {

    No *aux = lista;

    if (listaEstaVazia(lista) ){
        printf("A lista esta vazia!\n");
        return;
    }

    printf("Lista:  [  ");

    // loop percorrendo do primeiro ao último nó da lista  
    while (aux != NULL) {
        printf("%d  ", aux->id);
        aux = aux->proximo;
    }

    printf("]\n");

} /* fim da funcao imprimeLista */


/* funcao que pesquisa por um elemento na lista ----------------------- */
No* pesquisaElemento (No *lista, int dadoPesquisa) {

    No *aux = lista;
    printf(" -> pesquisa por %d\n", dadoPesquisa);

   /* caso contrario, caminha na lista ate encontrar o elemento */
    while ((aux != NULL) && (aux->id != dadoPesquisa))
        aux = aux->proximo;    	
	/* retorna o ponteiro para o elemento encontrado    */
    /* (se o elemento nao foi encontrado, retorna NULL) */
    return aux;
} /* fim da funcao pesquisaElemento */


/* funcao que insere um elemento no inicio da lista ------------------- */
void insereInicio (No **lista, int novoid) {
    
    No *novo;
        
    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc(sizeof(No));
    novo->id = novoid;

    /* se a lista estiver vazia, novo noh aponta para NULL */
    if (listaEstaVazia(*lista) == 1)
        novo->proximo = NULL;
    /* caso contrario, novo noh aponta para o inicio da lista */
    else
        novo->proximo = *lista;

    /* novo noh passa a ser o inicio da lista */
    *lista = novo;

} /* fim da funcao insereInicio */

/* funcao que insere um elemento no final da lista -------------------- */
void insereFinal (No **lista, int novoid) {
    No *novo;
    No *aux = *lista;

    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->id = novoid;
    novo->proximo = NULL;

    /* se a lista estiver vazia, novo noh passa a ser o inicio da lista */
     if (listaEstaVazia(*lista)) {
        *lista = novo;
        return;
    }
	
	/* caso contrario, caminha na lista ate parar no ultimo noh */
    while (aux->proximo != NULL)
         aux = aux->proximo;
        
    /* ultimo noh aponta para o novo noh */
    aux->proximo = novo;

} /* fim da funcao insereFinal */

/* funcao que insere um elemento de forma ordenada na lista */
void insereOrdenado (No **lista, int novoid) {

    No *novo;
    No *aux = *lista;
    No *anterior = *lista;

    /* cria o novo noh a ser inserido na lista */
    novo = (No*) malloc (sizeof(No));
    novo->id = novoid;
    novo->proximo = NULL;

    /* se a lista estiver vazia, novo noh passa a ser o inicio da lista */
    if (listaEstaVazia(*lista)) {
        *lista = novo;
        return;
    }

   /* caso contrario, caminha na lista ate achar posicao correta */
    /* (insere de forma ordenada crescente na lista)              */
    while ((aux != NULL) && (aux->id < novoid)){
        anterior = aux;
        aux = aux->proximo;
    }

    /* testar se o novo nó será incluído antes do início da lista */
    if (aux == *lista) {
        insereInicio(lista, novoid);
        return;
    }

   /* testar se o novo nó virá após o final da lista */
    if (aux == NULL) {
        insereFinal(lista, novoid);
        return;
    }

    /* sobrou a inserção na posiçaõ encontrada no meio da lista */
    anterior->proximo = novo;
    novo->proximo = aux;

} /* fim da funcao insereOrdenado */


/* funcao que remove um elemento no inicio da lista -------------------- */
void removeInicio (No **lista){
	
	No *aux = *lista;
	
	if(listaEstaVazia(*lista))
		return;
		
	// fazer o início apontar para o segundo nó da estrutura
	*lista = aux->proximo;
	
	// devolver o uso da memória para o sistema operacional
	free(aux);	
}

/* funcao que remove um elemento no final da lista -------------------- */
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

/* funcao que remove um elemento especifico da lista ------------------ */
void removeEspecifico (No **lista, int idRemover){

    No *aux      = *lista;
    No *anterior = *lista;

    /* testar se a lista está vazia e encerrar */
    if (listaEstaVazia(*lista))
        return;

    printf("Id a ser removido %d\n", idRemover);

    /* camoinhar na lista até encontrar o elemento */
    while ((aux != NULL) && (aux->id != idRemover)) {
        anterior = aux;
        aux = aux->proximo;
    }

    /* testar se o id a ser removido não está na lista */                         
    if (aux == NULL) {
        printf("Id %d nao encontrado na lista!\n", idRemover);
        return;
    }

    /* testar se o elemento eh o da primeira posicao */
    if (aux == *lista) {
        removeInicio(lista);
        return;
    }

  /* testar se o elemento a ser removido é o último da lista */
    if (aux->proximo == NULL) {
        removeFinal(lista);
        return;
    }

    /* sobrou um nó do meio da lista como local a ser removido */
    anterior->proximo = aux->proximo;
    free(aux);
} /* fim da funcao removeElemento */                                                       


/* funcao que esvazia a lista ----------------------------------------- */
void esvaziaLista (No **lista) {

    /* enquanto a lista nao estiver vazia, entao 
	   remove o primeiro noh 
	*/
    
    while (!listaEstaVazia(*lista))
        removeInicio(lista);
      
} /* fim da funcao esvaziaLista */








