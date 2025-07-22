/* ************************************************** */ 
/* **** operações - arquivo A08Ex04_operacoes.c  **** */
/* ************************************************** */
#include <stdio.h>
#include "A09Ex04_header.h"

void ordenaBubbleSort2 (int *jog, int N) {  // Pode ser usada outra rotina de ordenação,
	int i, j, aux, troca = 1;				// inclusive a função qsort do próprio compilador
	for (i = 0; (i < N-1) && troca; i++) {
		troca = 0;
		for (j = 0; j < N-i-1; j++) {
			if (jog[j] > jog[j+1]) {
				aux = jog[j];
				jog[j] = jog[j+1];
				jog[j+1] = aux;
				troca = 1;
			}
		}
	}
}

void carregaAtaque(Time *a, int qde) {
	int i;
	a->qde = qde;
	for (i=0; i<a->qde; i++) {
		scanf("%d", &a->jogador[i]);
	}
}

void organizaAtaque(Time *a) { 
	ordenaBubbleSort2 (&a->jogador[0], a->qde) ;
}

void carregaDefesa(Time *d, int qde) {
	int i;
	d->qde = qde;
	for (i=0; i<d->qde; i++) {
		scanf("%d", &d->jogador[i]);
	}
}

char lance(Time a, Time d) {
	if (a.jogador[0] < d.jogador[1]) 
		return 'Y';
	else 
		return 'N';
}

