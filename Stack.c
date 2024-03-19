#include<stdio.h>
#include<stdlib.h>
#define max 3

int top = -1;
int stack[max];
int isfull();
int isempty();
void push(int item);
int pop();
void peek();
void display();

int main()
{
    int op;
    int item;
    while(1)
    {
        printf("operations on stack\n1.push\n2.pop\n3.peek\n4.display\n5.exit\nselect operation : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("enter the element to push : ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                printf("%d is deleted from the stack\n",pop());
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
                printf("invalid input");
        }
    }
}

void push(int item)
{
    if(isfull())
    {
        printf("\nstack is full\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("\nitem is inserted in the stack\n\n");
}

void display()
{
    if(isempty())
    {
        printf("stack is empty\n");
        return;
    }
    for(int i = top;i>=0;i--)
    {
        printf("\nstack[%d] %d\n.....",i,stack[i]);
    }
    printf("\n");
}

void peek()
{

    if(isempty())
    {
        printf("stack is empty\n");
        exit(1);
    }
    printf("\nTop element = %d\n\n",stack[top]);
}

int pop()
{
    if(isempty())
    {
        printf("\nstack is empty\n");
        exit(1);
    }else{
        int item = stack[top];
        top--;
        return item;
    }
}

int isfull()
{
    if(top == max-1)
    {
        return 1;
    }else{
        return 0;
    }
}

int isempty()
{
    if(top == -1)
    {
        return 1;
    }else{
        return 0;
    }
}
