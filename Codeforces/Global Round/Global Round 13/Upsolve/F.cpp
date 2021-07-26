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

ll ask(ll l, ll r, ll x)
{
	cout << "? " << r - l + 1 << " " << 1 << endl;

	for(ll i = l; i <= r; i++) cout << i << " ";
	cout << endl;

	cout << x << endl;

	ll ret;

	cin >> ret;

	return ret;
}

ll fndvalid(ll n)
{
	for(ll i = 2; i <= n; i++)
	{
		ll val = ask(1, i - 1, i);

		if(val) return i;
	}

	assert(0);
}

void solve()
{
	ll n;
	vector < ll > ans;

	cin >> n;

	ll valid = fndvalid(n);

	for(ll i = valid + 1; i <= n; i++)
	{
		if(ask(i,i,valid) == 0) ans.push_back(i);
	}

	ll lo = 1;
	ll hi = valid - 1;
	ll ret = -1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(ask(1,mid,valid))
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	assert(ret != -1);

	for(ll i = 1; i < valid; i++)
	{
		if(i != ret) ans.push_back(i);
	}

	cout << "! " << ans.size() << " ";

	for(auto it: ans) cout << it << " ";

	cout << endl;

	return;
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
		solve();
    }

    return 0;
}


