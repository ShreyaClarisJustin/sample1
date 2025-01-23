#include<stdio.h>
#include<string.h>
int s[30], size = 30, top = -1;
void push(char c)
{
if(top < size - 1)
{
s[++top] = c;
}
else
{
printf("Stack is full\n");
}
}
char pop()
{
if(top >= 0)
{
return s[top--];
}
else
{
printf("Stack is empty\n");
return '\0';
}
}
int isPalindrome(char str[])
{
int n = strlen(str);
for(int i = 0; i < n; i++)
{
push(str[i]);
}
for(int i = 0; i < n; i++)
{
if(str[i] != pop())
{
return 0;
}
}
return 1;
}
int main()
{
char str[30];
printf("Enter a string: ");
scanf("%s", str);
if(isPalindrome(str) == 1)
{
printf("%s is palindrome\n", str);
}
else

{
printf("%s is not a palindrome\n", str);
}
return 0;
}