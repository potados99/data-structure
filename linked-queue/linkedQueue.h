//
//  linkedQueue.h
//  Linked-Queue
//
//  Created by POTADOS on 2018. 5. 2..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#ifndef linkedQueue_h
#define linkedQueue_h

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct _Node {
    element data;
    struct _Node *link;
    
} _Node;
typedef _Node* Node;

typedef struct _Queue {
    Node front;
    Node rear;
    
    void (*init)(struct _Queue *);
    int (*isEmpty)(struct _Queue *);
    void (*enqueue)(struct _Queue *, element);
    element (*dequeue)(struct _Queue *);
    
} _Queue;
typedef _Queue* Queue;

Queue new_Queue(void);

void Queue_init(Queue self);
int Queue_isEmpty(Queue self);
void Queue_enqueue(Queue self, element data);
element Queue_dequeue(Queue self);

Node newNode(element data, Node link);
void error(char *message);

#endif /* linkedQueue_h */
