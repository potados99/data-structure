//
//  circularQueue.h
//  Queue
//
//  Created by POTADOS on 2018. 5. 2..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef circularQueue_h
#define circularQueue_h

#define SIZE 8

#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct _queue {
    element q[SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *self);

void enqueue(Queue *self, element data);

element dequeue(Queue *self);

void look(Queue *myQueue);

void error(char *message);

int rightIndex(int index);

#endif /* circularQueue_h */
