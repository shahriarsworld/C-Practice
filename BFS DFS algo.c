#include <stdio.h>
#include <stdlib.h>

#define VERTICES 100

void add_edge(int mat[][VERTICES], int src, int dest) {
    mat[src][dest] = 1;
    mat[dest][src] = 1;
}

void bfs(int mat[][VERTICES], int n, int start) {
    int visited[VERTICES] = {0};
    int queue[VERTICES];
    int front = -1, rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (mat[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

void dfs_util(int mat[][VERTICES], int n, int curr, int visited[]) {
    visited[curr] = 1;
    printf("%d ", curr);

    for (int i = 0; i < n; i++) {
        if (mat[curr][i] && !visited[i])
            dfs_util(mat, n, i, visited);
    }
}

void dfs(int mat[][VERTICES], int n, int start) {
    int visited[VERTICES] = {0};
    dfs_util(mat, n, start, visited);
}

int main() {
    int n = 5;
    int mat[VERTICES][VERTICES] = {0};

    add_edge(mat, 0, 1);
    add_edge(mat, 0, 2);
    add_edge(mat, 1, 2);
    add_edge(mat, 2, 3);
    add_edge(mat, 3, 4);

    printf("BFS traversal starting from vertex 0: ");
    bfs(mat, n, 0);
    printf("\n");

    printf("DFS traversal starting from vertex 0: ");
    dfs(mat, n, 0);
    printf("\n");

    return 0;
}
