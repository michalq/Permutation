/**
 * Created by: Michal Kutrzeba
 */
#include <stdio.h>
#include "Permutations/Generator.h"

/**
 * - Do something with dynamically generated tables in Nodes.cpp and Permutaions.cpp
 */

int main(void)
{
    // Set nodes
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
    // Initialize permutations generator
    Permutations::Generator generator = Permutations::Generator(&nodes);
    generator.init();
    // Permutations object
    Permutations::Permutations *permutations = generator.getPermutations();

    //printf("\n\List of nodes:\n");
    //nodes.listOfNodes();
    printf("\n\nTable reresentation:\n");
    nodes.table();

    printf("\n\nAll permutations:");
    permutations->table();

    printf("\nDeterminant:\n");
    permutations->detEquationRPN();

    return 0;
}
