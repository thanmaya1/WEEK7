#include <stdio.h>
#include <stdlib.h>

/* structure to represent a bogie */
typedef struct Bogie {
    int id;
    struct Bogie *next;
} Bogie;

/* structure to represent a queue of bogies */
typedef struct Queue {
    Bogie *front;
    Bogie *rear;
} Queue;

/* function to create an empty queue */
Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/* function to create a new bogie with given id */
Bogie *createBogie(int id) {
    Bogie *bogie = (Bogie *) malloc(sizeof(Bogie));
    bogie->id = id;
    bogie->next = NULL;
    return bogie;
}

/* function to insert a bogie at the rear of the queue */
void enqueue(Queue *queue, int id) {
    Bogie *bogie = createBogie(id);
    if (queue->rear == NULL) {
        queue->front = bogie;
        queue->rear = bogie;
    } else {
        queue->rear->next = bogie;
        queue->rear = bogie;
    }
    printf("Bogie %d added to the queue.\n", id);
}

/* function to remove a bogie from the front of the queue */
void dequeue(Queue *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Bogie *bogie = queue->front;
    queue->front = bogie->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("Bogie %d removed from the queue.\n", bogie->id);
    free(bogie);
}

/* function to search for a bogie in the queue */
void search(Queue *queue, int id) {
    Bogie *bogie = queue->front;
    while (bogie != NULL) {
        if (bogie->id == id) {
            printf("Bogie %d found in the queue.\n", id);
            return;
        }
        bogie = bogie->next;
    }
    printf("Bogie %d not found in the queue.\n", id);
}

/* function to display the bogies in the queue */
void display(Queue *queue) {
    Bogie *bogie = queue->front;
    if (bogie == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Bogies in the queue: ");
    while (bogie != NULL) {
        printf("%d ", bogie->id);
        bogie = bogie->next;
    }
    printf("\n");
}

/* main function to test the queue operations */
int main() {
    Queue *queue = createQueue();
    int choice, id;
    do {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter bogie id to enqueue: ");
                scanf("%d", &id);
                enqueue(queue, id);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Enter bogie id to search: ");
scanf("%d", &id);
search(queue, id);
break;
case 4:
display(queue);
break;
case 5:
printf("Exiting.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 5);
return 0;
}

