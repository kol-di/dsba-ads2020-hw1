#ifndef BACKEND_MULTIPLICATOR_H
#define BACKEND_MULTIPLICATOR_H

#include "Number.h"

class Multiplicator
{
public:
    Multiplicator(int k);           //creates two objects of class Number of length k


public:
    Number SchoolMultiply(const Number& number1, const Number& number2) const;


    Number DivideAndConquerMultiply(const Number& number1, const Number& number2) const;


    Number KaratsubasMultiply(const Number& number1, const Number& number2) const;


    std::pair<Number, Number> getNumbers();

private:
    Number _number1, _number2;
};


#endif //BACKEND_MULTIPLICATOR_H
