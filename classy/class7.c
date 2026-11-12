#include <stdio.h>

void copy(char source[], char destination[], int i)
{
    destination[i] = source[i];

    if (source[i] == '\0')
        return;

    copy(source, destination, i + 1);
}

int main()
{
    char source[100], destination[100];

    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    copy(source, destination, 0);

    printf("Copied string: %s", destination);

    return 0;
}