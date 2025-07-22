#include<stdio.h> 
#include<stdlib.h> 

typedef struct {
	int   ra;
	char  nome[20];
	int   idade;
	float media;
} Aluno;

int main(){
    Aluno varaluno;    // pense em como seria a solução com uma variável no lugar do ponteiro
	
	Aluno *a;
    a = (Aluno *) malloc(sizeof(Aluno));
	
	printf("RA: ");
	scanf("%d", &a->ra);
	
	fflush(stdin);
	printf("Nome: ");
	gets(a->nome);
	
	printf("Idade: ");
	scanf("%d", &a->idade);

	printf("Media: ");
	scanf("%f", &a->media);
	
    printf("\nDados, enderecos na memoria e quantidade de memoria\n\n");
    
	printf("RA: %d, endereco: %p, bytes: %d\n", 
	a->ra, &a->ra, sizeof(a->ra));	
		
	printf("Nome: %s, endereco: %p, bytes: %d\n", 
	a->nome, &a->nome, sizeof(a->nome));	
	
	printf("Idade: %d, endereco: %p, bytes: %d\n", 
	a->idade, &a->idade, sizeof(a->idade));	
	
	printf("Media: %.1f, endereco: %p, bytes: %d\n", 
	a->media, &a->media, sizeof(a->media));	
	
	printf("\nDados do ponteiro\n");
	printf("Endereco de memoria: %p\n", &a);
	printf("Tamanho em bytes Do ponteiro aponta: %d\n", sizeof(a));
	printf("Tamanho em bytes de quem o ponteiro aponta: %d\n", sizeof(*a));

	return 0;
}
