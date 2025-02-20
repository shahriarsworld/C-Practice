//C program to check if a number is positive ,negative or zero.
#include <stdio.h>
int main () {
int num;
printf("enter a number:");
scanf("%d", &num);

switch (num>0){
case 1:
    printf("positive");
    break;
case 0:
    switch (num<0){
case 1:
    printf("negative");
    break;
case 0:
    printf("zero");
    break;

}
}
}
