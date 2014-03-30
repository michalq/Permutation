#include <stdio.h>
#include "Permutation.h"
#include "Node.h"

Permutation::Permutation(){}

Permutation::Permutation(int amount)
{
    this->setAmount(amount);
    this->nodes = new Node * [this->amount];
    this->columns = new int [this->amount];

    for (int i = 1; i < this->amount; i++)
    {
        this->columns[i] = 0;
    }
}

Permutation::Permutation(const Permutation& layout)
{
    this->amount = layout.amount;
    this->nodes = new Node * [layout.amount];
    this->columns = new int [this->amount];
    for (int i = 1; i < layout.amount; i++)
    {
        this->nodes[i]   = layout.nodes[i];
        this->columns[i] = layout.columns[i];
    }
}

Permutation Permutation::copy(Permutation *layout)
{
    this->amount = layout->amount;
    this->nodes =  new Node * [layout->amount];
    this->columns = new int [this->amount];
    for (int i = 1; i < layout->amount; i++)
    {
        this->nodes[i]   = layout->nodes[i];
        this->columns[i] = layout->columns[i];
    }
    return *this;
}


Permutation::~Permutation(void)
{
    if ( ! this->nodes)
    {
        delete [] this->nodes;
    }

    if ( ! this->columns)
    {
        delete [] this->columns;
    }
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
 * Adding node to the last possible field
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

/**
 * "Removing" last element.
 * Decrementing amount of noodes, last element is overwriting by push()
 */
void Permutation::pop()
{
    this->position -= 1;
    int cache = this->nodes[this->position]->getTo();
    this->columns[cache] -= 1;
}

/**
 * Output pethods
 */

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

void Permutation::table()
{
    for (int i = 1; i < this->getAmount(); i++)
    {
        printf("| %i | %c | 0 |\n", i, this->nodes[i]->getName());
    }
    printf("Sign: -\n");
}

/**
 * Getters/Setters
 */

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
