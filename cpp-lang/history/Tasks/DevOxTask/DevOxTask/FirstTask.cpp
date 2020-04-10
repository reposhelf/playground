//
//  FirstTask.cpp
//  DevOxTask
//
//  Created by Vova Myroniuk on 7/12/17.
//  Copyright © 2017 Vova Myroniuk. All rights reserved.
//

#include "FirstTask.hpp"

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mainMutex;

void displayUnique() {
    std::lock_guard<std::mutex> guard(mainMutex);
    static int u = 0;
    std::cout << ++u << std::endl;
}

void runFirstTask() {
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 100; ++i) {
        threads.push_back(std::thread(displayUnique));
    }
    
    for (auto &&t : threads) {
        t.join();
    }
}
