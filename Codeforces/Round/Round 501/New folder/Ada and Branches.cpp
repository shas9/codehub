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

#define maxn 300005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll par[maxn];

struct node
{
    ll type, a, b, w;

    node(ll _type, ll _a, ll _b, ll _w)
    {
        type = _type;
        a = _a;
        b = _b;
        w = _w;
    }
};

bool comp(node a, node b)
{
    if(a.w == b.w) return a.type < b.type;

    return a.w > b.w;
}

vector < node > vec;

ll ans[maxn];
ll val[maxn];

ll fnd(ll a)
{
    if(par[a] == a) return a;

    return par[a] = fnd(par[a]);
}

void dsu(ll ind)
{
    node x = vec[ind];

    ll roota = fnd(x.a);
    ll rootb = fnd(x.b);

    if(roota == rootb) return;

    par[rootb] = par[roota];

    val[roota] += val[rootb];

    val[rootb] = 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);
    slld(q);

    for(i = 1; i <= n; i++) par[i] = i, val[i] = 1;

    for(i = 1; i <= m; i++)
    {
        slld(j);
        slld(k);
        slld(l);

        j++, k++;

        vec.push_back(node(0,j,k,l));
    }

    for(i = 1; i <= q; i++)
    {
        slld(j);
        slld(k);

        j++;
        vec.push_back(node(i,j,0,k));
    }

    sort(vec.begin(),vec.end(),comp);

    ll sz = vec.size();
    for(i = 0; i < sz; i++)
    {
        node nd = vec[i];

        if(nd.type == 0)
        {
            dsu(i);
            continue;
        }

        ans[nd.type] = val[fnd(nd.a)];
    }

    for(i = 1; i <= q; i++) plld(ans[i]);



}


