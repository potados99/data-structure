//
//  linked_list_test.c
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "linked_list.h"

void append_test(void);
void insert_test(void);
void pop_test(void);
void get_value_test(void);
void append_speed_test(void);

int main(int argc, const char * argv[]) {
    printf("Demo of linked list.\n");
    
    //append_test();
    //get_value_test();
    //pop_test();
    //insert_test();
    append_speed_test();
}

void append_test() {
    List myList;
    init_list(&myList);
    
    int input = 0;
    printf("append test\n");
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
    
    int val = 0;
    printf("insert test\n");
    printf("input integer: ");
    scanf("%d", &val);
    while (val != -99) {
        append_list(&myList, val);
        
        printf("input integer: ");
        scanf("%d", &val);
    }
    
    print_list(&myList);
    
    int input = 0;
    printf("input integer: ");
    scanf("%d", &input);
    int num = 100;
    while (input != -99) {
        insert_list(&myList, input, num ++);
        print_list(&myList);

        printf("input integer: ");
        scanf("%d", &input);
    }
    
    print_list(&myList);
    printf("\n");
}

void pop_test() {
    List myList;
    init_list(&myList);
    
    int val = 0;
    printf("pop test\n");
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
        printf("%d\n", pop_list(&myList, index));
        print_list(&myList);

        printf("input integer: ");
        scanf("%d", &index);
    }
    
    printf("\n");
}

void get_value_test() {
    List myList;
    init_list(&myList);
    
    int val = 0;
    printf("get_value test\n");
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

void append_speed_test() {
    List myList;
    init_list(&myList);
    
    time_t startTime;
    time_t endTime;
    float time = 0;
    
    append_list(&myList, 1);
    append_list(&myList, 2);
    append_list(&myList, 3);
    append_list(&myList, 4);

    register unsigned int i = 0;
    startTime = clock();
    for (i = 100000; i != 0; i --) {
        //insert_list(&myList, 0, 3);
        append_list(&myList, 1);

    }
    endTime = clock();
    
    time = (float)(endTime - startTime)/(CLOCKS_PER_SEC);
    printf("%f secs\n", time);
}

