#include <stdio.h>

int organizaTrem(int *vetor, int N) {
	
    int i, j, aux, flagTroca = 1, contTrocas=0;
    
    for (i = 0; (i < N-1) && flagTroca; i++) { 
        flagTroca = 0;
        
        for (j = 0; j < N-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                contTrocas++;
                flagTroca = 1;
            }
        }
    }
    return contTrocas;
}
 
int main(){
	int n, i, t, tam, qdeTrocas;
	int trem[50];
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &tam);
		for (t=0; t<tam; t++){
			scanf("%d", &trem[t]);
		}
		
		qdeTrocas = organizaTrem(trem, tam);
		printf("Optimal train swapping takes %d swaps.\n", qdeTrocas);
	}	
	
    return 0;
}
