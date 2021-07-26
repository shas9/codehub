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

ll arr[200005];
vector < ll > graph[200005];
ll ans[200005];
ll dist[200005];

struct node
{
    ll xx, odd, even;

    node(ll _xx, ll _odd, ll _even)
    {
        xx = _xx;
        odd = _odd;
        even = _even;
    }
};

void solve1(ll n)
{
    // even to odd;

    queue  < ll > q;

    memset(dist, -1, sizeof dist);

    for(ll i = 1;  i <= n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            dist[i]  = 0;

            q.push(i);
        }
    }

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll xx = graph[top][i];

            if(dist[xx] == -1)
            {
                dist[xx] = dist[top] + 1;

                q.push(xx);
            }
        }
    }

    for(ll i = 1; i <= n; i++)
    {
        if(arr[i] % 2 == 1)
        {
            ans[i] = dist[i];
        }
    }
}

void solve2(ll n)
{
    // even to odd;

    queue  < ll > q;

    memset(dist, -1, sizeof dist);

    for(ll i = 1;  i <= n; i++)
    {
        if(arr[i] % 2 == 1)
        {
            dist[i]  = 0;

            q.push(i);
        }
    }

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll xx = graph[top][i];

            if(dist[xx] == -1)
            {
                dist[xx] = dist[top] + 1;

                q.push(xx);
            }
        }
    }

    for(ll i = 1; i <= n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            ans[i] = dist[i];
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

    for(i = 1; i <= n; i++)
        slld(arr[i]);

    for(i = 1; i <= n; i++) ans[i] = mxlld;

    for(i = 1; i <= n; i++)
    {
        ll lf = i - arr[i];
        ll rf = i + arr[i];

        if(lf >= 1) graph[lf].push_back(i);
        if(rf <= n) graph[rf].push_back(i);
    }

    solve1(n);
    solve2(n);

    for(i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
}

