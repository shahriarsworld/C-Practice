#include<stdio.h>
int main () {
int number;
printf("ENTER A NUMBER FROM 0 TO 7:");
scanf("%d", &number);
switch (number){
  case 1:
      printf("Saturday");
      break;
  case 2:
      printf("Sunday");
      break;
  case 3:
      printf("Monday");
      break;
  case 4:
      printf("Tuesday");
      break;
  case 5:
      printf("Wednesday");
      break;
  case 6:
      printf("Thursday");
      break;
  case 7:
      printf("Friday");
      break;

  default:
    printf("invalid number");
}
return 0;
}
