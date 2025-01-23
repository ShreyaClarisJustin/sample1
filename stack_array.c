#include <stdio.h>
int top = -1, size = 5, s[10], item;
void push()
{
    if (top == size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        top = top + 1;
        s[top] = item;
        printf("%d pushed into stack\n", s[top]);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        item = s[top];
        printf("%d popped from stack\n", item);
        top = top - 1;
    }
}
void peek()
{
    if (top != -1)
    {
        printf("Top most element is %d\n", s[top]);
    }
    else
    {
        printf("Stack is empty\n");
    }
}
void display()
{
    for (int i = top; i > -1; i--)
    {
        printf("%d\t", s[i]);
    }
    printf("\n");
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
}
int main()
{
    int n;
    char ch;
    do
    {
        printf("Menu:\n1-Push\n2-Pop\n3-Peek\n4-Display\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            peek();
            break;
        }
        case 4:
        {
            display();
            break;
        }
        default:
            printf("Invalid choice\n");
        }
        printf("Do you want to continue?(y/n) ");
        scanf(" %c", &ch);
    } while (ch == 'y');
    return 0;
}