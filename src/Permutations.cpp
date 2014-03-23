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
    Permutation *test = new Permutation(5);

    for (int i = 1; i <= versesAmount; i++)
    {
        verses[i] = this->nodes->verse(i);
        test->addNode(this->nodes->getNode(verses[i]));
        printf("\nStatus %c: %s",this->nodes->getNode(verses[i])->getName() , test->checkPossibilityForce()?"true":"false");
    }

    /*
    test->addNode(this->nodes->getNode(0)); // a

    test->addNode(this->nodes->getNode(3)); // d
    printf("\n%i Status: %s",this->nodes->verse(2) , test->checkPossibilityForce()?"true":"false");
    test->addNode(this->nodes->getNode(8)); // i
    printf("\n%i Status: %s",this->nodes->verse(3) , test->checkPossibilityForce()?"true":"false");
    test->addNode(this->nodes->getNode(10)); // k
    printf("\n%i Status: %s",this->nodes->verse(4) , test->checkPossibilityForce()?"true":"false");
    test->addNode(this->nodes->getNode(14)); // o
    printf("\n%i Status: %s",this->nodes->verse(5) , test->checkPossibilityForce()?"true":"false");
    */
    /*for (int i = 0; i < 5; i++)
    {
        if (test->checkPossibility())
        {
            this->addCombination(test);
        }
        else
        {
            delete test;
            continue;
        }
    }*/
    delete verses;
}

void Permutations::addCombination(Permutation *permutation)
{
    this->combinations[position] = permutation;
    position++;
}
