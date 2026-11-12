#include <stdio.h>

int biggest(int a[], int n)
{
    if (n == 1)
        return a[0];

    int max = biggest(a, n - 1);

    if (a[n - 1] > max)
        return a[n - 1];

    return max;
}

int main()
{
    int a[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Biggest number = %d", biggest(a, n));

    return 0;
}