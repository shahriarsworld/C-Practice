#include <stdio.h>
int main () {
int number;
printf("Enter the number: ");
scanf("%d", &number);

if (number > 0){
    printf("positive");
}
    else if (number<0){
        printf("negative");

    }
    else if (number==0){
        printf("zero");
    }
}
