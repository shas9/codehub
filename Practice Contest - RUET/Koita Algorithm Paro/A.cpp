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

ll dp[30][2][60];
bool prime[200];
vector < ll > v;

ll solve(ll pos, bool issmall, ll sum)
{
	if(pos == 30)
	{
		return prime[sum];
	}

	ll &ret = dp[pos][issmall][sum];

	if(ret != -1) return ret;

	ll lo = 0;
	ll hi = 2;

	if(issmall == 0) hi = v[pos];

	ret = 0;

	for(ll i = lo; i <= hi; i++)
	{
		if(i < hi)
		{
			ret += solve(pos + 1, 1, sum + i);
		}
		else
		{
			ret += solve(pos + 1, issmall, sum + i);
		}
	}

	return ret;
}

void conv(ll x)
{
	v.clear();

	while(x)
	{
		v.push_back(x % 3);
		x /= 3;
	}

	while(v.size() < 30) v.push_back(0);

	reverse(v.begin(),v.end());
}

void calc()
{
	memset(prime,0,sizeof prime);

	for(ll i = 2; i < 200; i++)
	{
		bool on = 1;

		for(ll j = 2; j < i; j++)
		{
			if(i % j == 0) on = 0;
		}

		prime[i] = on;
	}
}

ll soln(ll mid)
{
	conv(mid);

	memset(dp,-1,sizeof dp);

	return solve(1,0,0);
}

void brute()
{
	ll x = 0;
	ll n = (1e13);

	while(n)
	{
		x++;
		n /= 3;
	}

	cout << x << "\n";
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	brute();

    slld(testcase);

    calc();

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> k;

		ll lo = 2;
		ll hi = n;
		ans = -1;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			ll x = soln(mid);

//			cout << mid << " " << x << endl;

			if(x >= k)
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

		cout << ans << "\n";

    }


}


