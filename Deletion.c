#include<stdio.h>

void main()
{
    int a[100],i,n,pos;

    printf("How many elements in the array? : ");
    scanf("%d",&n);

    printf("\nEnter the elements: ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\nElements of the array are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\nEnter the index position of the number to delete: ");
    scanf("%d",&pos);
    for(i=pos;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;
    printf("\nUpdated Array = ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
