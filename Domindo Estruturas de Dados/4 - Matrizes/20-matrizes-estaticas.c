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