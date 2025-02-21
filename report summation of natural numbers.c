#include <stdio.h>
int main ()
{
int i,num,sum=0;
printf("Enter the range of natural numbers to sum: ");
scanf("%d",&num);

for(i=1;i<=num;i++)
{
    sum=sum+i;
}
printf("The summation is %d",sum);

return 0;
}

