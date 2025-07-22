/* ******************************************** */
/* **** header - arquivo A08Ex04_header.h  **** */
/* ******************************************** */ 
#ifndef A09EX04_HEADER_H
#define A09EX04_HEADER_H

typedef struct {
	int qde;
	int jogador[11];
} Time;

void carregaAtaque(Time *, int);	// monta o time de ataque
void organizaAtaque(Time *); 		// encontra atacante mais avançado
void carregaDefesa(Time *, int);	// monta o time de defesa
void organizaDefesa(Time *);  		// encontra os dois defensores mais recuados
char analisaLance(Time, Time);     	// verifica se tem impedimento na jogada

#endif

