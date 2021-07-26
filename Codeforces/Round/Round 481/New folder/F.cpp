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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 200005

using namespace std;

vector < ll > v;
ll arr[maxn];
vector < ll > q[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
        v.pb(arr[i]);
    }

    sort(v.begin(),v.end());

    for(i = 1; i <= k; i++)
    {
        ll u, v;
        cin >> u >> v;

        q[u].pb(v);
        q[v].pb(u);
    }

    for(i = 1; i <= n; i++)
    {
        ll low = lower_bound(v.begin(),v.end(),arr[i]) - v.begin();

        ll x = q[i].size();

        for( j = 0; j < x; j++)
        {
            ll id = q[i][j];

            if(arr[id] < arr[i]) low--;
        }

        cout << low << " ";
    }


}


