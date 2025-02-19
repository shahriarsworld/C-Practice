//a C program to find number of days in a month
#include<stdio.h>
int main () {
int number;
printf("Enter the number of Month: ");
scanf("%d" , &number);

switch(number){
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
    printf("The number of month is 31");
    break;

case 4:
case 6:
case 9:
case 11:
    printf("The number of month is 30");
    break;
case 2:
    printf("The number of month is 28");
    break;
}
return 0;
}
