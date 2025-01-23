#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *top = NULL;
struct Node *header = NULL;
struct Node *header1 = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;
void push(int data1);
int pop();
void Enqueue(int data);
int dequeue();
void displayQueue();
void createQueueList();
void createStackList();
void createQueueList()
{
    header = malloc(sizeof(struct Node));
    if (!header)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    header->link = NULL;
    front = rear = NULL;
}
void createStackList()
{
    header1 = malloc(sizeof(struct Node));
    if (!header1)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    header1->link = NULL;
    top = NULL;
}
void Enqueue(int data)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = data;
    temp->link = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}
int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = front;
    int data = temp->data;
    front = front->link;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return data;
}
void push(int data1)
{
    struct Node *temp = malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data = data1;
    temp->link = header1->link;
    header1->link = temp;
    top = header1->link;
}
int pop()
{
    if (header1->link == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node *temp = header1->link;
    int data = temp->data;
    header1->link = temp->link;
    top = header1->link;
    free(temp);
    return data;
}
void displayQueue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *ptr = front;
    printf("Reversed Queue contents: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
int main()
{
    createQueueList();
    createStackList();
    int ch, range = 0, data;
    char c;
    do
    {
        printf("Enter 1 for enqueue\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter data: ");
            scanf("%d", &data);
            Enqueue(data);
            range++;
            break;
        }
        default:
            printf("invalid");
            break;
        }
        printf("Do you want to continue?(y/n)");
        scanf(" %c", &c);
    } while (c == 'y');
    for (int i = 0; i < range; i++)
    {
        int y = dequeue();
        if (y != -1)
        {
            push(y);
        }
    }
    for (int k = 0; k < range; k++)
    {
        int x = pop();
        if (x != -1)
        {
            Enqueue(x);
        }
    }
    displayQueue();
    return 0;
}