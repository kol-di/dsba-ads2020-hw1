#include "Multiplicator.h"


Multiplicator::Multiplicator(int k)
        :_number1(k)
        ,_number2(k)
{}

Number Multiplicator::SchoolMultiply(const Number& number1, const Number& number2) const
{
    Number newNumber, addNumber;
    for (int i = 0; i < number1.getLength(); i++)
    {
        std::string tempString(number2.getLength() + i + 1, '0');
        int addNext = 0;
        for (int j = 0; j < number2.getLength(); j++)
        {
            int add2 = tempString[i + j] + ((number1.getNum()[i] - 48) * (number2.getNum()[j] - 48) + addNext);
            tempString[i + j] = ((tempString[i + j] + ((number1.getNum()[i] - 48) * (number2.getNum()[j] - 48) + addNext) - 48) % 10) + 48;
            addNext = (add2 - 48) / 10;
        }                                                                 //Calculations are so complicated because they help us handle the
        if (addNext != 0)                                                 //the problem with exceeding of ASCII table max index
            tempString[number2.getLength() + i] += addNext;
        else
            tempString.resize(number2.getLength() + i);
        addNumber.setNum(tempString);
        newNumber = newNumber + addNumber;
    }
    return newNumber;
}


Number Multiplicator::DivideAndConquerMultiply(const Number& number1, const Number& number2) const
{
    int n = std::max(number2.getLength(), number1.getLength());
    if ((number1.getLength() == 1) || (number2.getLength() == 1))
        return SchoolMultiply(number1, number2);
    else
    {
        Number a, b, c, d, number1Cop(number1), number2Cop(number2);
        while (number1Cop.getLength() != n)
            number1Cop.setNum(number1Cop.getNum() + "0");
        while (number2Cop.getLength() != n)
            number2Cop.setNum(number2Cop.getNum() + "0");
        number1Cop.split(a,b);                                      //Function split doesn't result in equal parts. One of them can be
        number2Cop.split(c,d);                                      //bigger by 1 than another
        Number ac = DivideAndConquerMultiply(a, c);
        Number ad = DivideAndConquerMultiply(a, d);
        Number bc = DivideAndConquerMultiply(b, c);
        Number bd = DivideAndConquerMultiply(b, d);
        if (n % 2)
            --n;
        return Number(std::string(n, '0') + ac.getNum()) +
               Number(std::string(n / 2, '0') + (ad + bc).getNum()) +
               Number(bd.getNum());
    }
}

Number Multiplicator::KaratsubasMultiply(const Number& number1, const Number& number2) const
{
    int n = std::max(number2.getLength(), number1.getLength());
    if ((number1.getLength() == 1) || (number2.getLength() == 1))
        return SchoolMultiply(number1, number2);
    else
    {
        Number a, b, c, d, number1Cop(number1), number2Cop(number2);
        while (number1Cop.getLength() != n)
            number1Cop.setNum(number1Cop.getNum() + "0");
        while (number2Cop.getLength() != n)
            number2Cop.setNum(number2Cop.getNum() + "0");
        number1Cop.split(a,b);                                      //Function split doesn't result in equal parts. One of them can be
        number2Cop.split(c,d);                                      //bigger by 1 than another
        Number ac = KaratsubasMultiply(a, c);
        Number bd = KaratsubasMultiply(b, d);
        Number prod = KaratsubasMultiply(a + b, c + d);
        if (n % 2)
            --n;
        return Number(std::string(n, '0') + ac.getNum()) +
               Number(std::string(n / 2, '0') + ((prod - ac) - bd).getNum()) +
               Number(bd.getNum());
    }
}


std::pair<Number, Number> Multiplicator::getNumbers() { return std::pair(_number1, _number2); }
