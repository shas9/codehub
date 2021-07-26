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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

vector < ll > graph[200005];
ll n;
ll cnt;
bool vis[200005];

void solve(ll x, ll dist)
{
    ll sz = graph[x].size();

    vis[x] = 1;
    bool flag = 0;

    if(dist == 2)
        if(sz == 2)
    {
            for(ll i = 0; i < sz; i++)
            {
                ll top = graph[x][i];

                if(vis[top]) continue;

                if(graph[top].size() == 2)
                {
                    vis[top] = 1;

                    for(ll j = 0; j < graph[top].size(); j++)
                    {
                        ll toptop = graph[top][j];

                        if(vis[toptop]) continue;

                        cnt++;

                        solve(toptop,1);
                    }
                }
            }

            return;
    }

    for(ll i = 0; i < sz; i++)
    {
        ll top = graph[x][i];

        if(vis[top] == 0)
        {
            if(dist == 2)
            {
                if(flag == 0)
                {
                    cnt++;
                    flag = 1;
                }

                solve(top,2);
            }
            else
            {
                solve(top, dist + 1);
            }
        }
    }
}

int main()
{
    ll i, j, k, l, m, o, r, q;
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

    cnt = 0;

    solve(1,0);

    plld(cnt);




}

