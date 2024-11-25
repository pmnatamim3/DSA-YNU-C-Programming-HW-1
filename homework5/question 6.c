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

void reverse_queue(Queue* q) {
    int temp[MAX_SIZE];
    int top = -1;

    while (!isEmpty(q)) {
        temp[++top] = dequeue(q);
    }

    while (top != -1) {
        enqueue(q, temp[top--]);
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
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("Queue elements are:\n");
    display(q);
    printf("Reverse Queue, elements are:\n");
    reverse_queue(q);
    display(q);
    enqueue(q, 100);
    enqueue(q, 200);
    printf("Add two elements to the said queue:\n");    
    printf("Queue elements are:\n");
    display(q);
    printf("Reverse Queue, elements are:\n");
    reverse_queue(q);
    display(q);
    return 0;
}