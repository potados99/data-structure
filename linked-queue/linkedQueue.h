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

typedef void* queueElement;

typedef struct _QueueNode {
    queueElement data;
    struct _QueueNode *link;
    
} _QueueNode;
typedef _QueueNode* QueueNode;

typedef struct _Queue {
    QueueNode front;
    QueueNode rear;
    
    void (*init)(struct _Queue *);
    int (*isEmpty)(struct _Queue *);
    void (*enqueue)(struct _Queue *, queueElement);
    queueElement (*dequeue)(struct _Queue *);
    
} _Queue;
typedef _Queue* Queue;

Queue new_Queue(void);

void Queue_init(Queue self);
int Queue_isEmpty(Queue self);
void Queue_enqueue(Queue self, queueElement data);
queueElement Queue_dequeue(Queue self);

QueueNode newNode(queueElement data, QueueNode link);
void error(char *message);

#endif /* linkedQueue_h */
