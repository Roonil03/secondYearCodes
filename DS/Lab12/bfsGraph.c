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

typedef struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
void initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
}

// Function to add an undirected edge
void addEdge(Graph* graph, int from, int to) {
    Node* newNode = createNode(to);
    newNode->next = graph->adjList[from];
    graph->adjList[from] = newNode;

    newNode = createNode(from); // For undirected graph
    newNode->next = graph->adjList[to];
    graph->adjList[to] = newNode;
}

// Function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an element
void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->items[++queue->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// BFS algorithm
void bfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue queue;
    initQueue(&queue);

    visited[startVertex] = 1;
    enqueue(&queue, startVertex);

    printf("BFS Traversal: ");
    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(&queue, adjVertex);
            }
            temp = temp->next;
        }
    }
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(&graph, startVertex);

    return 0;
}
