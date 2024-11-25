#include <stdio.h>
#include <stdlib.h>
// NAT0056

struct Node {
    int data;
    struct Node* next;
};


struct Node* allocateNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}



void insert(struct Node** head, int data) {
    struct Node* newNode = allocateNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp;
        for (temp = *head; temp->next != NULL; temp = temp->next);
        temp->next = newNode;
    }
}



void deleteElement(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (; temp != NULL && temp->data != value; prev = temp, temp = temp->next);

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("List after insertion:\n");
    traverse(head);

    deleteElement(&head, 3);
    printf("List after deletion:\n");
    traverse(head);

    freeList(head);

    return 0;
}