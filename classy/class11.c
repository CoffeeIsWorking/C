#include<stdio.h>

int main()
{
    int num;
    enum{
        Red=
10, Yellow=11, Green=20};
    printf("Please enter a number among 10, 11, 20: ");
    scanf("%d", &num);
    return 0;
}