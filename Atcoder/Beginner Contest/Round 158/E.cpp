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

map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	string s;

	while(cin >> n >> m >> s)
	{
		if(m == 2 || m == 5)
		{
			ans = 0;

			for(ll i = 0; i < n; i++)
			{
				if((s[i] - '0') % m == 0)
				{
					ans += i + 1;
				}
			}

			cout << ans << "\n";
			continue;
		}
		mp.clear();
		mp[0] = 1;

		ll num = 0;
		ans = 0;

		for(auto it: s)
		{
			num *= 10;
			num += (it - '0');
			num %= m;

			ans += mp[num];

			mp[num]++;
		}

		cout << ans << "\n";
	}


}


