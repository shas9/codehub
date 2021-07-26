 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

ll arr[200005];
vector < ll > reg, imp;

ll solve(ll x)
{
	if(x <= 0) return 0;

	ll lo = 0;
	ll hi = imp.size() - 1;

	ll ret = -2;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(imp[mid] >= x)
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return ret + 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m;

		reg.clear();
		imp.clear();

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;

			if(input == 1) reg.push_back(arr[i]);
			else imp.push_back(arr[i]);
		}

		sort(reg.begin(),reg.end());
		reg.push_back(0);
		reverse(reg.begin(),reg.end());

		sort(imp.rbegin(),imp.rend());
//
//		for(auto it: reg) cout << it << " * ";
//		cout << endl;

		for(ll i = 1; i < reg.size(); i++)
		{
			reg[i] += reg[i - 1];
		}

		for(ll i = 1; i < imp.size(); i++)
		{
			imp[i] += imp[i - 1];
		}

		ans = mxlld;

		for(ll i = 0; i < reg.size(); i++)
		{
			ll x = solve(m - reg[i]);

//			cout << i << " " << x << " " << m - reg[i] << "\n";

			if(x != -1)
			{
				ans = min(ans, i + (x * 2));
			}
		}

		if(ans == mxlld) ans = -1;

		cout << ans << "\n";
	}


}


