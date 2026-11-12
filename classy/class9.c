#include <stdio.h>

void decimalToBinary(int n)
{
    if (n == 0)
        return;

    decimalToBinary(n / 2);

    printf("%d", n % 2);
}

int main()
{
    int n;

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    if (n == 0)
        printf("Binary = 0");
    else
    {
        printf("Binary = ");

        if (n < 0)
        {
            printf("-");
            n = -n;
        }

        decimalToBinary(n);
    }

    return 0;
}