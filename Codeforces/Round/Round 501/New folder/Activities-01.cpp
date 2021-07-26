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

#define mod 100000000


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll dp[300005];
vector < ll > vec;

pair < ll, ll > interval[100005];
unordered_map < ll, ll > mapp;

bool comp(pll a, pll b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(1)
    {
        slld(n);

        if(n == -1) return 0;

        mapp.clear();
        vec.clear();
        for(i = 1; i <= n; i++)
        {
            slld(interval[i].first);
            slld(interval[i].second);

            vec.push_back(interval[i].first);
            vec.push_back(interval[i].second);
        }

        ll sz = vec.size();

        sort(vec.begin(),vec.end());

        ll cnt = 0;
        for(i = 0; i < sz; i++)
        {
            flag = vec[i];

            if(mapp[flag] == 0) mapp[flag] = ++cnt;
        }

        for(i = 1; i <= n; i++)
        {
            interval[i].first = mapp[interval[i].first];
            interval[i].second = mapp[interval[i].second];
        }

        sort(interval + 1, interval + 1 + n, comp);

        memset(dp,0,sizeof dp);

        ll ind = 0;

        for(i = 1; i <= n; i++)
        {
            while(ind < interval[i].second)
            {
                ++ind;
                dp[ind] = dp[ind - 1];
            }

            dp[ind] += dp[interval[i].first] + 1;
            dp[ind] %= mod;
        }

        printf("%08lld\n", dp[interval[n].second]);
    }

}

