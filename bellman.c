#include <stdio.h>
#include <limits.h>

#define V 5
#define E 8

void bellman_ford(int graph[][3], int src, int dest) {
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
        for (int j = 0; j < E; j++)
            if (dist[graph[j][0]] != INT_MAX && dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];

    for (int i = 0; i < E; i++)
        if (dist[graph[i][0]] != INT_MAX && dist[graph[i][0]] + graph[i][2] < dist[graph[i][1]]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }

    printf("Shortest Distance from %d to %d: %d\n", src, dest, dist[dest]);
}

int main() {
    int graph[E][3] = {
        {0, 1, 4}, {0, 2, 5}, {1, 2, -2}, {1, 3, 6},
        {2, 3, 1}, {2, 4, 4}, {3, 4, 2}, {4, 3, -3}
    };

    bellman_ford(graph, 0, 4);

    return 0;
}

