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

vector < ll > a, b;

bool calc1(ll mid)
{
	mid--;

	for(ll i = mid, j = 0; i < a.size(); i++, j++)
	{
		if(b[i] < a[j]) return 0;
	}

	return 1;
}

bool calc2(ll mid)
{
	for(ll j = a.size() - mid, i = 0; j < a.size(); j++, i++)
	{
		if(a[j] < b[i]) return 0;
	}

	return 1;
}

ll solve(ll n)
{
	ll lo = 1;
	ll hi = n / 2;
	ll lim1 = n + 1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(calc1(mid))
		{
			lim1 = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	lo = lim1;
	hi = n / 2;
	ll lim2 = lo - 1;

//	for(auto it: a) cout << it << " + ";
//	for(auto it: b) cout << it << " * ";

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(calc2(mid))
		{
			lim2 = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return lim2 - lim1 + 2;
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
		cin >> n;

		a.clear();
		b.clear();

		b.resize(n);

		for(auto &it: b) cin >> it;

		b.push_back(n + n + 5);

		for(ll i = 1, j = 0; i <= 2 * n; i++)
		{
			if(b[j] == i) j++;
			else a.push_back(i);
		}

		b.pop_back();

		ans = solve(2 * n);

		cout << ans << "\n";
    }


}



