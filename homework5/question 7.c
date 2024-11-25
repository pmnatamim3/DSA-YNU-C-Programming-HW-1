#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
// NAT0056

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

int sumQueue(Queue* q) {
    int sum = 0;
    for (int i = q->front; i <= q->rear; i++) {
        sum += q->items[i];
    }
    return sum;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Queue elements are:\n");
    display(q);
    printf("Sum of the elements in the queue is: %d\n", sumQueue(q));

    printf("Remove 2 elements from the said queue:\n");
    dequeue(q);
    dequeue(q);
    display(q);
    printf("Sum of the elements in the queue is: %d\n", sumQueue(q));

    printf("Insert 3 more elements:\n");
    enqueue(q, 300);
    enqueue(q, 400);
    enqueue(q, 500);
    display(q);
    printf("Sum of the elements in the queue is: %d\n", sumQueue(q));

    return 0;
}