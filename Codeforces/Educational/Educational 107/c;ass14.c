
/*

1d array:

    int marjan[10]; = (10)

2d array example: // matrix

    int marjan[10][10]; = (10 * 10)
    double marjan[10][10];

3d array example: // cube

    int marjan[10][10][10] = (10 * 10 * 10)

10d array example:

    int marjan[10][10][10][10][10][10][10][10][10][10] = (10^10)

int arr[5][10][3] = total memory(5 * 10 * 3)


int graph[101][101];

int u, v;

u = 1, v = 3;

graph[u][v] = 1;
graph[v][u] = 1; // bi-directional

*/

/*

Algorithm of dfs:

1. Visit the node
2. Go the the left most unvisited child
3. If every child is visited, go to parent node.
*/

#include<stdio.h>

int graph[11][11];
int visited[11];

void dfs(int node)
{
    printf("Now visited node no.: %d\n\n", node);
    visited[node] = 1;
    int i;

    for(i = 1; i <= 10; i++)
    {
        if(graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }


    return;
}

void cycle(int node, int parent)
{
    if(visited[node] == 1)
    {
        printf("Sorry! We found a cycle in your tree. So, it is a graph.\n");
        exit(0);
    }

    visited[node] = 1;
    int i;

    for(i = 1; i <= 10; i++)
    {
        if(i != parent && graph[node][i] == 1)
        {
            cycle(i,node);
        }
    }

    return;
}

int queue[101];

void bfs(int start)
{
    int cursor = 1;
    int i;
    int last = 1;

    for(i = 1; i <= 100; i++) queue[i] = -1;

    queue[cursor] = start;

//    printf("BUG 1\n");

    while(queue[cursor] != -1)
    {
        int top = queue[cursor];
        cursor++;
        visited[top] = 1;

        for(i = 1; i <= 10; i++)
        {
            if(graph[top][i] == 1 && visited[i] == 0)
            {
                last++;
                queue[last] = i;
            }
        }
    }

//    printf("BUG 2");


    printf("The node visited in order: ");

    for(i = 1; i <= last; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");

    return;
}

int main()
{
    int i, j;

//    graph[0][0] = 0;
//    graph[0][1] = 0;
//    graph[0][2] = 0;
//    graph[0][3] = 0;
//    ...
//    graph[0][10] = 0;
//    graph[1][0] = 0;
//    ....
//    graph[1][10] = 0;
//    .....
//    graph[10][10] = 0;

    for(i = 0; i <= 10; i++) // i = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    {
        // j = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        for(j = 0; j <= 10; j++) // nested loop
        {
            graph[i][j] = 0;
        }
    }

    for(i = 0; i <= 10; i++)
    {
        visited[i] = 0;
    }

    int node, edge;

    printf("Please enter the sizeof node (from 1 to 10): ");
    scanf("%d", &node);

    printf("Please enter the number of edge: ");
    scanf("%d", &edge);

    for(i = 1; i <= edge; i++) // to take input all the edges
    {
        int u, v;
        printf("Please enter the %d-th edge: ", i);
        scanf("%d%d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

//    dfs(1);

//    cycle(1,-1);

//    printf("COngratulation! Your tree is a valid tree\n");

//    for(i = 1; i <= node; i++)
//    {
//        for(j = 1; j <= node; j++)
//        {
//            if(graph[i][j] == 1)
//            {
//                printf("Node %d and %d is connected by an edge.\n", i, j);
//            }
//        }
//    }

    bfs(1);

}
