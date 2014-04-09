#ifndef TEMPORARYPERMUTATION_H
#define TEMPORARYPERMUTATION_H

#include "Permutation.h"
namespace Graph {
    class TemporaryPermutation : public Permutation
    {
        public:
            TemporaryPermutation(int amount);
            bool push(Node *node);
            void pop();
            bool checkPossibility();
            bool checkPossibilityForce();
            bool checkLast();
            bool getStatus();
        protected:
            // Returns whther it is possible to create permutation
            bool isPossible = true;
            // This tell us if there is full combination (amount == position)
            int isFull = false;
            // Amount of elements per column
            int *columns;
    };
}

#endif // TEMPORARYPERMUTATION_H
