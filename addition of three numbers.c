#include<stdio.h>
int main ()
{
int x,y,z,sum;
printf("Enter three numbers to add:\n");
scanf("%d%d%d", &x,&y,&z);
sum=x+y+z;
printf("The summation of above three numbers is: %d",sum);
return 0;
}
