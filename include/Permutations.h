#include "Permutations/Permutations.h"
#include "Permutation.h"

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H


Permutations::Permutations::Permutations()
{
    this->counter = 0;
    this->container = new Permutation [200];
}

void Permutations::Permutations::add(Permutation *permutation)
{
    permutation->writeNode();
    Permutation cache = Permutation();
    //this->container[this->counter] = permutation;
    this->counter++;
}

#endif // PERMUTATIONS_H
