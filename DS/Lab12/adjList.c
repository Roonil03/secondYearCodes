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

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

void addEdgeDirected(Graph* graph, int from, int to) {
    Node* newNode = createNode(to);
    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;
}

void addEdgeUndirected(Graph* graph, int from, int to) {
    addEdgeDirected(graph, from, to);
    addEdgeDirected(graph, to, from);
}

void printGraph(Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjList[i];
        printf("%d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void inputEdges(Graph* graph, int isDirected) {
    int from, to;
    char choice;

    do {
        printf("Enter edge (from to): ");
        scanf("%d %d", &from, &to);

        if (from < 0 || from >= graph->vertices || to < 0 || to >= graph->vertices) {
            printf("Invalid vertices. Please enter values between 0 and %d.\n", graph->vertices - 1);
        } else {
            if (isDirected) {
                addEdgeDirected(graph, from, to);
            } else {
                addEdgeUndirected(graph, from, to);
            }
            printf("Edge added: %d -> %d\n", from, to);
        }

        printf("Do you want to add another edge? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    Graph graph;
    int vertices;
    int choice;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Number of vertices exceeds maximum limit!\n");
        return 1;
    }

    initializeGraph(&graph, vertices);

    printf("Choose graph type:\n");
    printf("1. Directed Graph\n");
    printf("2. Undirected Graph\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You chose Directed Graph.\n");
            inputEdges(&graph, 1);
            break;
        case 2:
            printf("You chose Undirected Graph.\n");
            inputEdges(&graph, 0);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printGraph(&graph);

    return EXIT_SUCCESS;
}
