#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
} Node;
void DeleteSpecific(Node *head, int data_node);
void DeleteEnd(Node *head);
void DeleteBeginning(Node *head);
void InsertSpecific(Node *head, int item, int data_node);
void InsertEnd(Node *head, int item);
void InsertBeginning(Node *head, int item);
void Display(Node *head);
int main()
{
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    head->link = NULL;
    printf("MENU\n1. Display\n2. Insert at beginning\n3. Insert at end\n4. Insert at specified position\n5. Delete from beginning\n6. Delete from end\n7. Delete from a specified position\n8.Exit\n");
    int n;
    char ch='y';
    while(ch=='y')
    {
        printf("Enter choice-");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            Display(head);
            break;
        case 2:
        {
            printf("Enter item to be inserted-");
            int item;
            scanf("%d", &item);
            InsertBeginning(head, item);
            break;
        }
        case 3:
        {
            printf("Enter item to be inserted-");
            int item;
            scanf("%d", &item);
            InsertEnd(head, item);
            break;
        }
        case 4:
        {
            printf("Enter item to be inserted-");
            int item;
            scanf("%d", &item);
            printf("Enter data of node after which has to be inserted-");
            int data_node;
            scanf("%d", &data_node);
            InsertSpecific(head, item, data_node);
            break;
        }
        case 5:
        {
            DeleteBeginning(head);
            break;
        }
        case 6:
        {
            DeleteEnd(head);
            break;
        }
        case 7:
        {
            printf("Enter data of node which has to be deleted-");
            int data_node;
            scanf("%d", &data_node);
            DeleteSpecific(head, data_node);
            break;
        }
        case 8:
        {
            ch = 'n';
            break;
        }
        }
    }
    free(head);
}
void Display(Node *head)
{
    Node *ptr;
    ptr = head->link;
    if (head->link == NULL)
    {
        printf("List is empty");
    }
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
void InsertBeginning(Node *head, int item)
{
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    ptr->data = item;
    ptr->link = head->link;
    head->link = ptr;
}
void InsertEnd(Node *head, int item)
{
    Node *ptr;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = item;
    ptr->link = newnode;
    newnode->link = NULL;
}
void InsertSpecific(Node *head, int item, int data_node)
{
    Node *ptr;
    ptr = head;
    while (ptr != NULL && ptr->data != data_node)
    {
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        printf("Data not found\n");
    }
    else
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = item;
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}
void DeleteBeginning(Node *head)
{
    if (head->link == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *ptr = (Node *)malloc(sizeof(Node));
        ptr = head->link;
        head->link = ptr->link;
        free(ptr);
    }
}
void DeleteEnd(Node *head)
{
    if (head->link == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *ptr = (Node *)malloc(sizeof(Node));
        Node *temp;
        temp = head;
        ptr = head->link;
        while (ptr->link != NULL)
        {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        free(ptr);
    }
}
void DeleteSpecific(Node *head, int data_node)
{
    if (head->link == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        Node *temp;
        Node *ptr = (Node *)malloc(sizeof(Node));
        temp = head;
        ptr = head->link;
        while (ptr != NULL && ptr->data != data_node)
        {
            temp = ptr;
            ptr = ptr->link;
        }
        if (ptr == NULL)
        {
            printf("Data not found\n");
        }
        else
        {
            temp->link = ptr->link;
            free(ptr);
        }
    }
}