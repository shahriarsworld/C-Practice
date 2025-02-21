#include <stdio.h>
int main ()
{
char c;
printf("Enter a character: ");
scanf("%c",&c);

if((c>='a' && c<= 'z') || (c>='A' && c<= 'Z'))
{
    printf("'%c' is an alphabet.",c);
}
else if(c>='0' && c<= '9')
{
    printf("'%c' is a digit.",c);
}
else
{
    printf("'%c' is not an alphabet or a digit.",c);
}
return 0;
}
