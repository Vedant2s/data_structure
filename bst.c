#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else if (root != NULL) {
        inorder(root->left);}
        printf("%d \n", root->key);
        inorder(root->right);
    
}
 void search(struct node*root,int key2)
 {
     if(root!=NULL)
     {
         return;
     }
     else if(key2==root->key)
     {
         printf("found\n");
     }
     else if(key2 < root->key)
     {
         search(root->left,key2);
     }
     else{
         search(root->right,key2);
     }
 }
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    else if (root != NULL) {
        printf("%d \n", root->key);
        inorder(root->left);}
        inorder(root->right);
    
}

struct node* insert(struct node* node, int key)
{
 
    if (node == NULL)
        {return newNode(key);}
 

    else if (key < node->key)
        {node->left = insert(node->left, key);}
    else if (key > node->key)
        {node->right = insert(node->right, key);}
 

    return node;
}
 

int main()
{

    struct node* root = NULL;
    root=(struct node*)malloc(sizeof(struct node));

    int ch,y,d;
    do{
        printf("\n1.insert\n2.traverse\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter the data\n");
            scanf("%d",&d);
            root=insert(root,d);
            break;
            case 2:
            
            inorder(root);
            break;
            case 3:
            printf("enter the data\n");
            scanf("%d",&d);
            search(root,d);
            break;
        }
        printf("do you want to continue?[0/1]\n");
        scanf("%d",&y);
    }while(y!=0);

 
    return 0;
}
