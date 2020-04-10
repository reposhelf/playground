//
//  FirstTaskPosix.cpp
//  DevOxTask
//
//  Created by Vova Myroniuk on 7/12/17.
//  Copyright © 2017 Vova Myroniuk. All rights reserved.
//

#include "FirstTaskPosix.hpp"

#include <iostream>
#include <pthread.h>

pthread_mutex_t mutex;

void *displayUnique(void *) {
    pthread_mutex_lock(&mutex);
    static int u = 0;
    std::cout << ++u << std::endl;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void runFirstTaskPosix() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[100];
    
    for (int i = 0; i < 100; ++i) {
        pthread_create(&threads[i], NULL, displayUnique, NULL);
    }
    
    for (int i = 0; i < 100; ++i) {
        pthread_join(threads[i], NULL);
    }
}
