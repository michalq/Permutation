#include "Permutations.h"
#include "Nodes.h"

void Permutations::setNodes(Nodes *nodes)
{
    this->nodes = nodes;
}

Permutations::Permutations(Nodes *nodes)
{
    this->setNodes(nodes);
}
