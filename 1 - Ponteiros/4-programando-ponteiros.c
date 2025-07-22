#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 10;
    int *p1 = NULL; // Ponteiro nulo
    int *p2;

    printf("Endereço de a: %p, valor de a: %d\n", &a, a);
    printf("Endereço de p1: %p, valor de p1: %p\n", &p1, p1); // p guardo o valor do endereço de a
    printf("Endereço de p2: %p, valor de p2: %p\n\n", &p2, p2);

    p1 = &a; // p1 agora aponta para o endereço de a
    p2 = p1; // p2 agora aponta para o mesmo endereço que p1
    *p2 = 20; // Modifica o valor de a através de p2

    printf("Endereço de a: %p, valor de a: %d\n", &a, a);
    printf("Endereço de p1: %p, valor de p1: %p\n", &p1, p1); // p guardo o valor do endereço de a
    printf("Endereço de p2: %p, valor de p2: %p\n\n", &p2, p2);

    return 0;
}