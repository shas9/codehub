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
ll dp[203][203][203];
string s, t;
ll n, k;

ll solve(ll pos, ll cnta, ll rem)
{
	ll &ret = dp[pos][cnta][rem];

	if(ret != -1) return ret;

	if(pos == s.size()) return ret = 0;

	ret = 0;

	if(s[pos] == t.front())
	{
		ret = max(ret, solve(pos + 1, cnta + 1, rem));
		if(rem) ret = max(ret, solve(pos + 1, cnta, rem - 1) + cnta) ;
	}
	else if(s[pos] == t.back())
	{
		if(rem) ret = max(ret, solve(pos + 1, cnta + 1, rem - 1));
		ret = max(ret, solve(pos + 1, cnta, rem) + cnta);
	}
	else
	{
		ret = max(ret, solve(pos + 1, cnta, rem));

		if(rem)
		{
			ret = max(ret, solve(pos + 1, cnta + 1, rem - 1));
			ret = max(ret, solve(pos + 1, cnta, rem - 1) + cnta);
		}
	}

	return ret;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k >> s >> t)
    {
		memset(dp,-1,sizeof dp);

		if(t.front() == t.back())
		{
			ll cnt = 0;
			for(auto it: s)
			{
				if(it == t.front()) cnt++;
				else if(k)
				{
					k--;
					cnt++;
				}
			}

			cout << cnt * (cnt - 1) / 2 << "\n";
		}
		else
		{
			ans = solve(0,0,k);

			cout << ans << "\n";
		}
    }


}



