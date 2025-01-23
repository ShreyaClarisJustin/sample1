#include<stdio.h>
#include<stdlib.h>
int pq[10][10], rear[10], front[10], item, size, max, priority;
void enqueue()
{
if (rear[priority] == size - 1)
{
printf("Queue at priority level is full\n");
}
else
{
rear[priority] = rear[priority] + 1;
printf("Enter the element: ");
scanf("%d", &item);
pq[priority][rear[priority]] = item;
if (rear[priority] == 0)
{
front[priority] = 0;
}
}
}
int dequeue()
{
priority = 0;
while (priority < max)
{
if (front[priority] == -1)
{
priority++;
}
else
{
item = pq[priority][front[priority]];
printf("Deleted item = %d\n", item);
front[priority] = front[priority] + 1;
if (front[priority] > rear[priority])
{
front[priority] = rear[priority] = -1;
}
return item;
}
}
if (priority == max)
{
printf("Queue is empty\n");
}
}
void display()
{
int flag = 0;

priority = 0;
for (int i = 0; i < max; i++)
{
if (front[i] != -1)
{
flag = 1;
}
}
if (flag == 0)
{
printf("Queue is empty\n");
}
else
{
while (priority < max)
{
if (front[priority] == -1)
{
priority++;
}
else
{
int j;
for (j = front[priority]; j <= rear[priority]; j++)
{
printf("%d\t", pq[priority][j]);
}
printf("\n");
priority++;
}
}
}
}
int main()
{
int n;
char ch;
printf("Enter the no. of priority: ");
scanf("%d", &max);
printf("Enter the size of each priority: ");
scanf("%d", &size);
for (int i = 0; i < max; i++)
{
front[i] = -1;
rear[i] = -1;
}
printf("Menu:\n");
printf("1-Insert elements into the priority queue\n");
printf("2-Delete elements from the priority queue\n");
printf("3-Display the elements of priority queue\n");
do
{

printf("Enter your choice: ");
scanf("%d", &n);
switch (n)
{
case 1:
{
printf("Enter the priority starting from 0: ");
scanf("%d", &priority);
enqueue();
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
{
printf("Invalid choice\n");
break;
}
}
printf("Do you want to continue? (y/n): ");
scanf(" %c", &ch);
} while (ch == 'y');
return 0;
}