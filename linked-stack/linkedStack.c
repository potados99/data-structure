//
//  linkedStack.c
//  linked-stack
//
//  Created by POTADOS on 2018. 6. 10..
//  Copyright © 2018년 POTADOS. All rights reserved.
//

#include "linkedStack.h"

Stack new_Stack() {
    Stack myStack = (Stack)malloc(sizeof(_Stack));
    myStack->top = NULL;
    
    return myStack;
}


void Stack_push(Stack self, StackElement data) {
    self->top = newNode(data, self->top);
}

StackElement Stack_pop(Stack self) {
    if (! self->top) {
        error("Stack empty.\n");
    }
    StackNode willBePoped = self->top;
    StackElement value = self->top->data;
    self->top = self->top->link;
    
    free(willBePoped);
    return value;
}



StackNode newNode(StackElement data, StackNode link) {
    StackNode newNode = (StackNode)malloc(sizeof(_StackNode));
    
    newNode->data = data;
    newNode->link = link;
    
    return newNode;
}

void error(char *message) {
    
}
