#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void initializeGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; // For an undirected graph
}

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    }

    int vertex = queue[front];
    front++;
    return vertex;
}

void breadthFirstSearch(int start, int numVertices) {
    printf("BFS traversal: ");
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    visited[start] = true;
    enqueue(start);

    while (front != -1) {
        int current = dequeue();
        if (current != -1) {
            printf("%d ", current);
            for (int i = 0; i < numVertices; i++) {
                if (graph[current][i] && !visited[i]) {
                    visited[i] = true;
                    enqueue(i);
                }
            }
        }
    }
    printf("\n");
}

void depthFirstSearch(int vertex, int numVertices) {
    if (visited[vertex])
        return;

    printf("%d ", vertex);
    visited[vertex] = true;

    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i])
            depthFirstSearch(i, numVertices);
    }
}

int main() {
    int numVertices, numEdges, startVertex;
    int choice;

    printf("Enter the number of vertices (maximum 10): ");
    scanf("%d", &numVertices);

    initializeGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int start, end;
    printf("Enter the edges (start end):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    printf("\nMenu:\n");
    printf("1. Breadth-First Search (BFS)\n");
    printf("2. Depth-First Search (DFS)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    switch (choice) {
        case 1:
            breadthFirstSearch(startVertex, numVertices);
            break;
        case 2:
            for (int i = 0; i < numVertices; i++)
                visited[i] = false;
            printf("DFS traversal: ");
            depthFirstSearch(startVertex, numVertices);
            printf("\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

