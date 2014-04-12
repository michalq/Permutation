#include "Graph/Determinant.h"
#include "Graph/Permutations.h"
#include "Equations/Postfix.h"

#include <stack>

Graph::Determinant::Determinant(Permutations *permutations)
{
    this->dummyPermutation = new Permutation();
    this->setPermutations(permutations);
    this->rpnequation = "";
    this->equation = "";
}

/**
 * It's a shortcut to ith permutation object
 */
Permutation *Graph::Determinant::getPermutation(int i)
{
    if (i < 0 || i >= this->getPermutations()->getAmount())
        return this->dummyPermutation;
    return this->permutations->getPermutation(i);
}

Graph::Permutations *Graph::Determinant::getPermutations()
{
    return this->permutations;
}

/**
 * Show determinant equation in RPN (Reverse Polish Notation)
 */
Graph::Determinant *Graph::Determinant::generate()
{
    this->rpnequation = "";

    int amountOfLines = this->getPermutation(0)->getAmount();
    int amountOfPermutations = this->getPermutations()->getAmount();

    if (this->getPermutation(0)->getSign() == -1)
    {
        this->rpnequation += "0";
    }
    for (int i = 0; i < amountOfPermutations; i++)
    {
        for (int j = this->getPermutation(i)->getBranchBegin(); j < amountOfLines; j++)
        {
            this->rpnequation += this->getPermutation(i)->getNode(j)->getName();
        }

        Permutation *cachePermutation = this->getPermutation(i);
        for (int j = amountOfLines-2; j >= this->getPermutation(i + 1)->getBranchBegin(); j--)
        {
            this->rpnequation += '*';
            if (cachePermutation->getBranchBegin() == j)
            {
                this->rpnequation += this->getPermutation(i)->getNodeSign(j)?'-':'+';
                cachePermutation = cachePermutation->getHigherBranch();
            }
        }
    }
    return this;
}

/**
 * Converts from reverse polish notation to normal equation.
 */
Graph::Determinant *Graph::Determinant::convertEquationFromRPN()
{
    Equations::Postfix *postfix = new Equations::Postfix();
    postfix->setEquation(this->getRPNEquation());
    postfix->toInfix();
    this->equation = postfix->getResult();
    return this;
}

/**
 * If you want get rpn equation you just need put object->getRPNEquation(),
 * but if you want to regenerate equation you need to do it manually
 * object->generate()->getRPNEquation()
 * returns regenerated equation.
 */
std::string Graph::Determinant::getRPNEquation()
{
    if (this->rpnequation.length() == 0)
        this->generate();
    return this->rpnequation;
}

/**
 * If you want get normal equation you can use just object->getEquation(),
 * but if you need to rebuild equation you should do it manually just like above,
 * and convert again from rpn to normal, just lke this:
 * object->generate()->convertEquationFromRPN()->getEquation()
 * returns regenerated and converted from RPN equation.
 */
std::string Graph::Determinant::getEquation()
{
    if (this->equation.length() == 0)
        this->convertEquationFromRPN();
    return this->equation;
}

void Graph::Determinant::setPermutations(Permutations *permutations)
{
    this->permutations = permutations;
}
