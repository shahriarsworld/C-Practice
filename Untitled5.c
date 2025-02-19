#include<stdio.h>
int main () {
char x;
printf("Enter a character:");
scanf("%c", &x);

if ((x >= 'a' && x <= 'z' ) || (x >= 'A' && x <= 'Z' ))
   printf("The character is an alphabet."),x;
else
    printf("The character is not an alphabet.",x);

if ((x >= 0 && x <= 9 ))
   printf("This is a number.",x);
else
    printf("This is not a number.",x);

return 0;
}
