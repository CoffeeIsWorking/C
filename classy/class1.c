#include <stdio.h>

int search(int a[10][10], int r, int c,
           int rows, int cols, int key)
{
    if (r == rows)
        return 0;

    if (a[r][c] == key)
        return 1;

    if (c == cols - 1)
        return search(a, r + 1, 0, rows, cols, key);

    return search(a, r, c + 1, rows, cols, key);
}

int main()
{
    int a[10][10], rows, cols, key;

    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &cols);

    printf("Enter array elements:\n");

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(a, 0, 0, rows, cols, key))
        printf("Element found");
    else
        printf("Element not found");

    return 0;
}