#ifndef DETERMINANT_H
#define DETERMINANT_H

#include <string>
#include "Permutation.h"

namespace Graph {
    class Permutations;
    class Determinant
    {
        public:
            Determinant(Permutations *);
            Determinant();
            Determinant *generate();
            void show();
            void setPermutations(Permutations *);
            Permutations *getPermutations();
            Permutation *getPermutation(int);
        private:
            Permutations *permutations;
            Permutation *dummyPermutation;
            std::string rpnequation;
            std::string equation;
    };
}

#endif // DETERMINANT_H
