#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct abc
{
    char data[25];
    struct abc*nextno;
};
struct abc*TOP=NULL;
char c;
int precedence(char c)
{
    if(c=='+')
    {
        return 1;
    }
    if(c=='-')
    {
        return 1;
    }
    if(c=='*')
    {
        return 2;
    }
    if(c=='/')
    {
        return 2;
    }
    if(c=='^')
    {
        return 3;
    }
}
int main() {
    char infix[40],postfix[40];
    printf("enter the equation\n");
    scanf(" %s",infix);
    TOP=(struct abc*)malloc(sizeof(struct abc));
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isalnum(infix[i]))
        {postfix[j]=infix[i];
            j++;
        }
        else{
            if(TOP==NULL)
            {
                push(infix[i]);
            }
            else{
                while(precedence(TOP->data)>=precedence(infix[i])&&TOP!=NULL)
                {
                    postfix[j]=pop();
                    j++;
                }
                push(infix[i]);
            }
        }i++;
    }
    while(TOP!=NULL){
        postfix[j]=pop();
        j++;
    }
    return 0;
}
