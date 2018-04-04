# data-structure
A study of data structure, implemented by C

# Source tree

## /lists
Implementation of linked list.

- /linked_list.h
- /linked_list.c

## /util
Utilities for implementing other functions.

- /error.h
- /error.c
- /literal.h
- /literal.c

## /test
Sources for testing. Includes main() in test.c.

- /linked_list_test.h
- /linked_list_test.c
- /test.c

# Specifications

## Linked list

### structs
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

### node functions
```c
Node *create_node(element value, Node *next);
```
Creates new `Node` variable with data and link to next node and returns the new node.

```c
Node *find_node(List *list, int index);
```
Searches for node by the index in the given list and returns the node found in it. The returned value is always NOT `NULL`. If there are `NULL` node in the middle of the list (usually cannot happen) or the given index is out of range, program exits with error message.

```c
Node *find_last_node(List *list);
```
Returns the last node of the list. It checks the link of every single node for whether `NULL` or not. Until It meets the last node, which the link is `NULL`, it checks next node and next...

### list methods
```c
void init_list(List *list);
```
Initializes `list`. It assigns `NULL` to the header of the list.

```c
void append_list(List *list, element value);
```
Appends an integer to the list. It creates a new node with data of `value` and appends it to the last node.

```c
void insert_list(List *list, int index, element value);
```
Inserts an integer to a specific index. It finds the node at `index` and appends a new node (which is created with data of `value`) to it.

```c
void print_list(List *list);
```
Displays list with form of `[element1, element2, ...]`.

### list functions
```c
int isEmpty(List *list);
```
Check if the list is empty and returns 1 if empty. If the head of the list is `NULL`, the list is considered empty.

```c
int get_value(List *list, int index);
```
Finds node at `index` and returns data of the node. It uses `find_node` function.

```c
int len_list(List *list);
```
It counts the number of nodes. It is similar to `find_last_node` function but it counts the number of nodes and returns it.
