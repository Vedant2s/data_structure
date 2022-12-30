 #include<stdio.h>
#include<stdlib.h>
struct Btree
{
   int data;
   struct Btree *left,*right;
};

struct Btree* insert(struct Btree *root)
{
   int data;
   root=(struct Btree*)malloc(sizeof(struct Btree));
   printf("\nEnter data:");
   scanf("%d",&root->data);
   root->left=root->right=NULL;

   if(root->data==-1)
   {
      return NULL;
   }
   printf("Enter data of left child of %d",root->data);
   root->left=insert(root->left);
   printf("Enter data of right child of %d",root->data);
   root->right=insert(root->right);
   return root;

}

void inorder(struct Btree* root)
{
   if(root==NULL)
      return;
   else
   {
      if(root!=NULL)
      {
         inorder(root->left);
      }
      printf("%d ",root->data);
      inorder(root->right);
   }
}

int main()
{
   struct Btree *root=NULL;
   root=insert(root);
   inorder(root);
   return 0;
}
