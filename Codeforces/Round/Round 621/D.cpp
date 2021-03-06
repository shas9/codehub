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

vector < ll > graph[200005];

ll dist[2][200005];

map < ll, ll > mp;

void bfs(ll st, ll en, ll nn)
{
    dist[nn][st] = 0;

    queue < ll > qq;

    qq.push(st);

    while(!qq.empty())
    {
        ll top = qq.front();
        qq.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll node = graph[top][i];

            if(dist[nn][node] != -1) continue;

            dist[nn][node] = dist[nn][top] + 1;

            qq.push(node);
        }
    }
}

vector < pll > lev;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);
    slld(k);

    mp.clear();

    for(i = 1; i <= k; i++)
    {
        slld(input);

        mp[input] = 1;
    }

    bool on = 0;

    for(i = 1; i <= m; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        if(on == 0)
        if(mp.find(u) != mp.end() && mp.find(v) != mp.end()) on = 1;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dist, -1, sizeof dist);

    bfs(1,n,0);
    bfs(n,1,1);

    ans = dist[0][n];

    if(on)
    {
//        bug;
        cout << ans << endl;
        return 0;
    }

    for(i = 1; i <= n; i++)
    {
        if(mp.find(i) != mp.end())
        {
            lev.push_back({dist[1][i], i});
        }
    }


    sort(lev.begin(),lev.end());

    ll tmp = 0;
    for(i = 1; i < lev.size(); i++)
    {
        ll u = lev[i].second;
        ll v = lev[i - 1].second;

        ll t1 = dist[0][u] + dist[1][v] + 1;
        ll t2 = dist[0][v] + dist[1][u] + 1;

        tmp = max(tmp, min(t1,t2));
    }

    cout << min(ans,tmp) << endl;


}



