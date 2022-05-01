/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

template<typename T>
Base *create() {
    return (new T());
}

Base *generate(void) {
    typedef Base* (*createFunctions)();
    createFunctions f[] = {
        &create<A>,
        &create<B>,
        &create<C>
    };
    srand((unsigned int)time(NULL));
    const unsigned int number = (rand() % 3);

    return (f[number]());
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "*p: " << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p)) {
        std::cout << "*p: " << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p)) {
        std::cout << "*p: " << "C" << std::endl;
    }
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "&p: " << "A" << std::endl;
    } catch (...) {}
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "&p: " << "B" << std::endl;
    } catch (...) {}
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "&p: " << "C" << std::endl;
    } catch (...) {}
}

int real(void) {
    Base *base;
    base = generate();

    Base &ref = *base;
    identify(base);
    identify(ref);
    return (0);
}

int main(void) {
    real();
    return (0);
}
