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
}

void insert_edge(int u, int v) {
    if (u >= 0 && u < MAX_VERTICES && v >= 0 && v < MAX_VERTICES) {
        adjacency_matrix[u][v] = 1;
        adjacency_matrix[v][u] = 1;
        printf("Edge (%d, %d) inserted.\n", u, v);
    } else {
        printf("Invalid vertices. Edge insertion failed.\n");
    }
}

void bfs(int source) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    queue[++rear] = source;
    visited[source] = 1;

    printf("BFS Traversal: ");

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

    create_graph();
        printf("\nMenu\n");
        printf("1. Create graph\n");
        printf("2. Insert edge\n");
        printf("3. Display elements using BFS\n");
        printf("4. Display elements using DFS\n");
        printf("5. Exit\n");
    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_graph();
                printf("Graph created.\n");
                break;
            case 2:
                printf("Enter source and destination vertices (0 to %d): ", MAX_VERTICES - 1);
                scanf("%d %d", &u, &v);
                insert_edge(u, v);
                break;
            case 3:
                printf("Enter the start vertex for BFS traversal (0 to %d): ", MAX_VERTICES - 1);
                scanf("%d", &u);
                for (int i = 0; i < MAX_VERTICES; i++) {
                    visited[i] = 0;
                }
                bfs(u);
                break;
            case 4:
                printf("Enter the start vertex for DFS traversal (0 to %d): ", MAX_VERTICES - 1);
                scanf("%d", &u);
                for (int i = 0; i < MAX_VERTICES; i++) {
                    visited[i] = 0;
                }
                printf("DFS Traversal: ");
                dfs(u);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
