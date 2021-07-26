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

#define maxn 100005

using namespace std;

map < string, ll > mp;

ll mn[maxn];
ll ind[maxn];
vector < ll > arr[maxn];
ll cost[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    mp.clear();
    for(i = 0; i < maxn; i++)
    {
        mn[i] = mxlld;
    }
    memset(ind,0,sizeof ind);

    cin >> n >> k >> m;

    string in;

    for(i = 1; i <= n; i++)
    {
        cin >> in;

        mp[in] = i;
    }

    for(i = 1; i <= n; i++)
    {
        slld(cost[i]);
        //cout << "--> " << cost[i] << endl;
    }

    for(i = 1; i <= k; i++)
    {
        ll u , v;

        slld(u);

        for(j = 1; j <= u; j++)
        {
            slld(v);

            arr[i].pb(v);

            mn[i] = min(mn[i],cost[v]);

            ind[v] = i;
        }
    }

//    for(i = 1; i <= n; i++)
//    {
//        cout << "Ind[i]" << ind[i] << " Min[i]: " << mn[i] << endl;
//    }


    ans = 0;

    for(i = 1; i <= m; i++)
    {
        cin >> in;

        flag = mp[in];

        tag = ind[flag];

        ans += mn[tag];
    }

    cout << ans << endl;


}


