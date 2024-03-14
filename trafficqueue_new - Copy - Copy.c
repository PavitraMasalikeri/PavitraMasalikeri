#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
bool isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to add a vehicle to the rear of the queue
void enqueue(struct Queue* queue, int vehicle) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot add more vehicles.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = vehicle;
        printf("Vehicle %d joined the queue.\n", vehicle);
    }
}

// Function to remove a vehicle from the front of the queue
int dequeue(struct Queue* queue) {
    int vehicle;
    if (isEmpty(queue)) {
        printf("Queue is empty. No vehicles to dequeue.\n");
        return -1;
    } else {
        vehicle = queue->items[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        printf("Vehicle %d crossed the signal.\n", vehicle);
        return vehicle;
    }
}

// Function to display the vehicles in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Vehicles in the queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue* trafficSignal = createQueue();

    enqueue(trafficSignal, 1);
    enqueue(trafficSignal, 2);
    enqueue(trafficSignal, 3);

    display(trafficSignal);

    dequeue(trafficSignal);
    dequeue(trafficSignal);

    display(trafficSignal);

    return 0;
}


