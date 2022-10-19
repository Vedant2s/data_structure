
#include <stdio.h>
#include<math.h>
int main() {
    int n,j1,k=0,p=0,s[19][19];
    printf("enter the no. of rows and columns of the matrix \n");
    scanf("%d",&n);
    scanf("%d",&j1);
    int a[19][19],count=0,meow;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<j1;j++)
        {
            printf("enter a[%d][%d] ",i,j);
            scanf("%d",&a[i][j]);
	    printf("\n");
            if(a[i][j]==0)
            {
                count++;
            }
            else
            {
                k++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<j1;j++)
        {
            if(a[i][j]!=0)
            {
                s[p][0]=i;
                s[p][1]=j;
                s[p][2]=a[i][j];
                p++;
            }
        }
    }
    printf("R \t c \t v \t\n");
    for(int i=0;i<k;i++)
    {
        printf("%d \t %d \t %d \t \n",s[i][0],s[i][1],s[i][2]);
        printf("\n");
    }
    meow=(n*j1)/2;
    if(count>meow)
    {
        printf("the matrix is sparse matrix");
    }

    return 0;
}
