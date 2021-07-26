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

bool toggle[1003];
bool on[1003];
vector < vector < ll > > v;

bool match(ll n)
{
	for(ll i = 1; i <= n; i++) if(on[i] != toggle[i]) return 0;

	return 1;
}

ll solve(ll n)
{
	ll ret = 0;

	for(auto it: v)
	{
		if(match(n)) return ret;

		for(auto jt: it)
		{
			toggle[jt] ^= 1;
		}

		ret++;
	}

	for(auto it: v)
	{
		if(match(n)) return ret;

		for(auto jt: it)
		{
			toggle[jt] ^= 1;
		}

		ret++;
	}

	if(match(n)) return ret;

	return -1;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		memset(toggle,0,sizeof toggle);
		memset(on,0,sizeof on);

		v.clear();

		cin >> k;

		for(ll i = 1; i <= k; i++)
		{
			cin >> input;
			on[input] = 1;
		}

		for(ll i = 1; i <= n; i++)
		{
			cin >> k;

			v.push_back({});

			for(ll j = 1; j <= k; j++)
			{
				cin >> input;
				v.back().push_back(input);
			}
		}

		ans = solve(m);

		cout << ans << "\n";
    }


}


