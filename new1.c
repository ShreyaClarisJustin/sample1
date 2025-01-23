#include <stdio.h>
int main()
{
    int a, b, res;
    printf("Enter two numbers a and b:");
    scanf("%d%d", &a, &b);
    res = a + b;
    printf("The sum is:%d", res);
    return 0;
}