#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// NAT0056

struct PrintJob {
    char document[100];
    int pages;
    struct PrintJob* next;
};

struct PrinterQueue {
    struct PrintJob* front;
    struct PrintJob* rear;
};

void initializeQueue(struct PrinterQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void addJob(struct PrinterQueue* queue, const char* document, int pages) {
    struct PrintJob* newJob = (struct PrintJob*)malloc(sizeof(struct PrintJob));
    strcpy(newJob->document, document);
    newJob->pages = pages;
    newJob->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newJob;
        return;
    }

    queue->rear->next = newJob;
    queue->rear = newJob;
}

void processJob(struct PrinterQueue* queue) {
    if (queue->front == NULL) {
        printf("No jobs in the queue.\n");
        return;
    }

    struct PrintJob* jobToProcess = queue->front;
    printf("Processing job: %s with %d pages.\n", jobToProcess->document, jobToProcess->pages);
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(jobToProcess);
}

void viewNextJob(struct PrinterQueue* queue) {
    if (queue->front == NULL) {
        printf("No jobs in the queue.\n");
        return;
    }

    printf("Next job to be processed: %s with %d pages.\n", queue->front->document, queue->front->pages);
}

int isQueueEmpty(struct PrinterQueue* queue) {
    return queue->front == NULL;
}

int main() {
    struct PrinterQueue queue;
    initializeQueue(&queue);

    addJob(&queue, "Report.pdf", 10);
    addJob(&queue, "Invoice.docx", 3);
    viewNextJob(&queue);

    processJob(&queue);
    viewNextJob(&queue);

    processJob(&queue);
    processJob(&queue);

    return 0;
}