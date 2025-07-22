// programa trabalha dados do indicador 3.2.2. das ODS
// mortalidade neonatal 

#include <stdio.h>
#include <stdlib.h>

#define QDEESTADOS 27

typedef struct _mort{
	char  estado[3];
	float mortes09;
	float mortes15;
	float indice;
} mortNeonatal;


void shellSortDes(mortNeonatal *vet, int n){
	int i, j, indk, k;
	int vetK[3] = {5, 3, 1};
	
	mortNeonatal aux;

	for(indk=0; indk<3; indk++){		
		k = vetK[indk];					
	
		for(i=k; i<n; i++){
			
			aux = vet[i];
			
			for(j=i-k; j>=0 && vet[j].mortes15 < aux.mortes15; j-=k){
				vet[j+k] = vet[j];	
			}
			
			vet[j+k] = aux;
		}
	}
}


int main(){
	
	mortNeonatal estados[QDEESTADOS];

	int i;

	for(i=0; i < QDEESTADOS; i++){
		scanf("%s %f %f", estados[i].estado, &estados[i].mortes09, &estados[i].mortes15);
		estados[i].indice = estados[i].mortes15 - estados[i].mortes09;
	}

	printf("\nDados em ordem de entrada\n");
	printf("Estado\t2009\t2015\tDiferenca\n");	
	for(i=0; i<QDEESTADOS; i++)
		printf("%s\t%.1f\t%.1f\t%.1f\n",estados[i].estado, estados[i].mortes09, estados[i].mortes15, estados[i].indice);

	shellSortDes(estados, QDEESTADOS);

	printf("\nDados ordenados por mortalidade em 2015\n");
	printf("Estado\t2009\t2015\tDiferenca\n");	
	for(i=0; i<QDEESTADOS; i++)
		printf("%s\t%.1f\t%.1f\t%.1f\n",estados[i].estado, estados[i].mortes09, estados[i].mortes15, estados[i].indice);
	
	return 0;
}
