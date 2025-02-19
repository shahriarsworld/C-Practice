#include <stdio.h>

int main()
{
    char ch;

    printf("Alphabets from a - z are: \n");
   int n= 'a' ;
   do
    {
        printf("%c\n", n);

        n = ++n;
    }
     while (n<='z');
    return 0;
}
