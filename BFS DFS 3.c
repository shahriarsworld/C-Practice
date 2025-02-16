#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES] = {0};

void create_graph() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
    printf("Graph created successfully.\n");
}

void insert_edge(int u, int v) {
    if (u >= 0 && u < MAX_VERTICES && v >= 0 && v < MAX_VERTICES) {
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
        printf("(%d, %d) inserted successfully.\n", u, v);
    } else {
        printf("Invalid vertices. Edge insertion failed.\n");
    }
}

void bfs(int source) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    queue[++rear] = source;
    visited[source] = 1;

    printf("BFS Output: ");

    while (front != rear) {
        source = queue[++front];
        printf("%d ", source);

        for (int i = 0; i < MAX_VERTICES; i++) {
            if (adjacency_matrix[source][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int source) {
    printf("%d ", source);
    visited[source] = 1;

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (adjacency_matrix[source][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int choice, u, v;
        printf("---------Menu---------\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Display in BFS\n");
        printf("4. Display in DFS\n");
        printf("5. Exit\n");
    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_graph();
                break;
            case 2:
                printf("Please enter the source and destination vertices (Range: 0 to %d): ", MAX_VERTICES - 1);
                scanf("%d %d", &u, &v);
                insert_edge(u, v);
                break;
            case 3:
                printf("Enter the starting vertex for the BFS traversal within the range of 0 to %d: ", MAX_VERTICES - 1);
                scanf("%d", &u);
                for (int i = 0; i < MAX_VERTICES; i++) {
                    visited[i] = 0;
                }
                bfs(u);
                break;
            case 4:
                printf("Enter the starting vertex for the DFS traversal within the range of 0 to %d: ", MAX_VERTICES - 1);
                scanf("%d", &u);
                for (int i = 0; i < MAX_VERTICES; i++) {
                    visited[i] = 0;
                }
                printf("DFS Output: ");
                dfs(u);
                printf("\n");
                break;
            case 5:
                printf("Exiting program....\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

