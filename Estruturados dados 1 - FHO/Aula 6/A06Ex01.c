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

    // iniciar todas as posições da tabela com zero (não ocupada)
    for(i=0; i<TAM_HASH; i++)
        hashTable[i] = 0;
    
    // loop para processamento de cada linha do arquivo
    for(i=0; i < QDEALUNOS; i++){  // aqui também poderia ser uma leitura até final de arquivo
        scanf("%d", &RA); // RA do aluno é a chave do resgistro de dados
        
        hashCode = hashFunction(RA);

		// testa se não houve colisão
		if(hashTable[hashCode] == 0){
	    	hashTable[hashCode] = RA;
		}
    }

	// exibe oas RAs armazenados e as respectivas posições na hash table		
    for(i=0; i<TAM_HASH; i++)
    	if (hashTable[i] > 0)
    		printf("RA: %d - Hash Code: %d\n", hashTable[i], i);

    return 0;
}
