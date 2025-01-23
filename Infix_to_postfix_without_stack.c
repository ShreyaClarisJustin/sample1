#include <stdio.h>
#include <string.h>
char s[30];
char infix[30];
char postfix[30];
int top = -1;
int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    }
}
void infix_to_postfix()
{
    char symbol;
    int i, j = 0;
    char next, n;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            s[++top] = symbol;
            break;
        case ')':
            while ((next = s[top--]) != '(')
            {
                postfix[j++] = next;
            }
            break;
        case '*':
        case '+':
        case '-':
        case '/':
        case '^':
            while ((top != -1) && precedence(s[top]) >= precedence(symbol))
            {
                postfix[j++] = s[top--];
            }
            s[++top] = symbol;
            break;
        default:
            postfix[j++] = symbol;
            break;
        }
    }
    while (top != -1)
    {
        n = s[top];
        if (n != '(')
        {
            postfix[j++] = n;
        }
        top--;
    }
    postfix[j] = '\0';
}
void main()
{
    printf("Enter the infix expression:\n");
    gets(infix);
    infix_to_postfix();
    printf("The postfix expression is:");
    puts(postfix);
}