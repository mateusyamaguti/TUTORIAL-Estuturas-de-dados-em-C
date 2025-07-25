#include <stdio.h>
#include <stdlib.h>             /* malloc e rand */


#define DDDD 10

/* ************************************************ */
/* ************ FUN��ES PARA MERGESORT ************ */
/* ************************************************ */
 
/* -------------------------------------------------------------------- */
void merge(int *v, int n) {

    int *aux;
    int meio;
    int i, j, k;
    
    meio = n/2;
         
        // declare e aloque vetorAux com tamanho N
        aux = (int *) malloc (n * sizeof(int));
             
		//compare cada par de elementos em ambas as parti��es:
		// fa�a i=0, j=meio e k=0
        i = 0;
        j = meio;
        k = 0;

        while ((i < meio) && (j < n)) { // enquanto i < meio e j < N, fa�a:

            if (v[i] <= v[j])          // se vetor[i] <= vetor[j]: vetorAux[k++] = vetor[i++]
               aux[k++] = v[i++];
             
            else                      // sen�o: vetorAux[k++] = vetor[j++]
                aux[k++] = v[j++];
                
        }


		// se i == meio: vetorAux[k++] = vetor[j++], enquanto j < N
        if (i == meio) {
            while (j < n)
                aux[k++] = v[j++];
        }
        // sen�o: vetorAux[k++] = vetor[i++], enquanto i < meio
        else {
            while (i < meio)
                aux[k++] = v[i++];
        }

		// copie vetorAux para vetor
        for (i = 0; i < n; ++i) 
            v[i] = aux[i];
                           
        free(aux);


} /* end of mergeSort */


/* -------------------------------------------------------------------- */
void mergeSort(int *v, int n) {

    int meio;
    int i, j, k;
 
//    printf("\n\nChamada da Funcao MergeSort\n");
//    for (i = 0; i < n; i++)
//        printf("%d ", v[i]);
     
    if (n > 1){  
        meio = n / 2; 
        
        // chama o procedimento recursivo:
		mergeSort(v, meio);
        mergeSort(v + meio, n - meio);
        
        merge(v, n);
	}
} /* end of mergeSort */       


/* ************************************************ */
/* ***********           MAIN           *********** */
/* ************************************************ */
int main (void) {
	
    int *baseDados;
    
    int n, i;

    /* gerando dados para teste */
    n = 10;
    baseDados = (int*) malloc (n * sizeof(int));
    
    for (i = 0; i < n; i++) 
		baseDados[i] = rand() % 80;
    
    
    /* testando Merge sort */
    printf("\nMerge sort\n\n");

    printf("\nEstrutura n�o ordenada\n");
    for (i = 0; i < n; i++)
        printf("%d ", baseDados[i]);
        
    mergeSort(baseDados, n);
    
    printf("\nEstrutura ordenada\n");
    for (i = 0; i < n; i++)
        printf("%d ", baseDados[i]);
        
     printf("\n");

    free(baseDados);

    return 0;

}
