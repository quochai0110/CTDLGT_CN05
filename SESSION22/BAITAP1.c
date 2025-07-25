#include <stdio.h>
#define MAX 100
int n;
int graph[MAX][MAX];
int matrix() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            graph[i][j] = 0;
        }
    }
}
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void printGraph() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(3, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    printGraph();
}