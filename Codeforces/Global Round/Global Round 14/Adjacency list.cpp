#include<iostream>
#include<vector>

using namespace std;

vector < int > adjacencylist[110];

void init()
{
    for(int i = 0; i <= 100; i++) adjacencylist[i].clear();
}

void addedge(int u, int v)
{
    adjacencylist[u].push_back(v);
    adjacencylist[v].push_back(u);
}

void printlist()
{
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j < adjacencylist[i].size(); j++)
        {
            cout << i << " and " << adjacencylist[i][j] << " is connected\n";
        }
    }
}


int main()
{
    init();

    int edge;

    cin >> edge;

    for(int i = 1; i <= edge; i++)
    {
        int u, v;

        cin >> u >> v;

        addedge(u,v);
    }

    printlist();
}
