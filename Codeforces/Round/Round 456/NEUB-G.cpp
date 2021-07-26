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

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

vector < ll > graph[5005];
ll n;
ll level[5005];

ll bfs()
{
    queue < ll > q;

    level[1] = 0;

    q.push(1);

    while(!q.empty())
    {
        ll top = q.front();

        q.pop();

        //cout << "-- " << top << endl;

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll temp = graph[top][i];

            if(level[temp] == -1 || level[temp] > level[top])
            {
                level[temp] = level[top];

                q.push(temp);
            }

        }

        if((level[top + 1] == -1 || level[top + 1] > level[top] + 1) && top + 1 <= n)
        {
            level[top + 1] = level[top] + 1;
            q.push(top + 1);
        }

        if((level[top - 1] == -1 || level[top - 1] > level[top] + 1) && top - 1 >= 1)
        {
            level[top - 1] = level[top] + 1;
            q.push(top - 1);
        }
    }


    return level[n];
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    ll u, v;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        for(i = 1; i <= n; i++)
        {
            graph[i].clear();
        }

        for(i = 1; i <= m; i++)
        {
            slld(u);
            slld(v);

            graph[u].pb(v);
        }
        memset(level,-1,sizeof(level));

        ans = bfs();

        plld(ans);
    }


}

