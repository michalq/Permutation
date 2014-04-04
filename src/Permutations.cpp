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

/**
 * Adding new permutation on stack
 */
void Permutations::Permutations::add(Permutation permutation)
{
    Permutation *cache = new Permutation();
    *cache = permutation;
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
        printf("\n#%i\n", i+1);
        this->container[i].table();
        printf("Sign: %i\n", this->container[i].getSign());
        printf("Branch begins at: %i\n", this->container[i].getBranchBegin());
    }
}

/**
 * Showing determinant equation in RPN
 */
void Permutations::Permutations::detEquationRPN()
{
    printf("0");
    std::stack <int> signs;
    int amount = this->container[0].getAmount();
    int lastSign;
    for (int i = 0; i < this->counter; i++)
    {
        if (this->container[i].getBranchBegin() != 1)
        {
            signs.push(this->container[i].getBranchBegin());
        }
        for (int j = this->container[i].getBranchBegin(); j < amount; j++)
        {
            printf("%c", this->container[i].getNode(j)->getName());
        }
        if ( ! signs.empty())
        {
            lastSign = signs.top();
        }
        for (int j = this->container[i+1].getBranchBegin()+1; j < amount; j++)
        {
            if (lastSign == j)
            {
                printf("-");
                signs.pop();
                if ( ! signs.empty())
                {
                    lastSign = signs.top();
                }
            }
            printf("*");
        }
    }
}

/**
 * Counting equation
 */
int Permutations::Permutations::det()
{
    return 5;
}
