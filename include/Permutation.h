#include "Node.h"
#ifndef PERMUTATION_H
#define PERMUTATION_H

/**
 * Single representation of one permutation
 */

class Permutation
{
    public:
        Permutation(int amount);
        Permutation();
        ~Permutation();
        void setAmount(int amount);
        int getAmount();
        int getPosition();
        bool getStatus();
        bool push(Node *node);
        void pop();
        bool checkPossibility();
        bool checkPossibilityForce();
        bool checkLast();
        void writeNode();
        void writeColumns();
    private:
        // Nodes in this combination
        Node **nodes;
        // Amount of Nodes
        int amount;
        // Iterator
        int position = 1;
        // This tell us if there is full combination (amount == position)
        int isFull = false;
        // Amount of elements per column
        int *columns;
        // Returns whther it is possible to create permutation
        bool isPossible = true;
};

#endif // PERMUTATION_H
