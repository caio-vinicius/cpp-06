/* Copyright (c) 2022 Caio Souza. All rights reserved. */
/* 42 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#define CHAR 'c'
#define INT 'i'
#define FLOAT 'f'
#define DOUBLE 'd'

#define FLOAT_POSITIVE_INFINITY 'x'
#define FLOAT_NEGATIVE_INFINITY 'X'
#define DOUBLE_POSITIVE_INFINITY 'z'
#define DOUBLE_NEGATIVE_INFINITY 'Z'
#define DOUBLE_NAN 'Y'

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
    bool n;

    dot = ftToBool(scalar.find("."));
    f = ftToBool(scalar.find("f"));
    n = ftToBool(scalar.find("n"));
    if (dot) {
        if (f)
            return (FLOAT);
        else
            return (DOUBLE);
    } else {
        if (!f && !n) {
            numeric = ftIsNumeric(scalar);
            if (numeric)
                return (INT);
            else
                if (scalar.length() == 1)
                    return (CHAR);
        } else {
            if (scalar == "-inff")
                return (FLOAT_POSITIVE_INFINITY);
            else if (scalar == "+inff")
                return (FLOAT_NEGATIVE_INFINITY);
            else if (scalar == "-inf")
                return (DOUBLE_POSITIVE_INFINITY);
            else if (scalar == "+inf")
                return (DOUBLE_NEGATIVE_INFINITY);
            else if (scalar == "nan")
                return (DOUBLE_NAN);
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
            c = static_cast< char >(i);
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
            c = scalar.c_str()[0];
            break;
        case (INT):
            stringToNumber(i, scalar.c_str());
            break;
        case (FLOAT):
            stringToNumber(f, scalar.c_str());
            break;
        case (DOUBLE):
            stringToNumber(d, scalar.c_str());
            break;
        case (IMPOSSIBLE):
            break;
    }
}

bool isPseudo(char const &type) {
    if (type == FLOAT_POSITIVE_INFINITY)
        return (true);
    else if (type == FLOAT_NEGATIVE_INFINITY)
        return (true);
    else if (type == DOUBLE_POSITIVE_INFINITY)
        return (true);
    else if (type == DOUBLE_NEGATIVE_INFINITY)
        return (true);
    else if (type == DOUBLE_NAN)
        return (true);
    else
        return (false);
}

void outputValues(char const &type, char const &c, int const &i, float const &f, double const &d) {
    std::stringstream ss;

    {
        ss << "char: ";
        if (c >= 32 && c <= 126)
            ss << c << std::endl;
        else if (type == FLOAT)
            ss << "'*'" << std::endl;
        else if (type == INT)
            ss << "Non displayable" << std::endl;
        else
            ss << "impossible" << std::endl;
    }
    {
        if (isPseudo(type))
            ss << "int: " << "0" << std::endl;
        else
            ss << "int: " << i << std::endl;
    }
    {
        float f2 = 0;

        ss << "float: ";
        if (type == FLOAT_POSITIVE_INFINITY)
            ss << "-inff" << std::endl;
        else if (type == FLOAT_NEGATIVE_INFINITY)
            ss << "+inff" << std::endl;
        else if (type == DOUBLE_NAN)
            ss << "nanf" << std::endl;
        else if (std::modf(f, &f2) == 0) {
            ss << std::fixed << std::setprecision(1) << f2;
            ss << "f" << std::endl;
        }
        else {
            ss << std::fixed << std::setprecision(10) << f;
            ss << "f" << std::endl;
        }
    }
    {
        ss << "double: ";
        if (type == DOUBLE_POSITIVE_INFINITY)
            ss << "+inf" << std::endl;
        else if (type == DOUBLE_NEGATIVE_INFINITY)
            ss << "-inf" << std::endl;
        else if (type == DOUBLE_NAN)
            ss << "nan" << std::endl;
        else
            ss << d << std::endl;
    }
    std::cout << ss.str();
}

int convert(std::string scalar) {
    char type;
    char c = 0;
    int i = 0;
    float f = 0;
    double d = 0;

    type = getScalarType(scalar);
    selectStringToNumber(type, c, i, f, d, scalar);
    typeCasting(type, c, i, f, d);
    outputValues(type, c, i, f, d);
    return (0);
}

int main(int argc, char **argv) {
    if (!*++argv || argc != 2) {
        return (0);
    }
    convert(*argv);
    return (0);
}
