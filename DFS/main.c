#include<stdio.h> #include<stdlib.h>
int topo[10],k;
void dfs(int a[10][10],int n,int v[10],int source)
{
    int i;
    v[source]=1;
    for(i=1; i<=n; i++)
    {
        if(v[i]==0 && a[source][i]==1) dfs(a,n,v,i);
    }
    topo[++k]=source;
}
int main()
{
    int n,i,j,a[10][10],v[10];
    printf("\n Enter the no of Vertices : ");
    scanf("%d",&n);
    printf("\n Enter the Adjacency matrix\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++) scanf("%d",&a[i][j]);
    for(i=1; i<=n; i++) v[i]=0;
    for(i=1; i<=n; i++)
    {
        if(v[i]==0) dfs(a,n,v,i);
    }
    printf("\n The topological ordering is\n");
    for(i=k; i>=1; i--)
        printf("%d\t",topo[i]);
}
