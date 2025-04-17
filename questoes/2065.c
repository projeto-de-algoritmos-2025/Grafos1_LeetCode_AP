//EXERCICIO NIVEL DIFICIL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005

typedef struct {
    int to;
    int time;
} Edge;

typedef struct {
    Edge edges[4];  // no máximo 4 arestas por nó
    int size;
} Graph;

Graph graph[MAXN];
int maxQuality = 0;

void dfs(int node, int timeLeft, int* values, int* visited, int totalValue) {
    // Soma valor se é a primeira vez que visita esse nó
    if (!visited[node]) {
        totalValue += values[node];
    }

    // Se retornou ao nó 0, atualiza a qualidade máxima
    if (node == 0) {
        if (totalValue > maxQuality)
            maxQuality = totalValue;
    }

    visited[node]++;
    
    for (int i = 0; i < graph[node].size; i++) {
        int next = graph[node].edges[i].to;
        int cost = graph[node].edges[i].time;

        if (timeLeft >= cost) {
            dfs(next, timeLeft - cost, values, visited, totalValue);
        }
    }

    visited[node]--;
}

int maximalPathQuality(int* values, int valuesSize, int** edges, int edgesSize, int* edgesColSize, int maxTime) {
    // Reset
    for (int i = 0; i < valuesSize; i++) {
        graph[i].size = 0;
    }

    // Construir grafo
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int t = edges[i][2];

        graph[u].edges[graph[u].size++] = (Edge){v, t};
        graph[v].edges[graph[v].size++] = (Edge){u, t};
    }

    int visited[MAXN] = {0};
    maxQuality = 0;

    dfs(0, maxTime, values, visited, 0);

    return maxQuality;
}