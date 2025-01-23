#include <stdio.h>
int front = -1;
int rear = -1;
int q[50];
int size = 5;
void enqueue(int item)
{
    if (rear == (size - 1))
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = rear + 1;
        q[rear] = item;
        printf("Inserted item: %d\n", q[rear]);

        if (rear == 0)
        {
            front = 0;
        }
    }
}
void dequeue()
{
    int item;
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = q[front];
        printf("Deleted item: %d\n", item);
        front = front + 1;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", q[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    char ch;
    printf("Menu:\n");
    printf("1 - Insert elements into the queue\n");
    printf("2 - Delete elements from the queue\n");
    printf("3 - Display the elements of queue\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            int item;
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        default:
            printf("Invalid choice\n");
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');
    return 0;
}