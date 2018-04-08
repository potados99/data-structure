//
//  array_list.h
//  Set_calculation
//
//  Created by potados on 2018. 3. 25..
//  Copyright © 2018 potados. All rights reserved.
//

#ifndef array_list_h
#define array_list_h

#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

Arr init_array(int size);

Arr append_array(Arr Array, int element);

Arr copy_array(Arr Array);

Arr extend_array(Arr Array1, Arr Array2);

Arr user_input_array(void);

void sort_array(Arr Array);

void print_array(Arr Array);

#endif /* array_list_h */
