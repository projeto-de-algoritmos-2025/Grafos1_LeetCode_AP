//EXERCICIO NIVEL DIFICIL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005
#define MAXC 26

int max(int a, int b) {
    return a > b ? a : b;
}

int largestPathValue(char* colors, int** edges, int edgesSize, int* edgesColSize) {
    int n = strlen(colors);


    //Estrutura inicial
    int* adj[MAXN];
    int adjSize[MAXN] = {0};
    int adjCap[MAXN] = {0};
    int indegree[MAXN] = {0};

    for (int i = 0; i < n; i++) {
        adjCap[i] = 4;
        adj[i] = malloc(sizeof(int) * adjCap[i]);
    }

    // Construir grafo
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (adjSize[u] >= adjCap[u]) {
            adjCap[u] *= 2;
            adj[u] = realloc(adj[u], sizeof(int) * adjCap[u]);
        }

        adj[u][adjSize[u]++] = v;
        indegree[v]++;
    }


    int** dp = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = calloc(MAXC, sizeof(int));
    }

    // Fila para ordenação
    int* queue = malloc(sizeof(int) * n);
    int front = 0, back = 0;

    //Inserindo nos
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[back++] = i;
        }
    }

    int visited = 0, answer = 0;

    while (front < back) {
        int u = queue[front++];
        visited++;

        int colorIdx = colors[u] - 'a';
        dp[u][colorIdx]++;
        answer = max(answer, dp[u][colorIdx]);

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];

            for (int c = 0; c < MAXC; c++) {
                dp[v][c] = max(dp[v][c], dp[u][c]);
            }

            indegree[v]--;
            if (indegree[v] == 0) {
                queue[back++] = v;
            }
        }
    }

    // Verificando nos
    if (visited < n) return -1;

    return answer;
}
