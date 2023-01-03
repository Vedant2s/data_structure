// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct abc{
    int data;
    char name[30];
    struct abc*next,*prv;
};
int count=0;
struct abc* insert(struct abc*head){
    struct abc*new=NULL;
    struct abc*temp;
    new=(struct abc*)malloc(sizeof(struct abc));
    temp=(struct abc*)malloc(sizeof(struct abc));
    scanf("%d",&new->data);
    scanf(" %s",new->name);
    if(head->next==NULL&&head->prv==NULL&&count==0){
        new->next=NULL;
        new->prv=NULL;
        head=new;
        
    }
    else if(count!=0){
        temp=head;
        if(count==1){
             temp->next=new;
        new->prv=temp;
        new->next=NULL;
        }
        else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
        new->prv=temp;
        new->next=NULL;}}
    
    count++;
    return head;
}
void display(struct abc*head){
    struct abc*temp=NULL;
    temp=(struct abc*)malloc(sizeof(struct abc*));
    temp=head;
    while(temp->next!=NULL){
        printf("%d\n%s\n",temp->data,temp->name);
        temp=temp->next;
    }
    printf("%d\n%s\n",temp->data,temp->name);
}
struct abc* modify(struct abc*head){
    char lop[30];
    scanf(" %s",lop);
    struct abc*temp=NULL;
    temp=(struct abc*)malloc(sizeof(struct abc*));
    temp=head;
    int red=strcmp(lop,temp->name);
    if(!red){
            printf("Enter the name\n");
            scanf(" %s",temp->name);
        }
        else{
    while(temp->next!=NULL){
        red==strcmp(lop,temp->name);
        if(!red){
            printf("Enter the name\n");
            scanf(" %s",temp->name);
        }
        temp=temp->next;
    }}
    
        return head;
}
void displayback(struct abc*head){
    struct abc*temp=NULL;
    temp=(struct abc*)malloc(sizeof(struct abc*));
    temp=head;
    while(temp->next!=NULL){
        //printf("%d\n%s\n",temp->data,temp->name);
        temp=temp->next;
    }
    while(temp->prv!=NULL){
        printf("%d\n%s\n",temp->data,temp->name);
        temp=temp->prv;
    }
    printf("%d\n%s\n",temp->data,temp->name);
    
}
struct abc*delete(struct abc*head){
    char lop[30];
    printf("enter the name of the person to be deleted\n");
    scanf(" %s",lop);
    struct abc*temp=NULL,*r;
    temp=(struct abc*)malloc(sizeof(struct abc*));
    r=(struct abc*)malloc(sizeof(struct abc*));
    temp=head;
    
    int red=strcmp(lop,temp->name);
    if(count==1&&!red){
            head=NULL;
            head->prv=NULL;
            head->next=NULL;
        }
        else if(!red){
            head=head->next;
            free(temp);
            return head;
        }
    while(temp->next!=NULL){
        if(count>=2){
        r=temp;
        temp=temp->next;
        if(!red){
            if(count>2)
            r->next=temp->next;
            temp->next->prv=r;
            free(temp);
            break;
        }}}
        
        
        
    
    return head;
}

int main() {
    struct abc*head=NULL;
    head=(struct abc*)malloc(sizeof(struct abc));
     head->next=NULL;
    head->prv=NULL;
    head=insert(head);
    head=insert(head);
    /*display(head);
    displayback(head);*/
    head=modify(head);
    display(head);
    head=delete(head);
    display(head);
    return 0;
}
