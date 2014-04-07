/**
 * Created by: Michal Kutrzeba
 */
#include "Permutations/Permutations.h"
#include "Permutation.h"
#include <stdio.h>
#include <stack>

Permutations::Permutations::Permutations()
{
    this->counter = 0;
    this->container = new Permutation [200];
    this->determinant = Determinant();
}

/**
 * Adding new permutation on stack
 */
void Permutations::Permutations::add(Permutation permutation)
{
    Permutation *cache = new Permutation();
    *cache = permutation;
    cache->updateSigns();
    this->container[this->counter] = *cache;
    this->counter++;
}

/**
 * Drawing table
 * #(permutation no)
 * (table)
 * Sign: (permutation sign)
 * Branch begins at: (begin of branch)
 */
void Permutations::Permutations::table()
{
    for (int i = 0; i < this->counter; i++)
    {
        printf("\n#%i, %p -> %p\n", i+1, this->container[i].getHigherBranch(), &this->container[i]);
        this->container[i].table();
        printf("Sign: %i\n", this->container[i].getSign());
        printf("Branch begins at: %i\n", this->container[i].getBranchBegin());
    }
}

/**
 * Returning determinant object
 */
Determinant Permutations::Permutations::det()
{
    return this->determinant;
}

/**
 * Returns last permutation
 */
Permutation *Permutations::Permutations::top()
{
    return &this->container[this->counter-1];
}
