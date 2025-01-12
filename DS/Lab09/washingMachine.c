#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>

typedef struct Node {
    char name[50];
    int duration;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

void addBooking(const char* name, int duration) {
    Node* newBooking = (Node*)malloc(sizeof(Node));
    strcpy(newBooking->name, name);
    newBooking->duration = duration;
    newBooking->next = newBooking;
    newBooking->prev = newBooking;

    if (head == NULL) {
        head = newBooking;
        head->next = head;
        head->prev = head;
    } else {
        Node* last = head->prev;
        last->next = newBooking;
        newBooking->prev = last;
        newBooking->next = head;
        head->prev = newBooking;
    }
}

void processBookings() {
    if (head == NULL) {
        printf("No bookings in the queue.\n");
        return;
    }
    
    Node* current = head;
    
    while (current != NULL) {
        printf("Washing machine booked by %s for %d seconds.\n", current->name, current->duration);
        sleep(current->duration);
        printf("Washing machine handed over to the next person in the queue.\n");

        Node* toFree = current;
        current = current->next;

        if (toFree == head && toFree->next == head) {
            head = NULL;
            free(toFree);
            break;
        } else {
            if (toFree == head) {
                head = head->next;
            }
            toFree->prev->next = toFree->next;
            toFree->next->prev = toFree->prev;
            free(toFree);
        }

        if (current == head) break;
    }
}

void printBookings() {
    if (head == NULL) {
        printf("No bookings in the queue.\n");
        return;
    }
    
    Node* current = head;
    do {
        printf("Name: %s, Duration: %d seconds\n", current->name, current->duration);
        current = current->next;
    } while (current != head);
}

int main() {
    int choice, duration;
    char name[50];

    while (1) {
        printf("\nWashing Machine Renting System\n");
        printf("1. Book a washing machine\n");
        printf("2. Process bookings\n");
        printf("3. Print current bookings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter duration in seconds: ");
                scanf("%d", &duration);
                addBooking(name, duration);
                break;
            case 2:
                processBookings();
                break;
            case 3:
                printBookings();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }    
    return EXIT_SUCCESS;
}
