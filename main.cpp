/**
 * Created by: Michal Kutrzeba
 */
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Graph/Generator.h"

/**
 * - Do something with dynamically generated tables in Nodes.cpp and Permutaions.cpp
 */

int main(void)
{
    // Set nodes
    Nodes nodes = Nodes();
    FILE *input;
    input = fopen ("input2","r");
    char name, sign;
    int from, to, weight;
    while(!feof(input))
    {
        fscanf (input, "%c[^ ]", &name);
        fscanf (input, "%i[^>]", &from);
        fscanf (input, "%c", &sign);
        fscanf (input, "%i", &to);
        fscanf (input, "%i\n", &weight);
        nodes.add(new Node(name, from, to, weight));
    }
    fclose(input);

    // Initialize permutations generator
    Graph::Generator generator = Graph::Generator(&nodes);
    generator.init();

    //printf("\nList of nodes:\n");
    //nodes.listOfNodes();
    printf("\n\nTable representation:\n");
    nodes.table();

    printf("\n\nAll permutations:");
    generator.getPermutations()->table();

    printf("\n\nDeterminant in postfix (RPN):\n");
    std::cout << generator.getPermutations()->det()->getRPNEquation();

    printf("\n\nDeterminant in infix:\n");
    std::cout << generator.getPermutations()->det()->getEquation();
    printf("\n");

    return 0;
}
