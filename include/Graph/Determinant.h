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
            void generate();
            void show();
            void setPermutations(Permutations *);
            Permutations *getPermutations();
            Permutation *getPermutation(int);
        private:
            Permutations *permutations;
            //std::string rpnequation;
            //std::string equation;
    };
}

#endif // DETERMINANT_H
