# data-structure
A study of data structure, implemented by C

# Source tree

## lists
Implementation of linked list.

- linked_list.h
- linked_list.c

## util
Utilities for implementing other functions.

- error.h
- error.c
- literal.h
- literal.c

## test
Sources for testing. Includes main() in test.c.

- linked_list_test.h
- linked_list_test.c
- test.c

# Specifications

## Linked list

#### structs
```c
typedef DATATYPE element;
```
```c
typedef struct Node {
    element data;
    struct Node * nextNode;
} Node;
```
```c
typedef struct List {
    Node * head;
} List;
```

#### functions
```c
Node *create_node(element value, Node *next);
```
It creates new `Node` variable with data and link to next node and returns the new node.

```c
Node *find_node(List *list, int index);
```
It searches for node by the index in the given list and returns the node found in it. The returned value is always NOT `NULL`. If there are `NULL` node in the middle of the list (usually cannot happen) or the given index is out of range, program exits with error message. 
