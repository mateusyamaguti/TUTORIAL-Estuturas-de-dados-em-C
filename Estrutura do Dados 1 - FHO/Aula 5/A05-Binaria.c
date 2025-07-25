#include <stdio.h> 
 
/* ********************************************* */
/* ***           pesquisa bin�ria            *** */
/* ********************************************* */
int pesquisaBinaria(int *v, int inicio, int fim, int valorPesquisado) {

    int meio = (inicio + fim) / 2;

    if (v[meio] == valorPesquisado)
        return meio;

    if (inicio >= fim)
        return -1;  // significa que o valor pesquisado n�o foi encontrado 

    if (valorPesquisado < v[meio])
        pesquisaBinaria(v, inicio, meio-1, valorPesquisado);
    else
        pesquisaBinaria(v, meio+1, fim, valorPesquisado);

} /* fim da funcao pesquisa */


/* ********************************************* */
/* ***          c�digo principal             *** */
/* ********************************************* */
int main () {

	/* condi��o necess�ria: vetor ordenado */
	int vet[20] = {3,5,7,12,14,15,17,18,19,23,25,33,34,42,43,45,54,56,67,89};
	
	int i, valor, tam = 20;
    int indiceRetornado;

    printf("\nDigite um valor para pesquisar: ");
    scanf("%d", &valor);  

	indiceRetornado = pesquisaBinaria(vet, 0, tam-1, valor);

	if(indiceRetornado == -1)
       printf("Valor nao encontrado");
    else   
       printf("Valor encontrado na posicao %d", indiceRetornado+1);
    return 0;

}
