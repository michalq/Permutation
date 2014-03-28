#include "Nodes.h"
#include "Permutation.h"
#include "Permutations/Permutations.h"

#ifndef GENERATOR_H
#define GENERATOR_H

namespace Permutations {
    class Generator
    {
        public:
            void setNodes(Nodes *nodes);
            Generator(Nodes *nodes);

            void init();
            bool recursiveToTop(Permutation *test, int *verses_cache, int *verses);
            void setContainer(Permutations *permutations);
            Permutations *getPermutations();
        private:
            // Stores reference to Nodes object
            Nodes *nodes;
            // Container that store found permutations
            Permutations *permutations;
            // Iterator
            int ite;
    };
}

#endif // GENERATOR_H
