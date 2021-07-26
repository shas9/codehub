/*

Property of tree:

1. There will be no cycle.
2. The edges will be bi-directional.
3. There must be one way to go from one node to another

Property of Graph:

1. There might be a cycle, might not be a cycle.
2. The edges might be directional, might be bi-directional.
3. There might be one or more than one way to traverse from one node to another. Or maybe none.

Property of forest:

1. There will be more than one tree in a single forest.
2. There will be no graph in a forest.



Algorithm:

1. BFS Algorithm (Use to traverse graph)
*/

#include <stdio.h>


int main()
{
    printf("Please enter the node size: ");
    int node;
    scanf("%d", &node);

    printf("Please enter the number of edge (Recommended edge: %d): ", node - 1);
    int edge;
    scanf("%d" &edge);

    int i;

    for(i = 1; i <= edge; i++)
    {
        int u, v;

        printf("Please type the number of two edge to connect: ");
        scanf("%d%d", &u, &v);
    }
}
