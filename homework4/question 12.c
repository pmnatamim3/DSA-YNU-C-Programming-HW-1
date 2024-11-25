#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 100
// NAT0056

int mainStack[MAX_SIZE];
int maxStack[MAX_SIZE];
int top = -1;
int max_top = -1;

void push(int ele) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    top++;
    mainStack[top] = ele;

    if (max_top == -1 || ele >= maxStack[max_top]) {
        max_top++;
        maxStack[max_top] = ele;
    }
}
int pop() {
    if (top < 0) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    int ele = mainStack[top];
    top--;
    if (ele == maxStack[max_top]) {
        max_top--;
    }

    return ele;
}
int getMax() {
    if (max_top < 0) {
        printf("Stack is empty\n");
        return INT_MIN;
    }

    return maxStack[max_top];
}
void printstack(int *stack) {
    printf("Current stack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}

int main() {
    push(5);
    push(2);
    push(1);
    push(6);
    push(8);
    printstack(mainStack);
    printf("\nMaximum element: %d\n", getMax()); 
    pop();
    pop();
    printf("\nAfter removing two elements:\n");
    printstack(mainStack);
    printf("\nMaximum element: %d\n", getMax());  
    push(10);
    printf("\nAfter adding one element:\n");
    printstack(mainStack);
    printf("\nMaximum element: %d\n", getMax());      
    return 0;
}