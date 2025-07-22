#ifndef LISTA_H

#define LISTA_H
/* declarada a estrutura de cada n� da lista */
typedef struct _no{
	int id;
	struct _no *proximo;
} No;

/* declara��es das opera��es */
void inicializaLista(No**);
int listaEstaVazia(No*);
void imprimeLista(No*);

void insereInicio(No**, int);
void insereFinal(No**, int);

void removeInicio(No**);
void removeFinal(No**);

#endif
