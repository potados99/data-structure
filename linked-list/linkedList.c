//
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include "linked_list.h"


#pragma mark - List methods

void init_list(List *list) {
    list->head = NULL;
    return;
}

void append_list(List *list, element value) {
	if (isEmpty(list)) {
		list->head = create_node(value, NULL);
        return;
    }
    
    Node *lastNode = find_last_node(list);
    Node *newNode = create_node(value, NULL);
    
    lastNode->nextNode = newNode;
    return;
}

void insert_list(List *list, const int index, element value) {
    if (isEmpty(list))
        error(LIST_EMPTY);
    
    if (index == 0) {
        list->head = create_node(value, list->head);
        return;
    }
    
    unsigned const int safeIndex = get_safe_index(list, index);
    Node *beforeNode = find_node(list, safeIndex - 1);
    Node *newNode = create_node(value, beforeNode->nextNode);

    beforeNode->nextNode = newNode;
    return;
}

element pop_list(List *list, const int index) {
    if (isEmpty(list))
        error(LIST_EMPTY);
    
    if (index == 0) {
        Node *nextNode = list->head->nextNode;
        const int value = list->head->data;
        
        free(list->head);
        list->head = NULL;
        list->head = nextNode;
        
        return value;
    }
    
    Node *beforeNode = find_node(list, index - 1);
    Node *currentNode = beforeNode->nextNode;
    const int value = currentNode->data;
    
    beforeNode->nextNode = currentNode->nextNode;
    
    free(currentNode);
    currentNode = NULL;
    
    return value;
}

void print_list(List *list) {
    if (isEmpty(list)) {
        printf("[]\n");
        return;
    }
    
	Node *currentNode = list->head;

    printf("[");

    while (currentNode->nextNode != NULL) {
        printf("%d, ", currentNode->data);
        currentNode = currentNode->nextNode;
    }
    
    printf("%d]\n", currentNode->data);
    return;
}


#pragma mark - List functions

int isEmpty(List *list) {
    return (list->head == NULL);
}

int get_length(List *list) {
    if (isEmpty(list))
        return 0;
    
    Node *currentNode = list->head;
    register unsigned int currentIndex = 1;
    
    while (currentNode->nextNode != NULL) {
        currentNode = currentNode->nextNode;
        currentIndex ++;
    }
    
    return currentIndex;
}

int get_safe_index(List *list, const int index) {
    unsigned const int length = get_length(list);
    unsigned int safeIndex = 0;
    
    if (index < 0) {
        if ((index * -1) > length)
            error(INDEX_OUT);
        safeIndex = length + index;
    } else {
        if (index > length - 1)
            error(INDEX_OUT);
        safeIndex = index;
    }
    
    return safeIndex;
}

element get_value(List *list, int index) {
    Node *node = find_node(list, index);

    return node->data;
}


#pragma mark - Node functions

Node *create_node(element value, Node *next) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    
    newNode->data = value;
    newNode->nextNode = next;
    
    return newNode;
}

Node *find_node(List *list, int index) {
    if (isEmpty(list))
        error(LIST_EMPTY);
    
    Node *currentNode = list->head;
    
    unsigned const int safeIndex = get_safe_index(list, index);
    register unsigned int i = 0;

    for (i = safeIndex; i != 0; i --) {
        currentNode = currentNode->nextNode;
        if (currentNode == NULL)
            error(NODE_EMPTY);
    }
    
    return currentNode;
}

Node *find_last_node(List *list) {
    if (isEmpty(list))
        error(INDEX_OUT);
    
    Node *currentNode = (Node *)malloc(sizeof(Node));
    
    currentNode = list->head;
    
    while (currentNode->nextNode != NULL)
        currentNode = currentNode->nextNode;
    
    return currentNode;
}


#pragma mark - Utils

void error(char *mes) {
    fprintf(stderr, "%s\n", mes);
    exit(1);
}
