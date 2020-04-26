#ifndef BACKEND_NUMBER_H
#define BACKEND_NUMBER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>


class Number
{
public:
    explicit Number();

    explicit Number(int k);

    explicit Number(const std::string& str);


public:
    const int getLength() const;

    const std::string& getNum() const;

    void setNum(const std::string& number);

    void split(Number& leftString, Number& rightString) const;


public:
    void operator= (const Number& number);

    Number operator* (const Number& number) const;

    Number operator*(const char& dig) const;                //Multiplication of object Number by a single digit(char) of another Number

    Number operator+ (const Number& number) const;

    Number operator- (const Number& number) const;

    friend std::ostream& operator<< (std::ostream &out, const Number& num)
    {
        for (int i = num._number.length() - 1; i >= 0; i--)
            out << num._number[i];
        return out;
    }


private:
    std::string _number;
};


#endif //BACKEND_NUMBER_H
