/**
 * Created by: Michal Kutrzeba
 */
#include "Nodes.h"
#include "Permutation.h"
#include "Graph/Permutations.h"
#include "Graph/TemporaryPermutation.h"

#ifndef GENERATOR_H
#define GENERATOR_H

namespace Graph {
    class Generator
    {
        public:
            void setNodes(Nodes *nodes);
            Generator(Nodes *nodes);

            void init();
            bool recursiveToTop(TemporaryPermutation *test, int *verses_cache, int *verses);
            void setContainer(Permutations *permutations);
            Permutations *getPermutations();
        private:
            // Stores reference to Nodes object
            Nodes *nodes;
            // Container that store found permutations
            Permutations *permutations;
            // Iterator (temp)
            int ite;
            // Branch tell us where branch out appears (temp)
            int branch;
    };
}

#endif // GENERATOR_H
