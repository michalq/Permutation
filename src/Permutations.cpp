#include "Permutations/Permutations.h"
#include "Permutation.h"
#include <stdio.h>

Permutations::Permutations::Permutations()
{
    this->counter = 0;
    this->container = new Permutation [200];
}

void Permutations::Permutations::add(Permutation permutation)
{
    Permutation *cache = new Permutation();
    *cache = permutation;
    this->container[this->counter] = *cache;
    this->counter++;
}

void Permutations::Permutations::table()
{
    for (int i = 0; i < this->counter; i++)
    {
        printf("\n#%i\n", i+1);
        this->container[i].table();
    }
}

void Permutations::Permutations::detEquationRPN()
{

}

int Permutations::Permutations::det()
{
    return 5;
}

void Permutations::Permutations::test()
{

}
