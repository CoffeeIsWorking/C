#include <stdio.h>

#define MAX 10

int multiply(int a[MAX][MAX], int b[MAX][MAX],
             int i, int j, int k, int n)
{
    if (k == n)
        return 0;

    return a[i][k] * b[k][j] +
           multiply(a, b, i, j, k + 1, n);
}

void calculate(int a[MAX][MAX], int b[MAX][MAX],
               int c[MAX][MAX], int i, int j,
               int rows, int cols, int n)
{
    if (i == rows)
        return;

    if (j == cols)
    {
        calculate(a, b, c, i + 1, 0, rows, cols, n);
        return;
    }

    c[i][j] = multiply(a, b, i, j, 0, n);

    calculate(a, b, c, i, j + 1, rows, cols, n);
}

int main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter dimensions of first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter dimensions of second matrix: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Matrix multiplication not possible");
        return 0;
    }

    printf("Enter first matrix:\n");

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter second matrix:\n");

    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    calculate(a, b, c, 0, 0, r1, c2, c1);

    printf("Resultant matrix:\n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
            printf("%d ", c[i][j]);

        printf("\n");
    }

    return 0;
}