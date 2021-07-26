#define mx 100005
#define ll long long

ll dist[mx]; // for counting the level. Or shortest distance of every node from starting node.
vector < ll > graph[mx];

void bfs(ll starting_node)
{
    queue < ll > qq;

    vis[starting_node] = 1;

    qq.push(starting_node);

    memset(dist, -1, sizeof dist);

    dist[starting_node] = 0;

    while(!qq.empty())
    {
        ll top = qq.front();
        qq.pop();

        ll sz = graph[top].size();
        for(ll i = 0; i < sz; i++)
        {
            ll v = graph[top][i];

            if(dist[v] != -1) continue;

            dist[v] = dist[top] + 1;

            vis[v] = 1;

            qq.push_back(v);
        }
    }
}

