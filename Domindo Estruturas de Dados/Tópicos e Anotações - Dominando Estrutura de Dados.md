## Anotações
<p><strong>Referência:</strong> Tenenbaum, Aaron M. <strong>Estruturas de dados usando C </strong>/ Aaron M. Tenenbaum,Yedidyah Langsam, Moshe J. Augenstein ; tradução Teresa Cristina Félix de Souza ; revisão técnica e adaptação dos programas Roberto Carlos Mayer. — São Paulo : MAKRON Books, 1995.</p>

<p>Link de vídeo aula: <a href = "https://www.youtube.com/playlist?list=PL3ZslI15yo2r-gHJtjORRMRKMSNRpf7u5">Curso: Dominando Estruturas de Dados 1</a></p>

<p>Repositório GitHub: <a href = "https://github.com/xavecoding/dominando-estruturas-de-dados-1?tab=readme-ov-file"> Dominando estrutura de dados I</a></p>

## Tópicos
- [Introducão a Estruturas de Dados](#introdução-a-estruturas-de-dados)
- [1 - Variáveis e a Memória RAM](#1---Variáveis-e-a-Memória-RAM)
- [2 - Introdução a Ponteiros](#2---Introdução-a-Ponteiros)
- [3 - Aprofundando em Ponteiros](#3---Aprofundando-em-Ponteiros)
- [7 - Ponteiro de ponteiro](#3---potneiro-de-ponteiro)
- [9 - Passagem de valor](#9---Passagem-de-valor)
- [11 Funções - Passagem por Referência](#11-Funções---Passagem-por-Referência)
- [13 - Vetores Estáticos](#13---Vetores-Estáticos)
- [14 - Vetores e Aritmética de Ponteiros](#14---Vetores-e-Aritmética-de-Ponteiros)
- [15 - Tipos de Alocação de Memória](#15---Tipos-de-Alocação-de-Memória)
- [17 - Vetores - Exemplos Práticos](#17---Vetores---Exemplos-Práticos)
- [20 - Matrizes Estáticas](#20---Matrizes-Estáticas)
- [21 - Matrizes Dinámicas](#21---Matrizes-Dinámicas)
- [22 - Matrizes 3D](#22---Matrizes-3D)
- [25 - Row e Column Major Order](#25---Row-e-Column-Major-Order)
- [27 - Structs - Definição e Exemplos](#27---Structs---Definição-e-Exemplos)
- [28 - Alocação Estática e Dinâmica de Structs](#28---Alocação-Estática-e-Dinâmica-de-Structs)
- [29 - Codificando um CRUD de Structs](#29---Codificando-um-CRUD-de-Structs)


## Introdução a Estruturas de Dados
<p>Capítulo 1</p>

## 1 - Variáveis e a Memória RAM
<p></p>

## 2 - Introdução a Ponteiros
<p>O que é um ponteiro? Ponteiro é um tipo de dados que guarda endereços de memória para um determinado tipo</p>

## 3 - Aprofundando em Ponteiros
<p>Quando temos a sintaxe <code>*p</code> de uma variável, isso indica que ela é um ponteiro, ou seja, armazena a informação de endereço de memoria de uma variável. Se declaramos que ela é um inteiro elá se tornará um int point</p>

```c
    int a = 10;
    int *p1 = NULL; // Ponteiro nulo
    int *p2;

    p1 = &a; // p1 agora aponta para o endereço de a
    p2 = p1; // p2 agora aponta para o mesmo endereço que p1
    *p2 = 20; // Modifica o valor de a através de p2
```

As linhas 4, 5 e 6 indicam que o p1 aponto para o endereço de memória de a, podemos fazer isso pois p1 um é um int point, e como estamos pegando o endereço de **a** que é um inteiro, logo **a** também é um int point. Sendo assim, podemos atribuir o valor de p1 como sendo o endereço de **a**. Em seguida, podemos fazer com que p2 armazene o valor de p1 que também é o mesmo endereço de **a**, com isso, podemos fazer com que o conteúdo de p2 altere o valor armazenado em **a**.<br>
Além disso, não poderiamos atribuir p1 = &p2 (p1 ao endereço de p2), pois p2 é um ponteiro, logo seu tipo seria um inteiro de um endereço de um endereço, ou seja um ponteiro duplo.

## 7 - Ponteiro de ponteiro
O ponteiro de ponteiro é um tipo de variável que armazena o endereço de um ponteiro. Podemos observar no código a seguir

```c
    int a = 10;
    int *p1 = &a;
    int* *p2 = &p1;

    **p2 = 99;
```

Na última linha podemos acessar o conteúdo do ponteiro do ponteiro p2, que por sua vez contém o endereço de p1, como p2 é um ponteiro de ponteiro, perguntamos novamete qual o conteudo do endereço encontrado e aí encontramos o valor de a que é 10. A partir disso, podemos alterar o valor armazenado na variável **a**.

## 9 - Passagem de valor

Em linguagem de programação C podemos ter funções com parâmetros e sem parâmetros. Além disso, em C a função retorna apenas um valor do mesmo tipo que a função foi declarada, como obervado abaixo
```c
int soma (int x, int y){
    int z = x + y
    return z
}
```
Funções que não tem parâmetros são delaradas como `void`, exemplo:
```c
void hello(){
    printf("Hello")
}
```

## 11 Funções - Passagem por Referência
Funções com passagem de referência tem por objetivo criar um parâmetro que possa alterar o valor do conteúdo de uma variável fora da função a partir do seu endereço de memória. Lembrando que as variáveis precisam ser do memso tipo. Exemplo:
```c
void soma(int x, int y, int *z) {
        *z = x + y;
    }

int main(){
    int a = 10;
    int b = 20;
    int c = 50;

    printf("Valor de C antes da função: %d \n", c);
    soma(a, b, &c);
    printf("Valor de C depois da função %d \n", c);

}
```

## 13 - Vetores Estáticos
Vetores é uma lista de elementos, em c podemos declarar um vetor dessa forma `int v[10]`, isso indica que estamos reservando um vetor com espaço de 10 elemetos na memória. Para isso podemos fazer o exemplo abaixo e perceber quando o laço for percorre a estrutura da vetor.
```c
int main(){
    int v[5]= {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; i++){
        printf("&v [%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }
    return 0;
}
```
Para utilizar o `scanf()` é precisar seguir seguinte sintaxe scanf("%tipo de elemento", &endereço do elemento). Exemplo:

```c
int i;
int v[5];

for (i = 0; i < 5; i++){
    scanf("%d", %v[i]);
}
```

## 14 - Vetores e Aritmética de Ponteiros
Quando declaramos um vetor de algum tipo é alocado um bloc continuo na memória do computador. Para acessar o conteúdo do vetor, é criado um endereço base que corresponde ao primeiro elemento do vetor. Pode ser acessado o endereço por `v = $v = &v[0]`. A patir disso o sistema faz um trabalho de multiplicação para acessar os demais vetores, ou seja, v[1] = (v + 1) que significar endereço de v + tamanho do tipo da variável * 1 (v + sizeof() * 1)

## 15 - Tipos de Alocação de Memória
A memória RAM é dividade em STACK (pilha - pouca quantidade de memória) e HEAP (grande quantidade de memória). STACK serve para armazenar variáveis estáticas somem depois do programa ou função ser executada. HEAP é um espaço dinâmica de memória que pode ser alterado conforme o programa é executado, sua liberação é feita manualmente pelo programador usando malloc(), calloc(), realloc() e é utilzado free() para liberar o espaço de memória.<br>
Exemplo de esqueleto para alocar memórica heap (dinâmica):
```c
// tipo* v = (tipo*) malloc(n * sizeof(tipo));
// Isto é, aloque na variável v de tipo tall, uma quantidade n de elementos vezes o tamanho do elemento.
float* v = (float*) malloc(n * sizeof(float)); 
```
O interessante é que v é um ponteiro do tipo float, que é alocado na stack, porém aponto todas as informações na HEAP.

## 17 - Vetores - Exemplos Práticos
Esse tópico é abordado uma prática de programação que compara a alocação de memória estática com a dinâmica. Segue instruções:<br>
Programa com vetores estáticos:
- Crie uma função que recebe o ponteiro de um vetor e seu tamanho e imprima os elementos do vetor
- Crie uma função que recebe o ponteiro de um vetor via colchetes [] e seu tamanho e imprima os elementos do vetor
- Imprima os endereços de memória e valores do vetor na main e dentro de cada função;<br>

Programa com vetores dinâmicos:
- Crie uma função que recebe o ponteiro de um vetor e seu tamanho e imprima os elementos do vetor
- Crie uma função que recebe o ponteiro de um vetor via colchetes [] e seu tamanho e imprima os elementos do vetor
- Imprima os endereços de memória e valores do vetor na main e dentro de cada função;<br>

Para executar os programas são criadas duas funções.
```c
void soma_vetor_com_escalar(int v[], int n, int escalar){
    for(int i = 0; i < n; i++){
        v[i] += escalar;
    }
}
```
A função `soma_vetor_com_escalar` cria um vetor por meio meio da sintaxe `v[]`.

```c
void print_vetor(const int *v, int n){
    for(int i = 0; i < n; i++){
        printf("Endereço de &v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
        // v[i]++; // v[i] + 1 == *(v + i) + 1 // Caso não tenha o const se executarmos essa linha será alterado o valor do vetor
    }
    puts("");
}
```

A segunda função recebe como parâmetro um ponteiro `*v`. <br>
Perceba que após a executação do programa completo, o ponteiro da alocação estárica mantém a mesma ordem de sua base. Todavia, a da alocação dinâmica é alterada. Isso ocorre por conta da função calloc criar um pseudo ponteiro `vh`, que aponto para as informações de um vetor amarzenado no memória heap.<br>
**Importante**
Além, é muito importante que após utilizar a memória heap o programador libere seu uso, para isso é necessário utilizar o exemplo:
```c
// desalocando o vetor dinâmico
free(vh);
vh = NULL;
```
Porém, isso pode se tornar moroso e também corre o risco do programdor esquecer as variáveis e não liberar o uso, para tal é comum criar um função para fazer o deslocamento do vetor dinâmica, ou seja, liberar seu espaço da seguinte maneira.
```c
void desaloca_vetor(int **v) {
    int *aux = *v;
    free(aux);
    *v = NULL;
}
```
Veja que nesse exemplo **v** é um ponteiro de ponteiro, pois ele precisa indicar o conteúdo do conteúdo do ponteiro que ele vai receber para poder limpar a memória.

## 20 - Matrizes Estáticas
Matriz em C é um tipo de estrutura de dados que armazena uma coleção de elementos que pode seu acessado por meio meio de indíces. Para criar uma matriz 2X3, como mostra a figura a seguir:<br>

| Coluna 1 | Coluna 2 | Coluna 3 |
|----------|----------|----------|
| Linha 1  | Dado 1   | Dado 2   |
| Linha 2  | Dado 3   | Dado 4   |

Podemos usar da seguinte notação: 
```c
    int m[2][3] = {
        {1, 2, 3}, 
        {4, 5, 6}};
```
A partir disso, podemos acessar seus dados da seguinte forma:
```c
#include <stdio.h>

int n_rows = 2;
int n_cols = 3;

int main(){
    
// Criação de matriz 2X3
    int m[2][3] = {
        {1, 2, 3}, 
        {4, 5, 6}};

    printf("&m = %p, m = %p\n\n", &m, m);

    for (int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols; j++){
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n",
                 i, j, &m[i][j], i, j, m[i][j]);
        }
        puts("");
    }
    return 0;
}
```
Veja que o endereço base da matriz é o mesmo endereço do primeiro elemento do matriz, isso se deve ao fato que ela está armazenado na memória stack.

## 21 - Matrizes Dinâmicas
Para alocar matrizes dinâmicas a notação é diferente. Deve-se utilizar calloc ou malloc da seguinte forma:
```c
    int **m = (int **) calloc(nrows, sizeof(int*));

    // para cada linha da matriz
    for (int i = 0; i < nrows; i++) {
        m[i] = (int*) calloc(ncols, sizeof(int));
    }
```

Veja que neste caso, é criado duas linhas pela ponteiro de ponteiro **m**, que irá armazenar o endereço de memorias dos primeiros elementos das linhas da matriz. Essa linhas serão armazenadas na heap, porém não há garantia que as linhas sejam sequências na memória.<br>
Após criada a matriz, seu acesso pode ser feito normalmento por `m[i][j]`<br>
Lembre-se sempre de liberar os elementos alocados com `free()`

## 22 - Matrizes 3D
Uma matriz 3D pode ser visualizada como um array de matrizes 2D. Se você tem dimensões [p][l][c] (profundidade x linhas x colunas), você terá 'p' matrizes 2D, cada uma com 'l' linhas e 'c' colunas. As matrizes 3D são muito utilizadas para processamento de imagem. Para criar uma matriz 3D pode ser usado o exemplo abaixo: <br>

```c
 /********* ALOCAÇÃO DINÂMICA DE MATRIZES *********/
    int ***m = (int***) calloc(n_slices, sizeof(int**));

    // para cada fatia
    for (int k = 0; k < n_slices; k++) {
        m[k] = (int**) calloc(n_rows, sizeof(int*));

        // para cada linha
        for (int i = 0; i < n_rows; i++) {
            m[k][i] = (int*) calloc(n_cols, sizeof(int));
        }
    }
    /*************************************************/
```

Note que nesta alocação dinâmica temos inicialmente um ponteiro triplo será responsável por criar as fatias (slices) da matriz tridimensional. Além disso, os laços tem uma lógica de deicaimento dos ponteiros. <br>
Vale lembrar que para desalocar a matriz 3D, faz se necessário acessar o conteúdo de cada elemento de dentro para fora e desalocar a memória heap. Isso pode ser feito como o exemplo abaixo: 

```c
    /********* DESALOCAÇÃO DE MATRIZES DINÂMICA *********/
    // para cada fatia
    for (int k = 0; k < n_slices; k++) {
        // para cada linha
        for (int i = 0; i < n_rows; i++) {
            free(m[k][i]);
        }

        free(m[k]);
    }
    free(m);
    m = NULL;
    /*************************************************/
```

## 25 - Row e Column Major Order
Row Major Order - Como C armazena matrizes:
Em C, as matrizes são armazenadas em memória seguindo o padrão "Row Major Order", que significa que os elementos são dispostos linha por linha de forma contínua. Por exemplo, uma matriz 3x3 declarada como int matriz[3][3] fica organizada na memória. <br>

**Como funciona o cache da memória:**<br>
O processador não acessa a RAM byte por byte quando precisa de dados. Em vez disso, ele carrega blocos inteiros de memória (chamados "cache lines") que geralmente têm 64 ou 128 bytes. Quando você acessa um elemento da matriz, o processador automaticamente carrega para o cache não apenas aquele elemento, mas também os elementos adjacentes na memória.<br>
**Por que percorrer linha-coluna é mais eficiente:**<br>
Quando você percorre a matriz usando for(i) for(j) (linha primeiro, coluna depois), você está acessando elementos sequencialmente na memória: matriz[0][0], depois matriz[0][1], depois matriz[0][2], etc. Como esses elementos estão fisicamente próximos (na mesma cache line), o processador já tem os próximos elementos disponíveis no cache quando você precisar deles. Isso resulta em "cache hits" - o processador encontra o dado que precisa rapidamente no cache, sem ter que buscar na RAM.

## 27 - Structs - Definição e Exemplos
Uma **struct** em linguagem C é uma estrutura de dados que permite agrupar vários dados sobre o mesmo nome.<br>
Sintaxe básica de uma struct
```c
struct Aluno {
    char nome[50];
    int matricula;
    float nota;
};
```

Para declarar (chamar) uma struct usamos:
```c
struct Aluno aluno1;

strcpy(aluno1.nome, "Maria"); // Usa-se strcpy para copiar uma string em C
aluno1.matricula = 12345;
aluno1.nota = 9.5;
```
Podemosa usar uma estrura mais alegante da struct:
```c
typedef struct {
    char nome[50];
    int matricula;
    float nota;
} Aluno;

Aluno aluno2
```

## 28 - Alocação Estática e Dinâmica de Structs
A alocação estática de uma struct em C pode ser feita da seguinte forma:
```c
struct Aluno {
    char nome[50];
    int matricula;
    float nota;
};

int main() {
    struct Aluno aluno1;  // alocação estática
}
```
Para alocarmos dinamicamente, necessitamos utilizar o malloc ou calloc
```c
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int matricula;
    float nota;
};

int main() {
    struct Aluno *aluno2;

    aluno2 = (struct Aluno *) malloc(sizeof(struct Aluno));

    if (aluno2 != NULL) {
        strcpy(aluno2->nome, "João");
        aluno2->matricula = 54321;
        aluno2->nota = 8.0;

        free(aluno2); // libera a memória alocada
    }
}

```

Outro ponto importante é como acessar os atributos de forma estática e dinâmica, pois eles são diferente.<br>
| Situação        | Acesso ao membro da struct |
| --------------- | -------------------------- |
| Struct estática | `aluno1.nota`              |
| Struct dinâmica | `aluno2->nota`             |


## 29 - Codificando um CRUD de Structs

✅ Objetivo da aula
Demonstrar como aplicar `structs` em um sistema simples de **CRUD** (Create, Read, Update, Delete), consolidando os conceitos de estruturas, arrays, manipulação de dados e uso de funções em C.

---

📦 O que é um CRUD?

CRUD é um acrônimo comum no desenvolvimento de sistemas e bancos de dados, que representa as **quatro operações básicas**:

| Letra | Operação | Significado            |
|-------|----------|------------------------|
| C     | Create   | Criar um novo registro |
| R     | Read     | Ler/exibir registros   |
| U     | Update   | Atualizar registros    |
| D     | Delete   | Deletar registros      |

---

## 🧠 Estrutura usada: `struct Aluno`

```c
struct Aluno {
    int matricula;
    char nome[50];
    float nota;
};

#define MAX 100
struct Aluno alunos[MAX];
int totalAlunos = 0;
```

Exercício<br>
- Considere que o Aluno possui um livro favorito, que, por simplificação, possui um título, número de páginas e preço.
- - Codifique a struct de Livro e adapte a struct de Aluno;<br>

- Crie as funções de Criação (C), Delete (D) e de Impressão para a Struct Aluno e Livro<br>
- Na função de Delete, garanta que o ponteiro é atribuído como NULL depois da desalocação