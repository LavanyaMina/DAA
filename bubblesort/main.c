#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
void bubble_sort(int A[size],int n)
{
    int i,j,temp;
    for(i=0;i<=n-2;i++)
    {
        for(j=0;j<=n-2-i;j++)
        {
            count++;
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}
int main()
{
    int i,A[size],n;
    printf("\nEnter array size:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    bubble_sort(A,n);
    printf("\nSorted elements are:\n");
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\nNumber of comparison is %d\n",count);
    return 0;
}
