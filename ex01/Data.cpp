/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include "Data.hpp"

Data::Data() {}
Data::~Data() {}

Data &Data::operator=(Data const &rhs) {
    (void)rhs;
    return (*this);
}

Data::Data(Data const &src) {
    *this = src;
}
