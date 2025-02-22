#include <stdio.h>
int main () {
char gender;
int balance, bonus;

printf("Are you female? type 'y' if yes or 'n' if no : ");
scanf("%c", &gender);
printf("Enter your balance:");
scanf("%d", &balance);


if (gender=='y')
{
    if (balance>5000)
        bonus = 0.05 * balance;
        printf("%d",bonus);

    else
        bonus = 0.02 * bonus;
        printf("%d",bonus);
}
if (gender=='n')
{
    bonus = 0.02 * bonus;
    printf("%d", bonus);
}

