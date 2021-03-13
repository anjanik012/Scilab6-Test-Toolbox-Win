#include <stdio.h>
#include <stdlib.h>
#include "trans.h"

void print(double **mat, int m, int n) {
    int i, j;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
}

/*
Sample input 

3 3
3 4 5
1 9 0
6 8 7

*/

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    double **mat = malloc(m * sizeof(double*));
    int i,j;
    for(i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(double));
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    double **res = trans(mat, m, n);
    print(res, n, m);
    return 0;
}
