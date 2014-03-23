#include "Nodes.h"
#include "Permutation.h"
#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

class Permutations
{
    public:
        void setNodes(Nodes *nodes);
        Permutations(Nodes *nodes);
    private:
        /**
         * Stores reference to Nodes object
         */
        Nodes *nodes;
};

#endif // PERMUTATIONS_H
