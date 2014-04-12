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
            Determinant *generate();
            Determinant *convertEquationFromRPN();
            std::string getRPNEquation();
            std::string getEquation();
            void setPermutations(Permutations *);
            Permutations *getPermutations();
            Permutation *getPermutation(int);
        private:
            /**
             * Stores Graph::Permutations object indicator
             */
            Permutations *permutations;
            /**
             * Dummy permutations is a permutation with default values and it is
             * returned by getPermutation when range is over
             */
            Permutation *dummyPermutation;
            /**
             * Equation in postfix notation
             */
            std::string rpnequation;
            /**
             * Equation in infix notation
             */
            std::string equation;
    };
}

#endif // DETERMINANT_H
