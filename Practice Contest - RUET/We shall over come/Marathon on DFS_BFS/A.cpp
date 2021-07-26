#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

using namespace std;

vector < ll > graph[2100];

ll color[2100];

ll ans;

bool visited[2100];

queue < ll > q;

void bfs(ll source)
{
    //cout << " " << source << endl;
    visited[source] = true;
    ll i, j, k, l;

    q.push(source);

    while(!q.empty())
    {
        k = q.front();

        //cout << "Front: " << k << endl;

        q.pop();
        l = graph[k].size();

        for(i = 0; i < l; i++)
        {
            if(color[graph[k][i]] != -1)
            {
                if(color[graph[k][i]] == color[k])
                {
                    ans = 1;
                }
            }
            else
            {
                if(visited[graph[k][i]] == false)
                {
                    visited[graph[k][i]] = true;
                    q.push(graph[k][i]);

                    if(color[k] == 1)
                    {
                        color[graph[k][i]] = 0;
                    }
                    else
                    {
                        color[graph[k][i]] = 1;
                    }
                }
            }
        }
    }

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;
    ll sctest, bugs;
    ll a, b;

    slld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        slld(bugs);
        slld(sctest);

        for(j = 1; j <= bugs; j++)
        {
            graph[j].clear();
            color[j] = -1;
        }

        for(j = 1; j <= sctest; j++)
        {
            slld(a);
            slld(b);

            graph[a].pb(b);
            graph[b].pb(a);
        }
        while(!q.empty())
        {
            q.pop();
        }

        printf("Scenario #%lld:\n", i);

        ans = 0;

        color[1] = 1;

        memset(visited,false,sizeof(visited));

        for(j = 1; j <= bugs; j++)
        {
            if(visited[j] == false)
            {
                bfs(j);
            }

            //cout << "     " << j << endl;

            if(ans == 1)
            {
                break;
            }
        }

        if(ans == 1)
        {
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "No suspicious bugs found!" << endl;
        }
    }
}

