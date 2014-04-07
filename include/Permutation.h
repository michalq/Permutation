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
        Permutation copy(Permutation *layout);
        virtual ~Permutation();

        void setAmount(int amount);
        void setBranchBegin(int branchBegin);
        void setHigherBranch(Permutation *branch);

        int getAmount();
        int getPosition();
        int getSign();
        int getBranchBegin();
        Node *getNode(int i);
        Permutation *getHigherBranch();

        void updateSigns();
        void writeNode();
        void table();

    protected:
        // Nodes in this combination
        Node **nodes;
        // Amount of Nodes
        int amount;
        // Iterator
        int position = 1;
        // Sign of permutation
        int sign;
        //
        int branchBegin;
        // Higher branch
        Permutation *higherBranch;
        // Signs on nodes
        int *signs;
};

#endif // PERMUTATION_H
