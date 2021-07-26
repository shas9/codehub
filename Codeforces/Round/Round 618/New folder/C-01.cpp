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

ll ans[5005][5005];
ll arr[5005];
vector < ll > graph[5005];

ll bfs(ll st)
{
    queue < pll > qq;

    qq.push({0,st});
    qq.push({n+1,st});

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();


        for(ll i = 0; i < graph[top.second].size(); i++)
        {
            ll px = graph[top.second][i];

            if(ans[top.second][px] != -1)

            if(top.first < top.second)
            {
               if(px > top.first && px < top.second)
               {

               }
            }
        }
    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    for(i = 1; i <= n; i++)
        slld(arr[i]);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(arr[i] <= arr[j]) continue;

            graph[i].push_back(j);
        }
    }

    memset(ans,-1,sizeof ans);

    for(i = 1; i <= n; i++)
    {
        cout << bfs(i) << " ";
    }

    cout << endl;


}


