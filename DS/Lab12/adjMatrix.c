#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

void initializeGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdgeDirected(int graph[MAX_VERTICES][MAX_VERTICES], int from, int to) {
    graph[from][to] = 1;
}

void addEdgeUndirected(int graph[MAX_VERTICES][MAX_VERTICES], int from, int to) {
    graph[from][to] = 1; 
    graph[to][from] = 1;
}

void printGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void inputEdges(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int isDirected) {
    int from, to;
    char choice;

    do {
        printf("Enter edge (from to): ");
        scanf("%d %d", &from, &to);

        if (from < 0 || from >= vertices || to < 0 || to >= vertices) {
            printf("Invalid vertices. Please enter values between 0 and %d.\n", vertices - 1);
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
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices;
    int choice;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Number of vertices exceeds maximum limit!\n");
        return 1;
    }

    initializeGraph(graph, vertices);

    printf("Choose graph type:\n");
    printf("1. Directed Graph\n");
    printf("2. Undirected Graph\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You chose Directed Graph.\n");
            inputEdges(graph, vertices, 1);
            break;
        case 2:
            printf("You chose Undirected Graph.\n");
            inputEdges(graph, vertices, 0);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printGraph(graph, vertices);

    return 0;
}
