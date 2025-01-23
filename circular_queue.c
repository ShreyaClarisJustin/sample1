#include <stdio.h>
int front = -1, rear = -1, cq[50], size = 5;
void enqueue(int item)
{
    if (front == (rear + 1) % size)
    {
        printf("Circular queue is full\n");
    }
    else
    {
        rear = (rear + 1) % size;
        cq[rear] = item;
        printf("Inserted item: %d\n", cq[rear]);
        if (front == -1)
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
        printf("Circular queue is empty\n");
    }
    else
    {
        item = cq[front];
        printf("Deleted item: %d\n", item);
        front = (front + 1) % size;
        if (front == (rear + 1) % size)
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
        printf("Circular queue is empty\n");
    }
    else
    {
        printf("Circular queue:\n");
        if (front > rear)
        {
            for (int i = front; i < size; i++)
            {
                printf("%d\t", cq[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d\t", cq[i]);
            }
        }
        else if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d\t", cq[i]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int n;
    char ch;
    printf("Menu:\n1-Insert elements into the circular queue\n2-Delete elements from the circular queue\n3-Display the elements of circular queue\n");
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
        printf("Do you want to continue? (y/n):");
        scanf(" %c", &ch);
 }
 while (ch == 'y');
 return 0;
}