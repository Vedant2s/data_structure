#include<stdio.h>
#define max 5

int q[max]={0};
int front=-1,rear=-1;

void enqueue()
{
    int x;
    if((front==0&&rear==max-1)||(rear+1==front))
    {
        printf("OVERFLOW\n");
        return;
    }
    else
    {
        printf("Enter the element\n");
        scanf("%d",&x);
        if(rear==-1)
        {
            front=0;
            rear=0;
        }
        else if(rear==max-1)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        q[rear]=x;
    }
}
void dequeue()
{
    int a;
    if(front==-1)
    {
        printf("UNDERFLOW\n");
        return;
    }
    else
    {
        a=q[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else if(front==max-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        printf("Deleted element is %d\n",a);
    }
}
void display()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("EMPTY/UNDERFLOW\n");
        return;
    }
    if(front>rear)
    {
        printf("The elements in circular queue are:\n");
        for(i=front;i<max;i++)
        {
            printf("%d\n",q[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d\n",q[i]);
        }
    }
    else
    {
        printf("The elements in circular queue are:\n");
        for(i=front;i<max;i++)
        {
            printf("%d\n",q[i]);
        }
    }
}
int main()
{
    int choice=0;
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    display();
    return 0;
}
