#include "Permutations/Determinant.h"

Determinant::Determinant()
{

}

/**
 * Show determinant equation in RPN (Reverse Polish Notation)
 */
void Determinant::getRPNequation()
{
    /*printf("0");
    std::stack <int> signs;
    int amount = this->container[0].getAmount();
    int lastSign;
    for (int i = 0; i < this->counter; i++)
    {
        if (this->container[i].getBranchBegin() != 1)
        {
            signs.push(this->container[i].getBranchBegin());
        }
        for (int j = this->container[i].getBranchBegin(); j < amount; j++)
        {
            printf("%c", this->container[i].getNode(j)->getName());
        }
        if ( ! signs.empty())
        {
            lastSign = signs.top();
        }
        for (int j = this->container[i+1].getBranchBegin()+1; j < amount; j++)
        {
            if (lastSign == j)
            {
                printf("-");
                signs.pop();
                if ( ! signs.empty())
                {
                    lastSign = signs.top();
                }
            }
            printf("*");
        }
    }*/
}

/**
 * Show human readable equation
 */
void Determinant::getEquation()
{

}
