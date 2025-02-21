#include <stdio.h>
int main ()
{
int num,i;
printf("Enter the range of print from 0 : ");
scanf("%d",&num);
printf("0 to %d is displayed below:\n",num);

for(i=0;i<=num;i++)
{
    printf("%d ",i);
}
return 0;
}
