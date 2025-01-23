#include<stdio.h>
int main()
{
 int m, n, i, a1[10], a2[10], a3[10];
 printf("Enter the no.of elements of array1: ");
 scanf("%d", &m);
 printf("Enter the no.of elements of array2: ");
 scanf("%d", &n);
 printf("Enter the elements of array1 in ascending order:\n");
 for(i = 0; i < m; i++)
 {
 scanf("%d", &a1[i]);
 }
 printf("Enter the elements of array2 in ascending order:\n");
 for(i = 0; i < n; i++)
 {
 scanf("%d", &a2[i]);
 }
 i = 0;
 int j = 0, k = 0;
 while(i < m && j < n)
 {
 if(a1[i] < a2[j])
 {
 a3[k] = a1[i];
 i++;
 k++;
 }
 else
 {
 a3[k] = a2[j];
 j++;
 k++;
 }
 }
 if(i >= m)
 {
 while(j < n)
 {
 a3[k] = a2[j];
 j++;
 k++;
 }
 }
 else
 {
 while(i < m)
 {
 a3[k] = a1[i];
 i++;
 k++;
 }
 }
 printf("The sorted array:\n");
 for(i = 0; i < k; i++)
 {
 printf("%d\t", a3[i]);
 }
 return 0;
}