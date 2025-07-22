#include <stdio.h> 

void shellSort(int *vet, int n){

}

int main(){
	int vet[30] = {23,45,12,43,13,56,18,42,89,67,7,3,18,34,17,54,5,3,14,25,65,22,9,15,33,12,6,52,48,15};
	int i, tam = 30;
	
	for(i=0; i<tam; i++){
		printf("%d ",vet[i]);
	}
	printf("\n\n");
	
	shellSort(vet, tam);
	
	for(i=0; i<tam; i++){
		printf("%d ",vet[i]);
	}
	return 0;
}

