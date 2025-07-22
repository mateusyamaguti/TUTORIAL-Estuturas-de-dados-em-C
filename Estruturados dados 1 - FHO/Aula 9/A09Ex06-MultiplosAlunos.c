#include <stdio.h>
#include <stdlib.h> 

typedef struct{
    int   ra;
    char  nome[20];
    int   idade;
    float media;
}Aluno;

void imprimeTodosAlunos(Aluno *a, int n){
	int i;
	
    for (i = 0; i < n; i++){
        printf("RA: %d, endereco: %p, bytes: %d\n", a[i].ra, &a[i].ra, sizeof(a[i].ra));
        printf("Nome: %s, endereco: %p, bytes: %d\n", a[i].nome, &a[i].nome, sizeof(a[i].nome));
        printf("Idade: %d, endereco: %p, bytes: %d\n", a[i].idade, &a[i].idade, sizeof(a[i].idade));
        printf("Media: %.1f, endereco: %p, bytes: %d\n", a[i].media, &a[i].media, sizeof(a[i].media));
        
        printf("\n");
    }	
}

int main() {
    int i, qtdAlunos;
    Aluno *a;

    printf("Informe quantos alunos deseja digitar: ");
    scanf("%d", &qtdAlunos);
    
    a = (Aluno *) malloc(qtdAlunos * sizeof(Aluno));
        
    for (i = 0; i < qtdAlunos; i++){
        printf("RA: ");
        scanf("%d", &a[i].ra);
        
        fflush(stdin);
		printf("Nome: ");
        gets(a[i].nome);
        
        printf("Idade: ");
        scanf("%d", &a[i].idade);
        
        printf("Media: ");
        scanf("%f", &a[i].media);
        
        printf("\n");
    }

    imprimeTodosAlunos(a, qtdAlunos);
    
	printf("\nDados do ponteiro\n");
	printf("Endereco de memoria: %p\n", &a);
	printf("Tamanho em bytes: %d\n", sizeof(a));
	
    return 0;
}
