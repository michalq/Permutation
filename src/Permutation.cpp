#include <stdio.h>
#include "Permutation.h"
#include "Node.h"

Permutation::Permutation(){}

Permutation::Permutation(int amount)
{
    this->setAmount(amount);
    this->nodes = new Node * [this->amount];
    this->columns = new int [this->amount];

    for (int i = 1; i <= this->amount; i++)
    {
        this->columns[i] = 0;
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

/**
 * Returns whether is last node correct choosen
 */
bool Permutation::checkLast()
{
    return !(this->columns[this->nodes[this->position-1]->getTo()] > 1);
}

/**
 *
 */
bool Permutation::push(Node *node)
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

void Permutation::pop()
{
    this->position -= 1;
    int cache = this->nodes[this->position]->getTo();
    this->columns[cache] -= 1;
}

void Permutation::writeNode()
{
    for (int i = 1; i < this->getAmount(); i++)
    {
        printf("%c, ", this->nodes[i]->getName());
    }
    printf("\n");
}

void Permutation::writeColumns()
{
    for (int i = 1; i < this->getAmount(); i++)
    {
        printf("%i, ", this->columns[i]);
    }
    printf("\n");
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
