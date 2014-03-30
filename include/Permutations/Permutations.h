#include "Permutation.h"

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

namespace Permutations {
    class Permutations
    {
        public:
            Permutations();
            void add(Permutation permutation);
            void test(); // TO REMOVE
            Permutation *container;
            void table();
            int det();
            void detEquationRPN();
        protected:
        private:
            int counter;
    };
}


#endif // PERMUTATIONS_H
