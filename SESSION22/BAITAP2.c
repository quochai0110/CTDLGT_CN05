#include <stdio.h>
#include <stdlib.h>
int n;
typedef struct Node {
    int vertex ;
    struct Node* next;
}Node;
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
};
Node *adjacency[100];
void addEdge(int u, int v) {
    Node *newNode = createNode(v);
    newNode->next = adjacency[u] ;
    adjacency[u] = newNode;
    newNode = createNode(u);
    newNode->next = adjacency[v] ;
    adjacency[v] = newNode;
};
void printfAdjacency() {
    for (int i = 0; i < n; i++) {
        Node *temp = adjacency[i];
        printf("%d:",i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;

        }
        printf("Null\n");
    }
}
int main() {
    printf("Nhap so dinh");
    scanf("%d",&n);

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);
    addEdge(3,2);
    addEdge(1,3);
    addEdge(3,4);

 printfAdjacency();
return 0;
}