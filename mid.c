#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct class5
{
    char name[25];
    struct class5*nextno;
};
int g=0;
void create(struct class5*head)
{
    struct class5*newno,*temp;
    newno=(struct class5*)malloc(sizeof(struct class5));
    printf("enter the name of student\n");
    scanf(" %s",newno->name);
    newno->nextno=NULL;
    temp=head;
    if(head->nextno==NULL)
    {
        head->nextno=newno;
    }
    else
    {
        while(temp->nextno!=head)
        {
            temp=temp->nextno;
        }
        temp->nextno=newno;
    }
    newno->nextno=head;
 
    
}
void deleteI(struct class5*head)
{
    int rt;
    struct class5*temp,*p,*q;
    printf("enter the name of the node after first entry you want to delete\n");
    scanf("%d",&rt);
    p=(struct class5*)malloc(sizeof(struct class5));
    temp=(struct class5*)malloc(sizeof(struct class5));
    q=(struct class5*)malloc(sizeof(struct class5));
    p->nextno=NULL;
    temp->nextno=NULL;
    q->nextno=NULL;
 
        int y=0;
    while(y!=rt)
    {
        if(p->nextno==NULL)
        {
            p=head;
        }
        else
        {p=p->nextno;}
        temp=p->nextno;
        q=temp->nextno;
        y++;
    }
    temp->nextno=NULL;
    p->nextno=q;
    free(temp);
    g--;
}
 struct class5*insertI(struct class5*head)
{
    int rt;
    struct class5*temp,*p,*q,*newr;
    printf("enter the name of the node after first entry you want to enter\n");
    scanf("%d",&rt);
    p=(struct class5*)malloc(sizeof(struct class5));
    temp=(struct class5*)malloc(sizeof(struct class5));
    q=(struct class5*)malloc(sizeof(struct class5));
    newr=(struct class5*)malloc(sizeof(struct class5));
    p->nextno=NULL;
    temp->nextno=NULL;
    q->nextno=NULL;
   printf("enter the name of the new element\n");
   scanf(" %s",newr->name);
        int y=0;
    while(y!=rt)
    {
        if(p->nextno==NULL)
        {
            p=head;
        }
        else
        {p=p->nextno;}
        temp=p->nextno;
        q=temp->nextno;
        y++;
    }
    p->nextno=newr;
   newr->nextno=temp;
    g++;
}
 void display(struct class5*head){
      struct class5*temp;
      temp=head;
      while(temp->nextno!=head)
      {
          printf("name : %s \n",temp->name);
          temp=temp->nextno;
      }
      printf("name : %s \n",temp->name);
     
 }
struct class5* rev(struct class5*head)
{
    struct class5*temp;
    struct class5*p,*q;
    temp=head;
    p=head->nextno;
    q=p->nextno;
    while(q!=head)
    {
        p->nextno=temp;
        temp=p;
        p=q;
        q=q->nextno;
    }
    p->nextno=temp;
    head->nextno=p;
    head=p;
    return head;
}
int main() {
    struct class5*head;
    struct class5*temp;
    
    head=(struct class5*)malloc(sizeof(struct class5));
    printf("Enter the name of student\n");
    scanf(" %s",head->name);
    head->nextno=NULL;
    g++;
    int choice,r,s=0;
    do{
        printf("enter your choice\n1.enter members\n2.delete intermediate\n3.display reverse\n4.count list\n5.insert intermediate\n6.display");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter no. of newxt nodes you want to enter\n");
            scanf("%d",&r);
            for(s=0;s<r;s++){
            create(head);
                g++;
            }
            break;
            case 2:
            deleteI(head);
            break;
            case 3:
            if(1){head=rev(head);
            display(head);
            head=rev(head);}
            break;
            case 4:
            printf("the no. of members are %d\n",g);
            break;
            case 5:
            insertI(head);
            break;
            case 6 :
            display(head);
            break;
        }
        
    }while(choice!=0);
    return 0;
}
