#include <stdio.h>
int front = -1, rear = -1, dq[50], size = 5;
void rear_enqueue()
{
    if (rear == (size - 1))
    {
        printf("Double ended queue is full\n");
    }
    else
    {
        int item;
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        rear = rear + 1;
        dq[rear] = item;
        printf("Inserted item: %d\n", dq[rear]);
        if (rear == 0)
        {
            front = 0;
        }
    }
}
void front_enqueue()
{
    if (front == 0)
    {
        printf("Cannot insert item at front\n");
    }
    else
    {
        if (front != -1)
        {
            int item;
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            front = front - 1;
            dq[front] = item;
        }
        else if (front == -1)
        {
            int item;
            front = front + 1;
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            dq[front] = item;
            rear = 0;
        }
    }
}
void rear_dequeue()
{
    int item;
    if (rear == -1)
    {
        printf("Double ended queue is empty\n");
    }
    else
    {
        item = dq[rear];
        rear--;
        if (rear < front)
        {
            front = -1;
            rear = -1;
        }
        printf("Deleted item: %d\n", item);
    }
}
void front_dequeue()
{
    int item;
    if (front == -1)
    {
        printf("Double ended queue is empty\n");
    }
    else
    {
        item = dq[front];
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        printf("Deleted item: %d\n", item);
    }
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Double ended queue is empty\n");
    }
    else
    {
        printf("Double ended queue:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", dq[i]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    char ch;
    do
    {
        printf("Menu:\n");
 printf("1-Rear enqueue\n2-Front enqueue\n3-Rear dequeue\n4-Front dequeue\n5-Display\n");
 printf("Enter your choice: ");
 scanf("%d", &n);
 switch (n)
 {
        case 1:
        {
            rear_enqueue();
            break;
        }
        case 2:
        {
            front_enqueue();
            break;
        }
        case 3:
        {
            rear_dequeue();
            break;
        }
        case 4:
        {
            front_dequeue();
            break;
        }
        case 5:
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