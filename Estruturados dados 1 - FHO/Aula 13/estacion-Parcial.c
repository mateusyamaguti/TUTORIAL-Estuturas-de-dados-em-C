#include <stdio.h> 
#include "estacion.h"

/* -------------------------------------------------------------------- */
int main() {
    No *vagas;
    int i, op, nroVeiculo=0, nro;
    char placa[8];

    inicializaPilha(&vagas);

    imprimePilha(vagas);

    while(1) {
	    printf("\nDIEGO'S PARKING HALL\n");
	    printf("1 - Entrada de um novo carro\n");
	    printf("2 - Saida do ultimo carro\n");
	    printf("3 - Saida de um carro especifico\n");
	    printf("4 - Exibe carros estacionados\n");
	    printf("5 - Encerra\n");
	    scanf("%d", &op);
		if(op==5)
			break;
			
		if(op==1){
			nroVeiculo++;
 			...
 			
 
 		}
		
		if(op==2){
			...
		}
    	
		if(op==3){
			printf("Numero da gia de estacionamento: ");
			...
		}
    	
		if(op==4){
	        ...
		}
    	        
    }

    return 0;

} /* fim da funcao main */
