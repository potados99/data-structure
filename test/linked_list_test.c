//
//  linked_list_test.c
//  data-structure
//
//  Created by MacBoogy on 2018. 4. 4..
//  Copyright © 2018년 MacBoogy. All rights reserved.
//

#include "linked_list_test.h"
#include "linked_list.h"

void append_test() {
    List myList;
    
    init_list(&myList);
    
    int input = 0;
    printf("input integer: ");
    scanf("%d", &input);
    while (input != -99) {
        append_list(&myList, input);
        
        printf("input integer: ");
        scanf("%d", &input);
    }
    
    print_list(&myList);
    printf("\n");
}

void insert_test() {
    List myList;
    
    init_list(&myList);
    
    int input = 0;
    printf("input integer: ");
    scanf("%d", &input);
    while (input != -99) {
        append_list(&myList, input);
        
        printf("input integer: ");
        scanf("%d", &input);
    }
    
    print_list(&myList);
    printf("\n");
}

void get_test() {
    List myList;
    
    init_list(&myList);
    
    int val = 0;
    printf("input integer: ");
    scanf("%d", &val);
    while (val != -99) {
        append_list(&myList, val);
        
        printf("input integer: ");
        scanf("%d", &val);
    }
    
    print_list(&myList);
    
    int index = 0;
    printf("input index: ");
    scanf("%d", &index);
    while (index != -99) {
        printf("%d\n", get_value(&myList, index));
        
        printf("input integer: ");
        scanf("%d", &index);
    }
    
    printf("\n");
}
