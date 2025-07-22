#include <stdio.h>
#include <string.h>
 
#define QDEESTADOS 27
#define TAMHASH 97

typedef struct{
    char estado[23];
    int  ocupado;   // zero posição da tabela não está ocupada
}ods;               // valor um, representa posição ocupada

int main(){
	int colisao = 0;
    int carac, i, tam, hashCode;
	
	char estado[20];
	ods hashTable[TAMHASH];

    // iniciar todas as posições com zero (não ocupada)
    for(i=0; i<TAMHASH; i++)
        hashTable[i].ocupado = 0;
    
    // loop para processamento de cada linha do arquivo
    for(i=0; i < QDEESTADOS; i++){  // aqui também oderia sr uma leitura até final de arquivo
        gets(estado);
        tam = strlen(estado);

        // calcula o hashCode  
        hashCode = 0;
        for(carac = 0; carac < tam; carac++)
            hashCode += estado[carac];
        
        hashCode = hashCode % TAMHASH;

		// verifica se a posição na tabela está ocupada ou não
		// se estiver, soma 1 em colisao
	    if(hashTable[hashCode].ocupado == 0){
	    	strcpy(hashTable[hashCode].estado, estado);
	    	hashTable[hashCode].ocupado = 1;
		}
		else
			colisao++;
    } // fecha o comando for
    printf("Quantidade de colisoes: %d", colisao);
    return 0;
}
