#include "Number.h"

const std::string RandomNumber(const int& k);

Number::Number() :_number("0") {}

Number::Number(const std::string& str) :_number(str) {}

Number::Number(int k)
        :_number()
{
    _number = RandomNumber(k);
}




const int Number::getLength() const { return _number.length(); }

const std::string& Number::getNum() const { return _number; }

void Number::setNum(const std::string& number) { _number = number; }




void Number::split(Number& leftString, Number& rightString) const
{
    rightString._number = _number.substr(0, this->getLength() / 2);
    leftString._number = _number.substr(this->getLength() / 2, this->getLength() - (this->getLength() / 2));
}



void Number::operator= (const Number& number)
{
    _number = number._number;
}


Number Number::operator+ (const Number& number) const
{
    Number newNumber;
    size_t sz;
    bool addOne = false;
    if (number.getLength() > this->getLength())
    {
        sz = number.getLength() + 1;
        std::string tempNumberString(sz, '0');
        for (int i = 0; i < this->getLength(); i++)
        {
            tempNumberString[i] += number._number[i] + this->_number[i] - 96;
            if (addOne)
            {
                tempNumberString[i] += 1;
                addOne = false;
            }
            if (tempNumberString[i] > 57)
            {
                tempNumberString[i] = 48 + (tempNumberString[i] - 58);
                addOne = true;
            }

        }
        for (int i = this->getLength(); i < sz; i++)
        {
            tempNumberString[i] = std::max(number._number[i] - 0, 48);
            if (addOne)
            {
                tempNumberString[i] += 1;
                addOne = false;
            }
            if (tempNumberString[i] > 57)
            {
                tempNumberString[i] = 48 + (tempNumberString[i] - 58);
                addOne = true;
            }
        }
        if (tempNumberString[sz - 1] == '0')
            tempNumberString.resize(sz - 1);
        newNumber._number = tempNumberString;
    }

    else
    {
        sz = this->getLength() + 1;
        std::string tempNumberString(sz, '0');
        for (int i = 0; i < number.getLength(); i++)
        {
            tempNumberString[i] += number._number[i] + this->_number[i] - 96;
            if (addOne)
            {
                tempNumberString[i] += 1;
                addOne = false;
            }
            if (tempNumberString[i] > 57)
            {
                tempNumberString[i] = 48 + (tempNumberString[i] - 58);
                addOne = true;
            }

        }
        for (int i = number.getLength(); i < sz; i++)
        {
            tempNumberString[i] = std::max(this->_number[i] - 0, 48);
            if (addOne)
            {
                tempNumberString[i] += 1;
                addOne = false;
            }
            if (tempNumberString[i] > 57)
            {
                tempNumberString[i] = 48 + (tempNumberString[i] - 58);
                addOne = true;
            }
        }
        if (tempNumberString[sz - 1] == '0')
            tempNumberString.resize(sz-1);
        newNumber._number = tempNumberString;
    }
    return newNumber;
}

Number Number::operator- (const Number& number) const
{
    Number newNumber;
    size_t sz;
    bool subOne = false;
    sz = this->getLength();
    std::string tempNumberString(sz, '0');
    for (int i = 0; i < number.getLength(); i++)
    {
        tempNumberString[i] += this->_number[i] - number._number[i];
        if (subOne)
        {
            tempNumberString[i] -= 1;
            subOne = false;
        }
        if (tempNumberString[i] < 48)
        {
            tempNumberString[i] += 10;
            subOne = true;
        }
    }
    for (int i = number.getLength() ; i < this->getLength(); i++)
    {
        tempNumberString[i] = this->_number[i];
        if (subOne)
        {
            tempNumberString[i] -= 1;
            subOne = false;
        }
        if (tempNumberString[i] < 48)
        {
            tempNumberString[i] += 10;
            subOne = true;
        }
    }
    newNumber._number = tempNumberString;
    return newNumber;
}

const std::string RandomNumber(const int& k)           //Method for creating a random number of size k
{
    std::string returnString;
    for (int i = 0; i < k; i++)
    {
        char digit;
        if (i < k - 1)
            digit = (std::rand() % 10) + 48;
        if (i == k - 1)
        {
            digit = ((std::rand() % 9) + 1) + 48;
        }
        returnString += digit;
    }
    return returnString;
}