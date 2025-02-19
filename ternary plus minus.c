#include <stdio.h>
int main () {

char operator;
int num1, num2;

printf("enter any arithmetic operator : ");
scanf("%c", &operator);

printf("first two numbers : ");
scanf("%d %d", &num1, &num2);

int result = (operator == '+') ? (num1 + num2) : (num1-num2);
printf("%d", result);
}
