//EXERCICIO NIVEL MEDIO

#include <stdbool.h>
#include <stdlib.h>

bool dfs(int** graph, int* colors, int node, int color, int* graphColSize) {
    colors[node] = color;

    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (colors[neighbor] == -1) {
            if (!dfs(graph, colors, neighbor, 1 - color, graphColSize)) {
                return false;
            }
        } else if (colors[neighbor] == color) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* colors = (int*)malloc(sizeof(int) * graphSize);
    for (int i = 0; i < graphSize; i++) {
        colors[i] = -1;  // -1: not colored yet
    }

    for (int i = 0; i < graphSize; i++) {
        if (colors[i] == -1) {
            if (!dfs(graph, colors, i, 0, graphColSize)) {
                free(colors);
                return false;
            }
        }
    }

    free(colors);
    return true;
}