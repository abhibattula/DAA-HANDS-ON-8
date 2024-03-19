#include<stdio.h>
#include<stdlib.h>
#define max 3
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int item);
void peek();
void display();
int isempty();
int isfull();
int main()
{
    int op;
    int item;
    while(1)
    {
        printf("operations on stack\n1.Enqueue\n2.DEQUEUE\n3.peek\n4.display\n5.exit\nselect operation : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("\nenter the element to enqueue : ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(1);
            default:
                printf("\n/*****INVALID INUPUT*****/\n\n");
        }
    }
}

void enqueue(int item)
{
    if(isfull())
    {
        printf("\n/*Q is full*/\n\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear++;
    queue[rear] = item;
    printf("\nfront %d :: rear %d\n",front,rear);
    printf("\n/*ITEM ENQUEUED*/\n\n");
}

void dequeue()
{
    if(isempty())
    {
        printf("\n/*Q is EMPTY* /\n\n");
        return;
    }
    printf("\nFront element is %d is DEQUEUED\n\n",queue[front]);
    for(int i=front;i<=rear;i++)
    {
        queue[i] = queue[i+1];
    }
    printf("\nfront %d :: rear %d\n",front,rear);
    rear--;
}

void peek()
{
    if(isempty())
    {
        printf("\n/*Q is EMPTY*/\n\n");
        return;
    }
    printf("\nFront element is %d \n\n",queue[front]);
}

void display()
{
    if(isempty())
    {
        printf("\n/*Q is EMPTY*/\n\n");
        return;
    }
    printf("\nQueue = ");
    for(int i=front;i<=rear;i++)
    {
        printf(" %d->",queue[i]);
    }
    printf("\b\b");
    printf("\n\n");
}

int isfull()
{
    if(rear == max-1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(front == -1 || front == rear+1)//front>rear
        return 1;
    else
        return 0;
}
