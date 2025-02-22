#include<stdio.h>

int max(int num1, int num2)
{
    if(num1>num2)
    {
        printf("%d is bigger",num1);
    }
    else
        printf("%d is bigger",num2);

    return 0;
}

int min(int num1, int num2)
{
    if(num1<num2)
    {
        printf("\n%d is smaller",num1);
    }
    else
        printf("\n%d is smaller",num2);

    return 0;
}

int main ()
{
    int userNum1,userNum2;
    printf("enter two numbers: ");
    scanf("%d %d", &userNum1, &userNum2);

    max(userNum1, userNum2);
        min(userNum1, userNum2);
    return 0;
}
