#include <stdio.h>

union Data
{
    int i;
    float f;
    char c;
};

int main()
{
    union Data d;

    d.i = 10;
    printf("Integer Value = %d\n", d.i);

    d.f = 12.5;
    printf("Float Value = %.2f\n", d.f);

    d.c = 'A';
    printf("Character Value = %c\n", d.c);

    return 0;
}
