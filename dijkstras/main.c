#include <stdio.h>
#include <stdlib.h>
void dijkstras(int cost[10][10],int n,int s)
{
    int i,u,count=1,d[10],visited[10],min;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        d[i]=cost[s][i];
    }
    visited[s]=1;
    d[s]=0;
    while(count<=n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if((visited[i]==0)&&(d[i]<min))
            {
                min=d[i];
                u=i;
            }
        }
        visited[u]=1;
        count++;
        for(i=1;i<=n;i++)
        {
            if(d[i]>d[u]+cost[u][i])
                d[i]=d[u]+cost[u][i];
        }
    }
    printf("\nShortest path from %d",s);
    for(i=1;i<=n;i++)
        printf("\n%d to %d is %d",s,i,d[i]);
}
int main()
{
    int n,cost[10][10],i,j,s;
    printf("\nRead number of nodes:");
    scanf("%d",&n);
    printf("\nRead source:");
    scanf("%d",&s);
    printf("\nRead cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    dijkstras(cost,n,s);
    return 0;
}
