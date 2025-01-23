#include <stdio.h>
int main()
{
    int a[10], n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int item;
    printf("Enter the item to be searched: ");
    scanf("%d", &item);
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == item)
        {
            printf("Item found at position %d\n", mid + 1);
            break;
        }
        else if (a[mid] < item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (low > high)
    {
        printf("Item not present\n");
    }
    return 0;
}