#include <stdio.h>
#include <stdlib.h>
#define size 100
int count;
int partition(int a[size],int l,int r)
{
    int i,j,pivot,temp;
    pivot=a[l];
    i=l+1;
    j=r;
    while(1)
    {
        while(pivot>=a[i] && i<=r)
           {
              count++;
              i++;
           }
        while(pivot<a[j])
        {
            count++;
            j--;
        }
        count++;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else{
            temp=a[j];
            a[j]=a[l];
            a[l]=temp;
            return j;
        }
    }
}
void quick_sort(int a[size],int l,int r)
{

    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quick_sort(a,l,s-1);
        quick_sort(a,s+1,r);
    }
}
int main()
{
    int i,n,a[size];
    printf("\nEnter size of array:");
    scanf("%d",&n);
    printf("\nEnter the elements of array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    printf("\nThe sorted array is:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTotal comparison:%d",count);
}
