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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 100000

using namespace std;

ll A[maxn + 5];
ll P[maxn + 5];

vector < pair<ll,ll> > graph[maxn + 5];

ll ans;
pair < ll, ll > par;



ll calc(ll ind)
{
    ll sz = graph[ind].size();

    if(sz == 0)
    {
        return A[ind];
    }

    ll x = 2e18;

    for(ll i = 0; i < sz; i++)
    {
        graph[ind][i].second = calc(graph[ind][i].first);

        //cout << graph[ind][i].first << " = " << graph[ind][i].second << endl;

        x = min(x, graph[ind][i].second);
        x = min(x, A[graph[ind][i].first]);
    }

    return x;
}

void solve(ll ind)
{
    ll sz = graph[ind].size();

    pair < ll, ll > top;

    for(ll i = 0; i < sz; i++)
    {
        top = graph[ind][i];

        if(graph[top.first].size() == 0)
        {
            continue;
        }

        ans = max(ans, A[top.first] - top.second);

        //cout << ans << " " << top.first << " " << top.second << endl;

        solve(top.first);

    }

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(A[cs]);
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(P[cs]);
    }


    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll u = P[cs];
        ll v = cs;

        if(u == -1)
        {
            par.first = v;
            //cout << v << " -" << endl;
            continue;
        }

        graph[u].pb(make_pair(v,A[v]));
    }

    ans = -2e18;

    par.second = calc(par.first);

    //cout << par.second << endl;

    ans =(A[par.first] - par.second);

    solve(par.first);

    plld(ans);

}

