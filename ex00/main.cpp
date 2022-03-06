/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include <string>
#include <sstream>

#define CHAR 'c'
#define INT 'i'
#define FLOAT 'f'
#define DOUBLE 'd'
#define IMPOSSIBLE 'I'

bool ftIsNumeric(std::string s) {
    return (s.find_first_not_of("0123456789-+") == std::string::npos);
}

bool ftToBool(char value) {
    if (value >= 0)
        return (true);
    return (false);
}

char getScalarType(std::string const &scalar) {
    bool dot;
    bool f;
    bool numeric;

    dot = ftToBool(scalar.find("."));
    f = ftToBool(scalar.find("f"));
    if (dot) {
        if (f)
            return (FLOAT);
        else
            return (DOUBLE);
    } else {
        if (!f) {
            numeric = ftIsNumeric(scalar);
            if (numeric)
                return (INT);
            else
                if (scalar.length() == 1)
                    return (CHAR);
        }
    }
    return (IMPOSSIBLE);
}

template<typename T>
bool stringToNumber(T &i, char const *s)
{
    std::stringstream ss(s);

    ss >> i;
    if (ss.fail()) {
        return (false);
    }
    return (true);
}

void typeCasting(char const type, char &c, int &i, float &f, double &d)
{
    switch (type) {
        case (INT):
            f = static_cast< float >(i);
            d = static_cast< double >(i);
            break;
        case (FLOAT):
            i = static_cast< int >(f);
            d = static_cast< double >(f);
            break;
        case (DOUBLE):
            i = static_cast< int >(d);
            f = static_cast< float >(d);
            break;
    }
}

void selectStringToNumber(char const type, char &c, int &i, float &f, double &d, std::string const &scalar) {
    switch (type) {
        case (CHAR):
            std::cout << "it's CHAR!" << std::endl;
            break;
        case (INT):
            stringToNumber(i, scalar.c_str());
            std::cout << "it's INT!" << std::endl;
            break;
        case (FLOAT):
            stringToNumber(f, scalar.c_str());
            std::cout << "it's FLOAT!" << std::endl;
            break;
        case (DOUBLE):
            stringToNumber(d, scalar.c_str());
            std::cout << "it's DOUBLE!" << std::endl;
            break;
        case (IMPOSSIBLE):
            std::cout << "it's IMPOSSIBLE!" << std::endl;
            break;
    }
}

void outputValues(char const &c, int const &i, float const &f, double const &d) {
    if (c)
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: " << "impossible" << std::endl;
    if (i)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: " << "impossible" << std::endl;
    if (f)
        std::cout << "float: " << f << std::endl;
    else
        std::cout << "float: " << "impossible" << std::endl;
    if (d)
        std::cout << "double: " << d << std::endl;
    else
        std::cout << "double: " << "impossible" << std::endl;
}

int convert(std::string scalar) {
    char type;
    char c;
    int i;
    float f;
    double d;

    type = getScalarType(scalar);
    selectStringToNumber(type, c, i, f, d, scalar);
    typeCasting(type, c, i, f, d);
    outputValues(c, i, f, d);

    //i = 4;
    //f = static_cast< float >(scalar);
    //f = reinterpret_cast< float* >(scalar);
    //f = std::atof(scalar);

    //std::cout << "float?: " << *f << std::endl;
    //(void)f;
    return (0);
}

int main(int argc, char **argv) {
    if (!*++argv || argc != 2) {
        return (0);
    }
    convert(*argv);
    return (0);
}
