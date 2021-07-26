#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector < pll > g[103];
ll dist[103];

void bfs(ll st)
{
    for(ll i = 1; i <= 10; i++) dist[i] = 1e17;

    priority_queue < ll > q;
    q.push({0,st});
    dist[st] = 0;

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(auto it: g[top])
        {
            if(dist[it] > dist[top] + 1)
            {
                dist[it] = dist[top] + 1;
                q.push(it);
            }
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;

    for(ll i = 1; i <= n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;

        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }

    bfs(5);

    for(ll i = 1; i <= 10; i++) cout << i << ": " << dist[i] << endl;
}
