#include <stdio.h>
#include <stdlib.h>
// NAT0056

#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
    printf("Initialize a queue!\n");
}

int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
    }
}

void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    if (isEmpty(&q)) {
        printf("Check the queue is empty or not? Yes\n");
    } else {
        printf("Check the queue is empty or not? No\n");
    }

    printf("\nInsert some elements into the queue:\n");
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    displayQueue(&q);

    printf("\nInsert another element into the queue:\n");
    enqueue(&q, 4);
    displayQueue(&q);

    if (isEmpty(&q)) {
        printf("\nCheck the queue is empty or not? Yes\n");
    } else {
        printf("\nCheck the queue is empty or not? No\n");
    }

    return 0;
}