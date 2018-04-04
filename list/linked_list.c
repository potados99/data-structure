//
//  linked_list.c
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include "linked_list.h"

#pragma mark - Node functions

Node *find_last_node(List *list) {
	Node *currentNode = (Node *)malloc(sizeof(Node));
	currentNode = list->head;
    
	while (currentNode->nextNode != NULL)
		currentNode = currentNode->nextNode;
	
    return currentNode;
}

Node *create_node(element value, Node *next) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = value;
	newNode->nextNode = next;

    return newNode;
}


#pragma mark - List methods

void init_list(List *list) {
    list->head = NULL;
}

void append_list(List *list, element value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
	Node *lastNode = (Node *)malloc(sizeof(Node));
    newNode = create_node(value, NULL);

	if (list->head == NULL) {
		list->head = newNode;
	} else {	
		lastNode = find_last_node(list);
		lastNode->nextNode = newNode;
	}
}

void display_list(List *list) {
	Node *currentNode = (Node *)malloc(sizeof(Node));
	currentNode = list->head;
    
	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	}
}


int main() {

	List myList;

	init_list(&myList);

	int input = 0;
	printf("input integer: ");
	scanf("%d", &input);
	while (input != 0) {
		append_list(&myList, input);
		
		printf("input integer: ");
		scanf("%d", &input);		
	}

	display_list(&myList);
	printf("\n");

}
