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
        bool addNode(Node *node);
        bool checkPossibility();
        bool checkPossibilityForce();
    private:
        // Nodes in this combination
        Node **nodes;
        // Amount of Nodes
        int amount;
        // Iterator
        int position = 1;
        // This tell us if there is full combination (amount == position)
        int isFull = false;
        //
        bool *columns;
        // Returns whther it is possible to create permutation
        bool isPossible = true;
};

#endif // PERMUTATION_H
