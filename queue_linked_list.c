#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
} Node;
Node *front = NULL;
Node *rear = NULL;
void Enqueue(Node *head, int item);
void Dequeue(Node *head);
void Display(Node *head);
void Enqueue(Node *head, int item)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    newnode->link = NULL;
    if (rear == NULL)
    {
        rear = front = newnode;
        head->link = rear;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
}
void Dequeue(Node *head)
{
    if (front == NULL)
    {
        printf("Queue empty\n");
    }
    else
    {
        Node *temp = front;
        printf("Deleted element=%d\n", temp->data);
        front = front->link;
        free(temp);
        if (front == NULL)
        {
            rear = NULL;
        }
    }
}
void Display(Node *head)
{
    if (front == NULL)
    {
        printf("Queue empty\n");
    }
    else
    {
        Node *ptr = front;
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}
int main()
{
 printf("MENU\n1.INSERT ELEMENT\n2.DELETE ELEMENT\n3.DISPLAY QUEUE\n4.EXIT\n");
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
            Enqueue(head, item);
            break;
        case 2:
            Dequeue(head);
            break;
        case 3:
            Display(head);
            break;
        case 4:
            ch = 'n';
            break;
        }
 }
}