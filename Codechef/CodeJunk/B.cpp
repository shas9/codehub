// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[100005];

ll func(ll n, ll k, ll x)
{
	ll ret = 0;

	for(ll i = 1;  i <= n; i++)
	{
		ll xx = 1;

		for(ll j = 1; j <= k; j++)
		{
			xx *= (x - arr[i]);
		}

		ret += abs(xx);
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    slld(k);

    ans = 0;

    for(ll i = 1; i <= n; i++) slld(arr[i]);

    ans = func(n,k,0);

    ll res = 0;

    ll lo = 1;
    ll hi = 100000;

    while(lo <= hi)
    {
		ll mid1 = (lo + (hi - lo) / 3);
		ll mid2 = (hi - (hi - lo) / 3);

		ll ans1 = func(n,k,mid1);
		ll ans2 = func(n,k,mid2);

		if(ans1 <= ans2)
		{
			if(ans == ans1) res = min(res, mid1);
			else if(ans > ans1) res = mid1;

			ans = min(ans, ans1);
			hi = mid2 - 1;
		}
		else
		{
			if(ans == ans2) res = min(res, mid2);
			else if(ans > ans2) res = mid2;
			ans = min(ans, ans2);
			lo = mid1 + 1;
		}
    }


    printf("%lld\n",res);


}




