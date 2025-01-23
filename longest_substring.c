#include<stdio.h>
#include<string.h>
void main()
{
 int i, j, k = 0, start = 0;
 char string[50], substring[50], longest[50];
 printf("Enter the string: ");
 scanf("%s", string);
 int n = strlen(string);
 longest[0] = '\0';
 for(start = 0; start < n; start++)
 {
 substring[0] = '\0';
 k = 0;
 for(i = start; start < strlen(string); i++)
 {
 int flag = 0;
 for(j = 0; j < k; j++)
 {
 if(string[i] == substring[j])
 {
 flag = 1;
 break;
 }
 }
 if(flag == 1)
 {
 break;
 }
 substring[k++] = string[i];
 substring[k] = '\0';
 }
 if(strlen(substring) > strlen(longest))
 {
 strcpy(longest, substring);
 }
 }
 printf("The longest substring: %s\nLength of the longest substring: %ld\n", longest,
strlen(longest));
}