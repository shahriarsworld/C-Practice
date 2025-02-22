#include<stdio.h>
int main ()
{
    int number=50;
    int* ptr = &number;

    printf("%d", *ptr);

    return 0;
}
