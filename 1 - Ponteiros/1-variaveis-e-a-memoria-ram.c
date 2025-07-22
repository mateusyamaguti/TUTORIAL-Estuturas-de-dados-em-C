#include <stdio.h>

int main() {
    int a = 10;
    int b, c ;

    // Para entender o conceito de variáveis e memória RAM, vamos imprimir o endereço de memória da variável 'a' e seu valor.
    // Para isso, utilizada-se o operador '&' para obter o endereço de memória da variável.
    printf("Endereço de &a = %p, valor de a = %d\n", &a, a);
    printf("Endereço de &b = %p, valor de b = %d\n", &b, b);
    printf("Endereço de &c = %p, valor de c = %d\n", &c, c);

    b = 20;
    c = a + b;

    printf("Endereço de &a = %p, valor de a = %d\n", &a, a);
    printf("Endereço de &b = %p, valor de b = %d\n", &b, b);
    printf("Endereço de &c = %p, valor de c = %d\n", &c, c);

    // Return 0 indica que o programa foi executado com sucesso.
    return 0;
}