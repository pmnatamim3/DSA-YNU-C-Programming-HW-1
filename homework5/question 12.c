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

void sortQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int temp[MAX_SIZE];
    int count = 0;

    while (!isEmpty(q)) {
        temp[count++] = dequeue(q);
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (temp[i] > temp[j]) {
                int tempVal = temp[i];
                temp[i] = temp[j];
                temp[j] = tempVal;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        enqueue(q, temp[i]);
    }
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

    enqueue(q, 4);
    enqueue(q, 2);
    enqueue(q, 7);
    enqueue(q, 5);
    enqueue(q, 1);

    printf("Input some elements into the queue:\n");
    printf("Elements of the queue:\n");
    display(q);

    printf("Sort the said queue:\n");
    sortQueue(q);
    printf("Elements of the sorted queue in ascending order:\n");
    display(q);

    enqueue(q, -1);
    enqueue(q, 3);

    printf("Input two more elements into the queue:\n");
    printf("Elements of the queue:\n");
    display(q);

    printf("Sort the said queue:\n");
    sortQueue(q);
    printf("Elements of the sorted queue in ascending order:\n");
    display(q);

    return 0;
}