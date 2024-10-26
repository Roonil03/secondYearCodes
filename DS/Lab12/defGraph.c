#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int vertices;
} Graph;

void initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int from, int to) {
    Node* newNode = createNode(to);
    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;

    newNode = createNode(from); // For undirected graph
    newNode->next = graph->adjList[to];
    graph->adjList[to] = newNode;
}

void dfsUtil(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfsUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal: ");
    dfsUtil(graph, startVertex, visited);
    printf("\n");
}

int main() {
    Graph graph;
    int vertices, edges, from, to;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Number of vertices exceeds maximum limit!\n");
        return 1;
    }

    initializeGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (from to): ");
        scanf("%d %d", &from, &to);
        addEdge(&graph, from, to);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    dfs(&graph, startVertex);

    return 0;
}
