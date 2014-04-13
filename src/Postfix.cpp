#include "Equations/Postfix.h"
/**
 * Very simple class to convert from postfix notation to:
 * - infix notation
 * -
 */

Equations::Postfix::Postfix(){}

void Equations::Postfix::toInfix()
{
    std::string rpneq = this->equation;
    int amount = rpneq.length();
    this->result = "";
    std::string cache;

    for (int i = amount - 1; i >= 0; i--)
    {
        cache = rpneq[i];
        this->makeEquation(cache);
    }
    this->result = this->buffer.top() + ")";
    this->buffer.pop();
}

void Equations::Postfix::makeEquation(std::string cache)
{
    std::string equation;
    std::string sign;
    if ( ! buffer.empty())
    {
        if (this->isSign(this->buffer.top()) || (!this->isSign(this->buffer.top()) && this->isSign(cache)))
        {
            if (cache.length() > 1 && cache[0] == '(')
                cache = cache + ")";
            this->buffer.push(cache);
        }
        else
        {
            equation = this->buffer.top();
            this->buffer.pop();
            sign = this->buffer.top();
            this->buffer.pop();

            equation = cache + sign + equation;
            if ((sign == "+" || sign == "-") && cache[0] != '(')
                equation = "(" + equation;
            this->makeEquation(equation);
        }
    }
    else
    {
        this->buffer.push(cache);
    }
}
