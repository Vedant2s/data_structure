#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct b
{
    char t;
    struct b*next;
};
struct b*top=NULL;
int i=-1;
 void push(int n,char r)
{
    struct b*new;
    if(i==n-1)
    {
        printf("OVERFLOW\n");
    }
    else if(top==NULL)
    {
        new=(struct b*)malloc(sizeof(struct b));
        new->t=r;
        new->next=NULL;
        i++;
    }
    else if(top!=NULL)
    {
        new=(struct b*)malloc(sizeof(struct b));
        new->t=r;
        new->next=top;
        top->next=NULL;
        top=new;
        i++;
    }
}
 char pop(int n)
{
     struct b*new;
     char y1;
    if(i==-1)
    {
        printf("UNDERFLOW\n");
        return y1;
    }
    else if(top->next==NULL)
    {

        new=top;
        y1=top->t;
        free(new);
        i--;
        return y1;
    }
    else if(top!=NULL)
    {
        new=top;
        y1=top->t;
        top=top->next;
        free(new);
        i--;
        return y1;
    }

}
int precedence(char rl)
{
    if(rl=='+'||rl=='-')
    {
        return(1);
    }
    if(rl=='*'||rl=='/')
    {
        return(2);
    }
    if(rl=='^')
    {
        return(3);
    }

}
void infixtopostfix(int n)
{
    top=(struct b*)malloc(sizeof(struct b));
    char infix[30],postfix[30];
    scanf("  %s",infix);
    int i1=0,j=0;
    while(infix[i1]!='\0')
    {
        if(isalnum(infix[i1]))
        {
            postfix[j]=infix[i1];
            j++;
        }
        else
        {
            if(top==NULL)
            {
                push(n,infix[i]);
            }
            else{
                while((precedence(top->t))>=(precedence(infix[i1]))&&top!=NULL)
            {
                postfix[j]=pop(n);
                j++;
            }
            push(n,infix[i1]);
            }
        }
        i1++;
    }
    while(i!=-1)
    {
        postfix[j]=pop(n);
        j++;
        postfix[j]='\0';
    }
     j=0;
     printf("\n");
    while(postfix[j]!='\0')
    {
        printf("%c",postfix[j]);
        j++;
    }
}

int main()
{
    printf("Enter the maximum size of the stack\n");
    int n;
    scanf("%d",&n);
    infixtopostfix(n);
    return 0;
}
/*#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct b
{
    char t;
    struct b*next;
};
struct b*top=NULL;
int i=-1;
 void push(int n,char r)
{
    struct b*new;
    if(i==n-1)
    {
        printf("OVERFLOW\n");
    }
    else if(top==NULL)
    {
        new=(struct b*)malloc(sizeof(struct b));
        new->t=r;
        new->next=NULL;
        i++;
    }
    else if(top!=NULL)
    {
        new=(struct b*)malloc(sizeof(struct b));
        new->t=r;
        new->next=top;
        top->next=NULL;
        top=new;
        i++;
    }
}
 char pop(int n)
{
     struct b*new;
     char y1;
    if(i==-1)
    {
        printf("UNDERFLOW\n");
        return y1;
    }
    else if(top->next==NULL)
    {

        new=top;
        y1=top->t;
        free(new);
        i--;
        return y1;
    }
    else if(top!=NULL)
    {
        new=top;
        y1=top->t;
        top=top->next;
        free(new);
        i--;
        return y1;
    }

}
int precedence(char rl)
{
    if(rl=='+'||rl=='-')
    {
        return(1);
    }
    if(rl=='*'||rl=='/')
    {
        return(2);
    }
    if(rl=='^')
    {
        return(3);
    }

}
void infixtopostfix(int n)
{
    top=(struct b*)malloc(sizeof(struct b));
    char infix[30],postfix[30];
    scanf("  %s",infix);
    int i1=0,j=0;
    while(infix[i1]!='\0')
    {
        if(isalnum(infix[i1]))
        {
            postfix[j]=infix[i1];
            j++;
        }
        else
        {
            if(top==NULL)
            {
                push(n,infix[i]);
            }
            else{
                while((precedence(top->t))>=(precedence(infix[i1]))&&top!=NULL)
            {
                postfix[j]=pop(n);
                j++;
            }
            push(n,infix[i1]);
            }
        }
        i1++;
    }
    while(i!=-1)
    {
        postfix[j]=pop(n);
        j++;
    }
     j=0;
     printf("\n");
    while(postfix[j]!='\0')
    {
        printf("%c",postfix[j]);
        j++;
    }
    EVALUATE(n,postfix);
}
int val(char rl)
{
    if(rl=='+')
    {
        return(1);
    }
    if(rl=='-')
    {
        return(2);
    }
    if(rl=='*')
    {
        return(3);
    }
    if(rl=='/')
    {
        return(4);
    }
    if(rl=='^')
    {
        return(5);
    }

}
int ev(int a,int b,char postfix)
{
    int rt;
    int yu;
    rt=val(postfix);
    switch(rt)
    {
        case 1:
        yu=a+b;
        break;
        case 2:
        yu=a-b;
        break;
        case 3:
        yu=a*b;
        break;
        case 4:
        yu=a/b;
        break;
        case 5:
        yu=a^b;
        break;
    }
    return(yu);
}
EVALUATE(int n,char postfix[])
{
    int i=0,z;
    while(postfix[i]!='\0')
    {
        if(isalnum(postfix[i])!=1)
        {
            push(n,postfix[i]);
        }
        else 
        {
            a=pop(n);
        b=pop(n);
       z= ev(a,b,postfix[j]);
            push(z);
        }
        i++;
    }
    printf("%d",)
}
int main()
{
    printf("Enter the maximum size of the stack\n");
    int n;
    scanf("%d",&n);
    infixtopostfix(n);
    EVALUATE(n);
    return 0;
}*/
