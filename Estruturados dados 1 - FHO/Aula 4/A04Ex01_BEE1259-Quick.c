#include <stdio.h> 

void quickSort(int *vetor, int esquerda, int direita){
    long  int i, j, pivo, aux,meio;
    
    pivo = vetor[esquerda];
	// outras opções para estabelecer o pivo
	//pivo = vetor[direita];
	//meio = (int) ((i + j) / 2);
    //pivo = vetor[meio];   
    
	i = esquerda;
    j = direita;
    
	while(i <= j){
		while (vetor[i] < pivo && i<direita) 
			i = i + 1;
	  	
		while (vetor[j] > pivo && j>esquerda) 
			j = j - 1;
      
		if(i <= j){         // permite trocar ascendente por descendente
			aux = vetor[i];
        	vetor[i] = vetor[j];
        	vetor[j] = aux;
        	i = i + 1;
        	j = j - 1;
    	}
      
	}
   
	if(j > esquerda) 
   		quickSort(vetor, esquerda, j);
   		
	if(i < direita) 
   		quickSort(vetor, i, direita);   
   		
}



int main(){
	int i, indp, indi, qde, par[100000], imp[100000];
	scanf("%d", &qde);
	for(i=0, indp=-1, indi=-1; i<qde; i++){
		scanf("%d", &par[++indp]);
		if(par[indp]%2 == 1){
			imp[++indi]= par[indp];
			indp--;
		}
	}
	
	quickSort(par, 0, indp);   // ascendente
	quickSort(imp, 0, indi);   // ascendente
	
	for(i=0; i<=indp; i++) 
		printf("%d\n", par[i]);		
	for(i=indi; i>=0; i--) // imprime de trás para frente
		printf("%d\n", imp[i]);
    return 0;
}
