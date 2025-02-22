#include<stdio.h>
int main()
{
    double salary = 20.99;
    double* ptr = &salary;

    printf("%.2lf",*ptr);

    *ptr = salary*2;

    printf("\nnew doubled salary : %.2lf",*ptr);


    return 0;
}
