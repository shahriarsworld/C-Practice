#include <stdio.h>
int main ()
{
int i,num,sum=0;
printf("Enter the range of natural numbers to calculate average: ");
scanf("%d",&num);

for(i=1;i<=num;i++)
{
    sum=sum+i;
}
float avrg=sum/num;
printf("The average is %f",avrg);

return 0;
}

