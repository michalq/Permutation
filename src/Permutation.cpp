#include "Permutation.h"
#include "Node.h"

Permutation::Permutation(){}

Permutation::Permutation(int amount)
{
    this->setAmount(amount);
    this->nodes = new Node * [this->amount];
    this->columns = new bool [this->amount];
    for (int i = 1; i < this->amount; i++)
    {
        this->columns[i] = false;
    }
}

Permutation::~Permutation()
{
    delete this->nodes;
}

/**
 * Check whether it is possible to create permutation with given nodes
 */
bool Permutation::checkPossibility()
{
    if (this->getStatus())
        return this->isPossible;

    return false;
}

bool Permutation::checkPossibilityForce()
{
    return this->isPossible;
}

bool Permutation::addNode(Node *node)
{
    if (this->getPosition() == this->getAmount())
    {
        this->isFull = false;
        return false;
    }

    this->nodes[position] = node;
    if (this->columns[node->getTo()])
    {
        this->isPossible = false;
    }
    else
    {
        this->columns[node->getTo()] = true;
    }
    position++;
    return true;
}


bool Permutation::getStatus()
{
    return this->isFull;
}

int Permutation::getAmount()
{
    return this->amount;
}

int Permutation::getPosition()
{
    return this->position;
}

void Permutation::setAmount(int amount)
{
    // We start from 1 so we need one more place
    this->amount = amount + 1;
}
