//
//  arrayList.h
//  data-structure
//
//  Created by potados on 2018. 3. 25..
//  Copyright © 2018 potados. All rights reserved.
//

#ifndef arrayList_h
#define arrayList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int *dataSet;
    int size;
} List;

void init_list(List *list);

void append_list(List *list, int element);

void extend_list(List *list1, List *list2);

void print_list(List *list);

#endif /* arrayList_h */
