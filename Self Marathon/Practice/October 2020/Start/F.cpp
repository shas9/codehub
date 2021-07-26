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

string str;

bool solve(ll len, ll k)
{
	ll aa = 0;

	for(ll i = 0; i < len; i++)
	{
		aa += str[i] == 'a';
	}

	if(aa <= k) return 1;
	if((len - aa) <= k) return 1;

	for(ll i = len; i < str.size(); i++)
	{
		aa -= str[i - len] == 'a';
		aa += str[i] == 'a';

		if(aa <= k) return 1;
		if((len - aa) <= k) return 1;
	}

	return 0;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		cin >> str;

		ans = 1;

		ll lo = 1;
		ll hi = n;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid,k))
			{
				ans = mid;
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}

		cout << ans << "\n";
    }


}


