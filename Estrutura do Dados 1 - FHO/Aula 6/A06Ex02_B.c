#include <stdio.h>
#include <string.h>

#define QDEESTADOS 27
#define TAMHASH 97
 
typedef struct{
    char estado[25];
    int  ocupado;   // zero posi��o da tabela n�o est� ocupada
}ods;               // valor um, representa posi��o ocupada

int main(){
	int colisao = 0;
    int carac, i, tam, hashCode;
	
	char estado[25];
	ods hashTable[TAMHASH];
    FILE *arqEnt;

    arqEnt = fopen("A06Ex01estados.txt", "r");
    if (arqEnt == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    // iniciar todas as posi��es com zero (n�o ocupada)
    for(i=0; i<TAMHASH; i++){
        hashTable[i].ocupado = 0;
    }
    
    // loop para processamento de cada linha do arquivo
    for(i=0; i < QDEESTADOS; i++){  // aqui tamb�m oderia sr uma leitura at� final de arquivo
        fgets(estado, 25, arqEnt);
        tam = strlen(estado);

        // calcula o hashCode        
        hashCode = 0;
        for(carac = 0; carac < tam; carac++)
            hashCode += estado[carac];
        
        hashCode = hashCode % TAMHASH;

		// verifica se a posi��o na tabela est� ocupada ou n�o
		// se estiver, soma 1 em colisao
	    if(hashTable[hashCode].ocupado == 0){
	    	strcpy(hashTable[hashCode].estado, estado);
	    	hashTable[hashCode].ocupado = 1;
		}
		else
			colisao++;

    }
		
    printf("Quantidade de colisoes: %d",colisao);

    fclose(arqEnt);
    return 0;
}
