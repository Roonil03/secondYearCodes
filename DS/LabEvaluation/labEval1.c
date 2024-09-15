#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int front, rear, size;
    int queue[MAX];
} Queue;

typedef struct {
    char name[MAX];
    char director[MAX];
    int seats;
    int id;
    Queue reservationQueue;
} Movie;

typedef struct {
    int top;
    Movie m[MAX];
} Stack;

// Queue functions
void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueFull(Queue *q) {
    return q->size == MAX;
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int id) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", id);
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = id;
    q->size++;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    int id = q->queue[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return id;
}

// Stack functions
void initializeStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, Movie movie) {
    if (isStackFull(s)) {
        printf("Stack is full. Cannot push movie\n");
        return;
    }
    s->top++;
    s->m[s->top] = movie;
}

Movie pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty. Cannot pop movie\n");
        exit(1);  // exit program if stack is empty
    }
    return s->m[s->top--];
}

// Display movie collection
void displayCollection(Stack *s) {
    printf("Movie Collection:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d %s %s Seats: %d\n", s->m[i].id, s->m[i].name, s->m[i].director, s->m[i].seats);
    }
}

// Search for a movie
int searchMovie(Stack *s, int id) {
    for (int i = 0; i <= s->top; i++) {
        if (s->m[i].id == id) {
            return i;
        }
    }
    return -1;  // Not found
}

int main() {
    int choice = 0;
    Stack movieStack;
    initializeStack(&movieStack);

    do {
        printf("1. Add a Movie\n2. Search for a Movie\n3. Book a Ticket\n4. Last Booked Movies\n5. Reserve a Ticket\n6. Cancel a Ticket\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {  // Add a Movie
                Movie newMovie;
                printf("Enter Movie ID: ");
                scanf("%d", &newMovie.id);
                printf("Enter Title: ");
                scanf(" %[^\n]", newMovie.name);  // Read full line including spaces
                printf("Enter Director: ");
                scanf(" %[^\n]", newMovie.director);
                printf("Enter Available Seats: ");
                scanf("%d", &newMovie.seats);
               
                // Add movie to stack and sort
                push(&movieStack, newMovie);

                // Sort movies by ID using bubble sort
                for (int i = 0; i < movieStack.top; i++) {
                    for (int j = 0; j < movieStack.top - i; j++) {
                        if (movieStack.m[j].id > movieStack.m[j + 1].id) {
                            Movie temp = movieStack.m[j];
                            movieStack.m[j] = movieStack.m[j + 1];
                            movieStack.m[j + 1] = temp;
                        }
                    }
                }

                printf("Movie added successfully.\n");
                displayCollection(&movieStack);
                break;
            }
            case 2: {  // Search for a Movie
                int id;
                printf("Enter the Movie ID to find: ");
                scanf("%d", &id);

                int index = searchMovie(&movieStack, id);
                if (index != -1) {
                    printf("Movie found:\n");
                    printf("%d %s %s Seats: %d\n", movieStack.m[index].id, movieStack.m[index].name, movieStack.m[index].director, movieStack.m[index].seats);
                } else {
                    printf("Movie not found.\n");
                }
                break;
            }
            case 3: {  // Book a Ticket
                int id;
                printf("Enter Movie ID to book a ticket: ");
                scanf("%d", &id);

                int index = searchMovie(&movieStack, id);
                if (index != -1) {
                    if (movieStack.m[index].seats > 0) {
                        movieStack.m[index].seats--;
                        printf("Ticket booked for movie:\n");
                        printf("%d %s %s\n", movieStack.m[index].id, movieStack.m[index].name, movieStack.m[index].director);
                        printf("Last Booked Movies:\n");
                        for (int i = 0; i <= movieStack.top; i++) {
                            if (i == movieStack.top) {
                                printf("%d %s %s\n", movieStack.m[i].id, movieStack.m[i].name, movieStack.m[i].director);
                            }
                        }
                        displayCollection(&movieStack);
                    } else {
                        printf("No seats available for this movie.\n");
                    }
                } else {
                    printf("Movie not found.\n");
                }
                break;
            }
            case 4: {  // Last Booked Movies
                printf("Last Booked Movies:\n");
                for (int i = 0; i <= movieStack.top; i++) {
                    printf("%d %s %s\n", movieStack.m[i].id, movieStack.m[i].name, movieStack.m[i].director);
                }
                break;
            }
            case 5: {  // Reserve a Ticket
                int id;
                printf("Enter Movie ID to reserve: ");
                scanf("%d", &id);

                int index = searchMovie(&movieStack, id);
                if (index != -1) {
                    if (movieStack.m[index].seats == 0) {
                        enqueue(&movieStack.m[index].reservationQueue, id);
                        printf("Reservation made successfully. You are in position %d in the queue.\n", movieStack.m[index].reservationQueue.size);
                    } else {
                        printf("Tickets are still available for this movie.\n");
                    }
                } else {
                    printf("Movie not found.\n");
                }
                break;
            }
            case 6: {  // Cancel a Ticket
                int id;
                printf("Enter Movie ID to cancel: ");
                scanf("%d", &id);

                int index = searchMovie(&movieStack, id);
                if (index != -1) {
                    if (movieStack.m[index].seats < 100) {  // Assuming seats can't exceed 100
                        movieStack.m[index].seats++;
                        printf("Ticket canceled successfully.\n");
                        if (!isQueueEmpty(&movieStack.m[index].reservationQueue)) {
                            int reservedID = dequeue(&movieStack.m[index].reservationQueue);
                            printf("Ticket automatically assigned to the next person in the reservation queue.\n");
                        }
                        displayCollection(&movieStack);
                    } else {
                        printf("No tickets to cancel.\n");
                    }
                } else {
                    printf("Movie not found.\n");
                }
                break;
            }
            case 7:  // Exit
                printf("Exiting program!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 7);

    return EXIT_SUCCESS;
}