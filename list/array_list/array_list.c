//
//  array_list.c
//  data-structure
//
//  Created by potados on 2018. 3. 25..
//  Copyright © 2018 potads. All rights reserved.
//

#include "array_list.h"

void init_list(List *list) {
    list->size = 0;
    list->dataSet = (int*) malloc(sizeof(int)*0);
}

void append_list(List *list, const int element) {
    list->dataSet = (int*) realloc(list->dataSet, sizeof(int)*(list->size + 1));
    list->dataSet[list->size ++] = element;
}

void extend_list(List *list1, List *list2) {
    int i = 0;
    for (i = 0; i <= list2->size - 1; i ++) {
        append_list(list1, list2->dataSet[i]);
    }
}

void print_list(List *list) {
    printf("[");
    int i = 0;
    for (i = 0; i <= list->size - 1; i ++) {
        if (i == list->size - 1) {
            printf("%d", list->dataSet[i]);
        } else {
            printf("%d, ", list->dataSet[i]);
        }
    }
    printf("]");
}

