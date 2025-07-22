#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    int ra;
    float n1;
	float n2;
	float media;
} Aluno;


/* ********************************************* */
/* ***          pesquisa sequencial          *** */
/* ***           pelo RA do aluno            *** */
/* ********************************************* */
int pesquisaSeq(Aluno *v, int n, int raPesquisado) {

 

}



/* ********************************************* */
/* ***  conta o número de linhas do arquivo  *** */
/* ***           (número de alunos)          *** */
/* ********************************************* */
int getQuantidadeAlunos() {

    FILE *arqAlunos;
    Aluno alu;
    int n = 0;

    if ((arqAlunos = fopen("A05naoOrdenado.txt", "r")) == NULL) {
        printf("Problemas para abrir o arquivo de dados!\n");
        exit(1);
    }

    while (! feof(arqAlunos)) {
        fscanf(arqAlunos, "%d", &alu.ra);
        fscanf(arqAlunos, "%f", &alu.n1);
        fscanf(arqAlunos, "%f", &alu.n2);
        n++;
    }

    fclose(arqAlunos);

    return n;

} 


/* ********************************************* */
/* ***     preenche o vetor de submissoes    *** */
/* ***       a partir do arquivo texto       *** */
/* ********************************************* */
void preencheVetor (Aluno *v, int n) {

    FILE *arqAlunos;
    Aluno alu;
    int i;

    arqAlunos = fopen("A05naoOrdenado.txt", "r");
    if (arqAlunos == NULL){
    	printf("Problemas com o arquivo de entrada de dados");
    	exit(1);    	
	}

    for (i = 0; i < n; i++) {

        fscanf(arqAlunos, "%d", &alu.ra);
        fscanf(arqAlunos, "%f", &alu.n1);
        fscanf(arqAlunos, "%f", &alu.n2);
        alu.media = (alu.n1 + alu.n2) / 2;
        
        v[i] = alu;
    }

    fclose(arqAlunos);

} 

/* ********************************************* */
/* ***   imprime os dados de uma submissao   *** */
/* ***           contida no vetor            *** */
/* ********************************************* */
void imprimeDados (Aluno *v, int ind) {

    if (ind == -1) {
        printf("\nAluno nao foi encontrado!\n");
        return;
    }

    printf("\nDADOS DO ALUNO\n" );

    printf("RA:%d\nN1:%.1f\nN2:%.1f\nMedia:%.1f\n",
                v[ind].ra,
                v[ind].n1,
                v[ind].n2,
                v[ind].media
          );

} 

/* ********************************************* */
/* ***          código principal             *** */
/* ********************************************* */
int main () {

    Aluno *vet;
    int ra;
    int n;
    int indiceRetornado;

    n = getQuantidadeAlunos();                  // descobre a quantidade de alunos
    vet = (Aluno*) malloc (n * sizeof(Aluno));  // aloca o vetor vet
    preencheVetor(vet, n);                      // preenche o vetor a partir do arquivo texto de entrada

    printf("\nDigite o RA do aluno: ");
    scanf("%d", &ra);  // entra com o RA do aluno a ser pesquisada

    indiceRetornado = pesquisaSeq(vet, n, ra);   // pesquisa pelos dados da última submissão da equipe 
    imprimeDados(vet, indiceRetornado); 	  // imprime os dados do aluno

    printf("\n");
    return 0;

}
