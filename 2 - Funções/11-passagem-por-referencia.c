#include <stdio.h>

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