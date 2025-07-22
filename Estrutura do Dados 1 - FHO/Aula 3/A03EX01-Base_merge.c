#include <stdio.h>
#include <stdlib.h>             /* malloc e rand */

/* ************************************************ */
/* ************ FUNÇÕES PARA MERGESORT ************ */
/* ************************************************ */
 
/* -------------------------------------------------------------------- */
void merge(int *v, int n) {


} /* end of mergeSort */


/* -------------------------------------------------------------------- */
void mergeSort(int *v, int n) {


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

    printf("\nEstrutura não ordenada\n");
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
