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

#define maxn 200005

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

vector < ll > graph[maxn];
ll dist[maxn];
ll par[maxn];
set < pll > qq;

void dfs(ll node, ll p, ll d)
{
    dist[node] = d;
    par[node] = p;

    ll sz = graph[node].size();

    for(ll i = 0; i < sz; i++)
    {
        ll top = graph[node][i];

        if(top == p) continue;

        dfs(top,node,d + 1);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    ll u, v;
    for(i = 1; i < n; i++)
    {
        slld(u);
        slld(v);

        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,-1,0);

    for(i = 1; i <= n; i++)
    {
        if(dist[i] > 2)
        qq.insert(make_pair(-dist[i],i));
    }

    ll cnt = 0;

    while(!qq.empty())
    {
        cnt++;

//        cout << qq.size() << endl;

        set < pll > :: iterator it;
        it = qq.begin();
        ll top = it -> second;
        top = par[top];

        if(qq.find(make_pair(-dist[top],top)) != qq.end())
        qq.erase(qq.find(make_pair(-dist[top],top)));

        ll sz = graph[top].size();

        for(i = 0; i < sz; i++)
        {
            ll topp = graph[top][i];

            if(qq.find(make_pair(-dist[topp],topp)) != qq.end())
            {
                qq.erase(qq.find(make_pair(-dist[topp],topp)));
            }
        }
    }

    plld(cnt);

}

