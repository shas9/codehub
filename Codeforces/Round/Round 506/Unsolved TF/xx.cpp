///input
/*
    11 15
    1 2
    1 3
    1 4
    2 6
    3 7
    3 8
    4 7
    6 10
    7 9
    8 7
    8 5
    9 7
    9 10
    9 5
    10 5
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e,s,d,x,y,a,b;
    cin>>v>>e;
    vector<int>vec[v];
    vector<int>lev(v,0);
    vector<int>in(v,0);
    for(int i=1; i<=e; i++)
    {
        cin>>s>>d;
        vec[s].push_back(d);
        if(i==1)
            ++in[i];
    }
    for(int i=1; i<=v; i++)
    {
        //cout<<"Vertex of "<<i<<": ";
        int s=vec[i].size();
        for(int j=0; j<s; j++)
        {
            int t=vec[i][j];
            if(in[t]==0)
            {
                lev[t]=lev[i]+1;
                ++in[t];
                cout<<"level of "<<t<<": "<<lev[t]<<endl;
            }

            //cout<<"level of "<<t<<": "<<lev[t]<<endl;
            //bfs(vec[i][j],s);

        }
    }
    cout<<"Give the node for finding  shortest path: ";
    cin>>s>>d;
    a=lev[s];
    b=lev[d];
    if(a>b)
        cout<<"Shortest path from "<<d<<" to "<<s<<" is "<<a-b<<endl;
    else
        cout<<"Shortest path from "<<s<<" to "<<d<<" is "<<b-a<<endl;

}
