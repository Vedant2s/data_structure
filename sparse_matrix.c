
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
    int n1,j11,k1=0;
    printf("enter the no. of rows and columns of the matrix \n");
    scanf("%d",&n1);
    scanf("%d",&j11);
    int ab[19][19],count1=0,sb[19][19];
    float meow1;
   p=0;
	int u=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<j11;j++)
        {
            printf("enter a[%d][%d] ",i,j);
            scanf("%d",&ab[i][j]);
	    printf("\n");
            if(ab[i][j]==0)
            {
                count1++;
            }
            else
            {
                k1++;
            }
        }
    }
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<j11;j++)
        {
            if(ab[i][j]!=0)
            {
                sb[p][0]=i;
                sb[p][1]=j;
                sb[p][2]=ab[i][j];
                p++;
            }
        }
    }
    printf("R \t c \t v \t\n");
    for(int i=0;i<k1;i++)
    {
        printf("%d \t %d \t %d \t \n",sb[i][0],sb[i][1],sb[i][2]);
        printf("\n");
    }
    meow1=(float)(n1*j11)/2;
    if(count1>meow1)
    {
        printf("the matrix is sparse matrix");
    }
	int xb=0,tr=0,r[19][19];
	while(xb<=k&&tr<=k1)
	{
		if(s[xb][0]==sb[tr][0])
		{
			if(s[xb][1]==sb[tr][1])
			{
				r[u][0]=s[xb][0];
				r[u][1]=s[xb][1];
				r[u][2]=s[xb][2]+sb[tr][2];
				u++;
				if(tr<k1)
				{tr++;}
				if(xb<k)
				{xb++;}
				else
				{break;}

			}
			else if(s[xb][1]<sb[tr][1])
			{
				r[u][0]=s[xb][0];
				r[u][1]=s[xb][1];
				r[u][2]=s[xb][2];
				u++;
				if(xb<k)
				{xb++;}
				else
				{break;}
			}
			else if(s[xb][1]>sb[tr][1])
			{
				r[u][0]=sb[tr][0];
				r[u][1]=sb[tr][1];
				r[u][2]=sb[tr][2];
				u++;
				if(tr<k1)
				{tr++;}
			}
			else
			{
				r[u][0]=sb[tr][0];
				r[u][1]=sb[tr][1];
				r[u][2]=sb[tr][2];
				u++;
				if(tr<k1)
				{tr++;}
			}
		}
	} printf("R \t c \t v \t\n");
	for(int i2=0;i2<u;i2++)
	    {
		printf("%d \t %d \t %d \t \n",r[i2][0],r[i2][1],r[i2][2]);
		printf("\n");
	    }
    return 0;
}
