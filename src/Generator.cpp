/**
 * Created by: Michal Kutrzeba
 */
 #include <stdio.h> //temp
#include <stack>
#include "Permutations/Generator.h"
#include "Permutations/Permutations.h"
#include "Permutations/TemporaryPermutation.h"
#include "Nodes.h"

void Permutations::Generator::setNodes(Nodes *nodes)
{
    this->nodes = nodes;
}

Permutations::Generator::Generator(Nodes *nodes)
{
    this->setNodes(nodes);
    this->permutations = new Permutations();
    this->branch = 1;
}

void Permutations::Generator::setContainer(Permutations *container)
{
    this->permutations = container;
}

Permutations::Permutations *Permutations::Generator::getPermutations()
{
    return this->permutations;
}

/**
 * JESUS CHRIST! YOU NEED TO OPTIMIZE THESE METHODS BELOW!
 * ... but dont hurry
 */
void Permutations::Generator::init()
{
    int versesAmount = this->nodes->maxFrom();
    int *verses = new int [versesAmount];
    int *verses_cache = new int [versesAmount];
    std::stack <Permutation*> branches;
    TemporaryPermutation *test = new TemporaryPermutation(versesAmount);
    Permutation *cache = new Permutation();
    // Init, first run
    for (int i = 1; i <= versesAmount; i++)
    {
        verses[i] = this->nodes->verse(i);
        verses_cache[i] = this->nodes->verse(i);
    }
    this->ite = 1;
    while (true)
    {
        test->push(this->nodes->getNode(verses_cache[this->ite]));

        if (test->checkLast() && this->ite == versesAmount)
        {
            // Saving good permutation
            if (this->branch == -1)
            {
                test->setBranchBegin(1);
            }
            else
            {
                test->setBranchBegin(this->branch);
                this->branch = -1;
            }
            cache = new Permutation();
            cache->copy(test);

            while ( (! branches.empty()) && (branches.top()->getBranchBegin() >= cache->getBranchBegin()))
            {
                branches.pop();
            }
            if ( ! branches.empty())
            {
                if (branches.top()->getBranchBegin() < cache->getBranchBegin())
                {
                    cache->setHigherBranch(branches.top());
                    branches.push(cache);
                    //printf("<%p>\n", cache->getHigherBranch());
                }
            }
            else
            {
                // If there is no branches, push first one
                branches.push(cache);
                cache->setHigherBranch(new Permutation());
            }
            this->permutations->add(cache);
        }

        //
        if ( ! test->checkLast() || this->ite == versesAmount)
        {

            if ( ! this->recursiveToTop(test, verses_cache, verses))
            {
                break;
            }
        }
        else
        {
            // If everything is ok, lets go to the next line
            this->ite++;
        }
    }
    delete test;
    delete verses;
    delete verses_cache;
}

bool Permutations::Generator::recursiveToTop(TemporaryPermutation *test, int *verses_cache, int *verses)
{
    // Deleting last object
    test->pop();
    // Checking another one object in line
    verses_cache[this->ite]++;
    // Line is over?
    if (this->nodes->getNode(verses_cache[ite])->getFrom() != this->nodes->getNode(verses[ite])->getFrom())
    {
        // Is this the end?
        if (this->ite == 1)
            return false;

        // Back to default in line
        verses_cache[this->ite] = verses[this->ite];
        // Back one line up
        this->ite--;
        // Set branching out on this position
        if (this->ite < this->branch || this->branch == -1)
        {
            this->branch = this->ite;
        }
        // And check another one line up
        return this->recursiveToTop(test, verses_cache, verses);
    }
    return true;
}
