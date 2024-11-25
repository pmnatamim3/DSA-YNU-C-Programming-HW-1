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

void deleteNthElement(Queue* q, int n) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    if (n <= 0 || n > (q->rear - q->front + 1)) {
        printf("Error: Invalid position\n");
        return;
    }

    for (int i = 1; i < n; i++) {
        dequeue(q);
    }

    dequeue(q);

    printf("Queue elements are:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
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

    printf("Insert some elements into the queue:\n");
    display(q);

    printf("\nDelete the 7th element of the said queue:\n");
    deleteNthElement(q, 7);

    printf("\nDelete the 3rd element of the said queue:\n");
    deleteNthElement(q, 3);

    return 0;
}