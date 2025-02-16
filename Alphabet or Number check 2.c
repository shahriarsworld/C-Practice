#include<stdio.h>
int main () {
char x;
printf("Enter a character:");
scanf("%c", &x);

if ((x >= 'a' && x <= 'z' ) || (x >= 'A' && x <= 'Z' ))
   printf("The character is an alphabet.");
else
    printf("The character is not an alphabet.");

if ((x >= '0' && x <= '9' ))
   printf("This is a number.");
else
    printf("This is not a number.");

return 0;
}
