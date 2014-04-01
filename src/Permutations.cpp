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
        printf("Sign: %i\n", this->container[i].getSign());
        printf("Branch begins at: %i\n", this->container[i].getBranchBegin());
    }
}

void Permutations::Permutations::detEquationRPN()
{
    printf("0");
    int amount = this->container[0].getAmount();
    for (int i = 0; i < this->counter; i++)
    {
        //printf("Begin at: %i\n", this->container[i].getBranchBegin());
        for (int j = this->container[i].getBranchBegin(); j < amount; j++)
        {
            printf("%c", this->container[i].getNode(j)->getName());
        }
        for (int j = this->container[i+1].getBranchBegin()+1; j < amount; j++)
        {
            printf("*");
        }
    }
}

int Permutations::Permutations::det()
{
    return 5;
}
