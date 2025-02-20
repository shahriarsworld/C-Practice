#include <stdio.h>
int main () {
char operator;
printf("Choose an operator [ '+' , '-' , '*', '/' : ");
scanf("%c", &operator);

int a,b;

printf("Enter the first number:");
scanf("%d",&a);

printf("Enter the second number:");
scanf("%d",&b);


switch(operator){
case '+':
    printf("%d + %d = %d", a,b,a+b);
    break;
case '-':
    printf("%d - %d = %d", a,b,a-b);
    break;
case '*':
    printf("%d * %d = %d", a,b,a*b);
    break;
case '/':
    printf("%d / %d = %d", a,b,a/b);
    break;

}
return 0;
}
