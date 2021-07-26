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

vector < vector < ll > > vec;
ll n, m, k;

ll solve(vector < ll > &v)
{
	ll ret = 0;

	for(ll i = 0; i < n; i++)
	{
		ll cnt1 = 0;
		ll cnt2 = 0;

		for(ll j = 0; j < m; j++)
		{
			cnt1 += (v[j] == vec[i][j]);
			cnt2 += (v[j] != vec[i][j]);
		}

		ret += min(cnt1,cnt2);
	}

	return ret;
}

ll solve1(vector < ll > &v)
{
	ll ret = 0;

	for(ll i = 0; i < m; i++)
	{
		ll cnt1 = 0;
		ll cnt2 = 0;

		for(ll j = 0; j < n; j++)
		{
			cnt1 += (v[j] == vec[j][i]);
			cnt2 += (v[j] != vec[j][i]);
		}

		ret += min(cnt1,cnt2);
	}

	return ret;
}

vector < ll > v;

ll backtrack(ll pos)
{
	if(pos == m)
	{
		return solve(v);
	}

	ll ret = mxlld;

	v.push_back(0);

	ret = backtrack(pos + 1);

	v.pop_back();


	v.push_back(1);

	ret = min(ret, backtrack(pos + 1));

	v.pop_back();

	return ret;
}


int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n >> m >> k)
    {
		ans = mxlld;
		vec.clear();

		for(ll i = 0; i < n; i++)
		{
			vec.push_back({});

			for(ll j = 0; j < m; j++)
			{
				cin >> input;

				vec.back().push_back(input);
			}
		}

		if(n <= k && m <= k)
		{
			ans = min(ans, backtrack(0));
		}
		else if(n <= k)
		{
			for(ll i = 0; i < m; i++)
			{
				v.clear();
				for(ll j = 0; j < n; j++) v.push_back(vec[j][i]);

				ans = min(ans,solve1(v));
			}
		}
		else
		{
			for(ll i = 0; i < n; i++)
			{
				ans = min(ans, solve(vec[i]));
			}
		}

		if(ans > k) cout << "-1\n";
		else cout << ans << "\n";
    }


}


