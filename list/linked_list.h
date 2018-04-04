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


#pragma mark - Structures

typedef DATATYPE element;

typedef struct Node {
    element data;
    struct Node * nextNode;
} Node;

typedef struct List {
    Node * head;
} List;


#pragma mark - Node functions

Node *find_last_node(List *list);
Node *create_node(element value, Node *next);


#pragma mark - List methods

void init_list(List *list);
void append_list(List *list, element value);
void display_list(List *list);


#endif /* linked_list_h */
