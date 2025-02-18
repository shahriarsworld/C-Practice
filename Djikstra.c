
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define VTX 100

int min_dist(int d[], int v[], int n) {
    int min = INT_MAX, min_idx;

    for (int i = 0; i < n; i++) {
        if (!v[i] && d[i] < min) {
            min = d[i];
            min_idx = i;
        }
    }

    return min_idx;
}

void print_path(int p[], int j) {
    if (p[j] == -1) return;
    print_path(p, p[j]);
    printf("%d -> ", j);
}

void print_shortest_path(int d[], int p[], int src, int dest) {
    printf("Shortest Path from %d to %d: ", src, dest);
    printf("%d -> ", src);
    print_path(p, dest);
    printf("\nShortest Distance from %d to %d: %d\n", src, dest, d[dest]);
}

void dijkstra(int g[][VTX], int src, int dest, int n) {
    int d[VTX], v[VTX], p[VTX];

    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        v[i] = 0;
        p[i] = -1;
    }

    d[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = min_dist(d, v, n);
        v[u] = 1;

        for (int i = 0; i < n; i++) {
            if (!v[i] && g[u][i] && d[u] != INT_MAX && d[u] + g[u][i] < d[i]) {
                d[i] = d[u] + g[u][i];
                p[i] = u;
            }
        }
    }

    print_shortest_path(d, p, src, dest);
}

int main() {
    int n = 9;
    int g[VTX][VTX] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int src = 0, dest = 4;

    dijkstra(g, src, dest, n);

    return 0;
}
