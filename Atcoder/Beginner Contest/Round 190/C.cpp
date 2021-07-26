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
ll n, m, k;
ll dp[16][(1 << 16)];
ll ff[105];
pll qq[105];
pll zz[105];

ll solve(ll pos, ll mask)
{
	if(pos == k)
	{
		for(ll i = 0; i < k; i++)
		{
			if(check(mask,i))
			{
				ff[zz[i].first] = 1;
			}
			else
			{
				ff[zz[i].second] = 1;
			}
		}

		ll cnt = 0;

		for(ll i = 1; i <= m; i++)
		{
			if(ff[qq[i].first] && ff[qq[i].second]) cnt++;
		}

		for(ll i = 0; i < k; i++)
		{
			if(check(mask,i))
			{
				ff[zz[i].first] = 0;
			}
			else
			{
				ff[zz[i].second] = 0;
			}
		}

		return cnt;
	}

	ll &ret = dp[pos][mask];

	if(ret != -1) return ret;

	return ret = max(solve(pos + 1, mask), solve(pos + 1, Set(mask,pos)));
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m )
    {
		memset(ff,0,sizeof ff);
		memset(dp,-1,sizeof dp);

		for(ll i = 1; i <= m; i++) cin >> qq[i].first >> qq[i].second;

		cin >> k;

		for(ll i = 0; i < k; i++) cin >> zz[i].first >> zz[i].second;

		ans = solve(0,0);

		cout << ans << "\n";
    }


}



