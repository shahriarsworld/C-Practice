#include <stdio.h>
int main () {

int i, num;

printf("enter the number:");
scanf("%d", &num);
i=1;
while (i<=10)
{

    printf("%d * %d = %d\n", num, i,(num*i));
i=i+1;
}
return 0;
}
