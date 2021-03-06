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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > graph[2003];
ll dist[2003];
ll ans[2003];
bool vis[2003];

void bfs(ll st)
{
    queue < ll > qq;

    qq.push(st);

    memset(dist,0,sizeof dist);
    memset(vis,0,sizeof vis);

    vis[st] = 1;
    while(!qq.empty())
    {
        ll top = qq.front();
        qq.pop();

        for(ll xx = 0; xx < graph[top].size(); xx++)
        {
            ll i = graph[top][xx];

            if(vis[i]) continue;

            dist[i] = dist[top] + 1;

            if(i > st)
            {
                ans[dist[i]]++;
            }

            vis[i] = 1;

            qq.push(i);
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    ll x, y;

    slld(x);
    slld(y);

    for(i = 1; i < n; i++)
    {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }

    graph[x].push_back(y);
    graph[y].push_back(x);

    for(i = 1; i <= n; i++)
    {
        bfs(i);
    }

    for(i = 1; i < n; i++)
    {
        cout << ans[i] << endl;
    }

}



