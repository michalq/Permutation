#include "Permutations/TemporaryPermutation.h"

/**
 * This class is using only by Generator to generate new permutations.
 */
 Permutations::TemporaryPermutation::TemporaryPermutation(int amount)
    : Permutation(amount)
 {
    this->columns = new int [this->amount];
    for (int i = 1; i < this->amount; i++)
    {
        this->columns[i] = 0;
    }
 }

bool Permutations::TemporaryPermutation::push(Node *node)
{
    if (this->getPosition() == this->getAmount())
    {
        this->isFull = false;
        return false;
    }
    this->nodes[node->getFrom()] = node;
    this->columns[node->getTo()]++;
    this->position++;
    return this->checkLast();
}

/**
 * "Removing" last element.
 * Decrementing amount of noodes, last element is overwriting by push()
 */
void Permutations::TemporaryPermutation::pop()
{
    this->position -= 1;
    int cache = this->nodes[this->position]->getTo();
    this->columns[cache] -= 1;
}

/**
 * Check whether it is possible to create permutation with given nodes
 */
bool Permutations::TemporaryPermutation::checkPossibility()
{
    if (this->getStatus())
        return this->isPossible;

    return false;
}

/**
 * Returns whether is last node correct choosen
 */
bool Permutations::TemporaryPermutation::checkLast()
{
    return !(this->columns[this->nodes[this->position-1]->getTo()] > 1);
}

bool Permutations::TemporaryPermutation::getStatus()
{
    return this->isFull;
}
