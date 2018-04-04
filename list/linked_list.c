#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node{
	element data;
	struct Node * link;
}Node;

typedef struct List{
	Node * head;
}List;

void init_list(List *list) {
	list->head = NULL;
}

Node *find_last_node(List *list) {
	Node *currentNode;
	currentNode = (Node *)malloc(sizeof(Node));

	currentNode = list->head;
	while (currentNode->link != NULL) {
		currentNode = currentNode->link;
	}
	return currentNode;
}

Node *create_node(element value, Node *next) {
	Node *newNode;
	newNode = (Node *)malloc(sizeof(Node));

	newNode->data = value;
	newNode->link = next;
	return newNode;
}


void append_list(List *list, element value) {
	Node *lastNode = (Node *)malloc(sizeof(Node));
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode = create_node(value, NULL);

	if (list->head == NULL) {
		list->head = newNode;
	} else {	
		lastNode = find_last_node(list);
		lastNode->link = newNode;
	}
}


void display_list(List *list) {
	Node *currentNode;
	currentNode = (Node *)malloc(sizeof(Node));
	
	currentNode = list->head;
	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->link;
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
