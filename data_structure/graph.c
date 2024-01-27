/*
 * Giovanna Borges Bottino 
 * giovannabbottino@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int vertices;
    Node** adjacency_list;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adjacency_list = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacency_list[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        printf("Vertex %d:", i);
        Node* current = graph->adjacency_list[i];
        while (current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
