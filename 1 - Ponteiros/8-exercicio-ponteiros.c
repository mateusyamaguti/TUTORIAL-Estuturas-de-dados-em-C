#include <stdio.h>
#include <stdlib.h>


int main() {
    int a, b, *p1, *p2;

    a = 4;
    printf("Conteudo de a: %d e endereco de a: %p\n" , a, &a);
    b = 3;
    printf("Conteudo de b: %d e endereco de a: %p\n\n" , b, &b);
    p1 = &a;
    printf("Conteudo de p1: %p e endereco de p1: %p\n", p1, &p1);
    p2 = p1;
    printf("Conteudo de p2: %p e endereco de p2: %p\n\n", p2, &p2);
    *p2 = *p1 + 3;
    printf("Conteudo de p2 apos alterar receber o valor do conteudo de p1 + 3: %d e endereco de p2: %p\n\n", *p2, &p2); 
    b = b * (*p1); 
    (*p2)++;
    p1 = &b;

    printf("%d %d\n", *p1, *p2);
    printf("%d %d\n", a, b);

    return 0;
}