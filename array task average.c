#include <stdio.h>
int main () {

int marks [5];

printf("Enter the marks of English:");
scanf("%d", &marks[0]);

printf("Enter the marks of Bangla:");
scanf("%d", &marks[1]);

printf("Enter the marks of Math:");
scanf("%d", &marks[2]);

printf("Enter the marks of Physics:");
scanf("%d", &marks[3]);

printf("Enter the marks of Chemisty:");
scanf("%d", &marks[4]);

int average = (marks[0]+marks[1]+marks[2]+marks[3]+marks[4])/5;

printf("The average of five subjects marks = %d", average);
return 0;
}
