#include <stdio.h>
#include <stdlib.h>

#define QDEESTADOS 27

typedef struct _mort{
	char  estado[3];
	float mortes09;
	float mortes15;
	float indice;
} mortMaterna;
	
 

void quicksort(mortMaterna *dados, int esq, int dir){
	int i, j, pivo;
     
	mortMaterna temp;
	
	pivo = esq;
   	i = esq;
   	j = dir;

    while(i <= j){
        
		while(dados[i].mortes15 < dados[pivo].mortes15 && i < dir)
            i++;
            
        while(dados[j].mortes15 >= dados[pivo].mortes15 && j > esq)
            j--;
            
        if(i <= j){
            temp     = dados[i];
            dados[i] = dados[j];
            dados[j] = temp;
            i++;
            j--;
        }
    }

 	if (j > esq)
	 	quicksort(dados, esq, j);
	 	
	if(i < dir)
		quicksort(dados, i, dir);
}


int main(){
	
	mortMaterna estados[QDEESTADOS];

	int i;

	for(i=0; i < QDEESTADOS; i++){
		scanf("%s %f %f", estados[i].estado, &estados[i].mortes09, &estados[i].mortes15);
		estados[i].indice = estados[i].mortes15 - estados[i].mortes09;
	}

	printf("\nDados em ordem de entrada\n");
	printf("Estado\t2009\t2015\tDiferenca\n");	
	for(i=0; i<QDEESTADOS; i++)
		printf("%s\t%.1f\t%.1f\t%.1f\n",estados[i].estado, estados[i].mortes09, estados[i].mortes15, estados[i].indice);

	quicksort(estados, 0, QDEESTADOS-1);

	printf("\nDados ordenados por mortalidade em 2015\n");
	printf("Estado\t2009\t2015\tDiferenca\n");	
	for(i=0; i<QDEESTADOS; i++)
		printf("%s\t%.1f\t%.1f\t%.1f\n",estados[i].estado, estados[i].mortes09, estados[i].mortes15, estados[i].indice);
	
	return 0;
}
