#include <stdio.h>
int main() {
   int i, rows, fact=1;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
i=1;
do {
    fact*=i;
    i=i+1;

}
while (i<=rows);
 printf("%d",fact);
   return 0;
}
