#include<iostream>
#include<stdio.h>
#include "Table.h"
#include "Permutations.h"
#include "Nodes.h"
#include "Node.h"

/**
 * - Do something with dynamically generated tables in Nodes.cpp
 *
 */

int main(void)
{
    //Table table = Table(6,6);
    //Permutations p = Permutations(&table);

    //table.appendData(true);

    Nodes nodes = Nodes();
    nodes.add(new Node('a', 1, 1));
    nodes.add(new Node('b', 1, 3));
    nodes.add(new Node('c', 1, 4));
    nodes.add(new Node('d', 2, 2));
    nodes.add(new Node('e', 2, 4));
    nodes.add(new Node('f', 2, 5));
    nodes.add(new Node('g', 3, 1));
    nodes.add(new Node('h', 3, 2));
    nodes.add(new Node('i', 3, 4));
    nodes.add(new Node('j', 4, 2));
    nodes.add(new Node('k', 4, 3));
    nodes.add(new Node('l', 4, 5));
    nodes.add(new Node('m', 5, 1));
    nodes.add(new Node('n', 5, 3));
    nodes.add(new Node('o', 5, 5));
    nodes.listOfNodes();
    nodes.showTable();

    return 0;
}
