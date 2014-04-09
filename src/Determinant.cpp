#include "Graph/Determinant.h"
#include "Graph/Permutations.h"
#include <stdio.h>
#include <stack>

Graph::Determinant::Determinant(Permutations *permutations)
{
    this->setPermutations(permutations);
}

Graph::Determinant::Determinant()
{

}

/**
 * It's a shortcut to ith permutation object
 */
Permutation *Graph::Determinant::getPermutation(int i)
{
    return this->permutations->getPermutation(i);
}

Graph::Permutations *Graph::Determinant::getPermutations()
{
    return this->permutations;
}

/**
 * Show determinant equation in RPN (Reverse Polish Notation)
 */
void Graph::Determinant::generate()
{

    int amountOfLines = this->getPermutation(0)->getAmount();
    int amountOfPermutations = this->getPermutations()->getAmount();

    for (int i = 0; i < amountOfPermutations; i++)
    {
        for (int j = this->getPermutation(i)->getBranchBegin(); j < amountOfLines; j++)
        {
            printf("%c", this->getPermutation(i)->getNode(j)->getName());
        }
    }
}

/**
 * Show human readable equation
 */
void Graph::Determinant::show()
{

}

void Graph::Determinant::setPermutations(Permutations *permutations)
{
    this->permutations = permutations;
}
