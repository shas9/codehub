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

vector < ll > v, f;

ll bs(ll val)
{
	if(val == 0) return 0;

	ll lo = 0;
	ll hi = f.size() - 1;
	ll ret = hi;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(f[mid] >= val)
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

ll circle(ll x, ll y)
{
	ll ret = (x / y);

	if(x % y) ret++;

	return ret;
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

		v.resize(n);
		f.clear();
		ll sum = 0;
		ll mx = mnlld;

		for(auto &it: v)
		{
			cin >> it;
			sum += it;
			mx = max(sum, mx);

			f.push_back(mx);
		}

		for(ll i = 0; i < m; i++)
		{
			ll ans = 0;
			cin >> input;

			if(f.back() < input && sum <= 0)
			{
				ans = 0;
			}
			else if(f.back() < input)
			{
				ans = circle(input - f.back(), sum);

				input -= (ans * sum);

				ans = (ans * n);

				ans += bs(input);
			}
			else
			{
				ans = bs(input);
			}

			cout << ans - 1 << " ";
		}

		cout << "\n";
    }


}



