/**
 * Created by: Michal Kutrzeba
 */
#include <stdio.h>
#include "Permutations/Generator.h"
#include <fstream>

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
    //permutations->detEquationRPN();

    return 0;
}
