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

map < pll, ll > mp;
ll ans[100005];
ll in[100005];
vector < ll > graph[100005];

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

        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

        in[u]++;
        in[v]++;

        mp[make_pair(u,v)] = i;
        mp[make_pair(v,u)] = i;
    }

    ll cnt = 0;

    memset(ans,-1,sizeof ans);

    for(i = 1; i <= n; i++)
    {
        if(in[i] <= 2) continue;

        for(j = 0; j < graph[i].size(); j++)
        {
            ll xx = graph[i][j];

//            cout << mp[make_pair(i,xx)] << endl;
            ans[mp[make_pair(i,xx)]] = cnt++;

//            cout << ans[mp[make_pair(i,xx)]] << endl;
        }
        break;
    }

    for(i = 1; i < n; i++)
    {
        if(ans[i] != -1) continue;

//        cout << "-- " << i << endl;
        ans[i] = cnt++;
    }

    for(i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;



}


