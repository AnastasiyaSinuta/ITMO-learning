#include <stdio.h>
#include <stdlib.h>

void vvod(double***, int, int);

int main() 
{
    double** a;
    int n = 3, m = 3;
    a = (double**)calloc(n, sizeof(double*));
    for (int i = 0; i < m; i++) 
    {
        a[i] = (double*)calloc(m, sizeof(double*));
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            a[i][j] = i * i + j * j;
            printf("%g ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) 
        free(a[i]);
    free(a);
    double** b;
    vvod(&b, 3, 3);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            b[i][j] = i * i + j * j;
            printf("%g ", b[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) 
        free(b[i]);
    free(b);
    return 0;
}

void vvod(double*** a, int index1, int index2) 
{
    *a = (double**)calloc(index1, sizeof(double*));
    for (int i = 0; i < index1; i++)
        (*a)[i] = (double*)calloc(index2, sizeof(double));
}
