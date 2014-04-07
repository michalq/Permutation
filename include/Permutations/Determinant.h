#include <string>

#ifndef DETERMINANT_H
#define DETERMINANT_H


class Determinant
{
    public:
        Determinant();
        void getRPNequation();
        void getEquation();
    private:
        std::string rpnequation;
        std::string equation;
};

#endif // DETERMINANT_H
