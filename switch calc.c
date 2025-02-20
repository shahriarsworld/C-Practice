#include <stdio.h>
int main () {
char operator;
float num1, num2;
printf("enter arithmatic symbols from [ + , - , * , / ] : ");
scanf("%c", &operator);

printf("enter first number : ");
scanf("%f", &num1);
printf("enter first number : ");
scanf("%f", &num2);


switch(operator){
case '+':
    printf("%f + %f = %f",num1,num2,num1+num2);
    break;
case '-':
    printf("%f - %f = %f",num1,num2,num1-num2);
    break;
case '*':
    printf("%f * %f = %f",num1,num2,num1*num2);
    break;
case '/':
    printf("%f / %f = %f",num1,num2,num1/num2);
    break;
}
}
