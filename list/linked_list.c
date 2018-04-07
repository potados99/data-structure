//
//  linked_list.c
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include "linked_list.h"
#include "error.h"
#include "literal.h"

#pragma mark - Node functions

Node *create_node(element value, Node *next) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->nextNode = next;

    return newNode;
}

Node *find_node(List *list, int index) {
    if (isEmpty(list)) {
        error(listEmpty);
    }
    
    int safeIndex = get_safe_index(list, index);
    int currentIndex = 0;
    Node *currentNode = list->head;
    /* When length is 1 */

    while (currentIndex < safeIndex) {
            currentNode = currentNode->nextNode;
            currentIndex ++;
            if (currentNode == NULL)
                error(nodeEmpty);
            /* When length is bigger than 1 */
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


#pragma mark - List methods

void init_list(List *list) {
    list->head = NULL;
}

void append_list(List *list, element value) {
    Node *newNode = create_node(value, NULL);

	if (isEmpty(list)) {
		list->head = newNode;
	} else {
        Node *lastNode = find_last_node(list);
		lastNode->nextNode = newNode;
	}
}

void insert_list(List *list, int index, element value) {
    Node *oldNode = find_node(list, index);
    Node *newNode = create_node(value, oldNode->nextNode);

    oldNode->nextNode = newNode;
}

element pop_list(List *list, int index) {
    if (isEmpty(list))
        error(listEmpty);
    
    int value = 0;
    
    if (index == 0) {
        Node *nextNode = list->head->nextNode;
        
        value = list->head->data;
        
        free(list->head);
        list->head = NULL;
        list->head = nextNode;
        
        return value;
    }
    
    Node *beforeNode = find_node(list, index - 1);
    Node *currentNode = beforeNode->nextNode;
    
    value = currentNode->data;
    beforeNode->nextNode = currentNode->nextNode;
    
    free(currentNode);
    currentNode = NULL;
    
    return value;
}


void print_list(List *list) {
	Node *currentNode = list->head;

    printf("[");
    if (! isEmpty(list)) {
        while (currentNode->nextNode != NULL) {
            printf("%d, ", currentNode->data);
            currentNode = currentNode->nextNode;
        }
        printf("%d", currentNode->data);
    }
    printf("]\n");
}


#pragma mark - List functions

int isEmpty(List *list) {
    return (list->head == NULL);
}

int get_safe_index(List *list, int index) {
    int length = get_length(list);
    int safeIndex = 0;
    
    if (index < 0) {
        if ((index * -1) > length)
            error(indexOut);
        safeIndex = length + index;
    }
    else {
        if (index > length - 1)
            error(indexOut);
        safeIndex = index;
    }
    
    return safeIndex;
}

int get_value(List *list, int index) {
    Node *node = find_node(list, index);

    return node->data;
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
