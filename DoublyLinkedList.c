#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Memory allocation failed.");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head)
        (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteAtBeginning(struct Node** head) {
    if (!*head) {
        puts("List is empty.");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
}

void deleteAtEnd(struct Node** head) {
    if (!*head) {
        puts("List is empty.");
        return;
    }
    struct Node* current = *head;
    while (current->next)
        current = current->next;
    if (current->prev)
        current->prev->next = NULL;
    else
        *head = NULL;
}

int searchElement(struct Node* head, int key) {
    struct Node* current = head;
    while (current) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;
    printf("--------MENU--------");
    printf("\n1. Create\n2. Display\n3. Insert at the beginning\n4. Insert at the end\n5. Delete at the beginning\n6. Delete at the end\n7. Search\n8. Exit");
    printf("\n--------------------");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the initial node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                deleteAtBeginning(&head);
                printf("Data successfully deleted at the beginning.");
                printf("\n");
                break;
            case 6:
                deleteAtEnd(&head);
                printf("Data successfully deleted at the end.");
                printf("\n");
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &key);
                searchElement(head, key) ? puts("Element found.") : puts("Element not found.");
                break;
            case 8:
                printf("Exiting program....");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
