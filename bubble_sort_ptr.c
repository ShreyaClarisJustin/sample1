#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int *a, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                temp = *(a + j + 1);
                *(a + j + 1) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
}
int main()
{
    int i, n;
    printf("Enter the no.of elements: ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    bubble_sort(a, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(a + i));
    }
    free(a);
    return 0;
}