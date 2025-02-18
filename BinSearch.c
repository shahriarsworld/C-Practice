#include<stdio.h>
int binSearch(int array[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    while(low<=high){
        mid = (low + high)/2;
        if(array[mid] == element){
            return mid;
        }
        if(array[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;

}
int main(){
    int element;
    int array[] = {10,20,30,40,50,60,70,80};
    int size = sizeof(array)/sizeof(int);
    printf("---------BINARY SEARCH---------\n");
    printf("10,20,30,40,50,60,70,80\n");
    printf("Choose a number from above to search it's position :");
    scanf("%d",&element);
    int searchIndex = binSearch(array, size, element);
    printf("The element %d was found at position %d \n", element, searchIndex+1);
    return 0;
}
