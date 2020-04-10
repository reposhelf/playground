//
//  SecondTask.cpp
//  DevOxTask
//
//  Created by Vova Myroniuk on 7/12/17.
//  Copyright © 2017 Vova Myroniuk. All rights reserved.
//

#include "SecondTask.hpp"

#include <iostream>

static void everythingExcept(int len, int *input, int *index, int *result) {
    for (int i = 0; i < len; ++i) {
        int product = 1;
        for (int j = 0; j < len; ++j) {
            if (index[i] != j) {
                product *= input[j];
            }
        }
        result[i] = product;
    }
}

static void printArray(int len, int *array) {
    for (int i = 0; i < len; ++i)
        std::cout << array[i] << std::endl;
}

void runSecondTask() {
    const int len = 4;
    int input[4] = {2, 3, 4, 5};
    int index[4] = {1, 3, 2, 0};
    int result[4] = {};
    
    everythingExcept(len, input, index, result);
    printArray(len, result);
}
