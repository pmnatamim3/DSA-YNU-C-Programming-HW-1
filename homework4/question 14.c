 #include <stdio.h>
#include <stdlib.h>
// NAT0056

typedef struct node {
    int data;
    int sum;
    struct node* next;
} Node;
typedef struct stack {
    Node* top;
    int size;
} Stack;

void init(Stack* s) {
    s->top = NULL;
    s->size = 0;
}
void push(Stack* s, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->sum = (s->top == NULL) ? value : s->top->sum + value;
    new_node->next = s->top;
    s->top = new_node;
    s->size++;
}
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    int value = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    s->size--;
    free(temp);
    return value;
}
float get_average(Stack* s) {
    if (s->size == 0) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    return (float) s->top->sum / s->size;
}
void printStack(Stack* s) {
    if (s->size == 0) {
        printf("Stack is empty\n");
        return;
    }

    struct node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    float avg_val;
    Stack s;
    init(&s);
    push(&s, 1);
    push(&s, 3);
    push(&s, 5);
    push(&s, 2);
    push(&s, 4);
    push(&s, 6);
    printf("Elements of the stack:\n");
    printStack(&s);
    avg_val = get_average(&s);
    printf("Average of the said stack values: %0.2f\n", avg_val);
    int popped_value = pop(&s);
    printf("\nPopped value: %d\n", popped_value);
    printf("\nElements of the stack:\n");
    printStack(&s);
    avg_val = get_average(&s);
    printf("Average of the said stack values: %0.2f\n", avg_val);
    return 0;
}