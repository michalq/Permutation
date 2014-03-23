#include "Nodes.h"
#include "Node.h"
#include<stdio.h>

/**
 * Constructor, creates stack of nodes
 */
Nodes::Nodes()
{
    // The 200 value is temporarily, it should be generated automatically
    this->stackOfNodes = new Node * [200];
    this->startOfVerses = new int [200];
}

/**
 * Add new node to stack
 *
 * @param   Node
 */
void Nodes::add(Node *node)
{
    this->stackOfNodes[amount] = node;
    this->amount++;
    if (node->getFrom() > this->maxFrom())
    {
        this->maxFrom(node->getFrom());
    }

    if (node->getTo() > this->maxTo())
    {
        this->maxTo(node->getTo());
    }
}

/**
 *
 * @return  Node **         Stack of nodes
 */
Node **Nodes::getList()
{
    return this->stackOfNodes;
}

/**
 *
 * @param   int     no      Number of element
 * @return  Node            Returns specified node
 */
Node Nodes::getNode(int no)
{
    if (no < 0 || no >= this->amount)
        return *nodeDummy;

    return *this->stackOfNodes[no];
}

/**
 * Public getter, returns 'from'
 *
 * @return  int
 */
int Nodes::maxFrom()
{
    return this->from;
}

/**
 * Public getter, returns 'to'
 *
 * @return  int
 */
int Nodes::maxTo()
{
    return this->to;
}

/**
 * Private setter, sets 'to'
 *
 * @param   int     max
 */
void Nodes::maxTo(int max)
{
    this->to = max;
}

/**
 * Private setter, sets 'from'
 *
 * @param   int     max
 */
 void Nodes::maxFrom(int max)
 {
    this->from = max;
 }

/**
 * Public getter, returns amount of nodes
 *
 * @return  int     Amount of nodes
 */
int Nodes::getAmount()
{
    return this->amount;
}

/**
 * Returns human readable table represantation of nodes
 */
void Nodes::showTable()
{
    printf("\nTable representation:\n\n  ");
    int amount = this->getAmount();
    int tabAmount;
    for (int i = 1; i <= this->maxTo(); i++)
    {
        printf("  %i ", i);
    }

    for (int i = 0, k = 1; i < amount; i++)
    {
        if (this->getNode(i - 1).getStatus() && this->getNode(i - 1).getFrom() != this->getNode(i).getFrom())
        {
            printf("\n%i |", k);
            tabAmount = this->getNode(i).getTo();
            k++;
        }
        else
        {
            tabAmount = this->getNode(i).getTo() - this->getNode(i - 1).getTo();
        }
        for (int j = 0; j < tabAmount - 1; j++)
        {
            printf("   |");
        }

        printf(" %c |", this->getNode(i).getName(), tabAmount);
    }
    printf("\n");
}

/**
 * Returns human readable list of nodes
 */
void Nodes::listOfNodes()
{
    printf("\nListof nodes:\n\n");
    int amount = this->getAmount();
    for (int i = 0; i < amount; i++)
    {
        printf(
            "%i. Name: %c, from: %i, to: %i, weight: %i\n",
            i,
            this->getNode(i).getName(),
            this->getNode(i).getFrom(),
            this->getNode(i).getTo(),
            this->getNode(i).getWeight()
        );
    }
}
