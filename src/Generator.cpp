/**
 * Created by: Michal Kutrzeba
 */
#include <stack>
#include "Graph/Generator.h"
#include "Graph/Permutations.h"
#include "Graph/TemporaryPermutation.h"
#include "Nodes.h"

void Graph::Generator::setNodes(Nodes *nodes)
{
    this->nodes = nodes;
}

Graph::Generator::Generator(Nodes *nodes)
{
    this->setNodes(nodes);
    this->permutations = new Permutations();
    this->branch = 1;
}

void Graph::Generator::setContainer(Permutations *container)
{
    this->permutations = container;
}

Graph::Permutations *Graph::Generator::getPermutations()
{
    return this->permutations;
}

/**
 * I think that this method could be better, but now at least it's working ...
 */
void Graph::Generator::init()
{
    int versesAmount = this->nodes->maxFrom();
    int *verses = new int [versesAmount];
    int *verses_cache = new int [versesAmount];
    std::stack <Permutation*> branches;
    TemporaryPermutation *test = new TemporaryPermutation(versesAmount);
    Permutation *cache = new Permutation();
    // This is Permutation object which will be assignes as higherBranch to Permutation who hasn't got any higher branches
    Permutation *topBranch;
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

            while ( (!branches.empty()) && (branches.top()->getBranchBegin() >= cache->getBranchBegin()))
            {
                branches.pop();
            }
            if ( ! branches.empty())
            {
                if (branches.top()->getBranchBegin() < cache->getBranchBegin())
                {
                    cache->setHigherBranch(branches.top());
                    branches.push(cache);
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

bool Graph::Generator::recursiveToTop(TemporaryPermutation *test, int *verses_cache, int *verses)
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
