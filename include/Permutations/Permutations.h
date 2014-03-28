#include "Permutation.h"

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

namespace Permutations {
    class Permutations
    {
        public:
            Permutations();
            void add(Permutation *permutation);
            void test(); // TO REMOVE
        protected:
        private:
            int counter;
            Permutation *container;
    };
}


#endif // PERMUTATIONS_H
