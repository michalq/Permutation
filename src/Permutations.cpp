/**
 * Created by: Michal Kutrzeba
 */
#include "Graph/Permutations.h"
#include "Graph/Determinant.h"
#include "Permutation.h"
#include <stdio.h>
#include <stack>

Graph::Permutations::Permutations()
{
    this->counter = 0;
    this->container = new Permutation * [200];
    this->determinant = Determinant(this);
}

/**
 * Adding new permutation on stack
 */
void Graph::Permutations::add(Permutation *permutation)
{
    permutation->updateSigns();
    this->container[this->counter] = permutation;
    this->counter++;
}

/**
 * Drawing table
 * #(permutation no)
 * (table)
 * Sign: (permutation sign)
 * Branch begins at: (begin of branch)
 */
void Graph::Permutations::table()
{
    for (int i = 0; i < this->counter; i++)
    {
        printf("\n#%i, %p -> %p\n", i+1, this->container[i]->getHigherBranch(), this->container[i]);
        this->container[i]->table();
        printf("Sign: %i\n", this->container[i]->getSign());
        printf("Branch begins at: %i\n", this->container[i]->getBranchBegin());
    }
}

/**
 * Returning determinant object
 */
Graph::Determinant Graph::Permutations::det()
{
    return this->determinant;
}

/**
 * Returns last permutation
 */
Permutation *Graph::Permutations::top()
{
    return this->container[this->counter-1];
}

/**
 *
 */
Permutation *Graph::Permutations::getPermutation(int i)
{
    return this->container[i];
}

/**
 *
 */
int Graph::Permutations::getAmount()
{
    return this->counter;
}
