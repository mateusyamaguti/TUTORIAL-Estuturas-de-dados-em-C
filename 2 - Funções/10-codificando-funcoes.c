#include <stdio.h>

int soma(int x, int y) {
    int z = x + y;
    puts("### Dentro da função ###");
    printf("Endereco de x: %p, valor de x: %d\n", &x, x);
    printf("Endereco de y: %p, valor de y: %d\n", &y, y);
    printf("Endereco de z: %p, valor de z: %d\n\n", &z, z);

    return z;
}

int main() {
    int a = 10;
    int b = 20;
    int c;

    puts("### Antes da função ###");
    printf("Endereco de a: %p, valor de a: %d\n", &a, a);
    printf("Endereco de b: %p, valor de b: %d\n", &b, b);
    printf("Endereco de c: %p, valor de c: %d\n\n", &c, c);

    c = soma(a, b);
    puts("### Depois da função ###");
    printf("Endereco de a: %p, valor de a: %d\n", &a, a);
    printf("Endereco de b: %p, valor de b: %d\n", &b, b);
    printf("Endereco de c: %p, valor de c: %d\n\n", &c, c);

    return 0;
}