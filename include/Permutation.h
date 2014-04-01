/**
 * Created by: Michal Kutrzeba
 */
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
        Permutation(void);
        Permutation(const Permutation & layout);
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
        Permutation copy(Permutation *layout);
        int getSign();
        int getBranchBegin();
        void setBranchBegin(int branchBegin);
        Node *getNode(int i);

        void writeNode();
        void writeColumns();
        void table();
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
        // Sign of permutation
        int sign;
        //
        int branchBegin;
};

#endif // PERMUTATION_H
