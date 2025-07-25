#include <stdio.h> 
 
/* ********************************************* */
/* ***          pesquisa sequencial          *** */
/* ********************************************* */
int pesquisaSequencial(int *v, int tamanho, int valorPesquisado) {

    int i = 0;

    while ( (v[i] != valorPesquisado) && (i < tamanho) )
        i++;

    /* se o valor nao foi encontrado retorna -1 */
    if (i == tamanho)
        return -1;

    /* se for encontrado, retorna o �ndice da tabela */
    else
        return i;

}

/* ********************************************* */
/* ***          c�digo principal             *** */
/* ********************************************* */
int main() {
	int vet[20] = {23,45,12,43,19,56,18,42,89,67,7,3,15,34,17,54,5,33,14,25};
	int i, valor, tam = 20;
    int indiceRetornado;

    printf("\nDigite um valor para pesquisar: ");
    scanf("%d", &valor);  

    indiceRetornado = pesquisaSequencial(vet, tam, valor); 
    
	if(indiceRetornado == -1)
       printf("Valor nao encontrado");
    else   
       printf("Valor encontrado na posicao %d", indiceRetornado+1);

    return 0;

}
