#include <stdio.h>
int main()
{
int num1;
printf("enter first number:");
scanf("%d", &num1);

int num2;
printf("enter second number:");
scanf("%d", &num2);

switch(num1>num2){
case 0:
    printf("%d is bigger",num2);
    break;
case 1:
    printf("%d is bigger",num1);
    break;
default:
    printf("invalid input");
}
return 0;
}
