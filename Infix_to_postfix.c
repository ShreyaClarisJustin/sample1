#include <stdio.h>
#include <string.h>
#include <math.h>
#define size 20
void InfixToPostfix(char[], char[]);
int Evaluate(char[]);
int s[20], top = -1;
void main()
{
    char exp[30], postfix[30];
    printf("Enter an infix expression: ");
    scanf(" %[^\n]", exp);
    InfixToPostfix(exp, postfix);
    printf("The postfix expression is %s\n", postfix);
    int result = Evaluate(postfix);
    printf("The evaluation of the postfix expression is %d\n", result);
}
void push(int item)
{
    if (top == size - 1)
        printf("Stack overflow\n");
    else
    {
        top = top + 1;
        s[top] = item;
    }
}
int pop()
{
    if (top == -1)
        printf("Stack empty\n");
    else
    {
        int item = s[top];
        top = top - 1;
        return item;
    }
}
int icp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '^')
        return 6;
    else if (ch == '(')
        return 7;
    else if (ch == ')')
        return 0;
}
int isp(char ch)
{
    if (ch == '+' || ch == '-')
        return 2;
    else if (ch == '*' || ch == '/')
        return 4;
    else if (ch == '^')
        return 5;
    else if (ch == '(')
        return 0;
}
void InfixToPostfix(char exp[], char postfix[])
{
    int i = 0, j = 0;
    char symb, optr;
    push('(');
    strcat(exp, ")");
    while (exp[i] != '\0')
    {
        symb = exp[i];
        optr = s[top];
        if ((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9'))
        {
            postfix[j] = exp[i];
            j++;
        }
        else if (symb == ')')
        {
            while (optr != '(')
            {
                postfix[j] = pop();
                j++;
                optr = s[top];
            }
            pop();
        }
        else
        {
            while (icp(symb) <= isp(optr))
            {
                postfix[j] = pop();
                j++;
                optr = s[top];
            }
            push(symb);
        }
        i++;
    }
}
int Evaluate(char postfix[])
{
    int i, o1, o2, value ;
    char symb;
    i = 0;
    while (postfix[i] != '\0')
    {
        symb = postfix[i];
        if (symb >= '0' && symb <= '9')
        {
            int num = symb - '0';
            push(num);
        }
        else if ((symb == '+') || (symb == '-') || (symb == '*') || (symb == '/') || (symb == '^'))
        {
            o1 = pop();
            o2 = pop();
            switch (symb)
            {
            case '+':
                value = o2 + o1;
                break;
            case '-':
                value = o2 - o1;
                break;
            case '*':
                value = o2 * o1;
                break;
            case '/':
                value = o2 / o1;
                break;
            case '^':
                value = pow(o2, o1);
                break;
            }
            push(value);
        }
        i++;
    }
    value = pop();
    return value;
}