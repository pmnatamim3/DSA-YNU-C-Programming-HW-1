#include <stdio.h>
// NAT0056

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(3);

    printf("Elements in the stack are: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
    return 0;
}