//
//  data-structure
//
//  Created by potados on 2018. 4. 4..
//  Copyright © 2018 potados. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "arrayList.h"

void append_test(void);
void extend_test(void);
//void insert_test(void);
//void pop_test(void);
void append_speed_test(void);

int main(int argc, const char * argv[]) {
    printf("Demo of array list.\n");
    
    append_test();
    extend_test();   //pop_test();
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

void extend_test() {
    List myList1;
    init_list(&myList1);
    
    List myList2;
    init_list(&myList2);
    
    int input = 0;
    printf("extend test - list1\n");
    printf("input integer: ");
    scanf("%d", &input);
    while (input != -99) {
        append_list(&myList1, input);
        
        printf("input integer: ");
        scanf("%d", &input);
    }
    
    printf("\n");
    
    input = 0;
    printf("extend test - list2\n");
    printf("input integer: ");
    scanf("%d", &input);
    while (input != -99) {
        append_list(&myList1, input);
        
        printf("input integer: ");
        scanf("%d", &input);
    }
    
    extend_list(&myList1, &myList2);
    
    print_list(&myList1);
    printf("\n");
    
}

/*
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
*/

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
    printf("Appended 100,004 items in %f secs\n", time);
}

