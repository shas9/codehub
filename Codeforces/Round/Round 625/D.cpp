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

ll dist_t[200005];

ll path[200005];

ll cnt[200005];

ll n, m;

void bfs()
{
    ll st = path[m];

    memset(dist_t, -1, sizeof dist_t);
    memset(cnt, 0, sizeof cnt);

    queue < ll > qq;

    qq.push(st);

    dist_t[st] = 0;

    cnt[st] = 1;

    while(!qq.empty())
    {
        ll top = qq.front();
        qq.pop();

        for(ll i = 0; i < graph[top].size(); i++)
        {
            ll node = graph[top][i];

            if(dist_t[node] != -1)
            {
                ll x = dist_t[top] + 1;

                if(dist_t[node] == x)
                {
                    cnt[node]++;
                }

                continue;
            }

            cnt[node]++;

            dist_t[node] = dist_t[top] + 1;

            qq.push(node);
        }
    }
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        graph[v].push_back(u);
    }

    slld(m);

    for(i = 1; i <= m; i++)
    {
        slld(path[i]);
    }

    bfs();

    ll mx = 0;
    ll mn = 0;

    for(i = 1; i < m; i++)
    {
        ll spi = dist_t[path[i]];
        ll spi1 = dist_t[path[i + 1]];

//        cout << i << ": " << spi << " " << spi1 << endl;

        if(spi1 + 1 != spi)
        {
            mx++;
            mn++;
            continue;
        }

//        cout << cnt[path[i]] << endl;

        if(cnt[path[i]] >= 2)
        {
            mx++;
        }

    }

    cout << mn <<  " " << mx << endl;
}


