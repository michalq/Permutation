#include "Graph/Determinant.h"
#include "Graph/Permutations.h"
#include <iostream>
#include <string>

Graph::Determinant::Determinant(Permutations *permutations)
{
    this->dummyPermutation = new Permutation();
    this->setPermutations(permutations);
    this->rpnequation = "";
}

Graph::Determinant::Determinant(){}

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

    for (int i = 0; i < amountOfPermutations; i++)
    {
        for (int j = this->getPermutation(i)->getBranchBegin(); j < amountOfLines; j++)
        {
            this->rpnequation += this->getPermutation(i)->getNode(j)->getName();
        }

        Permutation *cachePermutation = this->getPermutation(i);
        for (int j = amountOfLines-2; j >= this->getPermutation(i + 1)->getBranchBegin(); j--)
        {
            if (j == 0) break;
            this->rpnequation += '*';
            if (cachePermutation->getBranchBegin() == j)
            {
                this->rpnequation += this->getPermutation(i)->getNodeSign(j)?'-':'+';
                cachePermutation = cachePermutation->getHigherBranch();
            }
        }
    }
    return this;
    //std::cout << this->rpnequation;
}

/**
 * Show human readable equation
 */
void Graph::Determinant::show()
{
    std::cout << this->rpnequation;
}

void Graph::Determinant::setPermutations(Permutations *permutations)
{
    this->permutations = permutations;
}
