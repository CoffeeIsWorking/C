#include <stdio.h>

int lcm(int a, int b, int multiple)
{
    if (multiple % a == 0 && multiple % b == 0)
        return multiple;

    return lcm(a, b, multiple + 1);
}

int main()
{
    int a, b, start;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    if (a == 0 || b == 0)
    {
        printf("LCM = 0");
        return 0;
    }

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    start = (a > b) ? a : b;

    printf("LCM = %d", lcm(a, b, start));

    return 0;
}
