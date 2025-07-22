#include <stdio.h> 
 
/* ********************************************* */
/* ***           pesquisa binária            *** */
/* ********************************************* */
int pesquisaBinaria(int *v, int inicio, int fim, int valorPesquisado) {

    int meio = (inicio + fim) / 2;

    if (v[meio] == valorPesquisado)
        return meio;

    if (inicio >= fim)
        return -1;  // significa que o valor pesquisado não foi encontrado 

    if (valorPesquisado < v[meio])
        pesquisaBinaria(v, inicio, meio-1, valorPesquisado);
    else
        pesquisaBinaria(v, meio+1, fim, valorPesquisado);

} /* fim da funcao pesquisa */


/* ********************************************* */
/* ***          código principal             *** */
/* ********************************************* */
int main () {

	/* condição necessária: vetor ordenado */
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
