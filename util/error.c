//
//  error.c
//  data-structure
//
//  Created by MacBoogy on 2018. 4. 4..
//  Copyright © 2018년 MacBoogy. All rights reserved.
//

#include "error.h"

void error(char *mes) {
    fprintf(stderr, "%s\n", mes);
    exit(1);
}
