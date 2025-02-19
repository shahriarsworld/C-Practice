#include <stdio.h>
int main () {

int number;
printf("enter the number:");
scanf("%d", &number);

int count = 10;

while (count>=1){
    int solve = number * count;
    printf("%d * %d = %d\n",number, count, solve);
    count=count - 1;

}

return 0;
}
