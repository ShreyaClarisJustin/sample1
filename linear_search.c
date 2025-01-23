#include <stdio.h>
int main()
{
    int a[10], n, item, i, flag = 0;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Item found at position %d\n", i + 1);
    }
    else
    {
        printf("Item not found\n");
    }
    return 0;
}