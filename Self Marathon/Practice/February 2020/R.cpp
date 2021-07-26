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

ll ans[6003];

vector < pll > graph[6003];

struct node
{
    ll u, v, c;
};

node qq[6003];

bool dfs(ll u, ll par, ll v, ll c)
{
    if(u == v) return 1;

    for(ll i = 0; i < graph[u].size(); i++)
    {
        pll xx = graph[u][i];

        if(xx.first == par) continue;

        if(dfs(xx.first, u, v, c))
        {

            ans[xx.second] = max(ans[xx.second],c);
            return 1;
        }
    }

    return 0;
}

ll dfs1(ll u, ll par, ll v)
{
    ll ret = mxlld;
    bool on = 1;

    for(ll i = 0; i < graph[u].size(); i++)
    {
        pll xx = graph[u][i];

        if(xx.first == v)
        {
            return ans[xx.second];
        }

        if(xx.first == par) continue;

        ll x = dfs1(xx.first, u, v);

        if(x == -1) continue;

        ret = min(ans[xx.second], x);

        on = 0;
    }

    if(on) return -1;

    return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i < n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        graph[u].push_back(make_pair(v,i));
        graph[v].push_back(make_pair(u,i));
    }

    for(i = 0; i <= n; i++) ans[i] = 1;

    slld(m);

    for(i = 1; i <= m; i++)
    {
        ll u, v, c;

        slld(u);
        slld(v);
        slld(c);

        qq[i].u = u;
        qq[i].v = v;
        qq[i].c = c;

        dfs(u, - 1, v,c);
    }

//    for(i = 1; i < n; i++)
//    {
//        cout << ans[i] << " ";
//    }
//
//    cout << endl;


    for(i = 1; i <= m; i++)
    {
        ll zz = dfs1(qq[i].u, -1, qq[i].v);

//        cout << qq[i].u << " " << qq[i].v << endl;
//
//        cout << zz << endl;
        if(zz != qq[i].c)
        {
//            cout << i << endl;
            cout << -1 << endl;
            return 0;
        }
    }

    for(i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}



