#include "Equations/Postfix.h"

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
    this->result = this->buffer.top();
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
                equation = "(" + equation + ")";
            //std::cout << equation << "\n";
            this->makeEquation(equation);
        }
    }
    else
    {
        this->buffer.push(cache);
    }
}
