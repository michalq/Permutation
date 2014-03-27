#include<iostream>
#include<stdio.h>
#include "Permutations/Generator.h"
//#include "Permutations.h"
#include "Nodes.h"
#include "Node.h"

/**
 * - Do something with dynamically generated tables in Nodes.cpp and Permutaions.cpp
 *
 */

int main(void)
{
    Nodes nodes = Nodes();
    nodes.add(new Node('a', 1, 1));//0
    nodes.add(new Node('b', 1, 3));//1
    nodes.add(new Node('c', 1, 4));//2
    nodes.add(new Node('d', 2, 2));//3
    nodes.add(new Node('e', 2, 4));//4
    nodes.add(new Node('f', 2, 5));//5
    nodes.add(new Node('g', 3, 1));//6
    nodes.add(new Node('h', 3, 2));//7
    nodes.add(new Node('i', 3, 4));//8
    nodes.add(new Node('j', 4, 2));//9
    nodes.add(new Node('k', 4, 3));//10
    nodes.add(new Node('l', 4, 5));//11
    nodes.add(new Node('m', 5, 1));//12
    nodes.add(new Node('n', 5, 3));//13
    nodes.add(new Node('o', 5, 5));//14
    nodes.listOfNodes();
    nodes.showTable();

    Permutations::Generator generator = Permutations::Generator(&nodes);
    generator.init();

    //Permutations permutations = Permutations(&nodes);
    //permutations.generatePermutations();

    return 0;
}
