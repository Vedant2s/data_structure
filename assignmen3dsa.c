#include <stdio.h>
#define n 3
    int a[n][n],visited[n],stack[10]={},top=-1;
int pop(){
    int e= stack[top];
    stack[top]=0;
    top--;
    return e;
}
void DFS(int v){
    visited[v]=1;
    stack[++top]=v;
    printf("%d",v);
    for(int i=0;i<n;i++){
        if(a[v][i]==1&&!visited[i]){
            DFS(i);
        }
    }
    int f,e;
    while(top!=1){
        f=0;
        e=stack[top];
        for(int i=0;i<n;i++){
            if(a[e][i]==1&&!visited[i]){
                DFS(i);
                f=1;
            }
        }
        if(f==0)
        pop();
    }
}
int main()
{
    int v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
        printf("enter stack vertex");
        scanf("%d",&v);
        DFS(v);
    }
    return 0; 
}
