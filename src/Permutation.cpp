/**
 * Created by: Michal Kutrzeba
 */
#include <stdio.h>
#include "Permutation.h"
#include "Node.h"

Permutation::Permutation(void)
{
    this->sign = 0;
    this->branchBegin = 1;
}

Permutation::Permutation(int amount)
{
    this->setAmount(amount);
    this->nodes = new Node * [this->amount];
    this->signs = new int [this->amount];
    this->sign = 0;
    this->branchBegin = 1;
    this->setHigherBranch(new Permutation);
    for (int i = 1; i < this->amount; i++)
    {
        this->signs[i] = 0;
    }
}

Permutation::Permutation(const Permutation& layout)
{
    this->amount = layout.amount;
    this->nodes = new Node * [layout.amount];
    this->signs = new int [layout.amount];
    this->branchBegin = layout.branchBegin;
    this->higherBranch = layout.higherBranch;
    this->sign = 0;

    for (int i = 1; i < layout.amount; i++)
    {
        this->nodes[i] = layout.nodes[i];
        this->signs[i] = 0;
    }
}

int Permutation::getNodeSign(int i)
{
    return this->signs[i];
}

Permutation Permutation::copy(Permutation *layout)
{
    this->amount = layout->amount;
    this->nodes =  new Node * [layout->amount];
    this->signs = new int [layout->amount];
    this->setBranchBegin(layout->getBranchBegin());
    this->setHigherBranch(layout->getHigherBranch());
    for (int i = 1; i < layout->amount; i++)
    {
        this->nodes[i] = layout->nodes[i];
        //printf("%i\n", this->signs[i]);
        this->signs[i] = 0;
    }
    return *this;
}


Permutation::~Permutation(void)
{
    if ( ! this->nodes)
    {
        delete [] this->nodes;
    }
}
/**
 * Counting and getting sign
 */
 int Permutation::getSign()
 {
    if (this->sign != 0)
        return this->sign;

    int sub = 0;

    int *cache = new int [this->amount];
    for (int i = 1; i < this->amount - 1; i++)
    {
        cache[i] = 0;
    }

    for (int i = 1; i < this->amount - 1; i++)
    {
        cache[this->nodes[i]->getTo()] = 1;
        sub += this->nodes[i]->getTo() - 1;
        for (int j = 1; j < this->nodes[i]->getTo(); j++)
        {
            sub -=cache[j];
        }
        this->nodes[i];
    }
    delete cache;
    this->sign = (sub % 2)?-1:1;
    return this->sign;
 }


/**
 * Output methods
 */

void Permutation::writeNode()
{
    for (int i = 1; i < this->getAmount(); i++)
    {
        printf("%c, ", this->nodes[i]->getName());
    }
    printf("\n");
}

void Permutation::table()
{
    for (int i = 1; i < this->getAmount(); i++)
    {
        printf("| %i | %i | %c | %i |\n", i, this->nodes[i]->getTo(), this->nodes[i]->getName(), this->signs[i]);
    }
}

void Permutation::updateSigns()
{
    int consAmount = this->getSign()==-1?1:0;
    Permutation *handler = this;

    for (int i = this->getAmount()-1; i >= 1; i--)
    {
        consAmount += handler->signs[i];
        this->signs[i] = handler->signs[i];
        if (i == 1) break;
        if (i == handler->getBranchBegin())
        {
            // Segmentation faults
            //printf("%p %p\n", handler, handler->getHigherBranch());
            handler = handler->getHigherBranch();
        }
    }
    if (consAmount%2 != 0)
    {
        this->signs[this->getBranchBegin()] = 1;
        //printf("%i\n", this->signs[this->getBranchBegin()]);
    }
}

/**
 * Getters/Setters
 */
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

void Permutation::setBranchBegin(int branchBegin)
{
    this->branchBegin = branchBegin;
}

int Permutation::getBranchBegin()
{
    return this->branchBegin;
}

Node *Permutation::getNode(int i)
{
    return this->nodes[i];
}

void Permutation::setHigherBranch(Permutation *branch)
{
    this->higherBranch = branch;
}

Permutation *Permutation::getHigherBranch()
{
    return this->higherBranch;
}
