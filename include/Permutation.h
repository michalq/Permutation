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
        void setAmount(int amount);
        int getAmount();
        int getPosition();
        bool getStatus();
        bool addNode(Node *node);
    private:
        // Nodes in this combination
        Node **nodes;
        // Amount of Nodes
        int amount;
        // Iterator
        int position = 1;
        // This tell us if there is full combination (amount == position)
        int isFull = false;
};

#endif // PERMUTATION_H
