#include <stdio.h>
#include <stdlib.h>
// NAT0056

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

int isEmpty() {
    if (front == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Initialize a queue!");
    if (isEmpty()) {
        printf("\nCheck the queue is empty or not? Yes\n");
    } else {
        printf("\nCheck the queue is empty or not? No\n");
    }
    printf("\nInsert some elements into the queue:\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    displayQueue();
    printf("\nInsert another element into the queue:\n");
    enqueue(4);
    displayQueue();
    if (isEmpty()) {
        printf("\nCheck the queue is empty or not? Yes\n");
    } else {
        printf("\nCheck the queue is empty or not? No\n");
    }
    return 0;
}