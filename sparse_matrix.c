
#include <stdio.h>
#include<math.h>
int main() {
    int n,j1;
    printf("enter the no. of rows and columns of the matrix \n");
    scanf("%d",&n);
scanf("%d",&j1);
    int a[19][19],count=0,meow;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<j1;j++)
        {
            printf("enter a[%d][%d] ",i,j);
            scanf("%d \n",&a[i][j]);
            if(a[i][j]==0)
            {
                count++;
            }
        }
    }
    meow=(n*j1)/2;
    if(count>meow)
    {
        printf("the matrix is sparse matrix");
    }

    return 0;
}
