#include <stdio.h>

char firstCapital(char str[], int i)
{
    if (str[i] == '\0')
        return '\0';

    if (str[i] >= 'A' && str[i] <= 'Z')
        return str[i];

    return firstCapital(str, i + 1);
}

int main()
{
    char str[100], result;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    result = firstCapital(str, 0);

    if (result == '\0')
        printf("No capital letter found");
    else
        printf("First capital letter = %c", result);

    return 0;
}
