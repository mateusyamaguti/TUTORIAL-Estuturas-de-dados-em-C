/* ********************************************* */
/* ****    principal - arquivo A09Ex04.c    **** */
/* ********************************************* */
#include <stdio.h>
#include "A09Ex04_operacoes.c" // faz include no arquivo .c apenas dentro da ide
                               // faça include de arquivo .h
#define TRUE 1

int main() {
    Time timeAtaque; 
    Time timeDefesa;
	char impedido;
	int QdeA, QdeD;
	
    while (TRUE){
    	scanf("%d %d", &QdeA, &QdeD);
    	if (QdeA == 0) 
			break;
    	
    	carregaAtaque(&timeAtaque, QdeA);
    	organizaAtaque(&timeAtaque);
    	
    	carregaDefesa(&timeDefesa, QdeD);
    	organizaDefesa(&timeDefesa);
    	
    	impedido = lance(timeAtaque, timeDefesa);
    	printf("%c\n", impedido);
    }

    return 0;
}

