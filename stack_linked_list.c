#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
} Node;
void Push(Node *head, int item);
void Pop(Node *head);
void display(Node *head);
void Push(Node *head, int item)
{
    Node *top = head->link;
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->link = head->link;
    top = newnode;
    head->link = top;
}
void Pop(Node *head)
{
    Node *top = head->link;
    if (top == NULL)
    {
        printf("Stack empty\n");
    }
    else
    {
        Node *ptr = top->link;
        printf("Deleted element=%d\n", top->data);
        head->link = ptr;
        free(top);
        top = ptr;
    }
}
void display(Node *head)
{
    Node *top = head->link;
    if (top == NULL)
    {
        printf("Stack empty\n");
        return;
    }
    else
    {
        while (top != NULL)
        {
            printf("%d\t", top->data);
            top = top->link;
        }
        printf("\n");
    }
}
int main()
{
 printf("MENU\n1.PUSH ELEMENT\n2.POP ELEMENT\n3.DISPLAY STACK\n4.EXIT\n");
 int n,item;
 Node* head=(Node*)malloc(sizeof(Node));
 head->link=NULL;
 char ch='y';
 while(ch=='y')
 {
        printf("Enter choice-");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element to be inserted-");
            scanf("%d", &item);
            Push(head, item);
            break;
        case 2:
            Pop(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            ch = 'n';
            break;
        }
 }
}