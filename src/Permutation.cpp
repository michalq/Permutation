#include "Permutation.h"
#include "Node.h"

Permutation::Permutation(int amount)
{
    this->setAmount(amount);
    this->nodes = new Node * [this->amount];
}

bool Permutation::addNode(Node *node)
{
    if (this->getPosition() == this->getAmount())
    {
        this->isFull = false;
        return false;
    }

    this->nodes[position] = node;
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
