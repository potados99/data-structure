//
//  linked_list.c
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include "linked_list.h"
#include "../util/error.h"
#include "../util/literal.h"


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

void insert_list(List *list, int index, element value) {
    if (isEmpty(list))
        error(listEmpty);
    
    if (index == 0) {
        list->head = create_node(value, list->head);
        return;
    }
    
    int safeIndex = get_safe_index(list, index);
    Node *beforeNode = find_node(list, safeIndex - 1);
    Node *newNode = create_node(value, beforeNode->nextNode);

    beforeNode->nextNode = newNode;
    return;
}

element pop_list(List *list, int index) {
    if (isEmpty(list))
        error(listEmpty);
    
    if (index == 0) {
        Node *nextNode = list->head->nextNode;
        int value = list->head->data;
        
        free(list->head);
        list->head = NULL;
        list->head = nextNode;
        
        return value;
    }
    
    Node *beforeNode = find_node(list, index - 1);
    Node *currentNode = beforeNode->nextNode;
    int value = currentNode->data;
    
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
    int currentIndex = 1;
    
    while (currentNode->nextNode != NULL) {
        currentNode = currentNode->nextNode;
        currentIndex ++;
    }
    
    return currentIndex;
}

int get_safe_index(List *list, int index) {
    int length = get_length(list);
    int safeIndex = 0;
    
    if (index < 0) {
        if ((index * -1) > length)
            error(indexOut);
        safeIndex = length + index;
    } else {
        if (index > length - 1)
            error(indexOut);
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
        error(listEmpty);
    
    Node *currentNode = list->head;
    int currentIndex = 0;
    int safeIndex = get_safe_index(list, index);
    
    while (currentIndex < safeIndex) {
        currentNode = currentNode->nextNode;
        currentIndex ++;
        if (currentNode == NULL)
            error(nodeEmpty);
    }
    
    return currentNode;
}

Node *find_last_node(List *list) {
    if (isEmpty(list))
        error(indexOut);
    
    Node *currentNode = (Node *)malloc(sizeof(Node));
    
    currentNode = list->head;
    
    while (currentNode->nextNode != NULL)
        currentNode = currentNode->nextNode;
    
    return currentNode;
}
