//
//  linked_list.h
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>

#define DATATYPE int

#define INDEX_OUT "Index out of range."
#define NODE_EMPTY "Node is empty."
#define LIST_EMPTY "List is empty."


#pragma mark - Structures

typedef DATATYPE element;

typedef struct Node {
    element data;
    struct Node * nextNode;
}Node;

typedef struct List {
    Node * head;
}List;


#pragma mark - List methods

void init_list(List *list);
void append_list(List *list, element value);
void insert_list(List *list, const int index, element value);
element pop_list(List *list, const int index);
void print_list(List *list);


#pragma mark - List functions

int isEmpty(List *list);
int get_length(List *list);
int get_safe_index(List *list, const int index);
element get_value(List *list, const int index);


#pragma mark - Node functions

Node *create_node(element value, Node *next);
Node *find_node(List *list, const int index);
Node *find_last_node(List *list);


#pragma mark - Utils

void error(char *mes);


#endif /* linked_list_h */
