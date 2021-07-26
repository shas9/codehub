
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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll n;
ll a, r, m;
ll arr[100005];
ll tarr[100005];

ll solve(ll h)
{
	ll tot = h * n;
	ll ase = 0;

	ll ret = 0;

	for(ll i = 1; i <= n; i++) ase += arr[i], tarr[i] = arr[i];

	if(ase >= tot)
	{

		ret += (ase - tot) * r;

		ase -= tot;

		for(ll i = 1; i <= n && ase; i++)
		{
			ll x = tarr[i] - h;

			if(x <= 0) continue;

			tarr[i] -= min(ase,x);

			ase -= min(ase,x);
		}

		ll mv = 0;

		for(ll i = 1; i <= n; i++)
		{
			mv += max(0LL,tarr[i] - h);
		}

		ret += mv * min(a + r, m);
	}
	else
	{
 		ret += (tot - ase) * a;

 		ase -= tot;
 		ase = abs(ase);

 		for(ll i = 1; i <= n && ase; i++)
		{
			ll x = h - tarr[i];

			if(x <= 0) continue;

			tarr[i] += min(ase,x);

			ase -= min(ase,x);
		}

		ll mv = 0;

		for(ll i = 1; i <= n; i++)
		{
			mv += max(0LL,h - tarr[i]);
		}

		ret += mv * min(a + r, m);
	}

	return ret;
}

int main()
{
    ll i, j, k, l, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> a >> r >> m)
    {
		ll mn = mxlld;
		ll mx = 0;

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
			mn = min(mn,arr[i]);
			mx = max(mx,arr[i]);
		}

		ll lo = mn;
		ll hi = mx;

		while(lo <= hi)
		{
			ll mid1 = (lo + (hi - lo) / 3);
			ll mid2 = (hi - (hi - lo) / 3);

			ll x = solve(mid1);
			ll y = solve(mid2);

			if(x <= y) ans = x, hi = mid2 - 1;
			else lo = mid1 + 1;
		}

		cout << ans << "\n";
    }


}


