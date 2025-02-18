#include <stdio.h>
#include <stdlib.h>

// Structure for BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new Node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value Node in a BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a Node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform In-order traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform Pre-order traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform Post-order traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to free the memory allocated for the BST
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
        printf("--------Menu--------\n");
        printf("1. Creation\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Traversal in In-order\n");
        printf("5. Traversal in Pre-order\n");
        printf("6. Traversal in Post-order\n");
        printf("7. Exit\n");

    do {

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
        do {
        printf("Enter data for the new node or -1 to stop creating: ");
        scanf("%d", &data);

        if (data != -1) {
            struct Node* newNode = createNode(data);
            if (root == NULL) {
                root = newNode;
            } else {
                // BST insertion logic can be added here if needed.
                // For this example, we are only creating nodes.
            }
            printf("Node with data %d created.\n", data);
        }
    } while (data != -1);

    // You can add the option to perform other operations with the created nodes here
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;

        case 3:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;

        case 4:
            printf("In-order traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("Pre-order traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;

        case 6:
            printf("Post-order traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 7:
            freeTree(root); // Free the allocated memory before exiting
            printf("Exiting Program.....\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
