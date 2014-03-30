#include "Node.h"
#ifndef NODES_H
#define NODES_H


class Nodes
{
    public:
        Nodes();
        ~Nodes();
        Node **getList();
        Node *getNode(int no = 0);
        void add(Node *node);
        void table();
        void listOfNodes();
        int getAmount();
        int maxFrom();
        int maxTo();
        int verse(int i);
    private:
        void maxFrom(int max);
        void maxTo(int max);

        //List of nodes
        Node **stackOfNodes;
        // Amount of added nodes
        int amount;
        // Maximum Node.from value
        int from;
        // Maximum Node.to value
        int to;
        // Dummy node is returned by getNode(no) when
        // Node is not found in listOfNodes
        Node *nodeDummy;
        // This contains begining of the verses
        int *startOfVerses;
        // Verse where last was addes node
        int actualVerse;
};

#endif // NODES_H
