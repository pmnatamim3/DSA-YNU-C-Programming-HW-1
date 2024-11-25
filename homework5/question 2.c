#include <stdio.h>
#define MAX 100
// NAT0056

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    if (rear == MAX - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d\n", element);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete an element.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Initialize a queue!");
    printf("\nInsert some elements into the queue:\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    displayQueue();
    printf("\nDelete an element from the said queue:\n");
    dequeue();
    displayQueue();
    printf("\nInsert another element into the queue:\n");
    enqueue(4);
    displayQueue();

    return 0;
}