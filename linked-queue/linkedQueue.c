//
//  linkedQueue.c
//  Linked-Queue
//
//  Created by POTADOS on 2018. 5. 2..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "linkedQueue.h"

Queue new_Queue(void) {
    Queue newQueue = (Queue)malloc(sizeof(_Queue));
    newQueue->init = Queue_init;
    newQueue->init(newQueue);
    return newQueue;
}

void Queue_init(Queue self) {
    self->front = NULL;
    self->rear = NULL;
    
    self->init = Queue_init;
    self->isEmpty = Queue_isEmpty;
    self->enqueue = Queue_enqueue;
    self->dequeue = Queue_dequeue;
}

int Queue_isEmpty(Queue self) {
    return ((self->front == NULL) || (self->rear == NULL));
}

void Queue_enqueue(Queue self, element data) {
    Node node = newNode(data, NULL);
    if (self->isEmpty(self)) {
        self->front = node;
        self->rear = node;
    }
    else {
        self->rear->link = node; /* link new node */
        self->rear = node; /* make new node rear node */
    }
}

element Queue_dequeue(Queue self) {
    if (self->isEmpty(self))
        error("Queue is empty\n");
    
    Node node = self->front;
    int data = node->data;
    
    if (node->link == NULL)
        self->rear = NULL;
    else
        self->front = node->link;
    
    free(node);
    return data;
}

Node newNode(element data, Node link) {
    Node node = (Node)malloc(sizeof(_Node));
    node->data = data;
    node->link = link;
    return node;
}

void error(char *message) {
    fprintf(stderr, "%s", message);
    exit(1);
}

