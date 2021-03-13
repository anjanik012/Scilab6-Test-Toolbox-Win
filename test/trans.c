#include<stdlib.h>

double **trans(double **mat, int m, int n) {
    int i, j;
    double **x = malloc(n*sizeof(double*));
    for(i = 0; i < n; i++) {
        x[i] = malloc(m*sizeof(double));
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            x[j][i] = mat[i][j];
        }
    }

    return x;
}