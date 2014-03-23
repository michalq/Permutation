#include "Nodes.h"
#include "Permutation.h"
#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

class Permutations
{
    public:
        void setNodes(Nodes *nodes);
        Permutations(Nodes *nodes);
        ~Permutations();
        void addCombination(Permutation *permutation);
        void generatePermutations();
    private:
        /**
         * Stores reference to Nodes object
         */
        Nodes *nodes;
        Permutation **combinations;
        int position = 0;
};

#endif // PERMUTATIONS_H
