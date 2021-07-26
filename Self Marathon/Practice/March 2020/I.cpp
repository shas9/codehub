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

#define mod 1000000007

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll ff[5005];
ll arr[5005];
ll hh[5005];
vector < ll > cow[5005];
ll lft[5005];
ll rgt[5005];

bool comp(ll a, ll b)
{
    return hh[a] <  hh[b];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    slld(m);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    for(i = 1; i <= m; i++)
    {
        slld(ff[i]);
        slld(hh[i]);

        cow[ff[i]].push_back(i);
    }

    for(i = 1; i <= n; i++)
        if(cow[i].size()) sort(cow[i].begin(),cow[i].end(), comp);


    ans = 0;
    ll ways = 0;

    for(i = 1; i <= m; i++)
    {
        ll id = -1, cnt = 0;

        for(j = 1; j <= n; j++)
        {
            if(arr[j] != ff[i]) continue;

            cnt++;

            if(cnt == hh[i])
            {
                id = j;
                break;
            }
        }

        if(id == -1) continue;

        memset(lft,0,sizeof lft);
        memset(rgt,0,sizeof rgt);

        for(j = 1; j < id; j++)
        {
            if(arr[j] == ff[i]) continue;

            lft[arr[j]]++;
        }

        for(j = id + 1; j <= n; j++)
        {
            rgt[arr[j]]++;
        }

        ll curr = 1;
        ll ww = 1;

        for(j = 1; j <= n; j++)
        {
            ll lf = 0, rg = 0, both = 0;

            for(auto u:cow[j])
            {
                if(u == i) continue;

                if(hh[u] <= lft[ff[u]]) lf++;
                if(hh[u] <= rgt[ff[u]]) rg++;
                if(hh[u] <= lft[ff[u]] && hh[u] <= rgt[ff[u]]) both++;
            }

            ll ftwo = (lf * rg) - both;
            ll fone = (lf + rg);

            if(ftwo) curr += 2, ww = (ww * ftwo) % mod;
            else if(fone) curr++, ww = (ww * fone) % mod;
        }

    //        cout << curr << " ~~ " << ww << endl;

        if(curr > ans) ans = curr, ways = ww;
        else if(curr == ans) ways = (ways + ww) % mod;
    }


    memset(rgt,0,sizeof rgt);

    for(i = 1; i <= n; i++)
    {
        rgt[arr[i]]++;
    }

    ll curr = 0;
    ll ww = 1;

    for(i = 1; i <= n; i++)
    {
        ll cnt = 0;

        for(auto u:cow[i])
        {
            if(hh[u] <= rgt[ff[u]]) cnt++;
        }

        if(cnt)
        {
            curr++;
            ww = (ww * cnt) % mod;
        }
    }

//    cout << ans << " " << ways << endl;
//    cout << curr << " " << ww << endl;

    if(curr > ans) ans = curr, ways = ww;
    else if(curr == ans) ways = (ways + ww) % mod;

    printf("%lld %lld\n", ans, ways);
}


