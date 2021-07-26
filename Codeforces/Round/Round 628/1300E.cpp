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

ll arr[1000005];
deque < pair < double, ll > > dq;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    for(i = 1; i <= n; i++)
    {
        dq.push_back(make_pair(arr[i],1));
        ll sz = dq.size();

        while(sz >= 2 && dq[sz - 2] > dq[sz - 1])
        {
            ll tot = dq[sz - 2].second + dq[sz - 1].second;

            double avv = (dq[sz - 2].first * dq[sz - 2].second) + (dq[sz - 1].first * dq[sz - 1].second);
            avv /= (tot * 1.0);

            dq.pop_back();
            dq.pop_back();
            dq.push_back(make_pair(avv,tot));
            sz--;
        }
    }

    for(i = 0; i < dq.size(); i++)
    {
        for(j = 1; j <= dq[i].second; j++) printf("%.10f\n", dq[i].first);
    }



}

