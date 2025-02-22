#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void heapify(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int parent = i;
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;

        while (leftChild < n) {
            int max = leftChild;
            if (rightChild < n && arr[rightChild] > arr[leftChild])
                max = rightChild;

            if (arr[parent] < arr[max]) {
                int temp = arr[parent];
                arr[parent] = arr[max];
                arr[max] = temp;

                parent = max;
                leftChild = 2 * parent + 1;
                rightChild = 2 * parent + 2;
            } else {
                break;
            }
        }
    }
}

void insert(int arr[], int *n, int element) {
    arr[*n] = element;
    (*n)++;
    heapify(arr, *n);
}

void deleteElement(int arr[], int *n) {
    if (*n <= 0) {
        printf("There are no elements in the heap.\n");
        return;
    }

    int temp = arr[0];
    arr[0] = arr[*n - 1];
    arr[*n - 1] = temp;

    (*n)--;
    heapify(arr, *n);
}

void displayHeapSortedArray(int arr[], int n) {
    printf("Sorted heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current size of the heapified array

    int choice, element;
        printf("----------Menu----------\n");
        printf("1. Heapify the array\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Display heapsorted array\n");
        printf("5. Exit\n");
    do {
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                heapify(arr, n);
                break;
            case 2:
                printf("Enter the element you want to insert: ");
                scanf("%d", &element);
                insert(arr, &n, element);
                break;
            case 3:
                deleteElement(arr, &n);
                break;
            case 4:
                displayHeapSortedArray(arr, n);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

