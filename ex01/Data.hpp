/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#ifndef DATA_HPP
#define DATA_HPP

class Data {
 public:
    Data(void);
    ~Data(void);
    Data &operator=(Data const &rhs);
    Data(Data const &src);
};

#endif
