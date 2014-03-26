#include "Permutations.h"
#include "Nodes.h"
#include<stdio.h>

void Permutations::setNodes(Nodes *nodes)
{
    this->nodes = nodes;
    this->combinations = new Permutation * [200];
}

Permutations::~Permutations()
{
    delete this->combinations;

}

Permutations::Permutations(Nodes *nodes)
{
    this->setNodes(nodes);
}

void Permutations::generatePermutations()
{
    int versesAmount = this->nodes->maxFrom();
    int *verses = new int [versesAmount];
    int *verses_cache = new int [versesAmount];
    Permutation *test = new Permutation(versesAmount);
    // Init
    for (int i = 1; i <= versesAmount; i++)
    {
        verses[i] = this->nodes->verse(i);
        verses_cache[i] = this->nodes->verse(i);
    }
    int j = 1;
    for (this->ite = 1; ;)
    {
        test->push(this->nodes->getNode(verses_cache[this->ite]));

        if (test->checkLast() && this->ite == versesAmount)
        {
            // Ostatni element będzie prawidłowy sprawdzamy kolejny element na tej samej lini
            // add saving ...
            printf("%i. ", j++);
            test->writeNode();
        }

        //
        if (!test->checkLast() || this->ite == versesAmount)
        {
            if ( ! this->recursiveToTop(test, verses_cache, verses))
            {
                break;
            }
        }
        else
        {
            // If everything is ok, lets go to the nect line
            this->ite++;
        }
    }
    delete verses;
}

bool Permutations::recursiveToTop(Permutation *test, int *verses_cache, int *verses)
{
    test->pop(); // Deleting last object
    verses_cache[ite]++; // Checking another one object in line
    if (this->nodes->getNode(verses_cache[ite])->getFrom() != this->nodes->getNode(verses[ite])->getFrom())
    {
        if (this->ite == 1)
            return false;

        verses_cache[this->ite] = verses[this->ite];
        this->ite--; // Back one line to up
        return this->recursiveToTop(test, verses_cache, verses);

    }
}

void Permutations::addCombination(Permutation *permutation)
{
    this->combinations[position] = permutation;
    position++;
}
