#include <stdio.h>
 
#define TAM_HASH 97
#define QDEALUNOS 75

int hashFunction(int key){
	int hashCode;
	
	hashCode = key % TAM_HASH;
	
	return hashCode;
}

int main(){
	int RA, i, hashCode;

	int hashTable[TAM_HASH];

    // iniciar todas as posi��es da tabela com zero (n�o ocupada)
    for(i=0; i<TAM_HASH; i++)
        hashTable[i] = 0;
    
    // loop para processamento de cada linha do arquivo
    for(i=0; i < QDEALUNOS; i++){  // aqui tamb�m poderia ser uma leitura at� final de arquivo
        scanf("%d", &RA); // RA do aluno � a chave do resgistro de dados
        
        hashCode = hashFunction(RA);

		// testa se n�o houve colis�o
		if(hashTable[hashCode] == 0){
	    	hashTable[hashCode] = RA;
		}
    }

	// exibe oas RAs armazenados e as respectivas posi��es na hash table		
    for(i=0; i<TAM_HASH; i++)
    	if (hashTable[i] > 0)
    		printf("RA: %d - Hash Code: %d\n", hashTable[i], i);

    return 0;
}
