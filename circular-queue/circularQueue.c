//
//  circularQueue.c
//  Queue
//
//  Created by POTADOS on 2018. 5. 2..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "circularQueue.h"

void init(Queue *self) {
    self->front = 0;
    self->rear = 0;
    unsigned short i;
    for (i = 0; i < SIZE; i ++) {
        self->q[i] = '\0';
    }
}

void enqueue(Queue *self, element data) {
    if (self->front == (self->rear + 1) % SIZE)
        error("Queue full");

    self->q[self->rear = rightIndex(++self->rear)] = data;
}

element dequeue(Queue *self) {
    if (self->rear == self->front)
        error("Queue empty");
    
    char data = self->q[self->front = rightIndex(self->front + 1)];
    self->q[self->front] = '\0';
    
    return data;
}

void look(Queue *myQueue) {
    unsigned short i;
    printf("\n{front: %d, rear: %d}\n", myQueue->front, myQueue->rear);
    for (i = 0; i < SIZE; i ++) {
        printf("[%d, %c] ", i, myQueue->q[i]);
    }
    printf("\n\n");
}

void error(char *message) {
    fprintf(stderr, "%s", message);
    exit(1);
}

int rightIndex(int index) {
    return (index) % SIZE;
}

