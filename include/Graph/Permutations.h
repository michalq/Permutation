/**
 * Created by: Michal Kutrzeba
 */
#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include "Graph/Determinant.h"
#include "Permutation.h"

namespace Graph {
    class Permutations
    {
        public:
            Permutations();
            void add(Permutation*);
            Permutation **container;
            void table();
            Determinant det();
            Permutation *top();
            Permutation *getPermutation(int);
            int getAmount();
        protected:
        private:
            int counter;
            Determinant determinant;
    };
}


#endif // PERMUTATIONS_H
