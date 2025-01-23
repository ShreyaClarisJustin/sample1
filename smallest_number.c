#include<stdio.h>
int main()
{
 int *a, n, i;
 printf("Enter the no.of elements of the list: ");
 scanf("%d", &n);
 printf("Enter the elements of the list:\n");
 for(i = 0; i < n; i++)
 {
 scanf("%d", a + i);
 }
 int smallest = *a;
 for(i = 1; i < n; i++)
 {
 if(*(a + i) < smallest)
 {
 smallest = *(a + i);
 }
 }
 printf("The smallest number is: %d\n", smallest);
 return 0;
}