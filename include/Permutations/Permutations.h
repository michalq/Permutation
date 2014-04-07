/**
 * Created by: Michal Kutrzeba
 */
#include "Permutation.h"
#include "Permutations/Determinant.h"

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

namespace Permutations {
    class Permutations
    {
        public:
            Permutations();
            void add(Permutation *permutation);
            Permutation **container;
            void table();
            Determinant det();
            Permutation *top();
        protected:
        private:
            int counter;
            Determinant determinant;
    };
}


#endif // PERMUTATIONS_H
