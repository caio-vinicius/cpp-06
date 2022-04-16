/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include "Data.hpp"

#include <stdint.h> // uintptr_t

uintptr_t serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}

int main(void) {
    uintptr_t uintptr;
    Data *data;
    Data *finalData;

    data = new Data();
    uintptr = serialize(data);
    finalData = deserialize(uintptr);
    if (data == finalData) {
        std::cout << "Good... good..." << std::endl;
    } else {
        std::cout << "Yeah... You will listen to me, you're listen to me good... I will gonna teach you how to use casting in C++ in the correct way." << std::endl;
    }
    return (0);
}
