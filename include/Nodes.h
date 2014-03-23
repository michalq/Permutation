#include "Node.h"
#ifndef NODES_H
#define NODES_H


class Nodes
{
    public:
        Nodes();
        Node **getList();
        void add(Node *node);
        void showTable();
        void listOfNodes();
        int getAmount();
        int maxFrom();
        int maxTo();
        Node getNode(int no = 0);
    private:
        void maxFrom(int max);
        void maxTo(int max);

        //List of nodes
        Node **stackOfNodes;
        // Amount of added nodes
        int amount = 0;
        // Maximum Node.from value
        int from = 0;
        // Maximum Node.to value
        int to = 0;
        // Dummy node is returned by getNode(no) when
        // Node is not found in listOfNodes
        Node *nodeDummy = new Node();
        // This contains begining of the verses
        int *startOfVerses;
};

#endif // NODES_H
