#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct b
{
    char t;
    struct b*next;
};
struct b*top=NULL;
int i=-1;
float stack1[20];
int top1=-1;
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
void push1(float yq)
{
	top1=top1+1;
	stack1[top1]=yq;
}
float pop1()
{
	float y;
	if(top1!=-1){	
	y=stack1[top1];
	stack1[top1]=0;
	top1=top1-1;}
	return(y);
}
void evaluate2(float h1,float h2,char postfix)
	{
		float ye;
		switch(postfix)
		{
			case '+':
			ye=h2+h1;
			push1(ye);
			break;		
			case '-':
			ye=h2-h1;
			push1(ye);
			break;
			case '/':
			ye=h2/h1;
			push1(ye);
			break;
			case '*':
			ye=h2*h1;
			push1(ye);
			break;
			case '^':
			ye=pow(h2,h1);
			push1(ye);
			break;
		}
	}
void evaluate(char postfix[])
{
	int i=0;
	float num;
	while(postfix[i]!='\0')
	{
		if(isdigit(postfix[i]))
		{
			num=(postfix[i]-48);
			push1(num);
		}	
		else
		{
			float h1,h2;
			h1=pop1();
			h2=pop1();
			char yd;
			yd=postfix[i];
			evaluate2(h1,h2,yd);
		}
		i++;
	}
	float d;
	d=pop1();
	printf("\nthe value of the expression is %.3f\n",d);
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
	printf("\n");
	evaluate(postfix);

}

int main()
{
    printf("Enter the maximum size of the stack\n");
    int n;
    scanf("%d",&n);
    infixtopostfix(n);
    return 0;
}
