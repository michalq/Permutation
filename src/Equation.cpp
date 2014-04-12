#include "Equations/Equation.h"
#include "Equations/Postfix.h"

Equations::Equation::Equation()
{

}

void Equations::Equation::toPrefix()
{
    throw "Function not available.";
}

void Equations::Equation::toInfix()
{
    throw "Function not available.";
}

void Equations::Equation::toPostfix()
{
    throw "Function not available.";
}

void Equations::Equation::setEquation(std::string equation)
{
    if (this->equation.length() > 0)
        throw "You can set equation only once.";
    this->equation = equation;
}

std::string Equations::Equation::getResult()
{
    return this->result;
}

bool Equations::Equation::isSign(std::string sign)
{
    if (sign == "+"|| sign == "-" || sign == "*" || sign == "/")
        return true;
    return false;
}
