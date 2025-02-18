#include <stdio.h>
int main () {
 double number;
 char alphabet;

 printf("enter double value:");
 scanf("%lf", &number);

 printf("enter character value:");
 scanf("\n %c", &alphabet);

 printf("number = %.2lf",number);
 printf("\n character = %c",alphabet);

 return 0;

}
