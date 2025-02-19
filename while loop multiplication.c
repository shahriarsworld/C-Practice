#include <stdio.h>
int main () {
int number;
printf("Enter a number : ");
scanf("%d", &number);

int count = 5;

while (count <= 10){
    int result = number * count;
    printf("%d \n",result);
    count = count + 2;
}
}
