#include <stdio.h>
int main () {
char input;
printf("Type V for Vowel and C for Consonent:");
scanf("%c", &input);

switch(input){
case 'v':
    printf("A E I O U");
    break;
case 'c':
    printf("B C D F G H J K L M N P Q R S T V W X Y Z");
    break;
default:
    printf("incorrect input");
}
}
